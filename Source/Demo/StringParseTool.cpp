#include "StringParseTool.h"

#include "MyObjejct.h"
#include "Kismet/KismetStringLibrary.h"

void UStringParseTool::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	DescriptionPreview = ParseDescription();
}

FString UStringParseTool::ParseDescription() const
{
	//  Of course it's possible to do it in one for-loop going through each symbol once, but for more
	// readability in this non high-frequency code using default parser-pipeline Text -> Tokens -> ParseResult
	const FString& Str = Description.ToString();
	TArray<FToken> Tokens;
	
	int32 ProcessedSymbols = 0;
	while (ProcessedSymbols < Str.Len())
	{
		int32 LeftBracket = Str.Find("{", ESearchCase::CaseSensitive, ESearchDir::FromStart, ProcessedSymbols);

		if (LeftBracket == Str.Len())
		{
			Tokens.Push({FToken::READY, Str.Mid(ProcessedSymbols, Str.Len() - ProcessedSymbols)});
			break;
		}

		int32 RightBracket = Str.Find("}", ESearchCase::CaseSensitive, ESearchDir::FromStart, LeftBracket);
		if (RightBracket == Str.Len())
		{
			return "PARSE_ERROR: no matching \'}\' for \'{\' at position " + FString::FromInt(LeftBracket);
		}

		if (0 < LeftBracket - ProcessedSymbols)
		{
			Tokens.Push({FToken::READY,
				Str.Mid(ProcessedSymbols, LeftBracket - ProcessedSymbols)});	
		}
		Tokens.Push({FToken::NEED_TO_PARSE,
			Str.Mid(LeftBracket + 1, RightBracket - LeftBracket - 1)});
		ProcessedSymbols = RightBracket + 1;
	}

	TArray<FString> StringArray;
	StringArray.Reserve(Tokens.Num());
	for (auto& [TokenStatus, TokenValue] : Tokens)
	{
		if (TokenStatus == FToken::READY)
		{
			StringArray.Push(std::move(TokenValue));
			continue;
		}

		auto NewTokenValue = ParseToken(TokenValue);

		if (!NewTokenValue)
		{
			return "PARSE_ERROR: couldn't parse token " + TokenValue;
		}
		StringArray.Push(std::move(*NewTokenValue));
	}

	return UKismetStringLibrary::JoinStringArray(StringArray, "");
}

TOptional<FString> UStringParseTool::ParseToken(const FString& TokenValue) const
{
	int32 SemicolonIndex = TokenValue.Find(":");
	SemicolonIndex = SemicolonIndex == -1 ? TokenValue.Len() : SemicolonIndex;
	int32 DollarIndex1 = TokenValue.Find("$", ESearchCase::CaseSensitive, ESearchDir::FromStart, SemicolonIndex + 1);
	DollarIndex1 = DollarIndex1 == -1 ? TokenValue.Len() : DollarIndex1;
	int32 DollarIndex2 = TokenValue.Find("$", ESearchCase::CaseSensitive, ESearchDir::FromStart, DollarIndex1 + 1);
	DollarIndex2 = DollarIndex2 == -1 ? TokenValue.Len() : DollarIndex2;
	
	if (SemicolonIndex == TokenValue.Len() || (DollarIndex1 != TokenValue.Len() && DollarIndex2 == TokenValue.Len()))
	{
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Token {%s} doesn't follow required format"),
			this, *TokenValue);
		
		return NullOpt;
	}

	UMyObjejct *Holder;
	if (FProperty *HolderProperty = GetClass()->FindPropertyByName(FName(TokenValue.Mid(0, SemicolonIndex)));
		HolderProperty == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Couldn't find FProperty* named \"%s\" for token {%s}"),
			this, *TokenValue.Mid(0, SemicolonIndex), *TokenValue);
		
		return NullOpt;
	} else if (FObjectProperty *ObjectHolderProperty = CastField<FObjectProperty>(HolderProperty);
		ObjectHolderProperty == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Couldn't cast property named \"%s\" on address \'%p\' to FObjectProperty* for token {%s}"),
			this, *TokenValue.Mid(0, SemicolonIndex), HolderProperty, *TokenValue);
		
		return NullOpt;
	} else if (UObject *HolderObject = ObjectHolderProperty->GetOptionalPropertyValue_InContainer(this);
		HolderObject == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Couldn't get UObject* named \"%s\" for token {%s}"),
			this, *TokenValue.Mid(0, SemicolonIndex), *TokenValue);
		
		return NullOpt;
	} else if (UMyObjejct *TempHolder = Cast<UMyObjejct>(HolderObject);
		TempHolder == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Couldn't cast object named \"%s\" on address \'%p\' to MyObjejct* for token {%s}"),
			this, *TokenValue.Mid(0, SemicolonIndex), HolderObject, *TokenValue);
		
		return NullOpt;
	} else
	{
		Holder = TempHolder;
	}

	FString RequestedPropertyName = TokenValue.Mid(SemicolonIndex + 1, DollarIndex1 - SemicolonIndex - 1);
	FProperty *ValueProperty = Holder->GetClass()->FindPropertyByName(FName(std::move(RequestedPropertyName)));
    if (ValueProperty == nullptr)
   	{
    	UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Couldn't find FProperty* named \"%s\" for object \'%p\' for token {%s}"),
			 this, *TokenValue.Mid(SemicolonIndex + 1, DollarIndex1 - SemicolonIndex - 1), Holder, *TokenValue);
    	
    	return NullOpt;
   	}

	if (DollarIndex1 == DollarIndex2)  // i. e. we are guaranteed working not with bool
	{
		FNumericProperty *NumericValueProperty = CastField<FNumericProperty>(ValueProperty);
		if (NumericValueProperty == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: FProperty* on address \'%p\' named \"%s\" inside UMyObjejct* on address \'%p\' is not a float/int property (while it must be) for token {%s}"),
				this, ValueProperty, *TokenValue.Mid(SemicolonIndex + 1, DollarIndex1 - SemicolonIndex - 1), Holder, *TokenValue);

			return NullOpt;
		}

		return NumericValueProperty->GetNumericPropertyValueToString_InContainer(Holder);
	}
	
	if (FBoolProperty *BoolValueProperty = CastField<FBoolProperty>(ValueProperty))
	{
		return BoolValueProperty->GetPropertyValue(Holder)
			? TokenValue.Mid(DollarIndex1 + 1, DollarIndex2 - DollarIndex1 - 1)
			: TokenValue.Mid(DollarIndex2 + 1, TokenValue.Len() - DollarIndex2 - 1);
	}
	
	UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: FProperty* on address \'%p\' with name \"%s\" inside UMyObjejct* on address \'%p\' is not a bool property (while it must be) for token {%s}"),
		this, ValueProperty, *TokenValue.Mid(SemicolonIndex + 1, DollarIndex1 - SemicolonIndex - 1), Holder, *TokenValue);
	
	return NullOpt;
}
