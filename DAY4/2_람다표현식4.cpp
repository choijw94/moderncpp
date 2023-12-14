// 5_����ǥ����5
#include <iostream>
#include <vector>
#include <algorithm>

// ����ǥ���İ� Ÿ��

int main()
{
	// #1. ��� ���� ǥ������ �ٸ� Ÿ�� �Դϴ�.
	auto f1 = [](int a, int b) { return a + b; };
				// class xxx{}; xxx();

	auto f2 = [](int a, int b) { return a + b; };
				// class yyy{}; yyy();

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;


	// #2. ����ǥ�������� �ʱ�ȭ�� ������, �ٸ� ����ǥ���� ������ �����ϴ�.
	auto f3 = [](int a, int b) { return a + b; };

//	f3 = [](int a, int b) { return a + b; }; // error. Ÿ���� �ٸ��ϴ�.


	// #3. 
	// �Ʒ� �ڵ带 �� ������ ������. sort() �Լ��� � �����Ǿ������ ?
	std::vector<int> v = { 1,2,3 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

}





