// �Լ� ���ڷ�
// int&  : int Ÿ���� lvalue �� ������ �ִ�.
// int&& : int Ÿ���� rvalue �� ������ �ִ�.
// T&    : ��� Ÿ���� lvalue �� ������ �ִ�.


// T&&   : ��� Ÿ���� lvalue �� rvalue �� ��� ������ �ִ�.

// ��� ������ �ִٴ� �ǹ̴�, 
// => �Լ� �Ѱ��� ��� ���� ���� �ٴ� ���� �ƴ϶�, 
//    ������ ��츦 ������ �ִ� "�Լ��� �����Ҽ� �ִ�" �� ��.


// �Ʒ� ���� �ܿ켼�� ( n �� int �϶�)
// ���ڷ� lvalue ����(f4(n)) : T=int&,  ���ڴ� T&&=int& &&, ������ �Լ� f4(int&)
// ���ڷ� rvalue ����(f4(3)) : T=int    ���ڴ� T&&=int&&    ������ �Լ� f4(int&&)
// 
// ==> ������ �Լ��� ��� "call by value" �� �ƴ� "call by reference"
// ==> ��, ��� ���ڸ� ���纻 ���� ������ �ִ� �Լ����� �����ȴٴ� ��


// ��� ����
// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference

// T&&   : rvalue reference ��� �Ҽ��� �����ϴ�.
//		   lvalue, rvalue ��� ������ �����Ƿ�!!

// C++11 �ʱ⿡ "T&&" �� �̸��� ������ �ʾҽ��ϴ�. 
// �׷��� effective-modern C++�� ���ڰ� "universal reference" ��� �θ��ڰ� ����. 
//       �׷���, C++ ǥ������ȸ��        "forwarding reference" ��� ����!!

// T&& �� ���� ��Ī�� ���� "forwarding reference" �Դϴ�.