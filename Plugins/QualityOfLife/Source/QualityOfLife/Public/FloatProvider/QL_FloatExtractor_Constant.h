#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "QL_FloatExtractor_Constant.generated.h"

/**
 * Simple FloatProvider that only holds one value.
 */
UCLASS()
class QUALITYOFLIFE_API UQL_FloatExtractor_Constant : public UQL_FloatProvider
{
	GENERATED_BODY()

public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QoL|Float Provider")
	float Value = 0.0f;
};
