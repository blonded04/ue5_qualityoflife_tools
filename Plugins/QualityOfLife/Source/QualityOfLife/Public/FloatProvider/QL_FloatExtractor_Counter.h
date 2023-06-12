#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "QL_FloatExtractor_Counter.generated.h"

/**
 * FloatExtractor that changes value by some delta every time FloatExtractor is called
 */
UCLASS()
class QUALITYOFLIFE_API UQL_FloatExtractor_Counter : public UQL_FloatProvider
{
	GENERATED_BODY()
	
public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value = {};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Delta = 1.0f;
};
