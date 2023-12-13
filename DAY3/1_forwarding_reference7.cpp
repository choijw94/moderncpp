struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// lvalue �� rvalue �� ��� ������ �ִ� �Լ� �����. 

// ��� 1. call by value
// Ư¡ : ���纻�� ����� �˴ϴ�.
//void foo(Point pt) {}


// ��� 2. call by const lvalue reference
// Ư¡ 1. ���纻 ���� �ȵ�
//      2. �����(immutable)�� �߰��ؼ� �ް� �ȴ�. ��ü�� ���� ������ �Ҽ� ����.!
// void foo(const Point& pt) {}

//==========���� ������ C++98 ����� �Ҽ� �ִ� ��� �� ===========================
//==========�Ʒ� ����� C++11 ���� ���               ===========================

// ��� 3. lvalue/rvalue reference ������ ���� ����
// Ư¡ 1. ���纻 ���� �ȵ�
//      2. ������� �߰����� �ʰ�, ���� �״�� �޴� ��!
// void foo(Point&  pt) {}
// void foo(Point&& pt) {}


// ��� 4. forwarding reference
// => T&& �� ����ϸ� ���� 2�� �Լ��� �ڵ������Ҽ� �ִ�.
// => �ᱹ �Ʒ� �ڵ�� ���� 2�� �Լ��� �ڵ�����
// => ��, Point �� �ƴ϶� ��� Ÿ�Կ� ���� ��밡��. 
template<typename T>
void foo(T&& pt)
{
}



int main()
{
	Point pt(0, 0);

	// foo �Լ��� lvalue �� rvalue(�ӽð�ü)�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point(0,0));
}
