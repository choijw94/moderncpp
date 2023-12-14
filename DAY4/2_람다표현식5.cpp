// 143 
#include <functional>
#include <vector>

int main()
{
	// 람다표현식을 담는 방법

	auto f1            = [](int a, int b) { return a + b; }; // auto 변수

	int(*f2)(int, int) = [](int a, int b) { return a + b; }; // 함수포인터
						// => 우변이 임시객체인데.. 어떻게 함수포인터에 담을수 있나요 ?
						// => 오후에 다루게 됩니다.

	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; }; // function

	// # 특징 1. auto 변수에 다른 람다를 담을수 없지만, f2, f3 에는 담을수 있습니다.
	// f1 : 컴파일러가 만든 클래스 타입!! - 모든 람다는 다른 타입
	// f2 : 함수 포인터 타입
	// f3 : std::function 타입
//	f1 = [](int a, int b) { return a - b; }; // error
	f2 = [](int a, int b) { return a - b; }; // ok
	f3 = [](int a, int b) { return a - b; }; // ok

	// # 특징 2. 
	f1(1, 2);	// f1.operator()(1,2), 즉, 함수 이름으로 직접 호출하는것
				// => 인라인 치환 가능.

	f2(1, 2);	// (*f2)(1,2),   즉, 함수의 주소를 담은 함수 포인터를 통해서 호출하는 것
				// => 인라인 치환 안됨. 

	f3(1, 2);	// f2와 유사한 이유로, 치환 안됨.

	// 결론 : 람다표현식을 변수 담아서 함수 처럼 사용한다면
	//        auto 를 권장합니다.

	// #3. 람다표현식 여러개를 컨테이너(vector)에 보관하고 싶다.
	// => STL 컨테이너는 같은 타입을 여러개 보관합니다.
	// => 람다 표현식은 다른 타입이므로 컨테이너에 보관할수 없지만
	// => std::function 을 보관하는 컨테이너를 만들면 됩니다.

	std::vector < std::function<int(int, int)> >  v;

	v.push_back([](int a, int b) { return a - b; });
	v.push_back([](int a, int b) { return a + b; });
	v.push_back([](int a, int b) { return a * b; });

	// 함수 포인터를 보관하면 안되나요 ?
	// => 가능한데.. std::function 으로 하세요..
	// => 이유는 캡쳐한 람다는 함수 포인터 변환 안됩니다. (오후)
}