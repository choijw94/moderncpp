#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) �ǹ�.
	v.emplace_back(20);
	v.emplace_back(15);

	int k = 15;
	// ���̰� k���� ����� ã�� �ʹ�. ?

	auto ret = std::find(v.begin(), v.end(), 
					[k](const People& p) { return p.age == k; } );
}







