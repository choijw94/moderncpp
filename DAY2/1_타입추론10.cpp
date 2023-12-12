int x = 10;
int& foo() { return x;  }

int main()
{
	int x[3] = { 1,2,3 };

	// #1. auto vs decltype
//	auto a = x[0];		// int a = x[0]
//	decltype(x[0]) d;	// int& d;     초기값 없으므로 error. 

	// #2.
	auto ret1 = foo();
	decltype(foo()) ret2 = foo();
}

