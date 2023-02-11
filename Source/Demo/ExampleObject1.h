#pragma once

#include "CoreMinimal.h"
#include "MyObjejct.h"
#include "UObject/Object.h"
#include "ExampleObject1.generated.h"

UCLASS()
class DEMO_API UExampleObject1 : public UMyObjejct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Power;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCool;
	
};
