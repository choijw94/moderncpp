#include <iostream>
#include <type_traits> 

// ���� 9 page ������.

#pragma pack(1)		// ����ü align �� 1byte ������( padding �߰����� ����� �ǹ�)
struct PACKET
{
	char cmd;
	int  data;
};

// PACKET �� �����ϰ� ����Ϸ��� �Ʒ� ó�� �ڵ带 �߰��ϴ� ���� �����ϴ�.
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
			 "error, unexpected padding..");

/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/




template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic<T>::value : T�� �����Լ��� ���� Ÿ���̶�� true

	static_assert( !std::is_polymorphic<T>::value,
		"error, T has virtual function");

	memset(p, 0, sizeof(T)); 
}

class Object
{
	int data;
public:
	virtual void foo() {}
};
int main()
{
	Object obj;
	object_set_zero(&obj);
}

// �ٽ� 
// 1. static_assert �� ����ð� ����, ��ɿ��� ���� ������ �����ϴ�.
// 2. static_assert �� ������ �ڵ带 ����� �� ������ �ݴϴ�.
// 3. static_assert �� ���� ����ص� ���ɰ��� �����մϴ�.
//   