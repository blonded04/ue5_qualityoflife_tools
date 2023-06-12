#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.generated.h"

/**
 *  FloatExtractor is a blueprint instancable wrapper around float
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class QUALITYOFLIFE_API UQL_FloatProvider : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetValue();

    virtual float GetValue_Implementation();
};
