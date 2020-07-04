#pragma once
#include "UObject.h"

class UCollision : public UObject
{
public:
	void Frame(const float DeltaTime)override;
	void Render(const float DeltaTime)override;
};

