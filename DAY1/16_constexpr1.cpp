// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// ������ ������ ��� ��������
	int arr1[10]; // ok
	int arr2[n ]; // error. (��, g++�� ����. �Ʒ� �ּ� ����)
	int arr3[c1]; // ok			������ �ð� ���, �����Ϸ��� c1 �� �ʱⰪ�� �˰� �ִ�
	int arr4[c2]; // error		����ð� ���,    �����Ϸ��� c2 �� �ʱⰪ�� �˼� ����.

	// const �ǹ� : "���� �����Ҽ� ����" �� �ǹ�
	//				�ʱⰪ�� ������ �ð��� �˼��� �ְ�,
	//						������ �ð��� �˼� �������� �ִ�.
	// C#, RUST ���� �ٸ� ���� "���" �� �ƴ� "immutable", "readonly"
	// ������ �θ��ϴ�.

	// C#, swift, rust ������
	// read only, immutable : ���� �����Ҽ� ����.
	// constant             : ������ �Ҷ� ���� �˼� �ִ�.
}



// ���� : �迭�� ũ��
// C89 : �迭�� ũ��� ������ �ð��� �˾ƾ� �մϴ�. ���� ���ȵ�
// C99 : �迭�� ũ��� ���� ��밡��. 
//       (g++ ����, visual studio ��������)