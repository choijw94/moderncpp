struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// lvalue 와 rvalue 를 모두 받을수 있는 함수 만들기. 

// 방법 1. call by value
// 특징 : 복사본을 만들게 됩니다.
//void foo(Point pt) {}


// 방법 2. call by const lvalue reference
// 특징 1. 복사본 생성 안됨
//      2. 상수성(immutable)을 추가해서 받게 된다. 객체의 상태 변경은 할수 없다.!
// void foo(const Point& pt) {}

//==========여기 까지가 C++98 기술로 할수 있는 모든 것 ===========================
//==========아래 기술은 C++11 이후 기술               ===========================

// 방법 3. lvalue/rvalue reference 버전을 따로 제공
// 특징 1. 복사본 생성 안됨
//      2. 상수성도 추가되지 않고, 원본 그대로 받는 것!
// void foo(Point&  pt) {}
// void foo(Point&& pt) {}


// 방법 4. forwarding reference
// => T&& 를 사용하면 위의 2개 함수를 자동생성할수 있다.
// => 결국 아래 코드는 위의 2개 함수를 자동생성
// => 단, Point 뿐 아니라 모든 타입에 대해 사용가능. 
template<typename T>
void foo(T&& pt)
{
}



int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue(임시객체)를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
