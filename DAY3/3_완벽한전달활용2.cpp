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
	std::shared_ptr<Point> sp1( new Point(1,2) );
}







