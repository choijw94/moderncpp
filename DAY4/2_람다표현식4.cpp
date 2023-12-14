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


	// #3. ������ ���� ǥ������ ������ ����ϰ� �ȴٸ�, 
	//     auto ������ ��Ƽ� ����ϴ� ���� �����ϴ�.
	
	std::vector<int> v = { 1,2,3 };

	// �Ʒ� �ڵ带 �� ������ ������. sort() �Լ��� � �����Ǿ������ ?
	// => ������ ���� ǥ�����̶� �ٸ� Ÿ���̹Ƿ� "3���� sort" �����˴ϴ�.
	// => sort ���� �Լ��� "������ �����ϰ� inline �Ǵ� constexpr �̰�
	//    �����Ϸ� ����ȭ ���� ����������� �Ʒ� �ڵ�� ������尡 ũ�� �ʽ��ϴ�!
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });


	// �Ʒ� ó�� ����ϸ� "1���� sort" �� �����˴ϴ�.
	auto cmp = [](int a, int b) { return a < b; };

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// < ������ �ʿ��ϴٸ� ����ǥ������ �ƴ� "std::less" �� ����ص� �˴ϴ�
	std::sort(v.begin(), v.end(), std::less<int>());
	std::sort(v.begin(), v.end(), std::less<int>());
	std::sort(v.begin(), v.end(), std::less<int>());
}





