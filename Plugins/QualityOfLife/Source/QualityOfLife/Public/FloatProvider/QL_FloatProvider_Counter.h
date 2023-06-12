#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "QL_FloatProvider_Counter.generated.h"

/**
 * FloatProvider that changes value by some delta every time GetValue is called
 */
UCLASS(DisplayName="Counter")
class QUALITYOFLIFE_API UQL_FloatProvider_Counter : public UQL_FloatProvider
{
	GENERATED_BODY()
	
public:
	virtual float GetValue_Implementation() override;

	// Base value to count from
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Provider")
	float BaseValue = 0.0f;

	// Delta value which will be added to the BaseValue every call
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Provider")
	float Delta = 1.0f;
};
