// 7_�����������ø�1 - 225 page


// �������� Ŭ���� ���ø�
// => Types �ȿ��� �Ѱ��� Ÿ���� �ƴ� "Ÿ�Ե�"�� ���ԵǾ� �ֽ��ϴ�.
template<typename ... Types> class tuple 
{
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2;
	tuple<int, double, char> t3;
}