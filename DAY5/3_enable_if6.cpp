#include <iostream>
#include <string>
#include <vector>
#include <array>


class People
{
private:
	std::string name;
	std::string address;
public:
	// move �� �����ϱ� ���� setter �� ���鶧 T&& �� ����ϴ� �Լ�.
	// => �Ʒ� ó�� ����� "p.set(10, 20)" �� ������ �ƴմϴ�.
	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
};

int main()
{
	People p;
	p.set(10, 20);

}