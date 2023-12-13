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
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	/*
	// 방법 2. T&& 를 사용하면 위 2개를 자동생성할수 있습니다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
//		name = n;					// 1. 항상 복사 대입 연산자
//		name = std::move(n);		// 2. 항상 이동 대입 연산자
		name = std::forward<T>(n);	// 3. ok..
									//    set_name 인자로 lvalue 를 보내면 lvalue 캐스팅
									//					  rvalue 를 보내면 rvalue 캐스팅
	}
	*/
	// 권장 : 위 코드에서는 "방법1" 처럼 2개를 만드는 것을 T&& 버전보다 권장합니다.!!
	// => 가독성도 좋고, 안전합니다.
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
	//------------------------------------------------------

	// STL 컨테이너들은 push_xxx() 함수가 모두 move 버전도 지원합니다.
	std::vector<std::string> v;

	v.push_back(s1);			// s1을 복사해서 넣겠다. s1 계속 사용가능
	v.push_back(std::move(s1)); // s1의 자원을 이동해가라는 것. s1 더이상 사용안함

	// v.emplace_back( 인자로 객체가 아닌 생성자 인자 )
	// v.emplace_back( 객체 ) => 이경우 new Point(pt) 이므로 복사 생성자
}








