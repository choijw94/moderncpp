#include <iostream>

// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// (... + args)	    // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// #1. �ʱⰪ�� "0" �� �ƴ϶� "��� ��(��ü)" �� ����Ҽ� �ֽ��ϴ�.
	//     �Ʒ� �ڵ� �ؼ��� ������
	// �ʱⰪ     : std::cout 
	// ���׿����� : <<
	// => binary left fold
	(std::cout << ... << args);
			// ((((std::cout << 1) << 2) << 3) << 4) << 5

}

int main()
{
	Show(1, 2, 3, 4, 5);
}



