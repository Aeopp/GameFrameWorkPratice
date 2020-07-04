#pragma once
#include "stdafx.h"
// SingleTon Type UWorld 

class UWorld
{	
public:
	using ObjectID = uint32_t;
private:
	using _ObjectType = std::shared_ptr<class UObject>;
	friend class std::unique_ptr<UWorld>::deleter_type;
public:
	void Render(const float DeltaTime);
	void Frame(const float DeltaTime);
public:
	std::vector<std::shared_ptr<class UObject>> _Objects;
public:
	template<typename _MakeUObjectType,typename ...Types>
	void Create(Types&&... Params);

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
};

template<typename _MakeUObjectType, typename ...Types>
void UWorld::Create(Types&&... Params) {
	auto _Push = std::shared_ptr<_MakeUObjectType>(
		new _MakeUObjectType(
			std::forward<Types>(Params)...));

	_Objects.push_back(std::move_if_noexcept(_Push));
};

