#pragma once

#include "CoreMinimal.h"
#include "FloatExtractor.h"
#include "Engine/CurveTable.h"
#include "CurveTableRowFloatExtractor.generated.h"

/**
 * CurveTableRowFloatExtractor is a float extractor that allows you to get 
 */
UCLASS()
class QUALITYOFLIFE_API UCurveTableRowFloatExtractor : public UFloatExtractor
{
	GENERATED_BODY()
	
public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCurveTableRowHandle RowHandle;
};
