int main()
{
	// C++98 �ʱ�ȭ�� ������ �ֽ��ϴ�.
	int  n1 = 3.4;	// ok. ��, ����Ÿ �ս� 
					// C/C++ �� ����������, ��κ� �ٸ� ���� ����

	char c1 = 500;	// ok. ��, overflower �߻� 

	// prevent narrow - 56 page �߰��κ�
	int n2{ 3.4 };  // error. ����Ÿ �ս��� �߻��ϴ� �ʱ�ȭ�� ����!
	char c2{ 500 }; // error. 

}