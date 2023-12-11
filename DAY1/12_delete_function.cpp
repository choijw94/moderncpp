// 12_delete_function 37 page

class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 생성자, 소멸자, 복사생성자,대입연산자, 이동생성자, 이동 대입연산자
	// => special member function
	// => 사용자가 만들지 않으면 컴파일러가 디폴트 버전을 제공
	// => 필요 없다면 "삭제" 하면 컴파일러는 제공하지 않습니다.

	Point(const Point&) = delete;


	// C++98 시절의 테크닉( = delete 가 없던 시절)
	// => private 영역에 선언만!!!
	// => 의도적으로 구현을 제공하지 않으므로, 사용하는 코드가 있다면 에러 나오게 하는것
	/*
private:
	Point(const Point&); 
	*/
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2);	// 컴파일러가 만들어주는 복사생성자 사용
					// 삭제했다면 컴파일러가 제공안하므로 에러!
}