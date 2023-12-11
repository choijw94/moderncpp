#include <vector>
#include <string>
#include <string_view> // C++17!!

int main()
{
	// std::string      : �ڿ�(���ڿ��� ����) �մϴ�
	// std::string_view : �ڿ��� �������� �ʰ�, ������ ����մϴ�.
	std::string s = "to be or not to be";
	std::string_view sv = s;


	// �Ʒ� �ڵ带 ������ ������
	auto p1 = std::ranges::begin(std::vector<int>{1, 2, 3});
				// => vector �� �ڿ��� �����ϴ� �����̳� �Դϴ�.
				// => �ڿ��� �����ϴ� �����̳��� �ӽð�ü�� �����ϸ� error

	auto p2 = std::ranges::begin(std::string_view{s});
				// => string_view �� �ڿ��� ������ ����ϴ� �����̳� �Դϴ�
				// => �ӽð�ü�� �����ص�, �ݺ��ڴ� �ᱹ
				//    �ڿ��� �����ڸ� ����Ű�� �˴ϴ�.
				// => ����, ���ڵ�� ������ �ƴմϴ�.

	// C++20 : �ڿ��� �����ϴ� �����̳� ���� ?
	//         �ڿ��� ������ ����ϴ� �����̳� ������ �߿��ϰ� �˴ϴ�.
	//		   "borrowed range" �� ���������� �����ϰ� �˴ϴ�.

	
}