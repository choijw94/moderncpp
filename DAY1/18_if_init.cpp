// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}

	// C++17 부터 if 문을 아래 처럼 사용가능합니다.
	// if ( 초기화코드; 조건식 )
	if (int ret = foo(); ret == 0)
	{

	}	// <== ret 파괴

	
	// switch 도 가능합니다.
	switch (int n = foo(); n)
	{
	case 1: break;
	case 2: break;
	}

	// while 문도 될까요 ?
	// => 안됩니다.
	// => 만들 필요가 없었습니다. (for 문 사용하면 되므로)
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