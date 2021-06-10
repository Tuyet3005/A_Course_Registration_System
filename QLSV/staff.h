#pragma once
#include"variable.h"
#include"realtime.h"
#include"begin.h"
int InMenuGv();
int LuaChon(int maxChoice);
bool XlMenuGv(int chon, ListNamHoc& l);
void GiaoVu(ListNamHoc& l);
//TAO MOI
int InMenuTaoMoi(int chon);
bool XlTaoMoi(int chon, ListNamHoc& l);
//nam hoc
NodeNamHoc* TaoNodeNam(ListNamHoc& l);
void ThemNodeNamHoc(ListNamHoc& l, NodeNamHoc* n);
int HienNamHoc();
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(string ten);
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop* n);
int HienLopHoc(NodeLop* HeadLop);
void TaoLop(NodeNamHoc* node);
//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);