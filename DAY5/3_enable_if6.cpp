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
	/*
	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
	*/
	// p.set(10,20) 을 허용하지 않으려면 아래 처럼 하면 됩니다.
	template<typename T1, typename T2>	
	std::enable_if_t< std::is_convertible_v<T1, std::string> &&
					  std::is_convertible_v<T2, std::string> >		
	set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}

	// 생성자에 enable_if 기술 사용하기. 
	// => 생성자는 return 타입이 없습니다.
	// => 함수인자 또는 template 인자로 해야 합니다
	// => 보통 template 인자로 하게됩니다.
	// => 인자로하면 코드가 복잡해 보입니다.
	// 아래 처럼 만들고, 조건만 채우면 됩니다
	/*
	template<typename T1, typename T2,
			 typename T3 = std::enable_if_t< 조건 > >
	People(T1&& a1, T2&& a2) 
		: name( std::forward<T1>(a1)),
		  address( std::forward<T2>(a2) )
	{
	}
	*/

	// 실제 구현은 아래 처럼
	template<typename T1, typename T2,
		typename T3 = std::enable_if_t< std::is_convertible_v<T1, std::string>&&
										std::is_convertible_v<T2, std::string> > >
	People(T1&& a1, T2&& a2)
		: name(std::forward<T1>(a1)),
		address(std::forward<T2>(a2))
	{
	}
};



int main()
{
	People p;
	p.set(10, 20);

}