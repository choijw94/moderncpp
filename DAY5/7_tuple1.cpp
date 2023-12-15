// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);
	
	auto a1 = p.first;  // 1
	auto a2 = p.second; // 2.3

	// pair 에 2개 이상 보관도 됩니다.
	std::pair<int, std::pair<double, char>> p2(1, { 3.4, 'A' });

	auto a3 = p2.second.first; // 3.4

	//------------------------------------------
	// C++11 부터는 서로 다른 타입 N 개를 보관하는 tuple 제공
	std::tuple<int, double, char> t(1, 3.4, 'A');

	// 각 요소에 접근은 std::get 을 사용합니다.

	std::get<0>(t) = 100;

	std::cout << std::get<0>(t) << std::endl; // 100
	std::cout << std::get<1>(t) << std::endl; // 3.4

}