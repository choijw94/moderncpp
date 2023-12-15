// 7_가변인자템플릿1 - 225 page


// 가변인자 클래스 템플릿
// => Types 안에는 한개의 타입이 아닌 "타입들"이 포함되어 있습니다.
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2;
	tuple<int, double, char> t3;
}