# BlueprintFloats
You can use this wrapper around float values and float-functions to instance values as a blueprint properties accessible from C++.

### Usage
* For [FloatFunction](../Source/Demo/FloatFunction.h) create a Derived class, where you can override method `float Eval_Implementation(float Value)` (also from Blueprints).
* For [FloatExtractor](../Source/Demo/FloatExtractor.h) create a Derived class, where you can override method `float GetValue_Implementation()` (also from Blueprints).

### Examples
FloatFunction:
* [IdentityFunction](../Source/Demo/IdentityFunction.h)
* [SquareFunction](../Source/Demo/SquareFunction.h)

FloatExtractor:
* [ArithmeticFloatExtractor](../Source/Demo/ArithmeticFloatExtractor.h) — increments / decrements held value by held delta every `GetValue()` call
* [ConstFloatExtractor](../Source/Demo/ConstFloatExtractor.h) — is a simple float holder
* [CurveTableRowFloatExtractor](../Source/Demo/CurveTableRowFloatExtractor.h) — is a float holder that also holds `FCurveTableRowHandle` and evaluates `curve(value)` on `GetValue()` call
