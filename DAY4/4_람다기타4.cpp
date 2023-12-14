#include <iostream>

// ���� ǥ������ �Լ� �����Ϳ� ������ �ֽ��ϴ�
// ==> ������ ������ ���ô�.
class ClosureType
{
public:
	inline int operator()(int a, int b) const { return a + b; }


	// static ��� �Լ��� ��ü���� ȣ��ǹǷ� �Ϲ��Լ��� ������ �����Դϴ�.
	// => �Լ� �����ͷ��� ��ȯ�� ���ؼ� operator() �� ������ ���� �����ϴ�
	//    static ��� �Լ��� ����
	static int helper(int a, int b) { return a + b; }

	
	// �Լ� �����ͷ��� ��ȯ�� ���ؼ� ��ȯ������ �߰��˴ϴ�.
	using PF = int(*)(int, int);

//	operator PF() { return &ClosureType::operator(); } 
							// => error
							// => �Ϲ� �Լ� �����Ϳ� ��� �Լ����ּҸ� ������ �����ϴ�

	operator PF() { return &ClosureType::helper; }
};




int main()
{	
//	int(*f)(int, int) = [](int a, int b) {return a + b; }

	int(*f)(int, int) = ClosureType();
						// ��ü.operator �Լ�������Ÿ��();

	int n = f(1, 2);

	std::cout << n << std::endl; // 3
}












