// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	// �Ʒ� �ڵ�� ���� �ϱ�� ?
	// ���� T �� "int Ÿ��" �Դϴ�.

	// if : ����ð� ���
	//      ���ǹ��� ������ �ð��� false �� �����Ǿ
	//      �ν��Ͻ�ȭ�� �Լ����� ���Ե˴ϴ�.
//	if (false)
//		*a = 10;

	// if constexpr :  ������ �ð� ���
	//                 ���ǹ��� ������ �ð��� false �� �����Ǹ�
	//				   �ν��Ͻ�ȭ�� �Լ����� ���� �ȵ�.
	//				   C++17

	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(0); 
}

