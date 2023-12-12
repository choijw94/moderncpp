// 초기화 - 55 page
#include <iostream>

int x = 10;

class Test
{
	int value1 = 0;
	int value2 = ++x;	// 절대 이런 코드를 사용하지 마세요
						// 버그의 원인이 됩니다.
						// 위코드 처럼 = 0 정도만 사용하세요.
public:	
	Test() {}					// Test()      : value1(0), value2(++x) {}
	Test(int n) : value2(n) {}  // Test(int n) : value1(0), value2(n) {} 
};

int main()
{
	Test t1;		// 생성자에서 ++x 실행 됨
	Test t2(5);		// 생성자에서 ++x 실행 안됨.

	std::cout << x << std::endl;	// 예측해보세요. ?
									// 11
}