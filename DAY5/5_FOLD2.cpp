#include <iostream>

// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold
// (args + ... + 0) // E1+(E2+(E3+(E4+(E5+0))))  binary right fold

// (... + args)	    // (((E1+E2)+E3)+E4)+E5		 unary  left fold
// (0 + ... + args) // ((((0+E1)+E2)+E3)+E4)+E5  binary left fold


template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types>
void Show(Types ... args)
{
	// #1. 초기값은 "0" 뿐 아니라 "모든 값(객체)" 를 사용할수 있습니다.
	//     아래 코드 해석해 보세요
	// 초기값     : std::cout 
	// 이항연산자 : <<
	// => binary left fold
//	(std::cout << ... << args);
			// ((((std::cout << 1) << 2) << 3) << 4) << 5


	// #2. args 위치는 "pack이름" 뿐아니라
	//     "pack이름을 사용하는 코드" 을 넣어도 됩니다.
	// 이항연산자 : , 
	// pack 이름 대신 printv(args) 사용
	(printv(args), ...);
	// printv(1), (printv(2), (printv(3), (printv(4), printv(5))))	
	// => 결국, args 의 모든 요소를 printv 에 전달한것

}

int main()
{
	Show(1, 2, 3, 4, 5);
}



