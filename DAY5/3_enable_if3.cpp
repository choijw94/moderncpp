#include <iostream>
#include <type_traits>


// 아래 리턴 타입의 코드가 핵심입니다.
template<typename T> 

std::enable_if< std::is_integral_v<T>, T>::type

gcd(T a, T b)
{
	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);		
	gcd(3.1, 5.4); 
	gcd(3.1f, 5.4f); 
}