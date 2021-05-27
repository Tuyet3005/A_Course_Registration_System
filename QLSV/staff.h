#pragma once
#include"variable.h"
#include"realtime.h"
int InMenuGv();
int LuaChon(int maxChoice);
bool XlMenuGv(int chon, ListNamHoc& l);
void GiaoVu(ListNamHoc& l);
//TAO MOI
int InMenuTaoMoi(int chon);
bool XlTaoMoi(int chon, ListNamHoc& l);
//nam hoc
NodeNamHoc* TaoNodeNam();
void ThemNamHoc(ListNamHoc& l, NodeNamHoc* n);
int HienNamHoc();
void TaiNamTuFile(ListNamHoc& l);
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(string ten);
void ThemLopHoc(ListLopHoc& l, NodeLop* n);
int HienLopHoc(ListLopHoc l);
string TaiLopTuFile(ListNamHoc& l, NodeNamHoc* n);//tai lop tu file len he thong
void TaoLopNamNhat(ListNamHoc& l);
//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);