// 함수 인자로
// int&  : int 타입의 lvalue 만 받을수 있다.
// int&& : int 타입의 rvalue 만 받을수 있다.
// T&    : 모든 타입의 lvalue 만 받을수 있다.


// T&&   : 모든 타입의 lvalue 와 rvalue 를 모두 받을수 있다.

// 모두 받을수 있다는 의미는, 
// => 함수 한개가 모든 것을 받은 다는 것이 아니라, 
//    각각의 경우를 받을수 있는 "함수를 생성할수 있다" 는 것.


// 아래 내용 외우세요 ( n 은 int 일때)
// 인자로 lvalue 전달(f4(n)) : T=int&,  인자는 T&&=int& &&, 생성된 함수 f4(int&)
// 인자로 rvalue 전달(f4(3)) : T=int    인자는 T&&=int&&    생성된 함수 f4(int&&)
// 
// ==> 생성된 함수는 모두 "call by value" 가 아닌 "call by reference"
// ==> 즉, 모든 인자를 복사본 없이 받을수 있는 함수들이 생성된다는 것


// 용어 정리
// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference

// T&&   : rvalue reference 라고 할수는 없습니다.
//		   lvalue, rvalue 모두 받을수 있으므로!!

// C++11 초기에 "T&&" 의 이름을 정하지 않았습니다. 
// 그래서 effective-modern C++의 저자가 "universal reference" 라고 부르자고 제안. 
//       그런데, C++ 표준위원회는        "forwarding reference" 라고 결정!!

// T&& 의 공식 명칭은 현재 "forwarding reference" 입니다.