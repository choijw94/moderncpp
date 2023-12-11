// 16_constexpr1
int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// 다음중 에러를 모두 고르세요
	int arr1[10]; // ok
	int arr2[n ]; // error. (단, g++은 가능. 아래 주석 참고)
	int arr3[c1]; // ok			컴파일 시간 상수, 컴파일러가 c1 의 초기값을 알고 있다
	int arr4[c2]; // error		실행시간 상수,    컴파일러가 c2 의 초기값을 알수 없다.

	// const 의미 : "값을 변경할수 없다" 는 의미
	//				초기값을 컴파일 시간에 알수도 있고,
	//						컴파일 시간에 알수 없을수도 있다.
	// C#, RUST 등의 다른 언어는 "상수" 가 아닌 "immutable", "readonly"
	// 등으로 부릅니다.

	// C#, swift, rust 에서는
	// read only, immutable : 값을 변경할수 없다.
	// constant             : 컴파일 할때 값을 알수 있다.
}



// 참고 : 배열의 크기
// C89 : 배열의 크기는 컴파일 시간에 알아야 합니다. 변수 사용안됨
// C99 : 배열의 크기로 변수 사용가능. 
//       (g++ 지원, visual studio 지원안함)