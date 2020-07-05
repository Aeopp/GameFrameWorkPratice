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
private:
	template<typename ...Types>
	static std::shared_ptr<UObject> Create(Types&&... Params) {
		//Set Up Body .......................................
		//....................................................

		return std::make_shared<UObject>(std::forward< Types>(Params)...);
	};
protected:
	using Super = UObject;
protected:
	inline UObject() noexcept {
		
		static uint32_t _UniqueID = 0;
		_ID = _UniqueID++;
	};
	inline  UObject(const IDType SetID) noexcept :
	UObject(){
		_ID = SetID;
	};
	inline OwnerType GetOwner() const& noexcept {
		return _Owner;
	};
	inline void SetOwner(OwnerType SetOwner)& noexcept {
		_Owner = std::move_if_noexcept(SetOwner);
	};
	
public :
	
	inline IDType GetID() const& noexcept{
		return _ID;
	}
	inline bool operator!=(const UObject& Rhs) const & noexcept {
		return this->_ID != Rhs._ID;
	}
	inline bool IsOwner()const& noexcept {
		return _Owner.expired();
	};
protected:
	virtual ~UObject()noexcept = default;
};

