#pragma once

#include "CoreMinimal.h"
#include "QL_FloatFunction.h"
#include "QL_FloatFunction_Identity.generated.h"

/**
 * Basic FloatFunction that returns the same value
 */
UCLASS(DisplayName="Identity")
class QUALITYOFLIFE_API UQL_FloatFunction_Identity : public UQL_FloatFunction
{
	GENERATED_BODY()

public:
	virtual float Eval_Implementation(float Value) override;
};
