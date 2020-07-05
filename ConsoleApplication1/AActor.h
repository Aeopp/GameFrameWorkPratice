#pragma once
#include "UObject.h"

class AActor : public UObject
{
public :
	AActor();
	void Tick();

	static auto GetLogicFunc() {
		return &AActor::Tick;
	}
};

