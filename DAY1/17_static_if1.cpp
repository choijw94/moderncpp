/*
// �Ʒ� �ڵ尡 �� �������� ������ ������ ?
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;	// error. data �� int Ÿ���̹Ƿ� * ���� �Ҽ� ����.
	}
};
int main()
{
	A a;
}
*/

template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;
	}
};

int main()
{
	A<int> a;

	// ������ �ν��Ͻ�ȭ
	// => Ŭ���� ���ø��� ��� �Լ��� ���� ��� �Լ��� �ν��Ͻ�ȭ�� ���Ե˴ϴ�.
	// => �Ʒ� foo ó�� ����Ѱ͸�, ���� Ŭ������ ����� �����˴ϴ�.
	a.foo();
}