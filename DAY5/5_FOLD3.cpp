#include <iostream>
#include <vector>

template<typename ... Types>
void fn(std::vector<int>& v, Types ... args)
{
	// pack 안의 모든 요소를 v 에 넣고 싶다.
}

int main()
{
	std::vector<int> v;

	fn(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	fn(v, 1, 2, 3, 4, 5);

	for (auto e : v)
		std::cout << e << ", ";
		// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 
}