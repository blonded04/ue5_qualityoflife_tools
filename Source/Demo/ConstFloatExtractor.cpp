#include "ConstFloatExtractor.h"

UConstFloatExtractor::UConstFloatExtractor(float value) : m_value(value) 
{
}

float UConstFloatExtractor::GetValue_Implementation() {
	return m_value;
}
