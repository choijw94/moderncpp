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
	//	tuple<             short> t1; 
	//	tuple<     double, short> t2; 
	//	tuple<int, double, short> t3; 

	tuple<int, double, short> t(1, 3.4, 2);

	std::cout << t.value << std::endl; // 예측해 보세요

	// 주석처럼 결과가 나오도록 해보세요
	std::cout << ? << std::endl; // 3.4
	std::cout << ? << std::endl; // 2 
}
