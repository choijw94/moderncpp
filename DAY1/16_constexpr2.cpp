// constexpr �� 3���� �ֽ��ϴ�.
// 1. constexpr ��� - C++11 ( 16_constexpr1-1.cpp ���� )
// 2. constexpr �Լ� - C++11
// 3. constexpr if   - C++17



// constexpr function
// => ������ ���� ������ �ð��� �˼� �ְ�,
// => �Լ��� ȣ��Ǵ� ��ġ��, ������ �ð��� ���� �˾ƾ� �ϴ� ��ġ���
// => �Լ��� ������ ������ �Ҷ� ������ �޶�� ��!

constexpr int Factorial(int n)
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[ Factorial(5) ]; // ok.  ������ �ϸ� "int arr1[120]"

//	int arr2[ Factorial(n) ]; // error. ���ڰ��� ������ �Ҷ� �˼� ����.
							  //       "�迭�� ũ��" �� ������ �Ҷ� �˾ƾ� �Ѵ�.
					

	int s1 = Factorial(n);  // ok. ����ð��� ����

	int s2 = Factorial(5);  // ������ �ð� ? ����ð� ?
							// => �����Ϸ����� �ٸ��� ����. ǥ�ؿ��� �������� ����.

	const int s3 = Factorial(5); // ���� ����

	constexpr int s4 = Factorial(5);	// ������ �ð�!!
										// constexpr ����� ������ �ð��� ���� �˾ƾ� �Ѵ�.
}