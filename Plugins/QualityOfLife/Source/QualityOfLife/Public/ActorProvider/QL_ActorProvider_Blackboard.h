// 

#pragma once

#include "CoreMinimal.h"
#include "QL_ActorProvider.h"
#include "FloatProvider/QL_FloatProvider_Blackboard.h"
#include "UObject/Object.h"
#include "QL_ActorProvider_Blackboard.generated.h"

/**
 * ActorProvider that gets value from the blackboard key
 * It works only inside instanced BTNodes!
 */
UCLASS()
class QUALITYOFLIFE_API UQL_ActorProvider_Blackboard : public UQL_ActorProvider
{
	GENERATED_BODY()
public:
	
	UQL_ActorProvider_Blackboard(const FObjectInitializer& ObjectInitializer);

	virtual AActor* GetActor_Implementation() override;

	UPROPERTY(EditAnywhere, Category="Float Provider")
	FBlackboardKeySelector BlackboardKey;
};
