// 1_초기화11 - 65 page..
// aggregate initialization
// => 생성자가 없이 {} 로 초기화 하는 것

// aggregate type
// => 생성자가 없이 {} 로 초기화 가능한것
// => 배열, 구조체, 공용체, 

struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	void print() {} // 멤버 함수가 있어도 aggregate type

//	virtual void foo() {} // 가상함수가 있으면 aggregate type 아님.

//	Point() {}	// 생성자가 있으면 aggregate type 아님.

	Point() = default; // 이렇게 하면 aggregate type!!
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 };
}