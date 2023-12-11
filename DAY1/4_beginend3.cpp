#include <vector>
#include <string>
#include <string_view> // C++17!!

int main()
{
	// std::string      : 자원(문자열을 소유) 합니다
	// std::string_view : 자원을 소유하지 않고, 빌려서 사용합니다.
	std::string s = "to be or not to be";
	std::string_view sv = s;


	// 아래 코드를 생각해 보세요
	auto p1 = std::ranges::begin(std::vector<int>{1, 2, 3});
	auto p2 = std::ranges::begin(std::string_view{s});

	
}