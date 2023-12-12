#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;

	n + 5 = 20; // error. "n + 5" �� rvalue  


	// lvalue, ravlue �� �����Ϸ���
	// => decltype �� ��Ģ�� �߻����� ������
	using T = decltype(n + 5);	
				// n+5 �� lvalue ��� T �� ���� Ÿ��
				//        rvalue ��� T �� �� Ÿ��

	if (std::is_lvalue_reference_v<T>)
		std::cout << "lvalue" << std::endl;
	else 
		std::cout << "rvalue" << std::endl;
}