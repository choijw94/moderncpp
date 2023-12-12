// �ʱ�ȭ - 55 page
#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;
	int value2 = ++x;	// ���� �̷� �ڵ带 ������� ������
						// ������ ������ �˴ϴ�.
						// ���ڵ� ó�� = 0 ������ ����ϼ���.
public:	
	Test() {}					// Test()      : value1(0), value2(++x) {}
	Test(int n) : value2(n) {}  // Test(int n) : value1(0), value2(n) {} 
};

int main()
{
	Test t1;		// �����ڿ��� ++x ���� ��
	Test t2(5);		// �����ڿ��� ++x ���� �ȵ�.

	std::cout << x << std::endl;	// �����غ�����. ?
									// 11
}