#include <vector>
#include <string>
#include <memory>

// �Ʒ� ���� call by value �� �����ڵ�����, �ʱ�ȭ ���� ������ ����.
void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello"); // �������� �½��ϴ�. ���� ������ �ȵ˴ϴ�.
				  // ���� �ߵ˴ϴ�.
				  // std::string s = "hello" �� �ȴٴ� �ǹ�!
				  // string(const char*) �����ڴ� explicit �� �ƴ϶�� �ǹ�.

	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok


	goo(10);	// �������� ���� �ʽ��ϴ�. 
				// ���� �Դϴ�.
				// vector(std::size_t) �����ڴ� explicit ��� �ǹ�. 

	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error
	std::vector<int> v3 = { 10 }; // ok. �׷� �̰� ��?? �ǳ��� ?? - �ʱ�ȭ9.cpp ����!
	




}





