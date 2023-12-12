// member field initialization

class Point
{
	// C++11 ���� ��� ����Ÿ�� �ʱⰪ�� ���� ������ �ֽ��ϴ�.
	int x = 0;
	int y = 0;
public:
	Point() {}
	Point(int a) : y(a) {}
};

// �� �ڵ带 ������ �ϸ� �Ʒ� ó�� ����˴ϴ�.
class Point
{
	int x; // = 0;
	int y; // = 0;
public:
	// �� ��� �ʱⰪ�� ���� �����ڸ� �Ʒ� ó�� �����մϴ�.
	Point()      : x(0), y(0) {}
	Point(int a) : x(0), y(a) {} // <== �� �κ��� �ٽ�
};


int main()
{
	Point pt;
}