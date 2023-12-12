void f1(int&  r) {}	// int 타입의 lvalue 만 전달 가능
void f2(int&& r) {}	// int 타입의 rvalue 만 전달 가능

int main()
{
	int n = 3;

	f1(3);	// error
	f1(n);	// ok

	f2(3);	// ok
	f2(n);	// error
}

