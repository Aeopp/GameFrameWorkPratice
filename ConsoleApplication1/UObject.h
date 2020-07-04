#pragma once
#include "UWorld.h"
class UObject abstract
{
	friend class UWorld;
private:
	using OwnerType = std::weak_ptr<class UObject>;
protected:
	using IDType = uint32_t;
private:
	OwnerType _Owner {};
protected:
	IDType _ID;
	std::vector<std::weak_ptr<UObject>> Components;
private:
	template<typename ...Types>
	static std::shared_ptr<UObject> Create(Types&&... Params) {
		return std::make_shared<UObject>(std::forward< Types>(Params)...);
	};
protected:
	using Super = UObject;
protected:
	inline UObject() noexcept {
		static uint32_t _UniqueID = 0;
		_ID = _UniqueID++;
	};
	inline  UObject(const IDType SetID) noexcept {
		_ID = SetID;
	};
	inline OwnerType GetOwner() const& noexcept {
		return _Owner;
	};
	inline void SetOwner(OwnerType SetOwner)& noexcept {
		_Owner = std::move_if_noexcept(SetOwner);
	};
public :
	virtual void Frame(const float DeltaTime)abstract;
	virtual void Render(const float DeltaTime)abstract;

	inline bool operator!=(const UObject& Rhs) const & noexcept {
		return this->_ID != Rhs._ID;
	}
protected:
	virtual ~UObject()noexcept = default;
};

