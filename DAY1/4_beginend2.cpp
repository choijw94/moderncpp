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

	// std::ranges::begin �� �������� �߰��ϱ����� �����
	// => �Ʒ� 2���� ������ ������
	// => ���ڰ� �ӽð�ü�Դϴ�.
	auto p4 = std::begin( std::vector<int>{1, 2, 3, 4, 5} );
				// => ������ ���� �ƴմϴ�.
				// => ������, �ӽð�ü vector �� ��� �ı� �ǹǷ�
				// => p4 ���� runtime error

	auto p5 = std::ranges::begin( std::vector<int>{1, 2, 3, 4, 5} );
				// => ������ ����!! 

}