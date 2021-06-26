#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;
//THOI GIAN
struct Time
{
	int gio;
	int phut;
	int giay;
};
struct Ngay
{
	int d;
	int m;
	int y;
};
struct ThoiGian
{
	Ngay ngay_bd;
	Ngay ngay_kt;
};
struct Diem
{
	float gk, ck, cong, tongket;
};
struct Sv
{
	int stt;//dem tu 1
	int id, cmnd;
	string ten, ho, gioi;
	Ngay ngayS;//ngaySinh
	//int soMondk;//max=5
	//Diem diem;
};
//HOC KY
struct BuoiHoc
{
	string thu;//mon, tue, wed,...
	string buoi;//buoi(S1, S2, S3, S4)
	//S1 (07:30), S2(09:30), S3(13:30), S4(15:30)
};
struct MonHoc
{
	string id;
	string tenMon, tenGv;
	int so_tc;
	int MaxSv = 50;//sl sv toi da 
	BuoiHoc bh1, bh2;//hai buoi trong tuan
};
struct NodeSvMon
{
	int mssv;
	string lop;
	Diem diem;
	NodeSvMon* pNext;
};
struct NodeMon
{
	MonHoc data;
	NodeSvMon* headSvMon;
	NodeMon* pNext;
};
struct HocKy
{
	NodeMon* headMon;
	ThoiGian tg;//thoi gian bd, kt
};
//LOP HOC
struct NodeMonofSv
{
	NodeMon* mon;
	NodeMonofSv* pNext;
};
struct NodeSvLop
{
	Sv sv;
	NodeMonofSv* headMonhk1,* headMonhk2,* headMonhk3;
	NodeSvLop* pNext;
};
struct LopHoc
{
	NodeSvLop* headSvLop;
	string ten;
};
struct NodeLop
{
	NodeLop* pNext;
	LopHoc lop;
};
//NAM HOC
struct NamHoc
{
	ThoiGian tg;//chi cout nam (vd: tg.ngay_bd.y)
	HocKy hk1, hk2, hk3;
	NodeLop* headLopNam1;
	NodeLop* headLopNam2;
	NodeLop* headLopNam3;
	NodeLop* headLopNam4;//list lop hoc cua sv nam1, nam 2 ...
};
struct NodeNamHoc
{
	NamHoc data;
	NodeNamHoc* pNext;
};
struct ListNamHoc
{
	NodeNamHoc* pHead;
	NodeNamHoc* pTail;
};