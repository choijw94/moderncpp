// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// ��� ����� ������ �ʹ�.. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// C++17 ���ʹ� �Ʒ� ó�� ���ٷ� �����մϴ�.
	// => structural binding �̶�� ����
	auto [a1, a2, a3] = p3d;	// auto a1 = p3d.x;
								// auto a2 = p3d.y;
								// auto a3 = p3d.z;

//	int [a1, a2, a3] = p3d; // error. auto �� ����
//	auto [a1, a2]    = p3d; // error. ������ ���ƾ� �մϴ�.


	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "������";

	// map�� pair�� �����մϴ�.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "ȭ����";

	m.insert(p);

	//=====================
	// map �� ��� ��� ���� - C++14����
	for (auto& p : m)
	{
		// p �� pair& �Դϴ�.
		auto key = p.first;
		auto value = p.second;
	}

	// C++17
	for (auto& [key, value] : m)
	{
		// key, value
	}
}

