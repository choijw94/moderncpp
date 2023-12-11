#include <string>
#include <string_view>
#include <iostream>

void* operator new(std::size_t size)
{
	printf("operator new : %d\n", size);

	return malloc(size);
}

void f2(const std::string& s) {}

void f3(std::string_view sv) {}


int main()
{
	f2("to be or not to be");	// 임시객체를 생성하고, 문자열을 힙에 복사하기 위해
								// new 를 사용하게 됩니다.
				

//	f3("to be or not to be");	// 임시객체 같은것이 생성되지 않음. new 사용안함.
}
