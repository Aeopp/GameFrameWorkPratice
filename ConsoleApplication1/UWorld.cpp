#include "stdafx.h"
#include "UWorld.h"
#include "UObject.h"
#include "UMesh.h"
#include "AActor.h"
#include "UCollision.h"

void UWorld::Render()
{
	ObjectLogic(_Meshs, decltype(_Meshs)::value_type::element_type::GetLogicFunc());
};

std::weak_ptr<class UObject> UWorld::FindObject(const ObjectIDType TargetID) {

	auto iter = std::find_if(std::begin(_Objects), std::end(_Objects),
		[TargetID](const decltype(_Objects)::value_type& Target) {
			if (!(Target != nullptr)) {
				throw std::exception();
			};
			return Target->GetID() == TargetID; }
	);
	return *iter;
};
void UWorld::DeleteObj(uint32_t TargetID) & noexcept {

	auto IsFind{ [TargetID](const _ObjectType& Lhs)
   {return Lhs->_ID == TargetID; } };

	auto Target = std::find_if(std::begin(_Objects), std::end(_Objects),
		std::move_if_noexcept(IsFind));

	if (Target != std::end(_Objects)) {
		_Objects.erase(Target);
	}

};

void UWorld::ActorLogic()
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
};

void UWorld::Frame(  )
{
	ActorLogic();
	Collision();
}
void UWorld::Collision()
{
	ObjectLogic(_Collisions, decltype(_Collisions)::value_type::element_type::GetLogicFunc());
};

std::vector<std::weak_ptr<class UObject>> UWorld::GetObjects()
{
	std::vector<std::weak_ptr<class UObject>> Objects;
	std::copy(std::begin(_Objects), std::end(_Objects), std::begin(Objects));
	return Objects;
}
