// 9_FOLD - 237 page

#include <iostream>

// fold expression ( C++17 ) 
// => parameter pack 안에 모든 요소에 대해서 이항 연산을 수행하는 표현식

template<typename ... Types> 
int Sum(Types ... args)
{
	// args         : 1,  2,  3,  4,  5,  6,  7,  8,  9,  10
	// 합을 구하려면 : 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
	// => 즉, pack 에 있는 모든 요소에 대해서 이항연산(+) 를 수행하면 된다.

	int s = (... + args);

	return s;
}

int main()
{
	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	std::cout << n << std::endl;
}






// fold expression
// => () 가 반드시 있어야 합니다.
// => 4개 종류가 있습니다.
// => '+' 위치에 어떠한 이항 연산자도 올수 있습니다.
// => '0' 위치에 어떠한 값(변수)도 올수 있습니다(init value 라고 합니다.)

// 핵심 : pack 의 위치에 따라 () 의 위치가 달라 집니다.
// 
// (args + ...)			// E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0)		// E1+(E2+(E3+(E4+(E5+0))))  binary right fold
// ( ... + args)		// (((E1+E2)+E3)+E4)+E5		 unary  left fold
// ( 0 + ... + args)	// ((((0+E1)+E2)+E3)+E4)+E5  binary left fold