#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MyObjejct.generated.h"

/**
 * UMyObjejct is a Blueprintable interface for all the classes used in StringParseTool
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class DEMO_API UMyObjejct : public UObject
{
	GENERATED_BODY()
};
