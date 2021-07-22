#pragma once
#include"variable.h"
#include"student.h"
#include"console.h"
void drawTable(int Row, int Col, int posCol[], int posRow);
int viewDsSvLop(NodeLop* A);
void BackGround();
int viewDsMonHk(NodeMon* head, int ki);//tra ve so mon dung trong dkhp
int viewDsSvMon(NodeMon* A);
int viewDsKi(NodeNamHoc* A);
int viewDsNam(ListNamHoc A);
int viewDsLop(NodeLop* head);
void viewInfoSv(Sv A);
int viewMondaDk(NodeMon_Sv* A, int ki);
int viewSvScore(NodeSv_Lop* sv, int ki);
bool tinhGPA_SvvaLop(NodeLop* t, int ki);
int viewDiem_Lop(NodeLop* A, int ki);
void viewInfoGV(Sv A);