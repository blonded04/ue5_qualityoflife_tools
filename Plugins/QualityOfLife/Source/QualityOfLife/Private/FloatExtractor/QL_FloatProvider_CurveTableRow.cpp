#include "FloatProvider/QL_FloatProvider_CurveTableRow.h"

float UQL_FloatProvider_CurveTableRow::GetValue_Implementation() 
{
	return RowHandle.Eval(AxisXValue, FString(""));
}
