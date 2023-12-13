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
//	std::shared_ptr<Point> sp1( new Point(1,2) );


	// 2. std::make_shared
	// => Point ��ü�� control block �� �ٿ��� �ѹ��� �Ҵ��ϸ�
	//    �޸� ȿ���� ���� ���ϴ�.
	// => �׷��� �Ϸ��� ����ڰ� "new Point" �ϸ� �ȵǰ�..
	//    ���̺귯�� ���ο��� "sizeof(Point) + sizeof(control block)" �� 
	//    �ѹ��� �Ҵ��ؾ� �մϴ�.

	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);
								// => sizeof(Point) + sizeof(control block) 
								//    �� �ѹ��� �Ҵ�
								// => �ش� �޸𸮸� �����ϴ� std::shared_ptr ������
								//	  ��ȯ
}







