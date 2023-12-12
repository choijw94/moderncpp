// 0번 복사해오세요
#include <complex>
#include <vector>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	// => 중괄호 초기화 문법으로 해결
	int n1 = { 10 };
	int x[2] = { 1,2 };
	std::complex<double> c = { 1, 2 };


	// 2. 동적 할당한 배열을 초기화 할수 없다.
	// => 중괄호 초기화로 해결
	int* p = new int[3] {1, 2, 3};



	// 3. STL 컨테이너를 배열 처럼 초기화 할수 없다.
	// => std::initializer_list 로 해결..
	std::vector<int> v1 = { 1,2,3,4,5 }; // 
	std::vector<int> v2{ 1,2,3,4,5 }; // 

//	std::vector v3{ 1,2,3,4,5 }; // C++17 부터는 타입도 생략가능.
}

class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	// => 중괄호 초기화 사용 가능
	int x[3]{ 1,2,3 };
};



