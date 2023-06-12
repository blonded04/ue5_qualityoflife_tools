#pragma once

#include "CoreMinimal.h"
#include "QL_FloatFunction.generated.h"

/**
 * Blueprints instanceable wrapper around float to float function 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class QUALITYOFLIFE_API UQL_FloatFunction : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Float Function")
    float Eval(float Value);

    virtual float Eval_Implementation(float Value);
};
