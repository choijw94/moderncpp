int main()
{
	int n = 3;

	// ������ ������ ��� ������!
	auto& a1 = n;	// ok
	auto& a2 = 3;	// error.   3 �� rvalue

	// auto �� T �� ��Ģ�� �����մϴ�.
	// ���� auto&& �� T&& �Դϴ�
	// auto&& �� rvalue reference �ƴմϴ�. forwarding reference
	// => ���� �Ʒ� �ڵ�� ��� ���� �ƴմϴ�.

	auto&& a3 = n;	// n �� lvalue, auto(T)=int&, auto&&=int& &&.  int&  a3 = n;
	auto&& a4 = 3;  // 3 �� rvalue  auto(T)=int   auto&&=int&&     int&& a4 = 3;
}