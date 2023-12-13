#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// move �迭 �Լ��� ���� ����� �ȴٸ�..
	// 1. �ǵ��� ���ܰ� ���� ���弼��
	//    (��κ� ������ ����� �����ϰ� �ǹǷ�, ���� ���ɼ� �ִ� �ڵ�� ������� �ʰ� �˴ϴ�)

	// 2. ���ܰ� ������ �˸��� ���ؼ� noexcept �� ���̼��� 

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	Object o1;
	Object o2 = o1; // �׻� ���� ������ ȣ��
	Object o3 = std::move(o1); // �׻� move ������ ȣ��

	Object o4 = std::move_if_noexcept(o2);
							// o2 Ÿ���� move �����ڰ� 
							// ���ܰ� ���ٸ�(noexcept�� �ִٸ�) move ������ ���
							// ���� ���ɼ��� �ִٸ�			  copy ������ ���



	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	v.resize(10); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

