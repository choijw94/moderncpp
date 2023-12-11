// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };


	// # 1. C++98 ������ �ݺ��ڸ� ��� �ڵ�
	// => �Ʒ� ó�� �ݺ����� Ÿ���� ���� ����ϸ�
	// ���� 1. �ڵ尡 ������ ���̰�
	//      2. �����̳� ����� �ݺ��� Ÿ�Ե� ����Ǿ�� �մϴ�.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// # 2. �ݺ��� Ÿ���� ���� ������� ����, auto ����ϼ���
	// => �����̳� ����� �º��� �������ʿ� �����ϴ�.
	// => �� �Ʒ� �ڵ�� v �� �迭�̶�� error �Դϴ�.
//	auto p1 = v.begin();
//	auto p2 = v.end();


	// # 3. ��� �Լ� begin ���� �Ϲ� �Լ� begin �� �������� �����ϴ�.
	// => �Ʒ� ó�� ����ϸ� v �� �迭�̾ ���� �����ϴ�.
	auto p1 = std::begin(v);
	auto p2 = std::end(v);

}