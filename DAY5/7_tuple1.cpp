// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : ���� �ٸ� Ÿ�� 2���� ���� - C++98
	std::pair<int, double> p(1, 2.3);
	
	auto a1 = p.first;  // 1
	auto a2 = p.second; // 2.3

	// pair �� 2�� �̻� ������ �˴ϴ�.
	std::pair<int, std::pair<double, char>> p2(1, { 3.4, 'A' });

	auto a3 = p2.second.first; // 3.4

	//------------------------------------------
	// C++11 ���ʹ� ���� �ٸ� Ÿ�� N ���� �����ϴ� tuple ����
	std::tuple<int, double, char> t(1, 3.4, 'A');

	// �� ��ҿ� ������ std::get �� ����մϴ�.

	std::get<0>(t) = 100;

	std::cout << std::get<0>(t) << std::endl; // 100
	std::cout << std::get<1>(t) << std::endl; // 3.4

}