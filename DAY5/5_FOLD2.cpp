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
//	(std::cout << ... << args);
			// ((((std::cout << 1) << 2) << 3) << 4) << 5


	// #2. args ��ġ�� "pack�̸�" �Ӿƴ϶�
	//     "pack�̸��� ����ϴ� �ڵ�" �� �־ �˴ϴ�.
	// ���׿����� : , 
	// pack �̸� ��� printv(args) ���
	(printv(args), ...);
	// printv(1), (printv(2), (printv(3), (printv(4), printv(5))))	
	// => �ᱹ, args �� ��� ��Ҹ� printv �� �����Ѱ�

}

int main()
{
	Show(1, 2, 3, 4, 5);
}



