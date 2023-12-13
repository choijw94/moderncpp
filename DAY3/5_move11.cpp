// 105 page.. 상수 객체와 move
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  {std::cout << "move" << std::endl;	}
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	// move 생성자 호출

	const Object o3;
	Object o4 = std::move(o3);	// copy. 상수 객체는 move 될수 없습니다.
				// => static_cast< o3타입&& >(o3)  입니다.
				// => static_cast< const Object&& >(o3)  이므로
				// 에러는 아니고, 복사 생성자를 호출하게 됩니다.

	// 꼭 기억하세요
	// => 상수 객체는 move 될수 없다.
	// => 왜 중요 한가요 ?? => 내일 !!!
								

}



