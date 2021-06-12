#include"begin.h"
int main()
{
	string tk, mk;
	short lc = 1;//Ma tk:  0: giao vu ; 1: sinh vien
	//ListNamHoc listNam;
	//ds tam luu dia chi nodeSv lop
	l.pHead = l.pTail = NULL;
	//tai du lieu list nam hoc tu file len he thong
	TaiData_Nam(l);
	do
	{
		bool Thoat = false;
		LogIn(tk, mk, lc);//dn sai thi tu dong thoat ra luon
		system("cls");
		do
		{
			Thoat = XlMenuBD(LuaChon(InMenuBatDau(lc)), lc, tk, mk, l);
		} 		while (!Thoat);
		//
	} 	while (true);

	return 0;
}