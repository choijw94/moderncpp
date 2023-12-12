// C++98 초기화의 문제점 - 54 page
#include <complex>
#include <vector>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);


	// 2. 동적 할당한 배열을 초기화 할수 없다.
	int* p = new int[3];

	p[0] = 0; // 초기화가 아닌 대입


	// 3. STL 컨테이너를 배열 처럼 초기화 할수 없다.
	std::vector<int> v1(5, 3); // 5개를 3으로. 이렇게는 되지만
//	std::vector<int> v2 = { 1,2,3,4,5 }; // C++98 시절에는 에러.
}

class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int x[3];
};



