#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FloatExtractor.generated.h"

/**
 *  FloatExtractor is a blueprint instancable wrapper around float
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class DEMO_API UFloatExtractor : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetValue();

    virtual float GetValue_Implementation();
};
