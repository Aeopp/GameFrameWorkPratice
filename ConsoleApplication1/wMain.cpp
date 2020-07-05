#include "stdafx.h"
#include "UWorld.h"
#include "AActor.h"
#include "APlayer.h"
#include "AEnemy.h"

#define WORLD                      UWorld::Instance()  
int main() {
	using namespace std::chrono_literals;

	 auto Player = WORLD.Create<APlayer>();

	for(int i=0;i<10;++i){
		WORLD.Frame();
		WORLD.Render();
		//WORLD.DeleteObj(ObjectID);

		//Compute Time.............
		std::this_thread::sleep_for(1s);
		
		if (i == 0) {
			WORLD.DeleteObj(Player.lock()->GetID());
		}
	};
}