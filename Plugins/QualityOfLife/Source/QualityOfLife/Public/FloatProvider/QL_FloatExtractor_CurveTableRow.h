#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "Engine/CurveTable.h"
#include "QL_FloatExtractor_CurveTableRow.generated.h"

/**
 * CurveTableRowFloatExtractor is a float extractor that allows you to get 
 */
UCLASS()
class QUALITYOFLIFE_API UQL_FloatExtractor_CurveTableRow : public UQL_FloatProvider
{
	GENERATED_BODY()
	
public:
	virtual float GetValue_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCurveTableRowHandle RowHandle;
};
