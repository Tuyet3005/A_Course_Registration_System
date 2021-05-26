#pragma once
#include"variable.h"
int InMenuGv();
int LuaChon(int maxChoice);
bool XlCapNhat(int chon, ListNamHoc& l);
//bool HienThi();
bool XlMenuGv(int chon, ListNamHoc& l);
void GiaoVu(ListNamHoc& l);
//TAO MOI
int InMenuTaoMoi(int chon);
bool XlTaoMoi(int chon, ListNamHoc& l);
//nam hoc
NodeNamHoc* CheckNamHienTai(ListNamHoc& l, string& nam_bd);//check nam co dc nhap trong listnam
NodeNamHoc* TaoNodeNam();
void ThemNamHoc(ListNamHoc& l, NodeNamHoc* n);
int HienNamHoc();
void TaiNamTuFile(ListNamHoc& l);
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(ListNamHoc& l);
void ThemLopHoc(ListLopHoc& l, NodeLop* n);
int HienLopHoc();
void TaiLopTuFile(ListNamHoc& l, string& file);
void TaoLopNamNhat(ListNamHoc& l);