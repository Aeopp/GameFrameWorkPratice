#include "stdafx.h"
#include "UObject.h"
#include "UWorld.h"

bool UObject::IsOwner() & noexcept
{
	auto IsOwner = UWorld::Instance().FindObject(_OwnerID);
	bool bOwner = IsOwner.has_value();

	if (bOwner == false) {
		return false;
	};

	auto _OwnerWeakRef = IsOwner.value();
	
	if (_OwnerWeakRef.expired() == true) {
		return false;
	}
	else if (_OwnerWeakRef.expired() == false) {
		SetOwner(_OwnerWeakRef);
	};

	//if (auto IsOwner = UWorld::Instance().FindObject(_OwnerID);
	//	IsOwner.expired() == true) {
	//	return false;
	//}
	//else if (IsOwner.expired() == false) {
	//	
	//	return true;
	//};
}
