// 1_초기화10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 2);	// vector(std::size_t, int) 생성자 사용
								// => 10개의 요소를 2로 초기화

	std::vector<int> v4{10, 2};	// vector(std::intializer_list<int>) 생성자 사용
								// => 2개의 요소를 10, 2 로 초기화

	std::cout << v3.size() << std::endl; // 10
	std::cout << v4.size() << std::endl; // 2


	// 아래 코드에서 에러는 ?
	std::vector<int> v5 = 10;	// error. explicit vector(std::size_t) 이므로
								//        copy 초기화는 안됨.

	std::vector<int> v6 = {10}; // ok. vector(std::intializer_list<int>) 와같이
								//     explicit 생성자가 아닙니다.
								//     복사 초기화 가능
}




