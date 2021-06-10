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
void TaiData_Nam(ListNamHoc& l);
void TaiData_Lop(NodeNamHoc* n);
NodeSvLop* TaiData_DsLop(NodeLop* nodeLop);
void ThemNodeSvLop(NodeSvLop*& headSvLop, NodeSvLop* n);
NodeSvLop* TaoNodeSv(Sv sv);
Sv findInfo(int id);
string timLop(int id);
void test();
void BackwardFile(ifstream& inFile, long& numBytes);
void readFile(char* fileName);
