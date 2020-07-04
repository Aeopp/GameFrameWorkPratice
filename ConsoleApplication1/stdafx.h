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



#define TypePrint        TypePrint_Implementation(decltype(*this),this->_ID);

#define TypePrint_Implementation(Type,ID) std::cout<<typeid(Type).name()<<std::endl<<__FUNCTION__ <<std::endl<<"ID : " << ID<<std::endl;

namespace Test {
	template<typename Type>
	static void Print() {
		std::cout << typeid(Type).name() << std::endl;
		std::cout << __FUNCTION__ << std::endl;
	}
};


