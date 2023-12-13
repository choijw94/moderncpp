// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point(int, int)" << std::endl;	}
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

// main					emplace_back						Point(int a, int b)
// 1, 2 ================> 전달받은 인자로 Point 객체생성
//						  즉, new Point(1, 2) =================> 

// emplace_back : 전달 받은 1, 2 를 Point 의 생성자로 다시 전달.. 합니다.
//				  전달 받은 인자를 어떠한 변경도 없이 생성자에 보내야 합니다
//				  "완벽한 전달" 기술이 없으면 만들수 없습니다.

// 대략 emplace_back 은 아래 형태가 되게 됩니다.
/*
template<typename T> 
decltype(auto) emplace_back(T&& ... args)
{
	new Point(std::forward<T>(args)...);
}
*/

// STL 컨테이너 사용시
// #1. primitive 타입을 저장하는 컨테이너 ( std::vector<int> v) 의 경우
// => v.push_back(1)    <== 이렇게 하세요 (가독성이 아래 보다 좋습니다.)
// => v.emplace_back(1) <== 이렇게 해도 됩니다.


// #2. user define type 포인터를 저장(std::vector<Point*> v)
// => v.push_back( new Point ) <== 역시, push_back 사용하세요

// #3. user define type 을 value 로 보관 한다면 (std::vector<Point> v)
// => v.push_back( Point(1,2))  보다는 
// => v.emplace_back( 1, 2)     가 훨씬 빠릅니다.  되도록 이렇게 하세요

// 단, 객체를 사용하다거 넣는다면 push_back, emplace_back 동일..
// Point pt(1,2); // 만들고..
// pt 를 사용하다가..
// v.push_back(pt);    // 이렇게 하거나
// v.emplace_back(pt); // 이렇게 하거나 동일.
