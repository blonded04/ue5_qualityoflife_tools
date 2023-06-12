#include "FloatExtractor/CurveTableRowFloatExtractor.h"

float UCurveTableRowFloatExtractor::GetValue_Implementation() 
{
	return RowHandle.Eval(Value, FString(""));
}
