// 6_enable_if1.cpp
// �Ʒ� �ڵ�(enable_if) �� �̹� C++11 ǥ�ؿ� �ֽ��ϴ�. �Ʒ� �ڵ�� ���� ������ �������
template<bool, typename T = void > struct enable_if
{
	using type = T;
};

template<typename T> struct enable_if<false, T> 
{
	// �ٽ� : type ����� ����!!
};

// enable_if ���� : enable_if<bool��, Ÿ��>
// �ٽ� : 1��° ���ڰ� false �� ��� �κ� Ư��ȭ ���� ����

int main()
{
	// �Ʒ� �ڵ忡�� �� ������ Ÿ���� ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 �ε�, void �� ������ ����� �����Ƿ� error
	enable_if<false, int>::type n3; // "::type" �� �����Ƿ� error

	// enable_if �� ����Ұ�
	// 1. enable_if<false, "Ÿ��">::type  �� ����.. "type" �� ����.
	// 2. enable_if<true,  "Ÿ��">::type  �� ����� ������ Ÿ���� "Ÿ��"
	// 3. enable_if<true>::type           �� ����� ������ Ÿ���� "void"
}