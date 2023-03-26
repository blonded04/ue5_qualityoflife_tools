#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FloatFunction.generated.h"

/**
 * FloatFunction is a blueprints instancable wrapper around float -> float function 
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class DEMO_API UFloatFunction : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float Eval(float Value);

    virtual float Eval_Implementation(float Value);
};
