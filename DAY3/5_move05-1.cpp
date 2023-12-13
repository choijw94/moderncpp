#include <iostream>

class Object
{
public:
	Object() = default;
	Object(const Object& obj) { std::cout << "copy\n"; }
	Object(Object&& obj)      { std::cout << "move\n"; }
};

// ���ø� ���鶧 ���ڸ� T& �� ���� T&& �� ���� �� �Ǵ��ϼ��� 
// T&  : ���ڷ� lvalue �� �ްڴٴ� �ǵ�
// T&& : ���ڷ� lvalue, rvaue �� ��� �ްڴٴ� �ǵ�

// move : ���ڷ� lvalue, rvalue �� ��� �޾Ƽ� rvalue �� ĳ����

template<typename T>
T&& mymove(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = mymove( o2 );		// move ����� ���ô�. 

	Object o5 = mymove( Object() ); // �Ǿ� �ұ�� ? �ȵǾ� �ұ�� ?
}