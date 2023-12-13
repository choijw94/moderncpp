#include <iostream>
#include <vector>
#include <string>

class Object
{
	std::string name;
public:
	Object(const std::string& n) : name(n) {}

	Object(const Object& obj) : name(obj.name) { std::cout << "copy" << std::endl; }

	Object(Object&& obj) noexcept 
		: name(obj.name)
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{

}

