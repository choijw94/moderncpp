void f1(int&  r) {}	// int Ÿ���� lvalue �� ���� ����
void f2(int&& r) {}	// int Ÿ���� rvalue �� ���� ����

int main()
{
	int n = 3;

	f1(3);	// error
	f1(n);	// ok

	f2(3);	// ok
	f2(n);	// error
}

