#pragma once
#include"variable.h"
#include"login.h"
#include"staff.h"
#include"student.h"
#include"display.h"
#include"console.h"
#include"realtime.h"
int InMenuBatDau(int ma_tk);
bool XlMenuBD(int chon, short lc, string tk, string& mk, ListNamHoc& l);
// TAI DU LIEU TU FILE LEN HE THONG
//NAM HOC 
void TaiData_Nam(ListNamHoc& l);
//LOP HOC
NodeSv_Lop* TaoNodeSv(Sv sv);
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* n);
NodeSv_Lop* TaiData_SvLop(NodeLop* nodeLop);
void TaiData_Lop(NodeNamHoc* n);
//MON HOC 
void ThemNodeMon(NodeMon*& A, NodeMon* T);
NodeLop* timNodeLop(NodeNamHoc* namhoc, int styear, string lop);
NodeSv_Lop* timNodeSv_Lop(NodeSv_Lop* head, int mssv);
//Sv findInfo(int id); //can cai tien them 
void ThemNodeMon_Sv(NodeMon_Sv*& head, NodeMon* A, NodeSv_Mon* sv_mon);
void TaiData_SvMon(NodeMon*& mon, NodeNamHoc* nodeNam, int ki);
void TaiData_Mon(NodeNamHoc* n);
