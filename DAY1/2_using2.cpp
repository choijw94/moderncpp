#include <unordered_set>

typedef std::unordered_set<int>    USETI;
typedef std::unordered_set<double> USETD;

// 위 처럼 타입의 별명을 만들지 말고, 
// 아래 처럼 템플 자체의 별명을 만들수 없을까요 ?
// std::unordered_set<int> : 타입
// std::unordered_set      : 템플릿

//typedef std::unordered_set    USET;	// error
									// typedef 는 template 의 별명을 만들수 없습니다.

// using 은 타입뿐 아니라 template 의 별명을 만들수 있습니다.

// #1. type 별명
using DWORD = int;

// #2. template 별명
template<typename T>
using USET = std::unordered_set<T>;

int main()
{
//	std::unordered_set<int>    s1;
//	std::unordered_set<double> s2;

//	USET s1; // error. USET 은 template 입니다.

	USET<int>    s1;
	USET<double> s2;
}
