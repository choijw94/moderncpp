#include <iostream>
#include <vector>
#include <algorithm>

// �Լ���ü�� ���� 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// �־��� �������� "3�� ���"�� ã�� �ʹ�. 
	auto p1 = std::find_if(v.begin(), v.end(), foo);
					// => find_if �� 3��° ���ڴ� "�����Լ�" �̾�� �մϴ�.


	int k = 0;
	std::cin >> k;

	// �־��� �������� "k�� ���"�� ã�� �ʹ�. 
	// => ? �� �� �Լ��� ��� ������ �ұ�� ?
	// => ���� �ִ� foo ���� 3 ��� "k" �� ����ϰ� �Ҽ� ������� ?
	//    �Ϲ� �Լ��δ� ���� �ʽ��ϴ�.
	//    �Լ� ��ü�� ���� �Ҽ� �ֽ��ϴ�.
	auto p2 = std::find_if(v.begin(), v.end(), ?);
				

}



