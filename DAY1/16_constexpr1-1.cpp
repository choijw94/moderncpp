// 16_constexpr1-1

int main()
{
	int n = 10;

	// const : read only(immutable)�� ����� ��
	const int c1 = 10; // ok.  literal �� �ʱ�ȭ �ص��ǰ�
	const int c2 = n;  // ok.  ������ �ʱ�ȭ�� ����


	// C++11 constexpr : ������ �ð��� ���� �˼��ִ� ����� ����� ��
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error.


	// C++ ���� ����� "constant expression" �� �ֽ��ϴ�.
	// => ������ �ð��� ���� �˼� �ִ� ǥ����(expression)
}