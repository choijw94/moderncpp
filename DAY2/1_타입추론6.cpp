#include <iostream>

template<typename T> void foo(T a, T b)
{
}

template<typename T> void goo(T& a, T& b)
{
}

int main()
{	
	// "banana" : const char[7]
	// "apple"  : const char[6]

	foo("banana", "apple");	// ok
			// => const char[7] => const char* 
			// => const char[6] => const char* 
			// => 2개의 인자가 같은 타입이므로 ok. 

	goo("banana", "apple");	// error
			// => 배열을 참조로 받으면 포인터로 변경되지 않고, 배열로 받게된다
			// => "banana", "apple" 은 다른 타입이다.(글자 갯수)
}