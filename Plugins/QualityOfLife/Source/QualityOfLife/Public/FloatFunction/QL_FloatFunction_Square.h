#pragma once

#include "CoreMinimal.h"
#include "QL_FloatFunction.h"
#include "QL_FloatFunction_Square.generated.h"

/**
 * FloatFunction that squares given value
 */
UCLASS(DisplayName="Square")
class QUALITYOFLIFE_API UQL_FloatFunction_Square : public UQL_FloatFunction
{
	GENERATED_BODY()
	
public:
	virtual float Eval_Implementation(float Value) override;
};
