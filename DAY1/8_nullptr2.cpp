// 8_nullptr2
#include <iostream>

void foo(int* p) {}

int main()
{
	int n = 0;

	// 아래 2줄을 생각해 보세요.
	foo(0);	// ok.	  0은 정수지만 포인터로 암시적 형변환 가능합니다.
	foo(n);	// error. 리터럴 0만 포인터로 암시적 형변환 되고
			//        0으로 초기화면 정수 n은 포인터로 암시적 형변환 안됩니다.
}

template<typename F, typename ARG>
void forward_parameter(F f, ARG arg)
{
	f(arg);
}






