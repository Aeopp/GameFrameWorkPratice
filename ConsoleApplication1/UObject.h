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
	IDType _OwnerID{};
protected:
	IDType _ID;
private:
	template<typename ...Types>
	static std::shared_ptr<UObject> Create(Types&&... Params) {
		//Set Up Body .......................................
		//....................................................

		return std::make_shared<UObject>(std::forward<Types>(Params)...);
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
public :
	inline OwnerType GetOwner() const& noexcept {
		return _Owner;
	};
	inline void SetOwner(OwnerType SetOwner) & noexcept {
		_Owner = std::move_if_noexcept(SetOwner);
	};
	inline IDType GetOwnerID() const& noexcept {
		return _OwnerID;
	};
	inline void SetOwnerID(IDType SetOwnerID) & noexcept {
		_OwnerID = std::move_if_noexcept(SetOwnerID);
	};

	inline IDType GetID() const& noexcept{
		return _ID;
	}
	inline bool operator!=(const UObject& Rhs) const & noexcept {
		return this->_ID != Rhs._ID;
	}
	bool IsOwner()& noexcept;
protected:
	virtual ~UObject()noexcept = default;
};

