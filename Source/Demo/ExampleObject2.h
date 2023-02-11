#pragma once

#include "CoreMinimal.h"
#include "MyObjejct.h"
#include "UObject/Object.h"
#include "ExampleObject2.generated.h"

UCLASS()
class DEMO_API UExampleObject2 : public UMyObjejct
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Greatness;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Strength;
	
};
