// 후위반환 - 73 page 아래 부분
#include <iostream>

// 아래 코드에서 반환 타입 ? 를 어떻게 표기해야 할까요 ?
template<typename T1, typename T2>
// ? Mul(T1 a, T2 b)
decltype( a * b ) Mul(T1 a, T2 b) // 왜 에러일까요 ??
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;
}

