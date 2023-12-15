#include <iostream>
#include "tuple.h"

template<int N, typename T>
struct tuple_element
{
	using type = T;
};

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
	using tupleType = tuple<T, Types...>;
};


template<int N, typename T, typename ... Types>
struct tuple_element<N, tuple<T, Types...> >
{
	using type      = typename tuple_element<N - 1, tuple<Types...>>::type;
	using tupleType = typename tuple_element<N - 1, tuple<Types...>>::tupleType;
};


template<int N, typename TP>  
typename tuple_element<N, TP>::type&
get(TP& tp)
{
	return static_cast<typename tuple_element<N, TP>::tupleType&>(tp).value;
}


int main()
{
	tuple<int, double, short> t(1, 3.4, 2);

	get<0>(t) = 100;

	std::cout << get<0>(t) << std::endl; // 100
	std::cout << get<1>(t) << std::endl; // 3.4
}

