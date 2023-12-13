#include <iostream>
#include <vector>
#include <string>
// #1. move �迭������ ����� std::move �� �Űܶ�!

template<typename T>
class Object
{
	std::string name;
	int age;
	T data;
public:
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj) : name(obj.name) {  }

	// 1. ���ܰ� ������ �˸��� ���� noexcept
	// f() noexcept			: ���� ����.
	// f() noexcept(true)	: ���� ����.
	// f() noexcept(false)  : ���ܰ� ������ �ִ�.

	// 2. ���ܰ� �ִ��� �����ϱ� ���� noexcept
	// bool b = noexcept(exp)


	Object(Object&& obj) noexcept (    noexcept(data(std::move(obj.data)))      )
//		: name(obj.name)				// ���� �ڵ� �Դϴ�. std::string �� ���� ������ ȣ��
		: name( std::move(obj.name) ),	// ���� �ڵ�. string �� move ������ ȣ��
		  age(obj.age),			// ���� ���� ����
		  data( std::move(obj.data) )		// ????

	{
	}
};


int main()
{

}

