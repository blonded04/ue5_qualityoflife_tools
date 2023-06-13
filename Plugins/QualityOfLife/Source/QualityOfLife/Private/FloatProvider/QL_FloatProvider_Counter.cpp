#include "FloatProvider/QL_FloatProvider_Counter.h"

float UQL_FloatProvider_Counter::GetValue_Implementation() 
{
	return BaseValue += Delta;
}
