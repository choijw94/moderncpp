#include <iostream>
#include <type_traits>

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
std::remove_reference_t<T>&& mymove(T&& obj)
{
	// 핵심 : 아래 코드는 rvalue casting 이 아닙니다
	// mymove 인자로 rvalue 를 보냈으면 "rvalue 캐스팅"
	//              lvalue 를 보냈으면 "lvalue 캐스팅"
	// 
	// static_cast<T&&>(obj); // 즉, 이코드는 std::forward<T>(obj) 입니다.
	// 

	// 해결책
	// move 는 항상 rvalue 로 캐스팅 되어야 합니다.
	// T 안에 있는 모든 참조를 제거하고 && 를 붙여서 캐스팅 하면 됩니다.
	// std::remove_reference_t<T> : T 안에 있는 모든 참조를 제거한 타입 구하기

	return static_cast<std::remove_reference_t<T> &&>(obj);
						// => 위 코드는 항상 rvalue 캐스팅입니다.
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = mymove( o2 );		// move 만들어 봅시다. 

	Object o5 = mymove( Object() ); // 되야 할까요 ? 안되야 할까요 ?
}