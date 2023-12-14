#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

template<typename T>
int foo(T a) 
{ 
	typename T::type n;	 // SFINAE 가 적용될까요 ?
						 // 아니면 에러일까요 ?
	return 0; 
}



int main()
{
	foo(3);
}