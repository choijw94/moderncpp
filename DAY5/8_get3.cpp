#include <iostream>
#include "tuple.h"



// primary template 
template<int N, typename T>
struct tuple_element
{
	using type = T;
};


template<typename TP>
void foo(TP& tp)
{
	
	// TP : tuple<int, double, short>
	typename tuple_element<1, TP>::type n; // double



	std::cout << typeid(n).name() << std::endl;
}





int main()
{
	tuple<int, double, short> t(1, 3.4, 2);

	foo(t);
}

