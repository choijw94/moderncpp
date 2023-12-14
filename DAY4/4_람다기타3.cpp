int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;
	
	// �Ʒ� �ڵ尡 ������ �߻��ϴ°� �������� ? ������ �ƴѰ� �������� ?
	swap(n, d); // int �� double �� swap �� �������� ���� �ʽ��ϴ�.
				// ������ �����ϴ�.
				// �׷���, ���� �ƴմϴ�.
				// "generic lambda" �� ���ڰ� ��� ������ ���ø� ����

	// �ذ�å : 1, 2��° ���ڰ� ���ƾ� �Ѵ�!!! �� �ʿ� �մϴ�
	// => C++20 ���� "template ����" ���� �߰�.

	auto swap2 = []<typename T>(T& a, T& b) {  }; // ���� ����.
	
	swap2(n, d); // error
}