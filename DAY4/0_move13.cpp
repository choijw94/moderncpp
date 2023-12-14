#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <type_traits>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 2개인 setter 에 move 지원하기.
	// => 아래 코드는 move 지원 안됩니다.
	/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	// move 를 지원 하려면 아래 처럼 4개를 만들어야 합니다

	void set(const std::string& n,	const std::string& a) {}
	void set(const std::string& n,	std::string&& a) {}
	void set(std::string&& n,		const std::string& a) {}
	void set(std::string&& n,		std::string&& a) {}
	*/
	// 인자가 N 개인 setter 가 move 지원 하려면
	// => 2^N 개의 함수가 필요 합니다.
	// => 이 경우에는 위처럼 직접 만들지 말고 forwarding reference 를 권장
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

	// 생성자가 대표적인 setter 입니다
	// => 아래 생성자는 move 를 지원할수 없는 생성자 입니다.
//	People(const std::string& n, const std::string& a)
//		: name(n), address(a) {}

	// 생성자가 인자가 2개 이상 이면 T&& 가 좋습니다.
//	template<typename T1, typename T2>
//	People(T1&& n, T2&& a)
//		: name(std::forward<T1>(n) ), address( std::forward<T2>(a) ) {}

	// 위 생성자의 T1, T2 가 반드시 string 이어야 한다고 제약을 넣기 위해서는
	// enable_if 등의 기술이 필요 합니다.
	template<typename T1, typename T2, 
		typename T3 = std::enable_if_t< 
				std::is_convertible_v<T1, std::string> && 
				std::is_convertible_v<T2, std::string> >>

	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)), address(std::forward<T2>(a)) {}

};



int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

//	People p(name, addr);
	People p(name, std::move(addr) );

	p.set(name,			   addr);
//	p.set(std::move(name), addr);
//	p.set(name,			   std::move(addr));
//	p.set(std::move(name), std::move(addr));
}








