#pragma once

#include "CoreMinimal.h"
#include "StringParseTool.generated.h"

class UMyObjejct;

/**
 * DataAsset to get strings from other classes float/int/bool-fields and add them to a Description into DescriptionPreview.
 * 
 * Format for fields inside Description is strictly following:
 * - int/float-fields: {ObjX:MemberVariableName} where X is an integer between 1 and 3 representing StringParseTool member-variable and MemberVariableName exists as a member-variable / getter() inside *ObjX
 * - bool-fields: {ObjX:MemberVariableName$PrintIfTrue$PrintIfFalse} where X is an integer between 1 and 3 representing StringParseTool member-variable and MemberVariableName exists as a member-variable / getter() inside *ObjX
 */
UCLASS()
class DEMO_API UStringParseTool : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	FString ParseDescription() const;

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category="Objects")
	UMyObjejct *Obj1;
	
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category="Objects")
	UMyObjejct *Obj2;
	
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category="Objects")
	UMyObjejct *Obj3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString DescriptionPreview;

private:
	struct FToken
	{
		enum TOKEN_STATUS { READY, NEED_TO_PARSE } TokenStatus;
		FString TokenValue;
	};

	UE_NODISCARD TOptional<TArray<FToken>> GetTokens(const FString& Str) const;

	UE_NODISCARD TOptional<FString> ParseToken(const FString& TokenValue) const;

	UE_NODISCARD static int32 FindCharacterInToken(const FString& TokenValue, const FString& SubStr, int32 IndexStart);

	UE_NODISCARD TOptional<UMyObjejct*> GetObjectByName(FString&& Name) const;
};
