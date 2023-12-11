int main()
{
	int n1 = 0;

	// auto : 우변의 표현식을 가지고 좌변의 타입을 결정
	auto a1 = 3;		// int a1 = 3
	auto a2 = 3.4;

	// auto의 생각보다 어려운 내용이 많이 있습니다.
	const int c = 10;
	auto a3 = c; // 1. const int a3 = c;
				 // 2. int a3 = c;			// <== 정답. 
}



