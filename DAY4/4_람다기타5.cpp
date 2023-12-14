#include <iostream>

class ClosureType
{
	int v1;
	int v2;
public:
	ClosureType(int a, int b) : v1(a), v2(b) {}

	inline int operator()(int a, int b) const { return a + b + v1 + v2; }


	// �Ʒ� �Լ��� ���� �Դϴ�.
	// => static ��� �Լ����� ��� ����Ÿ ���� �ȵ˴ϴ�.
	// => �׷��� �����Ϸ��� �Լ� ������ ��ȯ�� �����ϱ� ���� �Ʒ� �Լ��� �����Ҽ� �����ϴ�.
	static int helper(int a, int b) { return a + b + v1 + v2; }



	using PF = int(*)(int, int);

	operator PF() { return &ClosureType::helper; }
};


int main()
{
	int v1 = 0, v2 = 0;

	// ĸ���� ���� ǥ������ �Լ� �����ͷ� ��ȯ �ɼ� �����ϴ�.
	// => �Ʒ� �ڵ�� ����!!
	// => ĸ�� ���� ���� ���� ǥ���ĸ� �Լ� ������ ��ȯ �����մϴ�.
	//	int(*f)(int, int) = [v1, v2](int a, int b) {return a + b + v1 + v2; }

	int(*f)(int, int) = ClosureType(v1, v2);

	int n = f(1, 2);

	std::cout << n << std::endl; // 3
}












