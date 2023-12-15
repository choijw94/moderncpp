#include <iostream>
#include "tuple.h"



// primary template 
template<int N, typename T>
struct tuple_element
{
	using type = T;
};


// #1. N == 0 �϶� ���� ������ �մϴ�.
/*
template<typename T>
struct tuple_element<0, T>
{
	// Ʃ�� T ���� 0��° ����� Ÿ���� ?? �˼� ����. �߸��� �κ� Ư��ȭ
	using type = ?;
};
*/
/*
template<typename ... Types>
struct tuple_element<0, tuple<Types...> >
{
	// Ʃ�� T ���� 0��° ����� Ÿ���� ?? �˼� ����. �߸��� �κ� Ư��ȭ
	using type = ? ;
};
*/

template<typename T, typename ... Types>
struct tuple_element<0, tuple<T, Types...> >
{
	using type = T;
};

// #2. N != 0 �� ���鶧�� "��͸� ����ؼ� N == 0" �� �ǵ��� �մϴ�.
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

