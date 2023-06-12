#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "Engine/CurveTable.h"
#include "QL_FloatExtractor_CurveTableRow.generated.h"

/**
 * FloatProvider that allows you to get floats from a curve table row 
 */
UCLASS()
class QUALITYOFLIFE_API UQL_FloatExtractor_CurveTableRow : public UQL_FloatProvider
{
	GENERATED_BODY()
	
public:
	virtual float GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QoL|Float Provider")
	float AxisXValue = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QoL|Float Provider")
	FCurveTableRowHandle RowHandle;
};
