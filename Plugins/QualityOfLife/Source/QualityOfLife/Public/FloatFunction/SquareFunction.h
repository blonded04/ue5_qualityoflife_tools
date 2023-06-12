#pragma once

#include "CoreMinimal.h"
#include "FloatFunction.h"
#include "SquareFunction.generated.h"

/**
 * FloatFunction that squares given value
 */
UCLASS()
class QUALITYOFLIFE_API USquareFunction : public UFloatFunction
{
	GENERATED_BODY()
	
public:
	virtual float Eval_Implementation(float Value) override;
};
