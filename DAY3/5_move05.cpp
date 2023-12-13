// std::move()소개
#include <iostream>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	// 복사 생성자(copy constructor )
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	// 이동 생성자(move constructor)
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}
};


Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;    // c1 인 lvalue, 복사 생성자 호출 
	Cat c3 = foo();	// 반환된 객체는 임시객체(rvalue), 이동생성자 호출 

	Cat c4 = static_cast<Cat&&>(c2);
					// lvalue 인 c2 를 rvalue 로 캐스팅 했으므로
					// 이동생성자 호출. c2의 자원은 c4로 이동.

	Cat c5 = std::move(c3); // 이 함수의 내부 원리가 위와 같은 캐스팅 입니다.
					// 결국 static_cast<Cat&&>(c3) 와 동일.
					// C++ 창시자는 "std::rvalue_cast" 라는 이름을 원했습니다.
					 
	// std::move(obj)
	// 1. std::move 자체가 자원을 이동하는 것 아닙니다.	
	// 2. 단지, obj 를 rvalue 로 캐스팅하는 역활만 합니다
	// 3. 캐스팅의 결과로 Cat 의 복사 생성자가 아닌, 이동생성자가 호출
	// 4. Cat 의 이동생성자에서 자원을 이동. 

	std::string s1 = "AAAAA";
	std::string s2 = std::move(s1);
					// 이 코드도 결국 std::string 의 이동 생성자가 자원을 이동하는것
	// 즉, move 는 클래스 설계자가 책임져야 합니다.!!!
}

// copy ellision
// => 최적화를 위해 임시객체의 생성을 막고, 복사(이동)생성자의 호출을 제거하는 기술
// => 원래 최적화 기법이었는데, C++17 부터 공식문법으로 채택

// 그래서 일부 예제의 결과가 예상과 달라질수 있습니다.
// => 이경우 g++ 컴파일러를 사용해서 "위 기법을 적용하지 말라" 고 하면 됩니다.
// => visual studio 는 이옵션이 없습니다.

// => g++ 소스이름.cpp -fno-elide-constructors


