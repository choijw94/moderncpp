int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
	
	// �Ʒ� �ڵ尡 ������ �߻��ϴ°� �������� ? ������ �ƴѰ� �������� ?
	swap(n, d); // ?
	
}