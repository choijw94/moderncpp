// 5_����ǥ����1
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// ����ǥ������ ����!
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	//=======================================================
	// �� �ڵ带 �����Ϸ��� �Ʒ�ó�� �����մϴ�.
	
	class CompilerGeneratedName
	{
	public:
		inline auto operator()(int a, int b) const
		{
			return a < b;
		}
	};

	std::sort(v.begin(), v.end(), CompilerGeneratedName() );

	// �ᱹ ���� ǥ������ ���� ����� "�ӽð�ü" �Դϴ�.
	// lambda expression ���� "expression(ǥ����)" �� �ϳ��� ������ ���Ǵ� �ڵ�!
	// => �Լ���ü�� �ӽð�ü ���·� �����Ѱ�. 
	// => �ᱹ, "Ŭ����" �� �����
	// => cppreference.com �� 1��° ȭ�鿡�� expression ����
	//    expression ������ �߰����� "lambda exression ����" �� 1��° ���� ������

}





