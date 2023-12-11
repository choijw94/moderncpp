#include <cassert>

// assert        : ����ð� ǥ������ ��ȿ���� Ȯ���ϴ� ����, C/C++
// static_assert : ������ �ð��� ��ȿ���� Ȯ��.
//					ǥ������ �����̸� ������ ���߰� �޼��� ���.
// 
// static_assert(exp) : exp �� �ݵ�� ������ �ð��� Ȯ�� �����ؾ� �Ѵ�.
//						"age > 0" �Ͱ��� ���� Ȯ���� �ȵ�.
// => �Լ� �ȶǴ� �ۿ� ����� �ֽ��ϴ�.

static_assert(sizeof(int*) >= 8, "error, not 64bit");


void foo(int age)
{
	// �Լ� ���ڸ� ����ϱ� ���� ��ȿ���� Ȯ���ϴ� ���� �����ϴ�.
	assert(age > 0);

	int* p = new int[age];

	delete[] p;
}

int main()
{
	foo(10);
//	foo(-10); // �Ǽ��ߴ�.!!
}