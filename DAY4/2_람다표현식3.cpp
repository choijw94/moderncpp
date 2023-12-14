#include <iostream>

// auto 와 람다 표현식

int main()
{
//	int foo() {} // 함수 안에 함수, local function, nested function 이라고 합니다

	// #1. 람다표현식을 auto 변수에 담아서 함수 처럼 사용가능합니다.
	// => 일부 언어(C#등)는 함수 안에 함수를 만들수 있습니다.
	// => C++ 은 함수 안에 함수를 만들수 없는데
	//    아래 처럼 만들면 결국, local function 을 만든것과 동일합니다.

	auto add = [](int a, int b) { return a + b; };
				// class ClosureType{ operator()(){} }; ClosureType();

	int n1 = add(1, 2);
	int n2 = add.operator()(1, 2);	// ok.. 결국 함수 객체이므로 
									// 이렇게 사용해도 됩니다


	// #2. 다음중 에러를 모두 고르세요 - f2 한개 에러
	// 
	//     에러가 아닌 코드중 최선의 코드를 고르세요 - f1 이 최선!!!
	// 
	// 핵심 : 람다표현식의 최종 결과는 "임시객체(rvalue)" 이다.

	auto  f1       = [](int a, int b) { return a + b; }; // ok
	auto& f2       = [](int a, int b) { return a + b; }; // error.
								// => 임시객체를 lvalue reference 로 가리킬수 없다

	const auto& f3 = [](int a, int b) { return a + b; }; // ok	
	auto&& f4      = [](int a, int b) { return a + b; }; // ok
					// auto&& 는 "forwarding reference" 인데.
					// 우변이 rvalue 이므로 auto : 값 타입, auto&& 는  타입&&(rvalue reference)
}

// 참고 : Point pt = Point(1, 2) 에대해서 생각해 봅시다.

// C++98
// Point pt = Point(1, 2)
//			  1. 임시객체를 생성하고
//			  2. 임시객체가 pt 에 복사(복사 생성자 사용)
//			  => 그런데, 대부분의 컴파일러는 임시객체의 생성, 복사생성자 호출의 과정을 생략하고
//               인자가 2개인 생성자만 호출로 최적화(copy ellision, elide copy constructor )
//			  => 그런데, Point 의 복사 생성자를 private 에 놓으면 에러
//				 g++ 소스.cpp -std=c++98

// C++11
// Point pt = Point(1, 2)
//			  1. 임시객체를 생성하고
//			  2. 임시객체가 pt 에 이동(move 생성자 사용)
//			  => 그런데, 역시 대부분의 컴파일러는 최적화 해서 인자가 2개인 생성자 호출

// C++17
// Point pt = Point(1, 2)
//			  1. 인자가 2개인 생성자 호출
//            => 임시객체 생성과 복사를 생략하는 것이 문법화됨...!!
//			  => 복사 생성자 와 이동생성자가 모두 private 에 있어도 에러 아님.

// auto   f1 = [](int a, int b) { return a + b; }; //
// auto   f1 = ClosureType(); // 결국 생성자만 1회 호출. 추가 오버헤드 없음

// auto&& f2 = [](int a, int b) { return a + b; }; // ok
// ClosureType* f2 = &ClosureType(); // 임시객체를 주소를 구할수 없지만 내부 원리설명을 위해
// 이후 f2 를 사용하면 f2가 가진 주소를 통해서 객체에 접근
// 즉, 직접 접근이 아닌 주소를 통해서 접근하므로 약간의 오버헤드!
