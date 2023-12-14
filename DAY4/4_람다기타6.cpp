// 5_람다표현식6
// 람다표현식은 인자를 받는 방법 - 143p 아래 부분

// #1. C 언어에서는 "함수를 인자로 받으려면 함수 포인터" 를 사용합니다
// 
// 1. 함수 뿐 아니라 캡쳐하지 않은 람다 표현식도 받을수 있습니다.
// 2. 캡쳐한 람다 표현식을 받을수 없습니다.
// 3. 람다가 아닌 일반 함수객체(std::less)를 받을수 없습니다.(변환 연산자 제공 안됨)
// void foo(int(*f)(int, int)) {  }


// #2. std::function 사용
// 1. 일반함수, 함수객체, 람다표현식, 캡쳐한 람다 표현식등 모두 받을수 있습니다.
void foo( std::function<int(int, int)> f ) 
{
	f(1, 2); // inline 치환이 되기 어렵습니다.
			 // 반복문 안에서 f 사용시 성능 이슈!
}

// #3. template - call by value  - 가장 널리 사용
template<typename T>
void foo(T f)
{
	f(1, 2); // inline 치환 가능.
}

// #4. template - call by const reference
// 1. mutable lambda 를 받을수 없다
template<typename T>
void foo(const T& f)
{
	f(1, 2); // f.operator()(1, 2)
			 // f는 상수 객체이므로 operator() 는 상수 함수만 가능.
}

// #5. template - T&&
// => 나쁘지 않습니다. 표준에서도 가끔 사용
template<typename T>
void foo(T&& f)
{

}

int main()
{
	foo([](int a, int b) mutable { return a + b; });
	foo([](int a, int b) { return a - b; });
}

// 결론 : foo(T f) 권장
//        foo(T&& f) 나쁘지 않음. 크기가 큰 객체(캡쳐를 많이 하는 경우)

