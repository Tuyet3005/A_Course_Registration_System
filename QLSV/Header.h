#pragma once
#include<iostream>
#include<string>
using namespace std;
struct Ngay
{
	int d;
	int m;
	int y;
};
//thoi gian cua hoc ky
struct ThoiGian
{
	Ngay ngay_bd;
	Ngay ngay_kt;
};
struct time
{
	int gio;
	int phut;
};
struct NodeMon
{
	MonHoc data;
	NodeMon* pNext;
};
struct ListMon
{
	NodeMon* pHead;
	NodeMon* pTail;
};
struct HocKy
{
	ListMon dsMon;
	ThoiGian tg;//thoi gian bd, kt
};
struct BuoiHoc
{
	string thu;//mon, tue, wed,...
	string buoi;//buoi(S1, S2, S3, S4)
	//S1 (07:30), S2(09:30), S3(13:30), S4(15:30)
};
struct Sv
{
	int stt;
	int id, cmnd;
	string ten, ho, gioi;
	Ngay ngayS;//ngaySinh
};
struct NodeSv
{
	Sv sv;
	NodeSv* pNext;
};
struct ListSv
{
	NodeSv* pHead;
	NodeSv* pTail;
};
struct LopHoc
{
	ListSv l;
	string ten;
};
struct NodeLop
{
	NodeLop* pNext;
	LopHoc lop;
};
struct ListLopHoc
{
	NodeLop* pHead;
	NodeLop* pTail;
};
struct MonHoc
{
	string id;
	string tenMon, tenGv;
	int so_tc;
	int MaxSv = 50;//sl sv toi da 
	BuoiHoc bh1, bh2;//hai buoi trong tuan
};
struct NamHoc
{
	ThoiGian tg;//chi cout nam (vd: tg.ngay_bd.y)
	HocKy hk1, hk2, hk3;
	ListLopHoc nam1, nam2, nam3, nam4;
};