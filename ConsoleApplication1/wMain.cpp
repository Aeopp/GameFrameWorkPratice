#include "stdafx.h"
#include "UWorld.h"
#include "AActor.h"

inline namespace {
	static constexpr inline float DeltaTime = 1.f / 200.f;
}

#define WORLD                      UWorld::Instance()  
int main() {

	using namespace std::chrono_literals;

	WORLD.Create<AActor>(/*Params...*/);
	WORLD.Create<AActor>(/*Params...*/);
	WORLD.Create<AActor>(/*Params...*/);

	for (int32_t ObjectID = 0; ObjectID < 3;++ObjectID) {
		WORLD.Frame(DeltaTime);
		WORLD.Render(DeltaTime);

		//WORLD.DeleteObj(ObjectID);

		//Compute Time.............
		std::this_thread::sleep_for(3s);
	};
}