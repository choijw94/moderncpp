#include <iostream>
#include <type_traits>

#define VALUE_CATEGORY( ... )										\
	if (std::is_lvalue_reference_v< decltype( ( __VA_ARGS__ ) ) >)	\
		std::cout << "lvalue" << std::endl;							\
	else                                                            \
		std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;

	VALUE_CATEGORY(n);
	VALUE_CATEGORY(n+1);
	VALUE_CATEGORY(n = 10);
	VALUE_CATEGORY(++n);
	VALUE_CATEGORY(n--);
	VALUE_CATEGORY(10);
}