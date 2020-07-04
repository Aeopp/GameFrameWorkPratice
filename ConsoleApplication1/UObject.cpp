#include "stdafx.h"
#include "UObject.h"

void UObject::Frame(const float DeltaTime)
{
	for (auto& Component : Components) {
		if (auto _ComponentRef = Component.lock();
			Component.expired()) {
			_ComponentRef->Frame(DeltaTime);
		}
	};
};

void UObject::Render(const float DeltaTime)
{
	for (auto& Component : Components) {
		if (auto _ComponentRef = Component.lock();
			Component.expired()) {
			_ComponentRef->Frame(DeltaTime);
		}
	};
};

