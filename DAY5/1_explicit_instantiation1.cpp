// 아래 코드를 godbolt.org 에 넣어 보세요

// template instantiation ( 템플릿 인스턴스화 )
// => 템플릿으로 부터 실제 함수(클래스) 를 만드는 과정

// implicit instantiation : 실제 템플릿을 사용하는 코드를 보고 인스턴스화(B)
// explicit instantiation : 사용하는 코드가 없어도 명시적으로 인스턴스화 해달라는 요청(A)

template<typename T>
T square(T a)
{
	return a * a;
}

//template double square(double);  // A

int main()
{
//	square(3);		// B
}