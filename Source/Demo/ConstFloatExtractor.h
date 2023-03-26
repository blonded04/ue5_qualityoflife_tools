#pragma once

#include "CoreMinimal.h"
#include "FloatExtractor.h"
#include "ConstFloatExtractor.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UConstFloatExtractor : public UFloatExtractor
{
	GENERATED_BODY()

public:
	UConstFloatExtractor() = default;
	UConstFloatExtractor(float value);

	virtual float GetValue_Implementation() override;

private:
	float m_value{};
};
