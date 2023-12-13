#include <string>
#include <iostream>

int main()
{
	// std::move : 단지 rvalue 로 캐스팅 할 뿐입니다.
	//			   이동생성자가 있는 타입만 효과가 있습니다

	// #1
	std::string s1 = "aaaaaa";
	std::string s2 = std::move(s1);
					// => std::string 은 move 생성자가 제공됩니다.
					// => 자원 이동됩니다.

	// #2.
	int n1 = 10;
	int n2 = std::move(n1);	// 이렇게 하면 n1 은 0이 되나요 ?
							// move 효과 없습니다.
							// int n2 = n1 과 동일

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 10

	// #3.
	int* p1 = new int;
	int* p2 = std::move(p1);	// 이 코드는
//	int* p2 = p1;				// 이 코드와 동일합니다.

	printf("%p\n", p1); // 0 이 아닙니다. 


	// #4. swap 에 대해서
	std::string s3 = "aaa";
	std::string s4 = "cccc";

	std::swap(s3, s4); // C++98 : 복사 생성자를 사용한 swap 입니다.
					   //         버퍼 자체를 복사하므로 느립니다.
						// C++11 이후 : move 생성자를 사용한 swap
						//			    아래와 같은 멤버 함수 swap(포인터 swap) 과
						//				거의 동일 합니다.

	s3.swap(s4); // s3 의 버퍼 주소와 s4 의 버퍼 주소를 swap. pointer swap 
}