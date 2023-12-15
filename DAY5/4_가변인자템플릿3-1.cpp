#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types>
void foo(Types ... args)
{
	// args : 1, 2, 3
//	goo(args);	// error. pack 이름 자체를 함수 인자로 사용할수 없습니다.
				//        pack 안의 요소를 , 로 분리해서 보내야 합니다.


	// #1. pack expansion 문법을 알아야 합니다
	// => ... 으로 pack 안의 모든 요소를 , 로 분리하는 것
	// "pack이름..."           => E1, E2, E3
	// "pack을사용하는코드..."  => E1을사용하는코드, E2을사용하는코드, E3을사용하는코드

	goo(args...);		// goo(1, 2, 3)

	goo((++args)...);	// goo(++E1, ++E2, ++E3)

	// 아래 2줄의 차이점 생각해 보세요
	goo(hoo(args...));	// goo( hoo(1,2,3)) 의 의미 인데..
						// hoo 함수는 인자가 한개 이므로 error

	goo(hoo(args)...);	// goo(hoo(1), hoo(2), hoo(3))
						// 위의 hoo, goo 조건을 만족하므로 ok.. 

}


int main()
{
	foo(1, 2, 3);
}
