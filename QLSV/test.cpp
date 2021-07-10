#include"variable.h"
#include"staff.h"
#include"display.h"

void test()
{
	fstream f;
	f.open("2019n1.txt");
	string s;
	NodeLop* headSvLop = NULL;

	while (!f.eof())
	{
		//f.clear();
		getline(f, s, ',');
		if (s != "")
		{
			NodeLop* node = new NodeLop;
			node->pNext = NULL;
			node->lop.ten = s;
			node->lop.headSvLop = TaiData_SvLop(node);
			ThemNodeLopHoc(headSvLop, node);
		}
	}
	viewDsLop(headSvLop);
}