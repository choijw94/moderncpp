// Step2. 한개 요소 보관 하기

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0; 
};

// tuple 사용시 타입이 한개 이상 있는 경우에 대한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& v) : value(v) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3;
}