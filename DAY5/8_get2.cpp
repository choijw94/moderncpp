#include <iostream>

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;

	tuple() = default;
	tuple(const T& v, const Types& ... args)
		: value(v), base(args...) {}

	static constexpr int N = base::N + 1;
};


int main()
{
	//	tuple<> t0;
	//	tuple<             short> t1; // 2��° �θ�  - 2 
	//	tuple<     double, short> t2; // 1��° �θ�	- 3.4
	//	tuple<int, double, short> t3; // 0��° �θ�  - 1 ����

	tuple<int, double, short> t(1, 3.4, 2);


	std::cout << t.value << std::endl; // 1

	// �ּ�ó�� ����� �������� �غ�����
	std::cout << static_cast<tuple<double, short>&>(t).value  << std::endl; // 3.4
	std::cout << static_cast<tuple<short>&>(t).value << std::endl; // 2 
}
