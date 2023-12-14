       int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출. 인자를 약속된 장소에 넣고 Add1 의 위치로 이동
	int n2 = Add2(1, 2); // 치환. 이 위치를 Add2 의 기계어 코드로 변경
						 // 장점 : 빠르다!

	int(*f)(int, int) = &Add2;

//	if (사용자입력값 == 1) f = &Add1;

	f(1, 2); // 호출
}

// 1. 인라인 치환은 "컴파일 시간"에 수행되는 문법 입니다.
// 2. 인라인 함수라도 함수 포인터에 담아서 호출하면 인라인 치환될수 없습니다.
