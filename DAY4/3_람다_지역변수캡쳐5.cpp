// 149
int main()
{
	int v1 = 0, v2 = 0;

	// #1. 캡쳐 문법 정리

	auto f1 = [v1, &v2](int a) { ... }; // v1은 값   캡쳐, v2 는 참조 캡쳐
	auto f2 = [&v1, v2](int a) { ... }; // v1은 참조 캡쳐, v2 는 값 캡쳐

	auto f3 = [=](int a) { ... };	// 모든 지역변수를 "값" 캡쳐
	auto f4 = [&](int a) { ... }; 	// 모든 지역변수를 "참조" 캡쳐

	auto f5 = [=, &v2](int a) { ... };	// v2만 참조, 그외 모든 지역변수는 값
	auto f6 = [&,  v2](int a) { ... };	// V2만 값,   그외 모든 지역변수는 참조
	auto f7 = [&, &v2](int a) { ... };  // ERROR.	
										// 디폴트 모드와 다른 경우만 표기

	// 이름을 변경해서 캡쳐
	auto f8 = [x = v1, &y = v2](int a) { x, y };
			 // int  x = v1;
			 //	int& y = v2;	

	std::string s = "aaaa";
	auto f9 = [s1 = std::move(s)](int a) { ... }
			// std::string s1 = std::move(s);

	// 이후 부터는 s 는 자원 없습니다.
}




