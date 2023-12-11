
// C++98 enum : unscoped enum
// enum COLOR { red = 1, green = 2 };

// C++11 enum : scoped enum
enum class COLOR { red = 1, green = 2 };

int main()
{
//	int c1 = red;	      // error. COLOR �����Ҽ� ����.
//	int c1 = COLOR::red;  // error. int �� �Ͻ��� ��ȯ �ȵ�

	COLOR c1 = COLOR::red;  // ok. �̷��Ը� ��밡��.
							// ���� ������ ��Ģ��θ� ��밡��
							// ���׸� ���ϼ� �ִ�.
}





