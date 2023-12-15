// 9_FOLD - 237 page

#include <iostream>

// fold expression ( C++17 ) 
// => parameter pack �ȿ� ��� ��ҿ� ���ؼ� ���� ������ �����ϴ� ǥ����

template<typename ... Types> 
int Sum(Types ... args)
{
	// args         : 1,  2,  3,  4,  5,  6,  7,  8,  9,  10
	// ���� ���Ϸ��� : 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
	// => ��, pack �� �ִ� ��� ��ҿ� ���ؼ� ���׿���(+) �� �����ϸ� �ȴ�.

	int s = (... + args);

	return s;
}

int main()
{
	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << n << std::endl;
}






// fold expression
// => () �� �ݵ�� �־�� �մϴ�.
// => 4�� ������ �ֽ��ϴ�.
// => '+' ��ġ�� ��� ���� �����ڵ� �ü� �ֽ��ϴ�.
// => '0' ��ġ�� ��� ��(����)�� �ü� �ֽ��ϴ�(init value ��� �մϴ�.)

// �ٽ� : pack �� ��ġ�� ���� () �� ��ġ�� �޶� ���ϴ�.
// 
// (args + ...)			// E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0)		// E1+(E2+(E3+(E4+(E5+0))))  binary right fold
// ( ... + args)		// (((E1+E2)+E3)+E4)+E5		 unary  left fold
// ( 0 + ... + args)	// ((((0+E1)+E2)+E3)+E4)+E5  binary left fold