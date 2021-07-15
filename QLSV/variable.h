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
	int gio = NULL;
	int phut = NULL;
	int giay = NULL;
};
struct Ngay
{
	int d = NULL;
	int m = NULL;
	int y = NULL;
};
struct ThoiGian
{
	Ngay ngay_bd;
	Ngay ngay_kt;
};
//HOC KY
struct Diem
{
	float gk = NULL;
	float ck = NULL;
	float cong = NULL;
	float tongket = NULL;
};
struct BuoiHoc
{
	string thu;//mon, tue, wed,...
	string buoi;//buoi(S1, S2, S3, S4)
	//S1 (07:30), S2(09:30), S3(13:30), S4(15:30)
};
struct MonHoc
{
	string id = " ";
	string tenMon = "", tenGv = "";
	int so_tc = 0;
	int MaxSv = 50;//sl sv toi da 
	BuoiHoc bh1, bh2;//hai buoi trong tuan
	int num_Sv = 0;
};
struct NodeSv_Mon
{
	int mssv;
	string lop;
	Diem diem;
	NodeSv_Mon* pNext;
};
struct NodeMon
{
	MonHoc data;
	NodeSv_Mon* headSvMon;
	NodeMon* pNext;
};
struct HocKy
{
	NodeMon* headMon;
	ThoiGian tg;//thoi gian bd, kt
};
//LOP HOC
struct Sv
{
	int stt;//dem tu 1
	int id, cmnd;
	string ten, ho, gioi;
	Ngay ngayS;//ngaySinh
};
struct NodeMon_Sv
{
	NodeMon* mon;//thong tin chung cua mon hoc 
	NodeSv_Mon* svMon;//mssv, diem cua sv 
	NodeMon_Sv* pNext;
};
struct NodeSv_Lop
{
	Sv sv;
	NodeMon_Sv** headMon = new NodeMon_Sv * [3];//list mon cua 3 hk 
	NodeSv_Lop* pNext;
	float GPA[3] = { NULL,NULL,NULL };//GPA lan luot 3 ki
};
struct LopHoc
{
	NodeSv_Lop* headSvLop = NULL;
	string ten;
	float GPA[3] = { NULL,NULL,NULL };//GPA trung binh
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
	HocKy hk[3];
	NodeLop** headLop=new NodeLop*[4];//list lop hoc cua sv nam1, nam 2 ...
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

