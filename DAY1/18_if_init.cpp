// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}

	// C++17 ���� if ���� �Ʒ� ó�� ��밡���մϴ�.
	if (int ret = foo(); ret == 0)
	{

	}
}