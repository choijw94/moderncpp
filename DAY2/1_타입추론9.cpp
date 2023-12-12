// decltype ��Ģ 2.
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

	// decltype ��Ģ 1. �ɺ��� �̸��� ������, �ش� ������ ����Ÿ������ ����
	decltype(p)		d1; // int* d1


	// decltype(exp) ��Ģ2. exp �� "�ɺ��̸��� �����ڵ��� ǥ����"�� ���� ������
	//				 exp �� ��ȣ�� ���ʿ� �ü� �ִٸ� "reference" Ÿ��
	//               �׷��� �ʴٸ� "value" Ÿ�� 

	decltype(*p)	d2;		// *p = 10 �� �����ϹǷ�, int& d2, �ʱⰪ ������ error
	decltype(x[0])	d3;		// x[0] = 10  ����		 int& d3, �ʱⰪ ������ error

	decltype(n) d;			// n = 10 �� ����������, �ɺ��� �̸��� �����Ƿ� ��Ģ 1 ����
							// int d

	decltype(n + n) d4;		// n + n = 10 �� ����!   int d4;

	decltype(++n)   d5;		// ++n = 10 �� ���� �ƴ�  int& d5. �ʱⰪ ������ error						
						
	decltype(n++)   d6;		// n++ = 10 �� ����.     int d6			

	++n; // �� �ڵ带 �ڼ��� ������ ���ô�.
		 // operator++(n)

	n++; // operator++(n, int)
}
/*
// operator++ �� primitive Ÿ�Կ� ���ؼ� overloading �Ҽ� ������, ������ ����
// ������ ++
int& operator++(int& a)
{
	a = a + 1;
	return a;
}
int operator++(int& a, int)
{
	int temp = a;
	a = a + 1;
	return temp;
}
*/



// ����
/*
int x = 0;
int  f1() { return x; } // x�� �� 0 ��ȯ
int& f2() { return x; } // x�� �� 0�� �ƴ� ������ ��ȯ

int main()
{
	f1() = 10; // error. 0 = 10 �� �ǹ�.
	f2() = 10; // ok.    x = 10 �� �ǹ�.
}
*/