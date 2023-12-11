#include <list>
#include <iostream>

class MyList : public std::list<int>
{
public:
	void print() const
	{
		for (auto e : *this)
			std::cout << e << ", ";
		std::cout << std::endl;
	}
	
	// MyList �� std::list<int> �� �����ϰ� ����Ҽ� �ְ� �Ϸ���
	// => �����ڰ� �ʿ� �մϴ�.
	
	// # 1. C++98 �����̶�� - std::list<int> �� ������ ����� �����ڸ� MyList�� �߰�
	// => ���� ���� ���ڷ� �ٽ� ��� Ŭ���� �����ڷ� ���޸� �մϴ�.!!
	// => std::list �� �Ʒ� 2�� �̿ܿ��� ���� �����ڰ� �ֽ��ϴ�.
//	MyList(int sz)            : std::list<int>(sz) {}
//	MyList(int sz, int value) : std::list<int>(sz, value) {}

	// #2. C++11 �̶�� ������ ��� ���
	// => std::list �� ��� �����ڸ� MyList Ÿ�Կ� ���ؼ��� ��밡��
	using std::list<int>::list;
};

int main()
{
	MyList st1(10, 3); // 10���� 3���� �ʱ�ȭ
	MyList st2(10);

	st1.print();
}





