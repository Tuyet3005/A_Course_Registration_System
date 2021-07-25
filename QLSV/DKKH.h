#pragma once
#include"variable.h"
#include"display.h"
#include<conio.h>
#include<string>
//SV
void readFileDKKH(ThoiGian& tg, Time& tmBD, Time& tmKT, int& ki);
bool sosanhNgayGio(Ngay tg1, Time t1, Ngay tg2, Time t2);
bool cobuoiDKKH(ThoiGian tg, Time tmBD, Time tmKT);
void xoaLC(int dem, int mon, int ki, NodeSv_Lop* A, NodeMon* head); 
int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head);
bool BuoiHocHopLe(NodeMon* mon, NodeMon_Sv* dadk);
bool themMon(NodeSv_Lop* A, int ki, int stt, NodeMon* head);
void runDKKH_Sv(NodeSv_Lop* A, int ki, NodeMon*& head);
void DKKH_Sv(NodeNamHoc* HT, NodeSv_Lop*& A, int lc);
//GV
void taoDKKH_Gv(NodeNamHoc* H);
bool askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT, int ki);
bool xuatFile_DKKH(ThoiGian tg, Time tmBD, Time tmKT,int ki);
bool askY_N();
void nhapNgayGio(Ngay& ngay, Time& t);