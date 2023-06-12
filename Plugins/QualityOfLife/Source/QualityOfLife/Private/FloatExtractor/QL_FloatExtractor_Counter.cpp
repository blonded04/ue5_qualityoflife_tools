#include "FloatProvider/QL_FloatExtractor_Counter.h"

float UQL_FloatExtractor_Counter::GetValue_Implementation() 
{
	return Value += Delta;
}
