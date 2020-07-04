#pragma once
#include "UObject.h"

class AActor : public UObject
{
public :
	void Frame(const float DeltaTime);
	void Render(const float DeltaTime);
};

