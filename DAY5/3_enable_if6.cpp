#include <iostream>
#include <string>
#include <vector>
#include <array>


class People
{
private:
	std::string name;
	std::string address;
public:
	// move 를 지원하기 위한 setter 를 만들때 T&& 를 사용하는 함수.
	// => 아래 처럼 만들면 "p.set(10, 20)" 이 에러가 아닙니다.
	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
};

int main()
{
	People p;
	p.set(10, 20);

}