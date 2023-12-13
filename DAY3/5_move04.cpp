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

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// 핵심 : 임시객체(rvalue) 인 경우를 위한 복사 생성자를 
	//        추가로 제공하자(자원의 복사가 아닌 자원의 이동)
	//        => 즉, 최적화된 구현을 위해서
	// 
	// const Cat& : lvalue, rvalue 를 모두 받을수 있지만
	// Cat&& 버전이 있다면 rvalue 는 Cat&& 버전을 사용하게 된다.

	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		// 이제 인자로 전달된 객체(c, 임시객체)의 name 포인터를 0으로
		// => 자원 포기
		c.name = nullptr;

		// 위 코드가 실행되려면 
		// => 임시객체를 상수가 아닌 참조로 받을수 있어야 합니다.	
	}

};



Cat foo()
{
	Cat c("yaong", 3);
	return c;
}


int main()
{
	Cat c1 = foo(); // 이 한줄에 대해서 
					// 생각해 보세요. 
}