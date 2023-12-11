// 8_nullptr - 29page

int main()
{
	// C++98 시절
	int  n1 = 0;
	int* p1 = 0;	// 포인터 초기화에 0 사용.

	// C++11 부터
	int* p2 = 0;		// bad. 나쁜 코드
	int* p3 = nullptr;	// good. 좋은 코드

	int n2 = nullptr; // error. nullptr 은 포인터 초기화만 가능.

}