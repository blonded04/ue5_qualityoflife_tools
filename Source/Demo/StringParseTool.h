#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StringParseTool.generated.h"

class UMyObjejct;

UCLASS()
class DEMO_API UStringParseTool : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	FString ParseDescription() const;

	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category="Objects")
	UMyObjejct* Obj1;
	
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category="Objects")
	UMyObjejct* Obj2;
	
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category="Objects")
	UMyObjejct* Obj3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString DescriptionPreview;
};
