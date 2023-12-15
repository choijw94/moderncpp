#include <iostream>
#include "tuple.h"



// primary template 
template<int N, typename T>
struct tuple_element
{
	using type = T;
};


// #1. N == 0 일때 먼저 만들어야 합니다.
/*
template<typename T>
struct tuple_element<0, T>
{
	// 튜플 T 에서 0번째 요소의 타입은 ?? 알수 없다. 잘못된 부분 특수화
	using type = ?;
};
*/
/*
template<typename ... Types>
struct tuple_element<0, tuple<Types...> >
{
	// 튜플 T 에서 0번째 요소의 타입은 ?? 알수 없다. 잘못된 부분 특수화
	using type = ? ;
};
*/

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// #2. N != 0 을 만들때는 "재귀를 사용해서 N == 0" 이 되도록 합니다.
template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type = typename tuple_element<N - 1, tuple<Types...>>::type;
};


template<typename TP>
void foo(TP& tp)
{
	
	// TP : tuple<int, double, short>
//	typename tuple_element<1, TP>::type n; // double
	typename tuple_element<2, TP>::type n; // short



	std::cout << typeid(n).name() << std::endl;
}





int main()
{
	tuple<int, double, short> t(1, 3.4, 2);

	foo(t);
}

