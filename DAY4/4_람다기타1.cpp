// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo()	// void foo( Test* this) 
	{
		// ���� ǥ���Ŀ��� ��� ����Ÿ�� �����ϰ� �ʹ�.
//		auto f = [](int a) { return a + data; }; // error
//		auto f = [data](int a) { return a + data; }; // error. data �� ���������ƴ�

		// ����ǥ���Ŀ��� ��� ����Ÿ �����Ϸ��� this �� ĸ���ϸ� �˴ϴ�.
		auto f = [this](int a) { return a + data; }; // ok

	}
};

int main()
{
	Test t;
	t.foo(); // foo(&t)
}

