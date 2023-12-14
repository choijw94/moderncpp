#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	auto p1 = std::find_if(v.begin(), v.end(), foo);
					// => find_if 의 3번째 인자는 "단항함수" 이어야 합니다.


	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "k의 배수"를 찾고 싶다. 
	// => ? 에 들어갈 함수는 어떻게 만들어야 할까요 ?
	// => 위에 있는 foo 에서 3 대신 "k" 를 사용하게 할수 있을까요 ?
	//    일반 함수로는 쉽지 않습니다.
	//    함수 객체는 쉽게 할수 있습니다.
	auto p2 = std::find_if(v.begin(), v.end(), ?);
				

}



