
// C++98 enum : unscoped enum
// enum COLOR { red = 1, green = 2 };

// C++11 enum : scoped enum
enum class COLOR { red = 1, green = 2 };

int main()
{
//	int c1 = red;	      // error. COLOR 생략할수 없음.
//	int c1 = COLOR::red;  // error. int 로 암시적 변환 안됨

	COLOR c1 = COLOR::red;  // ok. 이렇게만 사용가능.
							// 보다 엄격한 규칙대로만 사용가능
							// 버그를 줄일수 있다.
}





