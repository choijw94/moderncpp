#include <iostream>
#include <vector>
#include <string>
// #1. move �迭������ ����� std::move �� �Űܶ�!

class Object
{
	std::string name;
public:
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj) : name(obj.name) {  }

	Object(Object&& obj) noexcept 
//		: name(obj.name)				// ���� �ڵ� �Դϴ�. std::string �� ���� ������ ȣ��
		: name( std::move(obj.name) )	// ���� �ڵ�. string �� move ������ ȣ��
	{
	}
};


int main()
{

}

