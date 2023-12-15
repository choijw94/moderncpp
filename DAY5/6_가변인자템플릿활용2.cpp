#include <iostream>

int f(int, double, char) { return 0; }


// 이번에는 반환타입이 아닌 인자의 타입을 구해 봅시다.
// primary template
template<int N, typename T> 
struct argument
{
	using type = T;
};

/*
template<int N, typename R, typename ... Types>
struct argument<N, R(Types...)>
{
	// ? 를 표기할수 있을까요 ?
	// N 을 알수 없다... 잘못된 부분 특수화
	using type = ?;
};
*/

/*
// N == 0
template<typename R, typename ... Types>
struct argument<0, R(Types...)>
{
	// R(Types...) 의 모양에서 0번째 인자의 타입을 구할수 없습니다.
	// 잘못된 부분 특수화
	using type = ? ;
};
*/

// N == 0
template<typename R, typename A, typename ... Types>
struct argument<0, R(A, Types...)>
{
	using type = A;
};


template<typename T> void foo(T& t)
{
	// T : int (int, double, char)
	typename argument<0, T>::type n; // int

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}