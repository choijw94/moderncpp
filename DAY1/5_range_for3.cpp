#include <iostream>
#include <vector>
// 사용자 정의 타입이라고 
// begin/end 만 있으면 range-for 에 넣을수 있습니다.
struct Point3D
{
	int x, y, z;

	int* begin() { return &x; }
	int* end()   { return &z + 1; } // 마지막 요소의 주소가 아닌
									// 마지막 요소의 다음 주소
};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 될까요 ? 되게하려면 필요한 것은 ?
		std::cout << n << std::endl; 

}















