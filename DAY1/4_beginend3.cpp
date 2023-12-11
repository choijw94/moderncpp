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
				// => vector 는 자원을 소유하는 컨테이너 입니다.
				// => 자원을 소유하는 컨테이너의 임시객체를 전달하면 error

	auto p2 = std::ranges::begin(std::string_view{s});
				// => string_view 는 자원을 빌려서 사용하는 컨테이너 입니다
				// => 임시객체를 전달해도, 반복자는 결국
				//    자원의 소유자를 가리키게 됩니다.
				// => 따라서, 이코드는 에러가 아닙니다.

	// C++20 : 자원을 소유하는 컨테이너 인지 ?
	//         자원을 빌려서 사용하는 컨테이너 인지가 중요하게 됩니다.
	//		   "borrowed range" 용어가 공식적으로 등장하게 됩니다.

	
}