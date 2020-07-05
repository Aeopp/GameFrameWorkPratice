#include "stdafx.h"
#include "AEnemy.h"
#include "UCollision.h"
#include "UMesh.h"

AEnemy::AEnemy()
{
	_Collision = UWorld::Instance().Create<UCollision>();
	_Mesh = UWorld::Instance().Create<UMesh>();

	auto Collision = _Collision.lock();
	auto Mesh = _Mesh.lock();


	Collision->SetOwnerID((this->GetID()));
	Mesh->SetOwnerID((this->GetID()));
}



	

