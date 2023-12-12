// 91 page
int main()
{
	int n = 10;

	// #1. �����ʹ� "���� ������" �� ����� �ֽ��ϴ�. �������� ������
	int *p = &n;
	int* *pp = &p;

	// #2. ���۷����� ���۷����� ������� �����ϴ�.
	int& r = n;
//	int& &rr = r; // error


	// #3. Ÿ�� �߷�, �Ǵ� using ���ô� �߻��ϴ� 
	//     ���۷����� ���۷����� �Ʒ� ��Ģ���� ��� �˴ϴ�.
	using LREF = int&; 
	using RREF = int&&;

	// reference collapsing ��Ģ. 
	LREF& r3 = n;   // int&  &   => int&
	RREF& r4 = n;   // int&& &	 => int&
	LREF&& r5 = n;  // int&  &&  => int&
	RREF&& r6 = 10; // int&& &&  => int&&


	// �Ʒ� foo �� ������ ������
	foo<int&>(n);

	int x[3] = { 1,2,3 };

	decltype(x[0])& r;  // int& & r;
						// int& r; �ε�, �ʱⰪ ������ ����. 
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a;
				// int& r = a;
}






