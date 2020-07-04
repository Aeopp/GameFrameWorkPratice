#pragma once
#include "stdafx.h"

// SingleTon Type UWorld 
class UWorld
{	
private:
	using _ObjectType = std::shared_ptr<class UObject>;
public:
	void Render(const float DeltaTime);
	void Frame(const float DeltaTime);
public:
	std::vector<std::shared_ptr<class UObject>> _Objects;
	std::vector<std::weak_ptr<class UObject>> GetActors();
public:
	template<typename _MakeUObjectType,typename ...Types>
	void Create(Types&&... Params){
		_Objects.emplace(_MakeUObjectType(std::forward<Types>(Params)...));
	};

	void DeleteObj(uint32_t TargetID) {
		auto Target = std::find(std::begin(_Objects), std::end(_Objects),[](
			const _ObjectType& Lhs , const _ObjectType& Rhs){
			return Lhs->_ID == Rhs->_ID;});

		_Objects.erase(Target);
	}
};

