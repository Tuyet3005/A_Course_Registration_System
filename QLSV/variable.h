#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
//
using namespace std;
//THOI GIAN
struct time
{
	int gio;
	int phut;
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
//LOP HOC
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
};
struct NodeSvLop
{
	Sv sv;
	NodeSvMon* headSvMonHk1, headSvMonHk2, headSvMonHk3;//ds mon ma 1 sv hoc
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
	//list lop hoc la nodelop* head
};
//HOC KY
struct BuoiHoc
{
	string thu;//mon, tue, wed,...
	string buoi;//buoi(S1, S2, S3, S4)
	//S1 (07:30), S2(09:30), S3(13:30), S4(15:30)
};
struct NodeSvMon
{
	NodeSvLop* sv;//thong tin sv
	Diem diem;
	NodeSvMon* pNext;
	NodeMon* mon;//thong tin mon 
};
struct MonHoc
{
	string id;
	string tenMon, tenGv;
	int so_tc;
	int MaxSv = 50;//sl sv toi da 
	BuoiHoc bh1, bh2;//hai buoi trong tuan
	NodeSvMon* head;
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
//NAM HOC
struct NamHoc 
{
	ThoiGian tg;//chi cout nam (vd: tg.ngay_bd.y)
	HocKy hk1, hk2, hk3;
	NodeLop* headLopNam1, headLopNam2, headLopNam3, headLopNam4;//list lop hoc cua sv nam1, nam 2 ...
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

