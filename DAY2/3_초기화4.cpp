// 58 page
class Vector
{
	int sz;
public:
	Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// #1. ���ڰ� �Ѱ��� �����ڰ� ������ �Ʒ��� ǥ����� �����մϴ�.
	Vector v1(10);		// C++98, direct initialization
	Vector v2 = 10;		// C++98, copy   initialization

	Vector v3{ 10 };	// C++11, direct initialization
	Vector v4 = { 10 };	// C++11, copy   initialization

	//----------------
	// #2. �Ʒ� �ڵ带 ������ ������.
	foo(10);	// �Լ��� ���� ������ "���� �ʱ�ȭ" �Դϴ�.
				// "Vector v = 10" �� �ǹ�!!
}







