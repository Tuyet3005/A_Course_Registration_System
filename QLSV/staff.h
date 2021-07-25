#pragma once
#include"begin.h"

int InMenuGv();
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
void NhapThongtinSv(NodeSv_Lop* n, int i);
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head);
void GhiThongtinSv(NodeLop* nodeLop, NodeSv_Lop* n);
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* nodeSv);
void ThemSvLop_tay(NodeLop* nodeLop);
void ThemSvLop_file(NodeLop* nodeLop);
void ThemSvLopNam1(ListNamHoc& l);
//nhap -> tim -> sua 
NodeNamHoc* ChonNamHoc(ListNamHoc l, int nam_hoc);
NodeNamHoc* NhapNamHoc(ListNamHoc l);
HocKy* NhapHocKy(NodeNamHoc* node_nam);
HocKy* TimHocKy(ListNamHoc l);
//sua info mon
NodeMon* ChonMonHoc(HocKy* hk, string id_mon_hoc);
void HienThiDSMon(NodeMon*& head_mon);
NodeMon* NhapMonHoc(HocKy* hoc_ky);
NodeMon* NhapMonHoc(ListNamHoc l);
void GhiFileMon(string filename, NodeMon* mon, bool remove);
void LuuMonHoc(ListNamHoc& l, NodeMon* node_mon, bool remove = false);
void CapNhatMonHoc(ListNamHoc& l);
//xoa mon
void XoaMonHoc(ListNamHoc& l);
//diem 
void XuatFileCsv(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);
bool DocDiemTuFile(string file, NodeMon* mon, int siso);
void NhapDiemTuFile(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);
void CapNhatDiemSv(ListNamHoc& l);
float NhapDiem(float diem);
void LuuDiemSv(string filename, NodeSv_Mon* node_sv_mon);
void HienThiDSLop(NodeLop* head_lop);
void HienThiDSSv(NodeSv_Lop* head_sv_lop);

//HIENTHI
//neu chua co du lieu
void hienthiNam(ListNamHoc l, int& lc);
//ki
void hienthiKi(NodeNamHoc* A, int& lc);
void hienthiDsMon(NodeMon* head, int& lc);
void hienthiDsSv_Mon(NodeMon* A, int& lc);
void end(int& lc);
int chonSt_Year();
//lop
bool ChonTThayDiem_Lop();
void hienthiDsLop(NodeLop* head, int& lc);
void hienthiTTSv_Lop(NodeLop* A, int& lc);
void hienthiDiem_Lop(NodeLop* A, int& lc);
bool ChonKihayLop();