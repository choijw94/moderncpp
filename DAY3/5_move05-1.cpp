#include <iostream>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

// 템플릿 만들때 인자를 T& 로 할지 T&& 로 할지 잘 판단하세요 
// T&  : 인자로 lvalue 만 받겠다는 의도
// T&& : 인자로 lvalue, rvaue 를 모두 받겠다는 의도

// move : 인자로 lvalue, rvalue 를 모두 받아서 rvalue 로 캐스팅

template<typename T>
T&& mymove(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = mymove( o2 );		// move 만들어 봅시다. 

	Object o5 = mymove( Object() ); // 되야 할까요 ? 안되야 할까요 ?
}