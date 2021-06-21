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
NodeNamHoc* TaoNodeNam();
void ThemNodeNamHoc(ListNamHoc& l, NodeNamHoc* n);
void HienNamHoc(ListNamHoc l);
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(string ten);
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop*& n);
void HienLopHoc(NodeLop* HeadLop);
void TaoLopNamNhat(NodeNamHoc* node);
//hoc ky 
void TaoHocKy(ListNamHoc& l);
NodeNamHoc* TimNodeNamHoc(ListNamHoc& l, int nam_bd);
//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);