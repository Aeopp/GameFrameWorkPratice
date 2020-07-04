#include "UWorld.h"
#include "UObject.h"

void UWorld::Render(const float DeltaTime)
{

};


void UWorld::Frame(const float DeltaTime)
{

};

std::vector<std::weak_ptr<class UObject>> UWorld::GetActors()
{
	std::vector<std::weak_ptr<class UObject>> Objects;
	std::copy(std::begin(_Objects), std::end(_Objects), std::begin(Objects));
	return Objects;
}
