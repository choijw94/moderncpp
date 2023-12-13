#include <iostream>
#include <string>

class Cat
{
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name(n),  age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}

	~Cat() { delete[] name; }




	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "복사" << std::endl;
	}

	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}

	// 복사생성자를 만든 경우, 대부분 대입연산자도 만들어야 합니다.
	Cat& operator=(const Cat& c)
	{
		// 자신과의 대입을 조사 ( a1 = a1 의 경우는 아무일도 할 필요 없다.)
		if (&c == this) return *this;

		age = c.age;

		delete[] name;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}

	// 이동 대입 연산자
	Cat& operator=(Cat&& c)
	{
		if (&c == this) return *this;

		age = c.age;

		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// 객체를 만들때 초기화. 복사 생성자 호출

	c2 = c1;		// 객체를 만든후에 대입. 대입연산자 호출.


	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




