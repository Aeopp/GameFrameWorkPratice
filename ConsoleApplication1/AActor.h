#pragma once
#include "UObject.h"

class AActor : public UObject
{
public :
	AActor();
	void Frame(const float DeltaTime)   override ;
	void Render(const float DeltaTime)  override;
};

