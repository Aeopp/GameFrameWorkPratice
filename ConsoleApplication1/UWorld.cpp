#include "stdafx.h"
#include "UWorld.h"
#include "UObject.h"
#include "UMesh.h"
#include "AActor.h"
#include "UCollision.h"

void UWorld::Render(  )
{

	ObjectLogic(_Meshs, decltype(_Meshs)::value_type::element_type::GetLogicFunc());

	/*for (auto _Mesh = std::begin(_Meshs); _Mesh != std::end(_Meshs);) {
		if (auto _MeshRef = _Mesh->lock();
			_Mesh->expired() == false) {
			_MeshRef->Render();
		}
		else if (_MeshRef->IsOwner() == false) {
			_GarBageIDs.insert(_MeshRef->GetID());
		}
		else if (_Mesh->expired() == true) {
			_Mesh = _Meshs.erase(_Mesh);
			continue;
		}
		std::advance(_Mesh, 1);
	};*/
};

void UWorld::DeleteObj(uint32_t TargetID) & noexcept {

	static auto IsFind{ [TargetID](const _ObjectType& Lhs)
	{return Lhs->_ID == TargetID; } };

	auto Target = std::find_if(std::begin(_Objects), std::end(_Objects),
		std::move_if_noexcept(IsFind));

	_Objects.erase(Target);
};

void UWorld::Frame(  )
{
	auto ActorFunc = std::mem_fn(AActor::GetLogicFunc());

	for (auto _Actor = std::begin(_Actors); _Actor != std::end(_Actors);) {
		if (auto _ActorRef = _Actor->lock();
			_Actor->expired() == false) {
			ActorFunc(*_ActorRef);
		}
		else if (_Actor->expired() == true) {
			_Actor = _Actors.erase(_Actor);
			continue;
		}
		std::advance(_Actor, 1);
	};


	Collision();


	/*for (auto _Collision = std::begin(_Collisions); _Collision != std::end(_Collisions);) {
		if (auto _CollisionRef = _Collision->lock();
			_Collision->expired() == false) {
			_CollisionRef->Frame();
		}
		else if (_CollisionRef->IsOwner() == false) {
			_GarBageIDs.insert(_CollisionRef->GetID());
		}
		else if (_Collision->expired() == true) {
			_Collision = _Collisions.erase(_Collision);
			continue;
		}
		std::advance(_Collision, 1);
	};*/
}
void UWorld::Collision()
{
	ObjectLogic(_Collisions, decltype(_Collisions)::value_type::element_type::GetLogicFunc());
}
;

std::vector<std::weak_ptr<class UObject>> UWorld::GetObjects()
{
	std::vector<std::weak_ptr<class UObject>> Objects;
	std::copy(std::begin(_Objects), std::end(_Objects), std::begin(Objects));
	return Objects;
}
