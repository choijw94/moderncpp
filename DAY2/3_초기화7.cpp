
// 핵심 : Point 는 디폴트 생성자가 없습니다.
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// 디폴트 생성자가 없는 타입이 멤버 로 있는 경우
class Rect
{
	Point pt; // ?
public:
	Rect() {}
	// 사용자 코드		// 컴파일러가 변경하는 코드
//	Rect() {}			// Rect() : pt() {}		// <= pt에는 디폴트 생성자없다 

	// C++98 시절 해결책 - Rect 초기화 리스트에서 pt 의 다른 생성자 호출!
//	Rect() : pt(0, 0) {}
};

// C++11 해결책
class Rect2
{
	Point pt{ 0, 0 }; // ok
	//	Point pt( 0, 0 ); // error. 이 위치에서는 () 대신 {}로 하세요
public:
};



int main()
{
	Rect r1;
}

