#pragma once
#include "stdafx.h"

//single                                                              




// ton
class UWorld
{	
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
};

