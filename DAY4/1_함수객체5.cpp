#include <iostream>
#include <algorithm> 


// 아래 함수는 비교 정책을 교체 가능하기 때문에 (마지막 인자가 비교함수)
// 장점 : 사용자가 정렬의 기준을 변경할수 있습니다.(오름 차순, 내림차순), 유연성!
// 단점 : 성능 저하.
//        cmp1, cmp2 가 inline 함수라도 함수 포인터 에 담아서 사용하므로 인라인 치환안됨.

void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])					// 1

			if ( cmp( x[i], x[j] ) == true )	// 2

				std::swap(x[i], x[j]);
		}
	}
}
//=================================
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}

