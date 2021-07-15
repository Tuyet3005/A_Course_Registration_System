#include"begin.h"
#include"DKKH.h"
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int main()
{
	string tk, mk;
	short lc = 1;//Ma tk:  0: giao vu ; 1: sinh vien
	ListNamHoc listNam;
	//ds tam luu dia chi nodeSv lop
	listNam.pHead = listNam.pTail = NULL;
	//tai du lieu list nam hoc tu file len he thong
	TaiData_Nam(listNam);
	do
	{
		bool Thoat = false;
		LogIn(tk, mk, lc);//dn sai thi tu dong thoat ra luon
		system("cls");
		do
		{
			Thoat = XlMenuBD(LuaChon(InMenuBatDau(lc)), lc, tk, mk, listNam);
		} 		while (!Thoat);
		//
	} 	while (true);
	return 0;

	//resizeConsole(WIDTH, HEIGHT);

	//fstream f;
	//f.open("2019n1.txt");
	//string s;
	//NodeLop* headSvLop = NULL;

	//while (!f.eof())
	//{
	//	//f.clear();
	//	getline(f, s, ',');
	//	if (s != "")
	//	{
	//		NodeLop* node = new NodeLop;
	//		node->pNext = NULL;
	//		node->lop.ten = s;
	//		node->lop.headSvLop = TaiData_SvLop(node);
	//		ThemNodeLopHoc(headSvLop, node);
	//	}
	//}
	//viewDsLop(headSvLop);

	return 0;
}