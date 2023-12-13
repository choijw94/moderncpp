#include <iostream>

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

//	main					chronometry						    hoo(int&&)
//  hoo(10) =====================================================> ok
//  chrometry(10) =========> int&& arg = 10
//								hoo(arg) =========================> error
//								hoo(static_cast<int&&>(arg)) =====> ok. 

template<typename F>
void chronometry(F f, int&& arg)
{
	// int&& arg = 10 에서 
	// 10  : rvalue
	// arg : lvalue. <<==== 핵심!

//	f(arg);	// arg가 lvalue 이므로
			// hoo(int&) 또는 hoo(int) 를 찾게 되니다.

	// main 에서는 rvalue(10) 을 보냈는데, 받으면서 이름이 생기고, lvalue 가 된것을
	// 다시 rvalue 로 변경해서 전달합니다.
	f(static_cast<int&&>(arg)); // ok
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10);	
}
