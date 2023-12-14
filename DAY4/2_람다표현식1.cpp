// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional> // std::less<>, std::greater<> �� �̹� �ֽ��ϴ�.(C++98)
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort �ϰ� �ʹٸ�
	
	// #1. �� �Լ��� �������� ���� ��� - ������������ ����
	std::sort( v.begin(), v.end() );  // 1,2,3,4,5,6,7,8,9,10


	// #2. �� �Լ��� �Ϲ��Լ��� ��� - ���Լ��� �ζ��� ġȯ �ȵ�.
	std::sort(v.begin(), v.end(), cmp);


	// #3. �� �Լ��� �Լ� ��ü�� ��� - �ζ��� ġȯ ����
	std::less<int> f; // < �� ��, 

	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>{}); // �ӽð�ü ���·� ����


	// #4. C++11 ���ʹ� �� �Լ��� "���� ǥ����" ��밡��.
	// [] : ����ǥ������ ���۵��� �˸��� ��ȣ, lambda introducer
	//      "�͸��� �Լ�" ��� �մϴ�.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; }) ;
}





