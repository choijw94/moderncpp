#include <vector>
#include <string>
#include <memory>

// 아래 같은 call by value 는 나쁜코드지만, 초기화 문법 설명을 위해.
void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello"); // 논리적으로 맞습니다. 에러 나오면 안됩니다.
				  // 지금 잘됩니다.
				  // std::string s = "hello" 가 된다는 의미!
				  // string(const char*) 생성자는 explicit 가 아니라는 의미.

	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok


	goo(10);	// 논리적으로 맞지 않습니다. 
				// 에러 입니다.
				// vector(std::size_t) 생성자는 explicit 라는 의미. 

	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error
	std::vector<int> v3 = { 10 }; // ok. 그럼 이건 왜?? 되나요 ?? - 초기화9.cpp 에서!
	




}





