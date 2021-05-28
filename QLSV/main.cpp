#include"startMenu.h"
int main()
{
	string tk, mk;
	short lc = 1;//Ma tk:  0: giao vu ; 1: sinh vien
	ListNamHoc listNam;
	listNam.pHead = listNam.pTail = NULL;
	//tai du lieu list nam hoc tu file len he thong
	TaiNamTuFile(listNam);
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
}