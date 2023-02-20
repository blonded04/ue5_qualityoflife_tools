#pragma once

#include "CoreMinimal.h"
#include "MyObjejct.h"
#include "ExampleObject1.generated.h"

UCLASS()
class DEMO_API UExampleObject1 : public UMyObjejct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level = 5;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Power = 23.214;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCool = true;
	
};
