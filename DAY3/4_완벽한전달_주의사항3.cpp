// 9_�Ϻ�������_���ǻ���3

// forwarding reference �̾߱�

template<typename T> class Test
{
public:
	// �Ʒ� �Լ��� ���ڰ� "forwarding reference" �ϱ�� ?
	// => �ƴմϴ�.
	// => forwarding reference �� �Ƿ��� "�Լ� ��ü�� template" �̾�� �մϴ�
	// => foo �� "Ŭ���� ���ø�(Test) �� �Ϲ� ��� �Լ�(�Լ����ø��� �ƴ�)" �Դϴ�.
	void foo(T&& arg)
	{
	}

	// forwarding reference �� �Ƿ��� �Ʒ� ó�� ��� �Լ� ��ü�� ���ø� �̾�� �մϴ�.
	template<typename U>
	void goo(U&& arg)
	{
	}

};
int main()
{
	int n = 0;
	Test<int> t;	// �̼��� T=int �� �����Ǿ Ŭ������ �����˴ϴ�.
					// void foo(int&& arg) �� �����Ǿ����ϴ�.
					// ��, foo ��ü�� �Լ� ���ø��� �ƴմϴ�.
	
	// �Ʒ� �ڵ带 �����غ�����. ������ ������� ?
	t.foo(n);	// error
	t.foo(10);	// ok

	t.goo(n);	// ok
	t.goo(10);	// ok
}

