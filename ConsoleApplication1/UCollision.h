#pragma once
#include "UObject.h"

class UCollision : public UObject
{
public:
	void Collision();

	static auto GetLogicFunc(){
		return &UCollision::Collision;
	}
};

