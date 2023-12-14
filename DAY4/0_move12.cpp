#include <iostream>
#include <string>
#include <vector>

// �ٽ� : Setter ����� #1

class People
{
private:
	std::string name;
	int age;

public:
	// setter �����.
	// #1. const string&
	// => C++98 �������� �ּ��� �ڵ�
	// => C++11 ���Ŀ��� �ּ��� �ƴ�. 
//	void set_name(const std::string& n) { name = n; } // �׻� ���� ����
//	void set_name(const std::string& n) { name = std::move(n); } // �׻� ���� ����
														// n ��ü�� const �̹Ƿ�
														// const �� move �ɼ� ����

	// C++11 ������ �ּ��� �ڵ�
	// => 2���� setter �� ���弼��
	// ��� 1. 2���� ���� �����
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	/*
	// ��� 2. T&& �� ����ϸ� �� 2���� �ڵ������Ҽ� �ֽ��ϴ�.
	template<typename T>
	void set_name(T&& n)
	{
		// ������ �´� ���� ?
//		name = n;					// 1. �׻� ���� ���� ������
//		name = std::move(n);		// 2. �׻� �̵� ���� ������
		name = std::forward<T>(n);	// 3. ok..
									//    set_name ���ڷ� lvalue �� ������ lvalue ĳ����
									//					  rvalue �� ������ rvalue ĳ����
	}
	*/
	// ���� : �� �ڵ忡���� "���1" ó�� 2���� ����� ���� T&& �������� �����մϴ�.!!
	// => �������� ����, �����մϴ�.
};



int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// s1�� �ڿ��� ����. s1�� ��� ����ϰڴٴ� �ǵ�
	p.set_name(std::move(s2));	// s2�� �ڿ��� �̵�. s2�� ���̻� ������� �ʰڴٴ� �ǵ�

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
	//------------------------------------------------------

	// STL �����̳ʵ��� push_xxx() �Լ��� ��� move ������ �����մϴ�.
	std::vector<std::string> v;

	v.push_back(s1);			// s1�� �����ؼ� �ְڴ�. s1 ��� ��밡��
	v.push_back(std::move(s1)); // s1�� �ڿ��� �̵��ذ���� ��. s1 ���̻� ������

	// v.emplace_back( ���ڷ� ��ü�� �ƴ� ������ ���� )
	// v.emplace_back( ��ü ) => �̰�� new Point(pt) �̹Ƿ� ���� ������
}







