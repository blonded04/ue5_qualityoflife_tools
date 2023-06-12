#pragma once

#include "CoreMinimal.h"
#include "FloatFunction.h"
#include "IdentityFunction.generated.h"

/**
 * Basic FloatFunction that returns the same value
 */
UCLASS()
class QUALITYOFLIFE_API UIdentityFunction : public UFloatFunction
{
	GENERATED_BODY()

public:
	virtual float Eval_Implementation(float Value) override;
};
