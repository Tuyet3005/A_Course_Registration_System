#pragma once
#include"variable.h"
#include"student.h"
#include"console.h"
void drawTable(int Row, int Col, int posCol[], int posRow);
int viewDsSvLop(NodeLop* A);
int viewDsMonHk(NodeMon* head, int ki);//tra ve so mon dung trong dkhp
int viewDsSvMon(NodeMon* A);
int viewDsKi(NodeNamHoc* A);
int viewDsNam(ListNamHoc A);
int viewDsLop(NodeLop* head);
void viewInfoSv(Sv A);
int viewMondaDk(NodeMon_Sv* A, int ki,int line);
int viewSvScore(NodeSv_Lop* sv, int ki);
void tinhGPA_SvvaLop(NodeLop* t, int ki);
int viewDiem_Lop(NodeLop* A, int ki);
void viewInfoGV(Sv A);

//giao dien
void background();
void background_Sv();
void background_Gv();
void background_Login();

//ve
void veHCN(int bd_x, int bd_y, int kt_x, int kt_y);

int LuaChon_Menu(int title_number, string title[] ,int cell_height,int line);

int LuaChon_HienThi(int line, int max, int title_number, string title[]);

//int LuaChon_DKKH(int line, int max);

void printA_Sentence(string a, int line);

//DKKH
void nhapNgay_ve(int line);

Ngay nhapNgay_nhap(int line);

void nhapGio_ve(int line);

Time nhapGio_nhap(int line);

//nhap Ngay: func=0 else nhap Gio
void nhapNgay_Gio_xoa(int line, int func);