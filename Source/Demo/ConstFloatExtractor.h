#pragma once

#include "CoreMinimal.h"
#include "FloatExtractor.h"
#include "ConstFloatExtractor.generated.h"

/**
 * Simple FloatExtractor that only holds one value.
 */
UCLASS()
class DEMO_API UConstFloatExtractor : public UFloatExtractor
{
	GENERATED_BODY()

public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value{};
};
