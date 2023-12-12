int main()
{
	// C++98 초기화는 단점이 있습니다.
	int  n1 = 3.4;	// ok. 단, 데이타 손실 
					// C/C++ 은 가능하지만, 대부분 다른 언어는 에러

	char c1 = 500;	// ok. 단, overflower 발생 

	// prevent narrow - 56 page 중간부분
	int n2{ 3.4 };  // error. 데이타 손실이 발생하는 초기화는 에러!
	char c2{ 500 }; // error. 

}