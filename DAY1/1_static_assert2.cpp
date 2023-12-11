#include <iostream>
#include <type_traits> 

#pragma pack(1)		// 구조체 align 을 1byte 단위로( padding 추가하지 말라는 의미)
struct PACKET
{
	char cmd;
	int  data;
};

// PACKET 을 안전하게 사용하려면 아래 처럼 코드를 추가하는 것이 좋습니다.
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
			 "error, unexpected padding..");


int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}





template<typename T> void object_set_zero(T* p)
{
	memset(p, 0, sizeof(T)); 
}
