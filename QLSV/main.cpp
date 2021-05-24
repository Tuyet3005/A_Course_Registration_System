#include"startMenu.h"
int main()
{
	string tk, mk;
	short lc = 1;//Ma tk:  0: giao vu ; 1: sinh vien
	do
	{
		bool Thoat = false;
		LogIn(tk, mk, lc);//dn sai thi tu dong thoat ra luon
		system("cls");
		do
		{
			Thoat = XlMenuBD(LuaChon(InMenuBatDau(lc)), lc, tk, mk);
		} 		while (!Thoat);
		//
	} 	while (true);
}