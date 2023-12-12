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
	decltype(*p)	d2;		// *p = 10
	decltype(x[0])	d3; 

	decltype(n) d; 
					

	decltype(n + n) d4; 
	decltype(++n)   d5; 
						
						
	decltype(n++)   d6; 
			
}

// ����
int x = 0;
int  f1() { return x; } // x�� �� 0 ��ȯ
int& f2() { return x; } // x�� �� 0�� �ƴ� ������ ��ȯ

int main()
{
	f1() = 10; // error. 0 = 10 �� �ǹ�.
	f2() = 10; // ok.    x = 10 �� �ǹ�.
}