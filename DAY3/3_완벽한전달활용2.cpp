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
	// ����Ʈ ������ ����. 
	// 1. ���� ��ü ����
	//    �Ʒ� �ڵ�� ���� �޸𸮸� ��� �Ҵ� �ұ�� ?
	// => new Point ������ 1�� ȣ��
	// => control block �� ����� ���ؼ� 1�� ȣ��(shared_ptr �����ڿ���)
	std::shared_ptr<Point> sp1( new Point(1,2) );
}







