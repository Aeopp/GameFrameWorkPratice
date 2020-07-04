#pragma once
#include "UWorld.h"
class UObject
{
	friend class UWorld;
private:
	class UObject* _Owner{ nullptr };
private:
	using IDType = uint32_t;

	template<typename ...Types>
	static std::shared_ptr<UObject> Create(Types&&... Params) {
		return std::make_shared<UObject>(std::forward< Types>(Params)...);
	};
protected:
	UObject() noexcept {
		static uint32_t _UniqueID = 0;
		_ID = _UniqueID++;
	};
	UObject(const IDType SetID) noexcept {
		_ID = SetID;
	}
public :
	IDType _ID;
	void Frame(const float DeltaTime);
	void Render(const float DeltaTime);

	std::vector<std::weak_ptr<UObject>> Components;

	inline bool operator!=(const UObject& Rhs) const & noexcept {
		return this->_ID != Rhs._ID;
	}
};

