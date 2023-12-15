// Step3. 여러개 보관하기

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<             short> t1; // t1 은 short 보관
	tuple<     double, short> t2; // t2 는 double 보관
	tuple<int, double, short> t3; // t3 는 int 만 보관
}