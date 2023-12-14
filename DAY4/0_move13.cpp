#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <type_traits>

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

	// �����ڰ� ��ǥ���� setter �Դϴ�
	// => �Ʒ� �����ڴ� move �� �����Ҽ� ���� ������ �Դϴ�.
//	People(const std::string& n, const std::string& a)
//		: name(n), address(a) {}

	// �����ڰ� ���ڰ� 2�� �̻� �̸� T&& �� �����ϴ�.
//	template<typename T1, typename T2>
//	People(T1&& n, T2&& a)
//		: name(std::forward<T1>(n) ), address( std::forward<T2>(a) ) {}

	// �� �������� T1, T2 �� �ݵ�� string �̾�� �Ѵٰ� ������ �ֱ� ���ؼ���
	// enable_if ���� ����� �ʿ� �մϴ�.
	template<typename T1, typename T2, 
		typename T3 = std::enable_if_t< 
				std::is_convertible_v<T1, std::string> && 
				std::is_convertible_v<T2, std::string> >>

	People(T1&& n, T2&& a)
		: name(std::forward<T1>(n)), address(std::forward<T2>(a)) {}

};



int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

//	People p(name, addr);
	People p(name, std::move(addr) );

	p.set(name,			   addr);
//	p.set(std::move(name), addr);
//	p.set(name,			   std::move(addr));
//	p.set(std::move(name), std::move(addr));
}








