#include <string>
#include <iostream>

int main()
{
	// std::move : ���� rvalue �� ĳ���� �� ���Դϴ�.
	//			   �̵������ڰ� �ִ� Ÿ�Ը� ȿ���� �ֽ��ϴ�

	// #1
	std::string s1 = "aaaaaa";
	std::string s2 = std::move(s1);
					// => std::string �� move �����ڰ� �����˴ϴ�.
					// => �ڿ� �̵��˴ϴ�.

	// #2.
	int n1 = 10;
	int n2 = std::move(n1);	// �̷��� �ϸ� n1 �� 0�� �ǳ��� ?
							// move ȿ�� �����ϴ�.
							// int n2 = n1 �� ����

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 10

	// #3.
	int* p1 = new int;
	int* p2 = std::move(p1);	// �� �ڵ��
//	int* p2 = p1;				// �� �ڵ�� �����մϴ�.

	printf("%p\n", p1); // 0 �� �ƴմϴ�. 


	// #4. swap �� ���ؼ�
	std::string s3 = "aaa";
	std::string s4 = "cccc";

	std::swap(s3, s4); // C++98 : ���� �����ڸ� ����� swap �Դϴ�.
					   //         ���� ��ü�� �����ϹǷ� �����ϴ�.
						// C++11 ���� : move �����ڸ� ����� swap
						//			    �Ʒ��� ���� ��� �Լ� swap(������ swap) ��
						//				���� ���� �մϴ�.

	s3.swap(s4); // s3 �� ���� �ּҿ� s4 �� ���� �ּҸ� swap. pointer swap 
}