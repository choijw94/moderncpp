// 5_����ǥ����5
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, typename CMP>
void sort(T first, T last, CMP cmp)
{
}

int main()
{
	std::vector<int> v = { 1,2,3 };

	// �Ʒ� �ڵ带 �� ������ ������. sort() �Լ��� � �����Ǿ������ ?
	// => ������ ���� ǥ�����̶� �ٸ� Ÿ���̹Ƿ� "3���� sort" �����˴ϴ�.
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	/*
	// �Ʒ� ó�� ����ϸ� "1���� sort" �� �����˴ϴ�.
	auto cmp = [](int a, int b) { return a < b; };

	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.end(), cmp);

	// < ������ �ʿ��ϴٸ� ����ǥ������ �ƴ� "std::less" �� ����ص� �˴ϴ�
	sort(v.begin(), v.end(), std::less<int>());
	sort(v.begin(), v.end(), std::less<int>());
	sort(v.begin(), v.end(), std::less<int>());
	*/
}





