#include "FloatProvider/QL_FloatExtractor_CurveTableRow.h"

float UQL_FloatExtractor_CurveTableRow::GetValue_Implementation() 
{
	return RowHandle.Eval(Value, FString(""));
}
