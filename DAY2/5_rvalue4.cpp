#include <iostream>
#include <type_traits>

// __VA_ARGS__ 
// => C ��� ǥ�� ���� �Դϴ�.
// => naver ���� "C ���� ���� ��ũ��" �˻��ϸ� �ڷ� ���� �ֽ��ϴ�.


#define VALUE_CATEGORY( ... )										\
	if (std::is_lvalue_reference_v< decltype( ( __VA_ARGS__ ) ) >)	\
		std::cout << "lvalue" << std::endl;							\
	else                                                            \
		std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;

	VALUE_CATEGORY(n);		// l
	VALUE_CATEGORY(n+1);	// r
	VALUE_CATEGORY(n = 10);	// l
	VALUE_CATEGORY(++n);	// l
	VALUE_CATEGORY(n--);	// r
	VALUE_CATEGORY(10);		// r

	VALUE_CATEGORY("hello"); // ?? lvalue ? rvalue
							// ����Ե� lvalue �Դϴ�.
							// ����, �Ǽ� ���ͷ� : rvalue	
							// ���ڿ� ���ͷ�     : lvalue 

	"hello"[0] = 'x';	// error. rvalue �� ������ �ƴ϶�
						// const �� ���� �Դϴ�.
}