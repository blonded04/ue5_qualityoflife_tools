#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around float
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class QUALITYOFLIFE_API UQL_FloatProvider : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Float Provider")
    float GetValue();

    virtual float GetValue_Implementation();
};
