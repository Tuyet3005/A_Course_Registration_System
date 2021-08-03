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
NodeNamHoc* TaoNodeNam(ListNamHoc& l);
void ThemNodeNamHoc(ListNamHoc& l, NodeNamHoc* n);
void TaiNam234(NodeNamHoc*& namT, NodeNamHoc*& namS);
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
bool TaoHocKy(ListNamHoc& l);
//mon hoc 
HocKy* HkHienTai(ListNamHoc& l, NodeNamHoc* n, int& i);
bool NhapNodeMon(NodeMon* n);
int HienLuaChonThu(int line);
string HienLuaChonGio(int line);
void XulyThu(int lc, BuoiHoc& bh);
void NhapTgMon(NodeMon* n);
bool checkTrungMon(NodeMon* head, NodeMon* n);
void TaoMon(ListNamHoc& l, int nam);
NodeMon* mondangmo_docfile(string file, int nam, int stt_hk);
NodeMon* mondangmo_nhaptay(int nam, int stt_hk);

//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l);
int InMenuCapNhat();
int InMenuCapNhat2(); //muc 2 cua menu cap nhat chinh
int InMenuCapNhat3(); //muc 3 cua menu cap nhat chinh
//them sv
void NhapThongtinSv(NodeSv_Lop* n, int i, int k);//i: stt them sv ; k: k19, k20...
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head);
void GhiThongtinSv(NodeLop* nodeLop, NodeSv_Lop* n);
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* nodeSv);
NodeSv_Lop* ThemSvLop_tay(NodeLop* nodeLop);
NodeSv_Lop* ThemSvLop_file(NodeLop* nodeLop);
void ThemSvLopNam1(ListNamHoc& l);
//sua info mon
void GhiFileMon(string filename, NodeMon* mon, bool remove);
void CapNhatMonHoc(ListNamHoc& l);
NodeMon* timNodeMon_CapNhat(ListNamHoc& l, NodeNamHoc*& NodeNam, int& ki, NodeMon*& headmonHK);
//xoa mon
void XoaMonHoc(ListNamHoc& l);
//xoa mon ra khoi ds mon cua sv (neu co sv dang ky)
bool XoaMon_Sv(ListNamHoc& l, NodeNamHoc* nodeNam, int ki, NodeMon*& headmonHK, NodeMon* mon);
//diem 
void XuatFileCsv(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);
bool DocDiemTuFile(string file, NodeMon* mon, int siso);
void NhapDiemTuFile(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk);

void CapNhatDiemSv(ListNamHoc& l);
void NhapDiem(float& diem, int x, int y);//x, y: toa do 
void LuuDiemSv(string filename, NodeSv_Mon* node_sv_mon);

//HIENTHI
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