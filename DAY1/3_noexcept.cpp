// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept Ű����(C++11)�� 2���� �뵵�� ���˴ϴ�.
// 1. ǥ������ ���ܰ� �ִ��� ���� �Ҷ�
//	  => bool b = noexcept( expression )
//    => �Լ��� ���� ��ü�� �����ϴ� ���� �ƴ϶�,
//       �Լ��� ���� noexcept �� ǥ��Ǿ� �ִ��� Ȯ���ϴ� ��
// 
// 2. �Լ��� ���ܰ� ����(����)�� �˸���

void foo()			// ���� ���ɼ��� �ִ� �Լ�
{
}
void goo() noexcept	// ���� ���ɼ��� ���� �Լ�
{
}

int main()
{
	bool b1 = noexcept( foo() ); 
	bool b2 = noexcept( goo() );

	std::cout << b1 << ", " << b2 << std::endl;
}
// ��?? ���ܰ� ���ٰ� �˷��� �ϳ��� ??
// => ������ noexcept Ű���常 �˾Ƶμ���
// => ���� move ��ﶧ Ȱ��˴ϴ�.




