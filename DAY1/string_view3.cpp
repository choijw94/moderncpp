#include <string>
#include <string_view>
#include <iostream>

void* operator new(std::size_t size)
{
	printf("operator new : %d\n", size);

	return malloc(size);
}

void f2(const std::string& s) {}

void f3(std::string_view sv) {}


int main()
{
	f2("to be or not to be");	// �ӽð�ü�� �����ϰ�, ���ڿ��� ���� �����ϱ� ����
								// new �� ����ϰ� �˴ϴ�.
				

//	f3("to be or not to be");	// �ӽð�ü �������� �������� ����. new ������.
}
