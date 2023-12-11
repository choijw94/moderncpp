//8_nullptr3
#include <iostream>

int main()
{
	// literal 과 타입
	// => 모든 리터럴(프로그램에서 사용하는 값)은 타입이 있습니다.

	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	
	false;		// bool 타입,    false 는 리터럴이고, 키워드

	nullptr;	// std::nullptr_t,      nullptr 도 리터럴(값), 키워드.


	// std::nullptr_t 타입은 모든 종류의 포인터로 암시적 형변환 가능합니다.
	std::nullptr_t n = nullptr;

	// 이제 n 은 nullptr 대신 사용가능합니다.
	int* p1 = n;
	char* p2 = n;
}



