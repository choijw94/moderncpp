#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

template<typename T>
int foo(T a) 
{ 
	typename T::type n;	 // SFINAE �� ����ɱ�� ?
						 // �ƴϸ� �����ϱ�� ?
	return 0; 
}



int main()
{
	foo(3);
}