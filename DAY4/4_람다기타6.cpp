// 5_����ǥ����6
// ����ǥ������ ���ڸ� �޴� ��� - 143p �Ʒ� �κ�

// #1. C ������ "�Լ��� ���ڷ� �������� �Լ� ������" �� ����մϴ�
// 
// 1. �Լ� �� �ƴ϶� ĸ������ ���� ���� ǥ���ĵ� ������ �ֽ��ϴ�.
// 2. ĸ���� ���� ǥ������ ������ �����ϴ�.
// 3. ���ٰ� �ƴ� �Ϲ� �Լ���ü(std::less)�� ������ �����ϴ�.(��ȯ ������ ���� �ȵ�)
// void foo(int(*f)(int, int)) {  }


// #2. std::function ���
// 1. �Ϲ��Լ�, �Լ���ü, ����ǥ����, ĸ���� ���� ǥ���ĵ� ��� ������ �ֽ��ϴ�.
void foo( std::function<int(int, int)> f ) 
{
	f(1, 2); // inline ġȯ�� �Ǳ� ��ƽ��ϴ�.
			 // �ݺ��� �ȿ��� f ���� ���� �̽�!
}

// #3. template - call by value  - ���� �θ� ���
template<typename T>
void foo(T f)
{
	f(1, 2); // inline ġȯ ����.
}

// #4. template - call by const reference
// 1. mutable lambda �� ������ ����
template<typename T>
void foo(const T& f)
{
	f(1, 2); // f.operator()(1, 2)
			 // f�� ��� ��ü�̹Ƿ� operator() �� ��� �Լ��� ����.
}

// #5. template - T&&
// => ������ �ʽ��ϴ�. ǥ�ؿ����� ���� ���
template<typename T>
void foo(T&& f)
{

}

int main()
{
	foo([](int a, int b) mutable { return a + b; });
	foo([](int a, int b) { return a - b; });
}

// ��� : foo(T f) ����
//        foo(T&& f) ������ ����. ũ�Ⱑ ū ��ü(ĸ�ĸ� ���� �ϴ� ���)

