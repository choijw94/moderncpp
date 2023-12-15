#include <iostream>

int f(int, double, char) { return 0; }


// �̹����� ��ȯŸ���� �ƴ� ������ Ÿ���� ���� ���ô�.
// primary template
template<int N, typename T> 
struct argument
{
	using type = T;
};

/*
template<int N, typename R, typename ... Types>
struct argument<N, R(Types...)>
{
	// ? �� ǥ���Ҽ� ������� ?
	// N �� �˼� ����... �߸��� �κ� Ư��ȭ
	using type = ?;
};
*/

/*
// N == 0
template<typename R, typename ... Types>
struct argument<0, R(Types...)>
{
	// R(Types...) �� ��翡�� 0��° ������ Ÿ���� ���Ҽ� �����ϴ�.
	// �߸��� �κ� Ư��ȭ
	using type = ? ;
};
*/

// N == 0
template<typename R, typename A, typename ... Types>
struct argument<0, R(A, Types...)>
{
	using type = A;
};


template<typename T> void foo(T& t)
{
	// T : int (int, double, char)
	typename argument<0, T>::type n; // int

	std::cout << typeid(n).name() << std::endl; 
}

int main()
{
	foo(f);
}