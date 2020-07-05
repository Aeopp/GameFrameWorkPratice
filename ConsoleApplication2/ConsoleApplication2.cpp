
#include <iostream>

#include <set>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <type_traits>
using namespace std;

template<typename t=void>
struct a {
	a() {
		static int q;
		w = ++q;
	}
	int w;
	void qwe() {
		std::cout << "qwe";

	}
};
struct b : public a<b> {

};
struct c : public a<c> {

};
//namespace std {
//	static bool operator<(const std::weak_ptr<a>& lhs, const std::weak_ptr<a>& rhs) {
//		if (lhs.expired() == false || rhs.expired() == false) {
//			throw std::exception();
//		}
//		else {
//			return lhs.lock()->w < rhs.lock()->w;
//		}
//	};
//}

template<typename c,typename f>
void foo(c& a,f F) {
	auto Func = std::mem_fn(F);

	for (auto iter = a.begin(); iter != a.end(); ++iter) {
		Func(*iter);
	}
};
class q {
public:
	q(int) {};

	float bar() {

	};

	int a = 11;
	void foo() {
		std::cout << a;

	}
};
struct QWE{
	float operator()(int) { return 1.f; };
};

class asd{
public:
	void foo() { };
};

template <class _Callable, class... _Args>
using invoke_result_t = typename _Invoke_traits<void, _Callable, _Args...>::type;

int main()
{

	std::shared_ptr<q> s= std::make_shared<q>(5);

	std::shared_ptr<q> d = s;
	auto c = d;

	auto dd = new q(1);

	
	d->foo();
	c->foo();

	


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
