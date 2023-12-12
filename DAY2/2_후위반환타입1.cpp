// 1_후위반환타입1.cpp - 교재 73 page

// C/C++ 에서 전통적인 함수의 모양
/*
int square(int a)
{
	return a * a;
}
*/
// C++11 부터 함수의 반환 타입을 () 뒤에 표기하는 문법이 도입됩니다.
// => suffix return type, trailing return type
auto square(int a) -> int
{
	return a * a;
}

int main()
{
	square(3);
}