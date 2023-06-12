#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "QL_FloatProvier_Constant.generated.h"

/**
 * Simple FloatProvider that only holds one value.
 */
UCLASS(DisplayName="Constant")
class QUALITYOFLIFE_API UQL_FloatProvier_Constant : public UQL_FloatProvider
{
	GENERATED_BODY()

public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Float Provider")
	float Value = 0.0f;
};
