#include"DKKH.h"

int main()
{
	system("color F0");
	SetConsole();
	SetFontSize(18);
	string tk, mk;
	bool lc = true;//true là sv, false là gv
	ListNamHoc listNam;
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
			Thoat = XlMenuBD(InMenuBatDau(lc), lc, tk, mk, listNam);
		}while (!Thoat);
		//
	} 	while (true);
	return 0;
}