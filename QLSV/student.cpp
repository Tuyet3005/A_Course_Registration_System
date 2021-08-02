#include"student.h"
#include"display.h"
#include"begin.h"
#include"DKKH.h"
int InMenuSv()
{
	system("cls");
	background_Sv();
	string title[5] = { "CAC MON HOC CUA TOI","DANG KI MON HOC","CAC MON DANG MO","QUAY VE","THOAT" };
	return LuaChon_Menu(5, title, 2, HEIGHT / 2);
}
Sv findInfo(string tenlop, int tk)//tim Info sv trong file Lop 
{
	ifstream f;
	f.open(tenlop + ".txt");
	string s;
	int acc;
	bool flag = false;
	Sv T;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		acc = stoi(s);
		if (acc == tk)
		{
			flag = true;
			T.id = tk;
			f.clear();
			getline(f, s, ',');
			T.stt = stoi(s);
			f.clear();
			getline(f, T.ten, ',');
			f.clear();
			getline(f, T.ho, ',');
			f.clear();
			getline(f, T.gioi, ',');
			f.clear();
			getline(f, s, ',');
			T.ngayS.d = stoi(s);
			T.ngayS.y = T.ngayS.d % 10000;
			T.ngayS.m = (T.ngayS.d / 10000) % 100;
			T.ngayS.d = T.ngayS.d / 1000000;
			f.clear();
			getline(f, s, ',');
			int size = s.length() + 1;
			T.cmnd = new char[size];
			strcpy_s(T.cmnd, size, s.c_str());
		}
		f.clear();
		getline(f, s);
	}
	if (flag)
	{

	}
	else
	{
		T.stt = NULL;
	}
	return T;
}
void SinhVien(ListNamHoc& l, int tk)
{
	NodeNamHoc* t = NodeNamHienTai(l);
	if (t == NULL)
		return;
	int namhientai = t->data.tg.ngay_bd.y;
	string tenlop = timLop(tk);
	NodeLop* plop = NULL;
	for (int i = 1; i <= 4; i++)
	{
		plop = timNodeLop(t, i, tenlop);
		if (plop == NULL)
			continue;
		break;
	}
	NodeSv_Lop* SV = timNodeSv_Lop(plop->lop.headSvLop, tk);
	bool Thoat = false;
	do
	{
		Thoat = XlMenuSv(InMenuSv(), l, SV);
	} while (!Thoat);
	system("cls");
}
bool XlMenuSv(int chon, ListNamHoc& l, NodeSv_Lop* A)
{
	char lenh;//thoat thi nhap Y/y
	bool Thoat = false;
	switch (chon)
	{
	case 1:
	{
		Xlviewmondk(A);
		break;
	}
	case 2:
	{
		DKKH_Sv(NodeNamHienTai(l), A, 0);
		break;
	}
	case 3:
	{
		DKKH_Sv(NodeNamHienTai(l), A, 1);
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		system("cls");
		background_Sv();
		if (Ask_YN("Ban thuc su muon THOAT?"))
		{
			gotoXY(0, HEIGHT - 4);
			exit(0);
		}
	}
	}
	return false;
}
//viewmondk
int chonKi(string cauhoi)
{
	setColor(background_color, title_color1);
	printA_Sentence(cauhoi, HEIGHT / 2 - 8);
	string title[] = { "KI 1","KI 2","KI 3" };
	return LuaChon_Menu(3, title, 2, HEIGHT / 2 - 5);
}
void Xlviewmondk(NodeSv_Lop* A)
{
	system("cls");
	int ki = chonKi("Ban muon xem ds mon cua ki may?");
	system("cls");
	setColor(background_color, red);
	printA_Sentence("Ban muon xem gi ?", HEIGHT / 2 - 4);
	string title[2] = { "THONG TIN LOP HOC","BANG DIEM" };
	if (LuaChon_Menu(2, title, 4, HEIGHT / 2 - 2) == 1)
	{
		system("cls");
		viewMondaDk(A->headMon[ki - 1], (int)ki, 2);
	}
	else
	{
		viewSvScore(A, ki);
	}
	setColor(background_color, title_color1);
	printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 5);
	char pause = _getch();
}