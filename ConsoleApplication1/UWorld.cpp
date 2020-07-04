#include "stdafx.h"
#include "UWorld.h"
#include "UObject.h"

void UWorld::Render(const float DeltaTime)
{
	for (auto& Objcet : _Objects) {
		Objcet->Render(DeltaTime);
	}
};

void UWorld::DeleteObj(uint32_t TargetID) &noexcept{

	static auto IsFind{ [TargetID](	const _ObjectType& Lhs) 
	{return Lhs->_ID == TargetID; } };

	auto Target = std::find_if(std::begin(_Objects), std::end(_Objects),
	std::move_if_noexcept(IsFind));

	_Objects.erase(Target);
}


void UWorld::Frame(const float DeltaTime)
{
	for (auto& Objcet : _Objects) {
		Objcet->Frame(DeltaTime);
	}
};

std::vector<std::weak_ptr<class UObject>> UWorld::GetObjects()
{
	std::vector<std::weak_ptr<class UObject>> Objects;
	std::copy(std::begin(_Objects), std::end(_Objects), std::begin(Objects));
	return Objects;
}
