// 145 page
#include <iostream>
int main()
{
	// ����ǥ������ ��Ȯ�� ���
	auto f1 = [](int a, int b) -> int { return a + b; };

	// #1. return ������ �Ѱ���� ��ȯ Ÿ�� ���� ����
	auto f2 = [](int a, int b) { return a + b; };

	// #2. return ������ ������ �� ���� Ÿ���� ��ȯ�ϸ� ��ȯ Ÿ�� ���� ����
	auto f3 = [](int a, int b) { if (a == 0) return b;  return a + b; };

	// #3. return ������ �������̰� �ٸ� Ÿ���� ��ȯ�ϸ� 
	//	   �ݵ�� return Ÿ�� ǥ���ؾ� �մϴ�.
	//     �Ʒ� �ڵ�� ����. 
	auto f4 = [](double a, int b) { if (a == 0) return b;  return a; }; 

	
}

