#pragma once
#include"variable.h"
#include"realtime.h"
#include"begin.h"

int InMenuGv();
int LuaChon(int maxChoice);
bool XlMenuGv(int chon, ListNamHoc& l);
void GiaoVu(ListNamHoc& l);

void ThongbaoCautrucFile(bool chon);
bool importFilehayNhapTay(bool chon);

//TAO MOI
int InMenuTaoMoi();
bool XlTaoMoi(int chon, ListNamHoc& l);
//nam hoc
NodeNamHoc* TaoNodeNam();
void ThemNodeNamHoc(ListNamHoc& l, NodeNamHoc* n);
int HienNamHoc(ListNamHoc l);
void TaoNam(ListNamHoc& l);
//lop hoc
NodeLop* TaoNodeLop(string ten);
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop* n);
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
void HienLuaChonThu(int buoi);
void HienLuaChonGio();
void XulyThu(int lc, BuoiHoc& bh);
void NhapTgMon(NodeMon* n);
bool checkTrungMon(HocKy* hk, NodeMon* n);
void TaoMon(ListNamHoc& l, int nam);
void mondangmo_docfile(string file, int nam, HocKy* hk, int stt_hk);
void mondangmo_nhaptay(int nam, HocKy* hk, int stt_hk);

//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);
int InMenuCapNhat();
int InMenuCapNhat2(); //muc 2 cua menu cap nhat chinh
int InMenuCapNhat3(); //muc 3 cua menu cap nhat chinh
//them sv
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head);
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* nodeSv);
void NhapThongtinSv(NodeSv_Lop* n, int i);
void ThemSvLop_tay(NodeLop* nodeLop);
void ThemSvLop_file(NodeLop* nodeLop);
void ThemSvLopNam1(ListNamHoc& l);

void XuatFileCsv(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);
bool DocDiemTuFile(string file, NodeMon* mon, int siso);
void NhapDiemTuFile(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);

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