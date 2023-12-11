#include <list>
#include <iostream>

class MyList : public std::list<int>
{
public:
	void print() const
	{
		for (auto e : *this)
			std::cout << e << ", ";
		std::cout << std::endl;
	}
	
	// MyList 를 std::list<int> 와 동일하게 사용할수 있게 하려면
	// => 생성자가 필요 합니다.
	
	// # 1. C++98 시절이라면 - std::list<int> 와 동일한 모양의 생성자를 MyList에 추가
	// => 전달 받은 인자로 다시 기반 클래스 생성자로 전달만 합니다.!!
	// => std::list 는 아래 2개 이외에도 많은 생성자가 있습니다.
//	MyList(int sz)            : std::list<int>(sz) {}
//	MyList(int sz, int value) : std::list<int>(sz, value) {}

	// #2. C++11 이라면 생성자 상속 사용
	// => std::list 의 모든 생성자를 MyList 타입에 대해서도 사용가능
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); // 10개를 3으로 초기화
	MyList st2(10);

	st1.print();
}





