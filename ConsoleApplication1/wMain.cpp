#include "stdafx.h"
#include "UWorld.h"
#include "AActor.h"

#define WORLD                      UWorld::Instance()  
int main() {
	using namespace std::chrono_literals;

	WORLD.Create<AActor>(/*Params...*/);
	WORLD.Create<AActor>(/*Params...*/);
	WORLD.Create<AActor>(/*Params...*/);

	for (int32_t ObjectID = 0; ObjectID < 3;++ObjectID) {
		WORLD.Frame();
		WORLD.Render();

		//WORLD.DeleteObj(ObjectID);

		//Compute Time.............
		std::this_thread::sleep_for(3s);
	};
}