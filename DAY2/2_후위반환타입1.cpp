// 1_������ȯŸ��1.cpp - ���� 73 page

// C/C++ ���� �������� �Լ��� ���
/*
int square(int a)
{
	return a * a;
}
*/
// C++11 ���� �Լ��� ��ȯ Ÿ���� () �ڿ� ǥ���ϴ� ������ ���Ե˴ϴ�.
// => suffix return type, trailing return type
auto square(int a) -> int
{
	return a * a;
}

int main()
{
	square(3);
}