
// �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// ����Ʈ �����ڰ� ���� Ÿ���� ��� �� �ִ� ���
class Rect
{
	Point pt; // ?
public:
	Rect() {}
	// ����� �ڵ�		// �����Ϸ��� �����ϴ� �ڵ�
//	Rect() {}			// Rect() : pt() {}		// <= pt���� ����Ʈ �����ھ��� 

	// C++98 ���� �ذ�å - Rect �ʱ�ȭ ����Ʈ���� pt �� �ٸ� ������ ȣ��!
//	Rect() : pt(0, 0) {}
};

// C++11 �ذ�å
class Rect2
{
	Point pt{ 0, 0 }; // ok
	//	Point pt( 0, 0 ); // error. �� ��ġ������ () ��� {}�� �ϼ���
public:
};



int main()
{
	Rect r1;
}

