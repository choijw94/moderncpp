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

// 핵심 : int (int, double) 형태의 타입에서 반환타입(int) 을 얻을수 있도록
//       부분 특수화 버전을 만들어야 합니다. 이부분이 핵심!!
// primary template 의 template 인자는 한개 지만
// 아래처럼 부분 특수화 할때는 template 인자의 갯수가 달라도 됩니다.
template<typename R, typename A1, typename A2> struct result< R(A1, A2) >
{
	using type = R;
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