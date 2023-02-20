#pragma once

#include "CoreMinimal.h"
#include "MyObjejct.h"
#include "ExampleObject2.generated.h"

UCLASS()
class DEMO_API UExampleObject2 : public UMyObjejct
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level = 33;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Greatness = 9999.9f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Strength = 13.0f;
	
};
