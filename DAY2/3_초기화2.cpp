#include <complex>

int main()
{
	// C++98 ����
	// => ��ü�� ������ ���� �ʱ�ȭ ����� �ٸ�.
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// C++11. "�ϰ��� �ʱ�ȭ(uniform initialization)" ����
	// => ��� ������ ��ü�� �Ѱ��� �ϰ��� ������� �ʱ�ȭ �Ҽ� �ִ�.
	// => "�߰�ȣ �ʱ�ȭ(brace initialization)" �̶�� �մϴ�.

	int n2 = { 10 };
	int x2[2] = { 1,2 };
	std::complex<double> c2 = { 1, 2 };
}












