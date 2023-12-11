// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>
#include <ranges>
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �������� for ��
	for (int i = 0; i < v.size(); i++)
	{
	}

	// C++11 ���� ���ο� for �� ���� - range for ��
	// ���̽� : for e in v
	// C#     : for var e in v
	for (auto e : v)
	{
	}

	// ��ü�� �ƴ� �Ϻθ� �Ҽ� ������ ?
	// 2ĭ�� �̵� �����Ѱ��� ?
	// �Ųٷ� �Ҽ� ������ ?
	// => ��� C++20 ���� ����. �������� �ȵ�.
	for (auto e : std::views::reverse(v) )
	{
		std::cout << e << ", ";
	}
}















