#include <string>
#include <iostream>

int main()
{
	// std::move : ���� rvalue �� ĳ���� �� ���Դϴ�.
	//			   �̵������ڰ� �ִ� Ÿ�Ը� ȿ���� �ֽ��ϴ�

	// #1
	std::string s1 = "aaaaaa";
	std::string s2 = std::move(s1);


}