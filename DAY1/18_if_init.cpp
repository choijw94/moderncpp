// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}

	// C++17 ���� if ���� �Ʒ� ó�� ��밡���մϴ�.
	// if ( �ʱ�ȭ�ڵ�; ���ǽ� )
	if (int ret = foo(); ret == 0)
	{

	}	// <== ret �ı�

	
	// switch �� �����մϴ�.
	switch (int n = foo(); n)
	{
	case 1: break;
	case 2: break;
	}

	// while ���� �ɱ�� ?
	// => �ȵ˴ϴ�.
	// => ���� �ʿ䰡 �������ϴ�. (for �� ����ϸ� �ǹǷ�)
	/*
	while (int cnt = 0; cnt < 10)
	{
		++cnt;
	}
	for (int cnt = 0; cnt < 10; ++cnt)
	{
	}
	*/
}