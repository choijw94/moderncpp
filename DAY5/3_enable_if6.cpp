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
	/*
	template<typename T1, typename T2>
	void set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}
	*/
	// p.set(10,20) �� ������� �������� �Ʒ� ó�� �ϸ� �˴ϴ�.
	template<typename T1, typename T2>	
	std::enable_if_t< std::is_convertible_v<T1, std::string> &&
					  std::is_convertible_v<T2, std::string> >		
	set(T1&& a1, T2&& a2)
	{
		name = std::forward<T1>(a1);
		address = std::forward<T2>(a2);
	}

	// �����ڿ� enable_if ��� ����ϱ�. 
	// => �����ڴ� return Ÿ���� �����ϴ�.
	// => �Լ����� �Ǵ� template ���ڷ� �ؾ� �մϴ�
	// => ���� template ���ڷ� �ϰԵ˴ϴ�.
	// => ���ڷ��ϸ� �ڵ尡 ������ ���Դϴ�.
	// �Ʒ� ó�� �����, ���Ǹ� ä��� �˴ϴ�
	/*
	template<typename T1, typename T2,
			 typename T3 = std::enable_if_t< ���� > >
	People(T1&& a1, T2&& a2) 
		: name( std::forward<T1>(a1)),
		  address( std::forward<T2>(a2) )
	{
	}
	*/

	// ���� ������ �Ʒ� ó��
	template<typename T1, typename T2,
		typename T3 = std::enable_if_t< std::is_convertible_v<T1, std::string>&&
										std::is_convertible_v<T2, std::string> > >
	People(T1&& a1, T2&& a2)
		: name(std::forward<T1>(a1)),
		address(std::forward<T2>(a2))
	{
	}
};



int main()
{
	People p;
	p.set(10, 20);

}