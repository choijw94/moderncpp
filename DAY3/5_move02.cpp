#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

// 아래 코드는 "복사" 기반의 swap 입니다(C++98 시절의 C++ 표준 구현)
// => 성능이 좋지 않습니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;	// T 타입의 복사 생성자 호출
				// string 이었다면 "문자열"을 깊은 복사
	a = b;
	b = tmp;
}

// 아래 코드는 C++11 에서의 swap 구현
// 이동을 사용한 swap 입니다.
// 복사 버전보다 빠릅니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);	
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move 라는 주제에서 알아야 하는것

// 1. swap 같은 알고리즘 작성시 std::move 를 사용하면 성능이 향상 된다는 점.

// 2. std::string 같은 표준 라이브러리가 아닌 
//    사용자가 만드는 "People" 같은 클래스가 move 를 지원하려면 어떻게 해야 하는가 ?



