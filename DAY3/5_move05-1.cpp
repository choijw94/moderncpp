#include <iostream>
#include <type_traits>

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
std::remove_reference_t<T>&& mymove(T&& obj)
{
	// �ٽ� : �Ʒ� �ڵ�� rvalue casting �� �ƴմϴ�
	// mymove ���ڷ� rvalue �� �������� "rvalue ĳ����"
	//              lvalue �� �������� "lvalue ĳ����"
	// 
	// static_cast<T&&>(obj); // ��, ���ڵ�� std::forward<T>(obj) �Դϴ�.
	// 

	// �ذ�å
	// move �� �׻� rvalue �� ĳ���� �Ǿ�� �մϴ�.
	// T �ȿ� �ִ� ��� ������ �����ϰ� && �� �ٿ��� ĳ���� �ϸ� �˴ϴ�.
	// std::remove_reference_t<T> : T �ȿ� �ִ� ��� ������ ������ Ÿ�� ���ϱ�

	return static_cast<std::remove_reference_t<T> &&>(obj);
						// => �� �ڵ�� �׻� rvalue ĳ�����Դϴ�.
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = mymove( o2 );		// move ����� ���ô�. 

	Object o5 = mymove( Object() ); // �Ǿ� �ұ�� ? �ȵǾ� �ұ�� ?
}