#include "stdafx.h"
#include "AActor.h"
#include "UWorld.h"
#include "UCollision.h"
AActor::AActor()
{
	UWorld::Instance().Create<UCollision>();
}
void AActor::Frame(const float DeltaTime)
{
	TypePrint
}

void AActor::Render(const float DeltaTime)
{
	TypePrint
}
