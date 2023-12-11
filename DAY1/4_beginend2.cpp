// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �ݺ��ڸ� ������ 3���� ���
	// # 1. ��� �Լ� begin ���(C++98)
	auto p1 = v.begin();

	// # 2. �Ϲ� �Լ� begin ���(C++11)
	// => v �� �迭�̶� ok
	auto p2 = std::begin(v);

	// # 3. std::ranges::begin ���(C++20)
	auto p3 = std::ranges::begin(v);


}