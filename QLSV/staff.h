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
int HienNamHoc(ListNamHoc l);
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(string ten);
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop*& n);
void HienLopHoc(NodeLop* HeadLop);
void TaoLopNamNhat(NodeNamHoc* node);
//hoc ky
NodeNamHoc* TimNodeNamHoc(ListNamHoc& l, int nam_bd);
bool sosanhNgay(Ngay ngay_truoc, Ngay ngay_sau);
bool XungdotTg(HocKy* hktruoc, Ngay ngBD_hksau, int hkTr, int hkS);
void TaoHocKy(ListNamHoc& l);
//mon hoc 
HocKy* HkHienTai(ListNamHoc& l, NodeNamHoc* n, int& i);
void NhapNodeMon(NodeMon* n);
void XulyThu(int lc, BuoiHoc& bh);
void NhapTgMon(NodeMon* n);
//bool checkTrungMon(HocKy* hk, NodeMon* n);
void TaoMon(ListNamHoc& l, int nam);

//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);

//HIENTHI
//neu chua co du lieu
void hienthiNam(ListNamHoc l, int& lc);
int Chon(int maxChoice);
//ki
void hienthiKi(NodeNamHoc* A, int& lc);
void hienthiDsMon(NodeMon* head, int& lc);
void hienthiDsSv_Mon(NodeMon* A, int& lc);
void end(int& lc);
//lop
bool ChonTThayDiem_Lop();
void hienthiDsLop(NodeLop* head, int& lc);
void hienthiTTSv_Lop(NodeLop* A, int& lc);
void hienthiDiem_Lop(NodeLop* A, int& lc);
bool ChonKihayLop();


