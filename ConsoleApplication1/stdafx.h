#pragma once
#include <vector>
#include <memory>
#include <xutility>
#include <algorithm>
#include <type_traits>
#include <typeinfo>
#include <iostream>

#define TypePrint                 Test::Print<decltype(*this)>();

namespace Test {
	template<typename Type>
	static void Print() {
		std::cout << typeid(Type).name() << std::endl;
		std::cout << "ID : " << _ID << std::endl;
		std::cout << __FUNCTION__ << std::endl;
	}
};


