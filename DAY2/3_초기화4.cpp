// 58 page
class Vector
{
	int sz;
public:
	Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
	// #1. 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);		// C++98, direct initialization
	Vector v2 = 10;		// C++98, copy   initialization

	Vector v3{ 10 };	// C++11, direct initialization
	Vector v4 = { 10 };	// C++11, copy   initialization

	//----------------
	// #2. 아래 코드를 생각해 보세요.
	foo(10);	// 함수의 인자 전달은 "복사 초기화" 입니다.
				// "Vector v = 10" 의 의미!!
}







