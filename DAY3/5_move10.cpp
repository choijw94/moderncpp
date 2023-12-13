#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// move 계열 함수를 직접 만들게 된다면..
	// 1. 되도록 예외가 없이 만드세요
	//    (대부분 포인터 복사로 구현하게 되므로, 예외 가능성 있는 코드는 사용하지 않게 됩니다)

	// 2. 예외가 없음을 알리기 위해서 noexcept 를 붙이세요 

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사 생성자 호출
	Object o3 = std::move(o1); // 항상 move 생성자 호출

	Object o4 = std::move_if_noexcept(o2);
							// o2 타입의 move 생성자가 
							// 예외가 없다면(noexcept가 있다면) move 생성자 사용
							// 예외 가능성이 있다면			  copy 생성자 사용



	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

