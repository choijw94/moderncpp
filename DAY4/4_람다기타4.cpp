#include <iostream>

// 람다 표현식은 함수 포인터에 담을수 있습니다
// ==> 원리를 생각해 봅시다.
class ClosureType
{
public:
	inline int operator()(int a, int b) const { return a + b; }


	// static 멤버 함수는 객체없이 호출되므로 일반함수와 유사한 성격입니다.
	// => 함수 포인터로의 변환을 위해서 operator() 와 동일한 일을 수행하는
	//    static 멤버 함수를 제공
	static int helper(int a, int b) { return a + b; }

	
	// 함수 포인터로의 변환을 위해서 변환연산자 추가됩니다.
	using PF = int(*)(int, int);

//	operator PF() { return &ClosureType::operator(); } 
							// => error
							// => 일반 함수 포인터에 멤버 함수의주소를 넣을수 없습니다

	operator PF() { return &ClosureType::helper; }
};




int main()
{	
//	int(*f)(int, int) = [](int a, int b) {return a + b; }

	int(*f)(int, int) = ClosureType();
						// 객체.operator 함수포인터타입();

	int n = f(1, 2);

	std::cout << n << std::endl; // 3
}












