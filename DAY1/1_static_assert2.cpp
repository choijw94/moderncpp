#include <iostream>
#include <type_traits> 

#pragma pack(1)		// ����ü align �� 1byte ������( padding �߰����� ����� �ǹ�)
struct PACKET
{
	char cmd;
	int  data;
};

// PACKET �� �����ϰ� ����Ϸ��� �Ʒ� ó�� �ڵ带 �߰��ϴ� ���� �����ϴ�.
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
			 "error, unexpected padding..");


int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}





template<typename T> void object_set_zero(T* p)
{
	memset(p, 0, sizeof(T)); 
}
