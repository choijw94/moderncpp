#include <iostream>

// 언제 가변인자 템플릿을 사용하나요 ??
// => 가변인자 템플릿을 사용하는 전형적으로 예제들이 있습니다.

// 1. 완벽현 전달을 사용하는 코드는 대부분 가변인자 템플릿 사용
// 2. std::tuple, std::get 같은 코드는 가변인자 템플릿으로 만들게 됩니다.

void foo(int a, int b, int& c) { c = 100; }

/*
// 아래 처럼 만들면, chronometry 는 인자가 한개인 함수만 forwarding 가능합니다.
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(arg)); 
}
*/

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
//	return f( std::forward<T>(arg...) ); // forward(E1, E2, E3) 인데
										 // forward 는 인자가 한개인 함수

	return f(std::forward<Types>(arg)... );
			// f( std::forward<T1>(E1), 
			//	  std::forward<T2>(E2),
			//    std::forward<T3>(E3) );
}



int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

