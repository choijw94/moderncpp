//8_nullptr3
#include <iostream>

int main()
{
	// literal �� Ÿ��
	// => ��� ���ͷ�(���α׷����� ����ϴ� ��)�� Ÿ���� �ֽ��ϴ�.

	3;			// int
	3.4;		// double
	"hello";	// const char[6]
	
	false;		// bool Ÿ��,    false �� ���ͷ��̰�, Ű����

	nullptr;	// std::nullptr_t,      nullptr �� ���ͷ�(��), Ű����.


	// std::nullptr_t Ÿ���� ��� ������ �����ͷ� �Ͻ��� ����ȯ �����մϴ�.
	std::nullptr_t n = nullptr;

	// ���� n �� nullptr ��� ��밡���մϴ�.
	int* p1 = n;
	char* p2 = n;
}



