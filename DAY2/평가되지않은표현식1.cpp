// �򰡵�������ǥ����1.cpp

int add(int a, int b) { return a + b; }

int main()
{
	// #1. expression(ǥ����) : �Ѱ��� ������ �����Ǵ� �ڵ� ����
	int n = 10;
	
	n * 2 + 3;
	add(1, 2);

	// #2. decltype() �� () �ȿ��� expression �� ����� �մϴ�.
//	decltype(int) d;  // error. int ��� Ÿ���� �ƴ� expression �� �־�� �մϴ�.


	// #3. decltype(exp) : exp �� �����ϴ� ����  Ÿ���� �����ϴ� ��
	// => �̶� exp �� ���� "��(����)������ �ʽ��ϴ�."
	// => �򰡵��� ���� ǥ����(unevaluated expression) �̶�� �մϴ�.
	decltype( add(1, 2) ) ret = add(1, 2);

	// C++���� �򰡵��� ���� ǥ������ 4���� �ֽ��ϴ�.
	decltype(add(1, 2)) d; 
	
	int n = sizeof(add(1, 2));

	bool b = noexcept(add(1, 2));

	const std::type_info& t = typeid(add(1, 2));

}
