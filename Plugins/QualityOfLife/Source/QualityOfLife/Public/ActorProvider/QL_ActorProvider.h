// 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QL_ActorProvider.generated.h"

/**
 *  Blueprint instanceable wrapper around Actor
 */
UCLASS(Abstract, Blueprintable, BlueprintType, DefaultToInstanced, EditInlineNew)
class QUALITYOFLIFE_API UQL_ActorProvider : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Actor Provider")
	AActor* GetActor();
};