// 9_enum - 32 page

// C/C++ �� enum ����

enum COLOR { red = 1, green = 2};

int main()   
{
	int c1 = COLOR::red;

	// #1. enum ���� 1. COLOR ������ ȥ���� �ʷ� �մϴ�.
	int c2 = red; // ok. COLOR �� ���� ����.

	int red = 0;
	int c3 = red; // ��������, red. 
				  // ������ COLOR::red �� ���� �̸��̹Ƿ� �������� ���� �ʽ��ϴ�.

	// #2. int �� �Ͻ��� ��ȯ�� ������ �ڵ�..
	int c4 = COLOR::red;
	c4 = 100;	// OK.. ������ ������ ������ ��� �ڵ�
}





