// 


#include "FloatProvider/QL_FloatProvider_Blackboard.h"

#include "QualityOfLife.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BTTaskNode.h"

UQL_FloatProvider_Blackboard::UQL_FloatProvider_Blackboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	BlackboardKey.AddFloatFilter(this, GET_MEMBER_NAME_CHECKED(UQL_FloatProvider_Blackboard, BlackboardKey));
}

float UQL_FloatProvider_Blackboard::GetValue_Implementation()
{
	if (UBTNode* NodeOwner = Cast<UBTNode>(GetOuter()))
	{
		return UBTFunctionLibrary::GetBlackboardValueAsFloat(NodeOwner, BlackboardKey);
	}
	UE_LOG(LogQoL, Error, TEXT("Called GetValue from QL_FloatProvider_BlackBoard which do not belong to BTNode. Owner is %s"), *GetNameSafe(GetOuter()))
	return 0.0f;
}
