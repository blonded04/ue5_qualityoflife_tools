#include "ArithmeticFloatExtractor.h"

float UArithmeticFloatExtractor::GetValue_Implementation() {
	return Value += Delta;
}
