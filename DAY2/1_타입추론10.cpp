int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// #1. auto vs decltype
//	auto a = x[0];		// int a = x[0]
//	decltype(x[0]) d;	// int& d;     �ʱⰪ �����Ƿ� error. 

	// #2.
	auto ret1 = foo();	// foo() ��ȯ Ÿ���� reference ���� auto ��Ģ�� ����
						// int ret1 = foo();

	// decltype(�Լ� ȣ���) : �Լ� ȣ���� ����� ������ Ÿ��. ��ȯ Ÿ��
	//						  �Լ� ������ ���� ����.
	decltype(foo()) ret2 = foo();	// int& ret2 = foo()


	// #3. decltype(auto) : C++14 ���� ����
	// => auto �ڸ��� �캯�� ���� �޶�!
	// => �캯���� Ÿ���� �߷��ϴµ�, ��Ģ�� decltype ���� �ش޶�
	decltype(auto) ret3 = foo();
	
	// ret1 �� int ����, ret2, ret3 �� int& �̹Ƿ� x�� ����

	
	
}

