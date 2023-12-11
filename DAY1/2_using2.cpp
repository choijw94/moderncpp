#include <unordered_set>

typedef std::unordered_set<int>    USETI;
typedef std::unordered_set<double> USETD;

// �� ó�� Ÿ���� ������ ������ ����, 
// �Ʒ� ó�� ���� ��ü�� ������ ����� ������� ?
// std::unordered_set<int> : Ÿ��
// std::unordered_set      : ���ø�

//typedef std::unordered_set    USET;	// error
									// typedef �� template �� ������ ����� �����ϴ�.

// using �� Ÿ�Ի� �ƴ϶� template �� ������ ����� �ֽ��ϴ�.

// #1. type ����
using DWORD = int;

// #2. template ����
template<typename T>
using USET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

//	USET s1; // error. USET �� template �Դϴ�.

	USET<int>    s1;
	USET<double> s2;
}
