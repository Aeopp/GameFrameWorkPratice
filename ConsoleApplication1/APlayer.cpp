#include "stdafx.h"
#include "APlayer.h"
#include "UMesh.h"
#include "UCollision.h"

APlayer::APlayer()
{
	_Collision = UWorld::Instance().Create<UCollision>();
	_Mesh = UWorld::Instance().Create<UMesh>();

	auto Collision = _Collision.lock();
	auto Mesh = _Mesh.lock();

	Collision->SetOwnerID((this->GetID()));
	Mesh->SetOwnerID((this->GetID()));

	_Collision2 = UWorld::Instance().Create<UCollision>();
	_Mesh2 = UWorld::Instance().Create<UMesh>();

	Collision = _Collision2.lock();
	Mesh = _Mesh2.lock();

	Collision->SetOwnerID((this->GetID()));
	Mesh->SetOwnerID((this->GetID()));

	_Collision3 = UWorld::Instance().Create<UCollision>();
	_Mesh3 = UWorld::Instance().Create<UMesh>();

	Collision = _Collision.lock();
	Mesh = _Mesh.lock();

	Collision->SetOwnerID((this->GetID()));
	Mesh->SetOwnerID((this->GetID()));
}

void APlayer::Test()
{
	UWorld::Instance().DeleteObj(_Collision.lock()->GetID());
	UWorld::Instance().DeleteObj(_Mesh.lock()->GetID());
	UWorld::Instance().DeleteObj(_Collision2.lock()->GetID());
	UWorld::Instance().DeleteObj(_Mesh2.lock()->GetID());
	UWorld::Instance().DeleteObj(_Collision3.lock()->GetID());
	UWorld::Instance().DeleteObj(_Mesh3.lock()->GetID());
}

