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
			// => 2���� ���ڰ� ���� Ÿ���̹Ƿ� ok. 

	goo("banana", "apple");	// error
			// => �迭�� ������ ������ �����ͷ� ������� �ʰ�, �迭�� �ްԵȴ�
			// => "banana", "apple" �� �ٸ� Ÿ���̴�.(���� ����)
}