// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();

	if (ret == 0)
	{
	}

	// C++17 부터 if 문을 아래 처럼 사용가능합니다.
	if (int ret = foo(); ret == 0)
	{

	}
}