#include <iostream>

// 타입 : 선언문에서 "이름"을 제거하면 타입만 남게 됩니다.
// int n    => 이름은 n, 타입 int
// int x[3] => 이름은 x, 타입 int[3]


// f 타입 : int (int, double)
int f(int a, double b) { return 0; }

// 함수 타입에서 "반환타입" 을 얻을수 있는 traits 만들기

// primary template
template<typename T> struct result
{
	using type = T;
};


template<typename T> void foo(T& a) 
{
	// T : int (int, double)
	typename result<T>::type n;  // int

	cout << typeid(n).name() << endl; 
}

int main()
{
	foo(f);
}