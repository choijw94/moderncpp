// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization
// => �����ڰ� ���� {} �� �ʱ�ȭ �ϴ� ��

// aggregate type
// => �����ڰ� ���� {} �� �ʱ�ȭ �����Ѱ�
// => �迭, ����ü, ����ü, 

struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	void print() {} // ��� �Լ��� �־ aggregate type

//	virtual void foo() {} // �����Լ��� ������ aggregate type �ƴ�.

//	Point() {}	// �����ڰ� ������ aggregate type �ƴ�.

	Point() = default; // �̷��� �ϸ� aggregate type!!
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };
}