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
	//	tuple<             short> t1; // 2번째 부모  - 2 
	//	tuple<     double, short> t2; // 1번째 부모	- 3.4
	//	tuple<int, double, short> t3; // 0번째 부모  - 1 보관

	tuple<int, double, short> t(1, 3.4, 2);


	std::cout << t.value << std::endl; // 1

	// 주석처럼 결과가 나오도록 해보세요
	std::cout << static_cast<tuple<double, short>&>(t).value  << std::endl; // 3.4
	std::cout << static_cast<tuple<short>&>(t).value << std::endl; // 2 
}
