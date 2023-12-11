// 9_enum - 32 page

// C/C++ 의 enum 문법

enum COLOR { red = 1, green = 2};

int main()   
{
	int c1 = COLOR::red;

	// #1. enum 단점 1. COLOR 생략이 혼란을 초래 합니다.
	int c2 = red; // ok. COLOR 는 생략 가능.

	int red = 0;
	int c3 = red; // 지역변수, red. 
				  // 하지만 COLOR::red 와 같은 이름이므로 가독성이 좋지 않습니다.

	// #2. int 로 암시적 변환이 위험한 코드..
	int c4 = COLOR::red;
	c4 = 100;	// OK.. 하지만 색상값의 범위를 벗어난 코드
}





