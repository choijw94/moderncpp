// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);
	// T a = 10;  // �̷��� ������ ���� �Ʒ� �ڵ�� �����մϴ�.
	auto a = 10;  // auto �߷� ��Ģ�� ���ø��� ���� ���� �մϴ�.


	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	//"T a1 = n" �� �ǹ� �̹Ƿ�. ��Ģ 1. ������ ������ �� �����ϸ� �˴ϴ�.
	//							�캯(����)�� const, volatile, reference ��� ����
	auto a1 = n;  // a1 : int a1 = n
	auto a2 = r;  // a2 : int a2 = r
	auto a3 = c;  // a3 : int a3 = c
	auto a4 = cr; // a4 : int a4 = cr


	// auto& �̹Ƿ� T& �� ����. ��Ģ 2. �캯(����)�� reference �� �����ϰ� ����
	auto& a5 = n;  // auto = int		a5 = int&
	auto& a6 = r;  // auto = int		a6 = int&
	auto& a7 = c;  // auto = const int	a7 = const int&
	auto& a8 = cr; // auto = const int  a8 = const int&

	
	int x[3] = { 1,2,3 };

	// x : int[3]
	auto  a11 = x;	// �迭�� �����ϸ� "int a11[3] = x;" �̹Ƿ� ����.
					// �׷���         "int* a11 = x;" �� ����
					// auto = int*     a11 = int*

	auto& a12 = x;  // auto = int[3]   a12 = int(&)[3]
}


