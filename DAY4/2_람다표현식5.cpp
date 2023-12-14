// 143 
#include <functional>

int main()
{
	// ����ǥ������ ��� ���

	auto f1            = [](int a, int b) { return a + b; }; // auto ����

	int(*f2)(int, int) = [](int a, int b) { return a + b; }; // �Լ�������
						// => �캯�� �ӽð�ü�ε�.. ��� �Լ������Ϳ� ������ �ֳ��� ?
						// => ���Ŀ� �ٷ�� �˴ϴ�.

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; }; // function

	// # Ư¡ 1. auto ������ �ٸ� ���ٸ� ������ ������, f2, f3 ���� ������ �ֽ��ϴ�.
	// f1 : �����Ϸ��� ���� Ŭ���� Ÿ��!! - ��� ���ٴ� �ٸ� Ÿ��
	// f2 : �Լ� ������ Ÿ��
	// f3 : std::function Ÿ��
//	f1 = [](int a, int b) { return a - b; }; // error
	f2 = [](int a, int b) { return a - b; }; // ok
	f3 = [](int a, int b) { return a - b; }; // ok

	// # Ư¡ 2. 
	f1(1, 2);
	f2(1, 2);
	f3(1, 2);
}