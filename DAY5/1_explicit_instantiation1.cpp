// �Ʒ� �ڵ带 godbolt.org �� �־� ������

// template instantiation ( ���ø� �ν��Ͻ�ȭ )
// => ���ø����� ���� ���� �Լ�(Ŭ����) �� ����� ����

// implicit instantiation : ���� ���ø��� ����ϴ� �ڵ带 ���� �ν��Ͻ�ȭ(B)
// explicit instantiation : ����ϴ� �ڵ尡 ��� ��������� �ν��Ͻ�ȭ �ش޶�� ��û(A)

template<typename T>
T square(T a)
{
	return a * a;
}

//template double square(double);  // A

int main()
{
//	square(3);		// B
}