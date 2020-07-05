#pragma once
#include "stdafx.h"
#include "UObject.h"

// SingleTon Type UWorld 

class UWorld
{	
public:
	using ObjectIDType = uint32_t;

private:
	using _ObjectType = std::shared_ptr<class UObject>;
	template<typename ObjectType>
	using _ObjectObserverType = std::weak_ptr<ObjectType>;
	friend class std::unique_ptr<UWorld>::deleter_type;
public:
	void Render();
	void Frame();
	void Collision();
public:
	std::vector<std::shared_ptr<class UObject>> _Objects;

	std::vector<std::weak_ptr<class UCollision>> _Collisions;
	std::vector<std::weak_ptr<class AActor>> _Actors;
	std::multiset<std::weak_ptr<class UMesh>> _Meshs;

	std::set<ObjectIDType> _GarBageIDs;
public:
	std::weak_ptr<class UObject> FindObject(const ObjectIDType TargetID);

	template<typename _MakeUObjectType,typename ...Types>
	[[nodiscard]]  _ObjectObserverType<_MakeUObjectType> Create(Types&&... Params) {
		auto _AddObject = std::shared_ptr<_MakeUObjectType>(
			new _MakeUObjectType(
				std::forward<Types>(Params)...));

		_Objects.push_back(_AddObject);
		
		if constexpr (std::is_same_v< _MakeUObjectType, decltype(_Actors)::value_type::element_type>) {
			_Actors.push_back(_AddObject);
		}
		else if constexpr (std::is_same_v< _MakeUObjectType, decltype(_Collisions)::value_type::element_type>) {
			_Collisions.push_back(_AddObject);
		}
		else if constexpr (std::is_same_v< _MakeUObjectType, decltype(_Meshs)::value_type::element_type>) {
			_Meshs.insert(_AddObject);
		}

		return _ObjectObserverType<_MakeUObjectType>{ _AddObject };
	};

	std::vector<std::weak_ptr<class UObject>> GetObjects();
	void DeleteObj(uint32_t TargetID)& noexcept;

	template<typename ...Types>
	static UWorld& Instance(Types&&... Params) {
		static std::once_flag _Flag{};
		static std::unique_ptr<UWorld> _WorldInstance;

		static auto MakeWorld = [&]() 
		{
			_WorldInstance = std::make_unique<UWorld>(std::forward<Types>(Params)...);
		};
		std::call_once(_Flag, MakeWorld);

		return *_WorldInstance;
	}
private:
	template<typename ObjectContainType,typename CallFuncType>
	void ObjectLogic(ObjectContainType& Container, CallFuncType Func) {
		auto MemberFunction = std::mem_fn(Func);
		for (auto _Object = std::begin(Container); _Object != std::end(Container);) {
			if (auto _ObjectRef = _Object->lock();
				_Object->expired() == false) {
				bool bOwner = _ObjectRef->IsOwner();
				if (bOwner) {
					MemberFunction(*_ObjectRef);
				}
				else if (!bOwner) {
					GarbageObjectErase(Container,_Object);
				}
			}
			else if (_Object->expired() == true) {
				_Object = Container.erase(_Object);
				continue;
			}
			std::advance(_Object, 1);
		};
	}

private:
	void ActorLogic();
	template<typename ObjectContainType, typename ObjectType>
	void GarbageObjectErase(ObjectContainType& Container,ObjectType& Object)
	{
		// 여기서 weak_ptr 포인터의 자료구조에서 타겟을 지우고
		// 오브젝트 shared_ptr 포인터 자료구조에서도 타겟을 지워야한다.

		Container.erase(Object.lock());
		ObjectIDType TargetID = Object.lock()->GetID();

		std::erase_if(Container, [TargetID](decltype(_Objects)::value_type& Target) {
			return Target->GetID() == TargetID;
			});
	};
};
