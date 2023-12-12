// 핵심 : rvalue, lvalue 의 개념은 
//       변수(객체)에 부여되는 개념이 아닌
//       표현식(expression) 에 부여 되는 개념
// 
// expression : 한개의 값으로 결정되는 코드 집합
//			=> 최종 결과값이 등호의 왼쪽에 올수 있는가 ?

int main()
{
	int n = 3;

	n * 2 + 7 = 10; // error.
					// n * 2 + 7 는 최종결과는 13인데..
					// 13은 연산의 결과로 만들어진 임시값, rvalue

	(n = 10) = 20;  // ok.  "n = 10" 이라는 표현식은 lvalue

	n = 3;
	++n = 10;	// ok. "++n" 이라는 표현식은 lvalue

	n++ = 10; // error. "n++" 이라는 표현식은 rvalue
}
// 왜 ?? lvalue, rvalue 따집니까 ??
// => lvalue 일때와 rvalue 일때 다르게 동작하는 함수등을 만들기 위해

// foo( lvalue ) : 인자는 함수 호출뒤에도 살아 있다.
// foo( rvalue ) : 인자는 함수 호출뒤에는 파괴 된다.