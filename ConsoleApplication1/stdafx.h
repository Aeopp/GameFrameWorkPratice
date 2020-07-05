#pragma once
#include <vector>
#include <memory>
#include <xutility>
#include <algorithm>
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <set>
#include <map>
#include <functional>

#define TypePrint        TypePrint_Implementation(decltype(*this),this->_ID);

#define TypePrint_Implementation(Type,ID) std::cout<<typeid(Type).name()<<std::endl<<__FUNCTION__ <<std::endl<<"ID : " << ID<<std::endl;

inline namespace {
	static constexpr inline float DeltaTime = 1.f / 200.f;
};

namespace Test {
	template<typename Type>
	static void Print() {
		std::cout << typeid(Type).name() << std::endl;
		std::cout << __FUNCTION__ << std::endl;
	}
};


