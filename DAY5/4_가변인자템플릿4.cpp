#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	printv(args...);	// error. printv(1, 2, 3) �� �ǹ��ε�, 
						//		  printv() �� ���ڴ� �Ѱ�

//	printv(args)...;	// printv(1), printv(2), printv(3) �ǵ� ������
						// error. 
						// �� ��ġ������ pack expansion �� �ɼ� �����ϴ�.

	// #1. pack expansion �� �Ʒ��� ��ġ������ �����մϴ�.
	// 1. �Լ� ȣ���� () ��			: goo(args...)
	// 2. ���ø� ������ <> ��			: std::tuple<Types...>
	// 3. {} �ʱ�ȭ �� ����ϴ� ����. : int x[] = {args...};


	// args �� ��� ��Ҹ� printv �� ��������
	// => �Ʒ� ����� C++11 ó�� �������� ����ߴ� ����Դϴ�.
	// => ������ ������ ��� �ֽ��ϴ�.(fold expression ��)
	int x[] = { 0, (printv(args), 0)... }; 
				// { 0, (printv(1), 0), (printv(2), 0), (printv(3), 0) }
}


int main()
{
	foo(1, 2, 3);
	foo();
}

