// 


#include "ActorProvider/QL_ActorProvider_Blackboard.h"

#include "QualityOfLife.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTNode.h"

UQL_ActorProvider_Blackboard::UQL_ActorProvider_Blackboard(const FObjectInitializer& ObjectInitializer)
{
	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UQL_FloatProvider_Blackboard, BlackboardKey), AActor::StaticClass());
}

AActor* UQL_ActorProvider_Blackboard::GetActor_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsActor(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogQoL, Error, TEXT("Called GetActor from QL_ActorProvider_Blackboard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return nullptr;
}
