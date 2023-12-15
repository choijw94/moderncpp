#include <iostream>
#include <vector>

// (args + ...)	    // E1+(E2+(E3+(E4+E5)))		 unary  right fold

template<typename ... Types>
void fn(std::vector<int>& v, Types ... args)
{
	// pack 안의 모든 요소를 v 에 넣고 싶다.
	( v.push_back(args) , ... );
		// v.push_back(E1), (v.push_back(E2), (v.push_back(E3) 
}

int main()
{
	std::vector<int> v;

	fn(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	fn(v, 1, 2, 3, 4, 5);

	for (auto e : v)
		std::cout << e << ", ";
		// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 
}