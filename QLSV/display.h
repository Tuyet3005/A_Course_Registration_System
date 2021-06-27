#pragma once
#include"variable.h"
#include"student.h"
#include"console.h"
void drawTable(int Row, int Col, int posCol[], int posRow);
void viewDsSvLop(LopHoc A);
void BackGround();
int viewDsMonHk(NodeMon* head, int ki);//tra ve so mon dung trong dkhp
void viewDsSvMon(NodeMon A);
void viewDsKi(NamHoc A);
void viewDsNam(ListNamHoc A);
void viewDsLop(NodeLop* head, int nam, int namhoc);
void viewInfoSv(Sv A);
void viewMondaDk(NodeMon_Sv* A, int ki);
void viewSvScore(NodeSv_Lop* sv, int ki);
bool tinhGPA_SvvaLop(NodeLop* t, int ki);