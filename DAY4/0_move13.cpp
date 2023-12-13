#include <iostream>
#include <string>
#include <vector>
#include <array>

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

};



int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
//	p.set(std::move(name), addr);
//	p.set(name,			   std::move(addr));
//	p.set(std::move(name), std::move(addr));
}








