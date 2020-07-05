#pragma once
#include "UObject.h"

class UMesh : public UObject
{
private:
	public:
		enum EMeshType :uint8_t{
			_1,
			_2,
			_3,
		};

		EMeshType _Type{};
public:
	static inline constexpr bool SortThrowable = true;

	bool operator<(const UMesh& Rhs) const&{
		return _Type < Rhs._Type;
	}
	void Render();

	static auto GetLogicFunc() {
		return &UMesh::Render;
	};

};

namespace std {
	static bool operator<(const std::weak_ptr<UMesh>& lhs, const std::weak_ptr<UMesh>& rhs) 
	noexcept(!UMesh::SortThrowable){

		if (lhs.expired()  || rhs.expired() ) {
			throw std::exception();
		}
		else {
			return lhs.lock()->_Type  < rhs.lock()->_Type;
		}
	};
}




