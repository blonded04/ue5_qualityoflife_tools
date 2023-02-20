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
	TArray<FToken> Tokens;
	if (auto TokenizedString = GetTokens(Description.ToString())) {
		Tokens = MoveTemp(*TokenizedString);
	} else
	{
		return "PARSE_ERROR: Invalid string format";
	}

	TArray<FString> StringArray;
	StringArray.Reserve(Tokens.Num());
	for (auto& [TokenStatus, TokenValue] : Tokens)
	{
		if (TokenStatus == FToken::READY)
		{
			StringArray.Push(MoveTemp(TokenValue));
			continue;
		}

		auto NewTokenValue = ParseToken(TokenValue);

		if (!NewTokenValue)
		{
			return "PARSE_ERROR: couldn't parse token " + TokenValue;
		}
		StringArray.Push(MoveTemp(*NewTokenValue));
	}

	return UKismetStringLibrary::JoinStringArray(StringArray, "");
}

TOptional<TArray<UStringParseTool::FToken>> UStringParseTool::GetTokens(const FString& Str) const
{
	TArray<FToken> Tokens;
	
	int32 ProcessedSymbols = 0;
	while (ProcessedSymbols < Str.Len())
	{
		int32 LeftBracket = FindCharacterInToken(Str, "{", ProcessedSymbols);

		if (LeftBracket == Str.Len())
		{
			Tokens.Push({FToken::READY, Str.Mid(ProcessedSymbols, Str.Len() - ProcessedSymbols)});
			break;
		}

		int32 RightBracket = FindCharacterInToken(Str, "}", LeftBracket);
		if (RightBracket == Str.Len())
		{
			UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: no matching \'}\' for \'{\' at position \'%i\'"),
				this, *FString::FromInt(LeftBracket));
			
			return NullOpt;
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

	return Tokens;
}

TOptional<FString> UStringParseTool::ParseToken(const FString& TokenValue) const
{
	int32 SemicolonIndex = FindCharacterInToken(TokenValue, ":", 0);
	int32 DollarIndex1 = FindCharacterInToken(TokenValue, "$", SemicolonIndex + 1);
	int32 DollarIndex2 = FindCharacterInToken(TokenValue, "$", DollarIndex1 + 1);
	
	if (SemicolonIndex == TokenValue.Len() || (DollarIndex1 != TokenValue.Len() && DollarIndex2 == TokenValue.Len()))
	{
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Token {%s} doesn't follow required format"),
			this, *TokenValue);
		
		return NullOpt;
	}

	UMyObjejct *Holder;
	if (auto MaybeHolder = GetObjectByName(TokenValue.Left(SemicolonIndex)))
	{
		Holder = *MaybeHolder;
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("StringParseTool-%p: Couldn't find member-variable named \"%s\" for StringParseTool \'%p\' for token {%s}"),
			 this, *TokenValue.Left(SemicolonIndex), this, *TokenValue);

		return NullOpt;
	}

	FString RequestedPropertyName = TokenValue.Mid(SemicolonIndex + 1, DollarIndex1 - SemicolonIndex - 1);
	FProperty *ValueProperty = Holder->GetClass()->FindPropertyByName(FName(MoveTemp(RequestedPropertyName)));
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

int32 UStringParseTool::FindCharacterInToken(const FString& TokenValue, const FString& SubStr, int32 IndexStart)
{
	const int32 Index = TokenValue.Find(SubStr, ESearchCase::CaseSensitive, ESearchDir::FromStart, IndexStart);
	return Index == -1 ? TokenValue.Len() : Index;
}

TOptional<UMyObjejct*> UStringParseTool::GetObjectByName(FString&& Name) const
{
#define STRINGPARSETOOL_MAP_ENTRY(name, obj) {FString(name), [](const UStringParseTool* ParseTool) { return ParseTool->obj; }}
	static TMap<FString, TFunction<UMyObjejct*(const UStringParseTool*)>> NameNoFunction = {
		STRINGPARSETOOL_MAP_ENTRY("Obj1", Obj1),
		STRINGPARSETOOL_MAP_ENTRY("Obj2", Obj2),
		STRINGPARSETOOL_MAP_ENTRY("Obj3", Obj3),
	  };
#undef STRINGPARSETOOL_MAP_ENTRY
	
	if (NameNoFunction.Contains(Name))
	{
		return NameNoFunction[Name](this);
	}
	return NullOpt;
}
