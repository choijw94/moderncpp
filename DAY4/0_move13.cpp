#include <iostream>
#include <string>
#include <vector>
#include <array>

// �ٽ� : Setter ����� #2

class People
{
private:
	std::string name;
	std::string address;
public:
	// ���ڰ� 2���� setter �� move �����ϱ�.
	// => �Ʒ� �ڵ�� move ���� �ȵ˴ϴ�.
	/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	// move �� ���� �Ϸ��� �Ʒ� ó�� 4���� ������ �մϴ�

	void set(const std::string& n,	const std::string& a) {}
	void set(const std::string& n,	std::string&& a) {}
	void set(std::string&& n,		const std::string& a) {}
	void set(std::string&& n,		std::string&& a) {}
	*/
	// ���ڰ� N ���� setter �� move ���� �Ϸ���
	// => 2^N ���� �Լ��� �ʿ� �մϴ�.
	// => �� ��쿡�� ��ó�� ���� ������ ���� forwarding reference �� ����
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

};



int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
//	p.set(std::move(name), addr);
//	p.set(name,			   std::move(addr));
//	p.set(std::move(name), std::move(addr));
}








