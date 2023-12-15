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

// N != 0
template<int N, typename R, typename A, typename ... Types>
struct argument<N, R(A, Types...)>
{
	// int (int, double, char) 의 1번째 인자의 타입(double) 은
	// int (     double, char) 의 0번째 인자의 타입과 같습니다.
	
	// => R(A, Types...)> 의  N 번째 인자의 타입은 
	// => R(   Types...)> 의  N-1 번째 인자의 타입과 같습니다.
	using type = typename argument<N - 1, R(Types...)>::type;
};


template<typename T> void foo(T& t)
{
	// T : int (int, double, char)
//	typename argument<0, T>::type n; // int
	typename argument<2, T>::type n; // char

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}