int main()
{
	int n1 = 0;

	// auto : �캯�� ǥ������ ������ �º��� Ÿ���� ����
	auto a1 = 3;		// int a1 = 3
	auto a2 = 3.4;

	// auto�� �������� ����� ������ ���� �ֽ��ϴ�.
	const int c = 10;
	auto a3 = c; // 1. const int a3 = c;
				 // 2. int a3 = c;			// <== ����. 
}



