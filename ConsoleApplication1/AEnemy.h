#pragma once
#include "AActor.h"

class AEnemy : public AActor
{
public:
	
	AEnemy();

	std::weak_ptr<UCollision> _Collision;
	std::weak_ptr<UMesh> _Mesh;
};

