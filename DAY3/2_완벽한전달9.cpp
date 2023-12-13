#include <iostream>

void foo(int a, double d, int& r) { r = 300; }


// forwarding 하는 인자 갯수에 제한을 없애려면
// => 가변인자 템플릿(variadic template) 기술을 사용하세요(금요일에 배우게됩니다)

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)... );
}

int main()
{
	int n = 3;

	chronometry(foo, 3, 3.4, n); // foo(3, 3.4, n) 의 의미

	std::cout << n << std::endl; // 300

}
