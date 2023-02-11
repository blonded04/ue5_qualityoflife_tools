#include "StringParseTool.h"

void UStringParseTool::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	DescriptionPreview = ParseDescription();
}

FString UStringParseTool::ParseDescription() const
{
	return Description.ToString(); // TODO: make logic
}
