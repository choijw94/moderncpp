#include <iostream>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

int main()
{
	Object o1;
	Object o2 = o1;
	Object o3 = std::move(o1);
	Object o4 = mymove(o1);		// 만들어 봅시다.
}