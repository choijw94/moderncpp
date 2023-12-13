#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// setter 만들기.
	// #1. const string&
	// => C++98 시절에는 최선의 코드
	// => C++11 이후에는 최선은 아님. 
//	void set_name(const std::string& n) { name = n; } // 항상 복사 대입
//	void set_name(const std::string& n) { name = std::move(n); } // 항상 복사 대입
														// n 자체가 const 이므로
														// const 는 move 될수 없다

	// C++11 이후의 최선의 코드
	// => 2개의 setter 를 만드세요
	// 방법 1. 2개를 직접 만들기
//	void set_name(const std::string& n) { name = n; }
//	void set_name(std::string&& n)      { name = std::move(n); }


	// 방법 2. T&& 를 사용하면 위 2개를 자동생성할수 있습니다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
		name = n;					// 1
		name = std::move(n);		// 2
		name = std::forward<T>(n);	// 3
	}
};



int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1의 자원을 복사. s1은 계속 사용하겠다는 의도
	p.set_name(std::move(s2));	// s2의 자원을 이동. s2는 더이상 사용하지 않겠다는 의도

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}








