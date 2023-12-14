
// 1. 템플릿은 구현부 자체를 헤더에 넣어야 합니다.

// 2. 단, 아래 처럼 명시적 인스턴스화를 해놓으면 구현에 있어도 됩니다
//   => 아주 드물게 사용하는 기법

template<typename T>
T square(T a)
{
	return a * a;
}

template int square(int a);
template double square(double a);