#include "stdafx.h"
#include "UWorld.h"
#include "UObject.h"
#include "UMesh.h"
#include "AActor.h"
#include "UCollision.h"

void UWorld::Render()
{
	ObjectLogic(_MeshList, decltype(_MeshList)::value_type::element_type::GetLogicFunc());
};

std::optional<std::weak_ptr<class UObject>>  
UWorld::FindObject(const ObjectIDType TargetID) {
	auto iter = std::find_if(std::begin(_ObjectList), std::end(_ObjectList),
		[TargetID](const decltype(_ObjectList)::value_type& Target) {
			if (!(Target != nullptr)) {
				throw std::exception();
			};
			return Target->GetID() == TargetID; }
	);
	if (iter != std::end(_ObjectList)) {
		return decltype(std::declval<UWorld>().FindObject(NULL)){*iter};
	}else 
		return std::nullopt;
};

void UWorld::DeleteObj(uint32_t TargetID) & noexcept {

	auto IsFind{ [TargetID](const _ObjectType& Lhs)
   {return Lhs->_ID == TargetID; } };

	auto Target = std::find_if(std::begin(_ObjectList), std::end(_ObjectList),
		std::move_if_noexcept(IsFind));

	if (Target != std::end(_ObjectList)) {
		_ObjectList.erase(Target);
	}
};

void UWorld::ActorLogic()
{
	auto ActorFunc = std::mem_fn(AActor::GetLogicFunc());

	for (auto _Actor = std::begin(_ActorList); _Actor != std::end(_ActorList);) {
		if (auto _ActorRef = _Actor->lock();
			_Actor->expired() == false) {
			ActorFunc(*_ActorRef);
		}
		else if (_Actor->expired() == true) {
			_Actor = _ActorList.erase(_Actor);
			continue;
		}
		std::advance(_Actor, 1);
	};
};

void UWorld::Frame()
{
	ActorLogic();
	Collision();
};

void UWorld::Collision()
{
	ObjectLogic(_CollisionList, decltype(_CollisionList)::value_type::element_type::GetLogicFunc());
};

std::vector<std::weak_ptr<class UObject>> 
UWorld::GetObjects()
{
	std::vector<std::weak_ptr<class UObject>> Objects;
	std::copy(std::begin(_ObjectList), std::end(_ObjectList), std::begin(Objects));
	return Objects;
}
