#include <iostream>

// std::is_constant_evaluated()
// => 컴파일 시간에 실행되었는지 확인 할때 사용
// => C++20

constexpr std::pair<int, bool> add(int a, int b)
{
	int c = a + b;

	bool ret = std::is_constant_evaluated();

	return std::pair<int, bool>(c, ret);
}

int main()
{
	auto           ret1 = add(1, 2);
	constexpr auto ret2 = add(1, 2); // 컴파일 시간!!

	std::cout << ret1.second << std::endl;
	std::cout << ret2.second << std::endl;
}