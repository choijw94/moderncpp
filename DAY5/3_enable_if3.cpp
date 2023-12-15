#include <iostream>
#include <type_traits>

// enable_if ��� ����
// 
// std::enable_if<����, "Ÿ��">::type �� ���� �����
//                ������ ���̸�   : "Ÿ��"
//                ������ �����̸� : "::type" ��ü�� ����!


// std::enable_if< std::is_integral_v<T>, T>::type
//							T �� �������, �������(����Ÿ��)�� T
//							T �� ������ �ƴϸ� "::type" ����, �Լ� ���� ����
//									SFINAE ��Ģ�� ���� ������ �ƴ� �ĺ����� ����

// static_assert				: ������ �������� ������ ������ ����
// enable_if �� ����� ��ȯ Ÿ�� : ������ �������� ������ ������� �ʰڴ�
//								  ������ �̸��� �ٸ� �Լ��� �ִٸ� ��밡��


// �Ʒ� ���� Ÿ���� �ڵ尡 �ٽ��Դϴ�.
template<typename T> 

//typename std::enable_if< std::is_integral_v<T>, T>::type
std::enable_if_t< std::is_integral_v<T>, T>
				
gcd(T a, T b)
{
	return 0;
}

void gcd(double a, double b) { std::cout << "double\n"; }

int main()
{
	gcd(6, 9);		
	gcd(3.1, 5.4); 
	gcd(3.1f, 5.4f); 
}