// 3_�Լ���ü6
// 1. �Ϲ� �Լ��� �ڽŸ��� Ÿ���� �����ϴ�.
//    signature(����Ÿ�԰� �Ķ����) �� 
//    ������ ��� �Լ��� ���� Ÿ���Դϴ�.


// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ֽ��ϴ�.
//    signature(����Ÿ�԰� �Ķ����) ��
//    �����ص�  ��� �Լ���ü�� �ٸ� Ÿ�� �Դϴ�.


struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};
//==================================================

void Sort(int* x, int sz, Less cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == true)
				std::swap(x[i], x[j]);
		}
	}
}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); 
	Greater f2; f2(1, 2); 
}



