// 8_nullptr - 29page

int main()
{
	// C++98 ����
	int  n1 = 0;
	int* p1 = 0;	// ������ �ʱ�ȭ�� 0 ���.

	// C++11 ����
	int* p2 = 0;		// bad. ���� �ڵ�
	int* p3 = nullptr;	// good. ���� �ڵ�

	int n2 = nullptr; // error. nullptr �� ������ �ʱ�ȭ�� ����.

}