#include <iostream>

// template Ÿ�� �߷� ��Ģ 1. ������ Ÿ���� "��(value)" �϶�
// => ���ڰ� ������ �ִ� "const, volatile, reference" �� �Ӽ��� �����Ŀ� Ÿ�԰���
template<typename T> void foo(T a)
{
//	a = 100;
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);		// T = int 
	foo(c);		// T = int
	foo(r);     // T = int
	foo(cr);    // T = int

	// ���� : ���ڰ� ���� const �Ӽ��� ���ŵ˴ϴ�.
	const char* s1 = "hello";	

	foo(s1); // s1 ��ü�� const �� �ƴմϴ�. s1�� ����Ű�� ���� const 
			 // ������ const �� ���� �ǹǷ� 
			 //	T = const char*


	const char* const s2 = "hello";
	foo(s2); // s2 ��ü�� const, ����Ű�� ���� const
			 // s2 : const char* const
			 // T  : const char* 

}