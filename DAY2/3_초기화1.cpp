// member field initialization

class Point
{
	// C++11 부터 멤버 데이타에 초기값을 직접 넣을수 있습니다.
	int x = 0;
	int y = 0;
public:
	Point() {}
	Point(int a) : y(a) {}
};

// 위 코드를 컴파일 하면 아래 처럼 변경됩니다.
class Point
{
	int x; // = 0;
	int y; // = 0;
public:
	// 위 멤버 초기값을 보고 생성자를 아래 처럼 변경합니다.
	Point()      : x(0), y(0) {}
	Point(int a) : x(0), y(a) {} // <== 이 부분이 핵심
};


int main()
{
	Point pt;
}