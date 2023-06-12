// 

#pragma once

#include "CoreMinimal.h"
#include "QL_FloatProvider.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QL_FloatProvider_Blackboard.generated.h"

/**
 * FloatProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes!
 */
UCLASS()
class QUALITYOFLIFE_API UQL_FloatProvider_Blackboard : public UQL_FloatProvider
{
	GENERATED_BODY()

public:

	UQL_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer);
	
	virtual float GetValue_Implementation() override;
	
	UPROPERTY(EditAnywhere, Category="Float Provider")
	FBlackboardKeySelector BlackboardKey;
};
