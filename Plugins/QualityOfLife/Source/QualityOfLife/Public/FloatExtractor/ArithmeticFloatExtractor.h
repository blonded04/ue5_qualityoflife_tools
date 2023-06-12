#pragma once

#include "CoreMinimal.h"
#include "FloatExtractor.h"
#include "ArithmeticFloatExtractor.generated.h"

/**
 * FloatExtractor that changes value by some delta every time FloatExtractor is called
 */
UCLASS()
class QUALITYOFLIFE_API UArithmeticFloatExtractor : public UFloatExtractor
{
	GENERATED_BODY()
	
public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value = {};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Delta = 1.0f;
};
