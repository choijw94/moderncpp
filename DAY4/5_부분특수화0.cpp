// 2_typename

struct Test
{
	static int data;
	using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
	// "Ŭ�����̸�::�̸�" ���� "�̸�" �� �ǹ̴� 
	// "��" �ϼ��� �ְ� "Ÿ��" �ϼ��� �ֽ��ϴ�.

//	Test::data  * p;	// data �� ��(static ��� ����Ÿ), * �� ���ϱ� �ǹ�
//	Test::DWORD * p;	// DWORD �� Ÿ��, * �� ������ ���� p �� �����ϴ� �ǹ�.


	// �Ʒ� �ڵ带 ������ ������
	T::data * p1;
	T::DWORD* p2;	
}


int main()
{
	Test t;
	foo(t);
}



