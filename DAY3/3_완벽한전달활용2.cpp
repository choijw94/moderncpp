#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
	~Point() { }
	Point(const Point&) {  }
};
void* operator new(std::size_t sz)
{
	printf("new : %d\n", sz);
	return malloc(sz);
}
int main()
{
	// 스마트 포인터 사용시. 
	// 1. 직접 객체 생성
	//    아래 코드는 동적 메모리를 몇번 할당 할까요 ?
	// => new Point 때문에 1번 호출
	// => control block 을 만들기 위해서 1번 호출(shared_ptr 생성자에서)
//	std::shared_ptr<Point> sp1( new Point(1,2) );


	// 2. std::make_shared
	// => Point 객체와 control block 을 붙여서 한번에 할당하면
	//    메모리 효율이 좋아 집니다.
	// => 그렇게 하려면 사용자가 "new Point" 하면 안되고..
	//    라이브러리 내부에서 "sizeof(Point) + sizeof(control block)" 을 
	//    한번에 할당해야 합니다.

	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);
								// => sizeof(Point) + sizeof(control block) 
								//    를 한번에 할당
								// => 해당 메모리를 관리하는 std::shared_ptr 생성후
								//	  반환
}







