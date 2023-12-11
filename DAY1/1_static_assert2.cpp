#include <iostream>
#include <type_traits> 

// 교재 9 page 보세요.

#pragma pack(1)		// 구조체 align 을 1byte 단위로( padding 추가하지 말라는 의미)
struct PACKET
{
	char cmd;
	int  data;
};

// PACKET 을 안전하게 사용하려면 아래 처럼 코드를 추가하는 것이 좋습니다.
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
			 "error, unexpected padding..");

/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/




template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic<T>::value : T가 가상함수를 가진 타입이라면 true

	static_assert( !std::is_polymorphic<T>::value,
		"error, T has virtual function");

	memset(p, 0, sizeof(T)); 
}

class Object
{
	int data;
public:
	virtual void foo() {}
};
int main()
{
	Object obj;
	object_set_zero(&obj);
}

// 핵심 
// 1. static_assert 는 실행시간 성능, 기능에는 전혀 영향이 없습니다.
// 2. static_assert 는 안전한 코드를 만드는 데 도움을 줍니다.
// 3. static_assert 는 많이 사용해도 성능과는 무관합니다.
//   