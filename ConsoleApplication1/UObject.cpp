#include "stdafx.h"
#include "UObject.h"
#include "UWorld.h"

bool UObject::IsOwner() & noexcept
{
	if (auto IsOwner = UWorld::Instance().FindObject(_OwnerID);
		IsOwner.expired() == true) {
		return false;
	}
	else if (IsOwner.expired() == false) {
		SetOwner(IsOwner);
		return true;
	};
}
