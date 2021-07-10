#pragma once
#include"variable.h"
#include"display.h"
#include<conio.h>
#include<string>
//SV
bool readFileDKKH(ThoiGian& tg, Time& tmBD, Time& tmKT, int& ki, string& file);
bool sosanhNgayGio(Ngay tg1, Time t1, Ngay tg2, Time t2);
bool cobuoiDKKH(ThoiGian tg, Time tmBD, Time tmKT);
void xuatLC(NodeMon_Sv* A);
void xoaLC(int dem, int mon, NodeMon_Sv*& A, NodeMon* head);
int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head);
bool BuoiHocHopLe(NodeMon* mon, NodeMon_Sv* dadk);
void themMon(NodeMon_Sv*& A, int stt, NodeMon* head);
void runDKKH_Sv(NodeMon_Sv*& A, int ki, NodeMon* head);
void DKKH_Sv(NodeMon_Sv*& A, NodeMon* head);
//GV
void taoDKKH_Gv(int nam);
bool importFilehayNhapTay();
bool askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT, int ki);
bool xuatFile_DKKH(ThoiGian tg, Time tmBD, Time tmKT,int ki,string file);