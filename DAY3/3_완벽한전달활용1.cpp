// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// => 아래 각각의 방법에 대한 화면 출력 결과를 정확히 이해 하세요
	
	// #1. 객체를 생성한 후에 넣기
//	Point pt(1, 2);
//	v.push_back(pt);


	// #2. 임시객체 형태로 생성해서 넣기
//	v.push_back( Point(1, 2) );


	// #3. {} 초기화 형태로 전달
//	v.push_back({ 1,2 }); // #2 와 동일한 코드


	// #4. 객체를 전달하지 말고, 
	//     객체를 만들기 위한 "생성자 인자"를 전달하자!! 핵심!!!!
	v.emplace_back(1, 2);
			// => emplace_back 함수가 내부적으로 "new Point(1,2)" 처럼 버퍼에 객체생성


	std::cout << "-----" << std::endl;
}


