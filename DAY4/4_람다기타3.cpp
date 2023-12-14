int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
	
	// 아래 코드가 에러가 발생하는게 좋으세요 ? 에러가 아닌게 좋으세요 ?
	swap(n, d); // ?
	
}