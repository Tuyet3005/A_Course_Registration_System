#pragma once
#include"variable.h"
#include"display.h"
#include<conio.h>
#include<string>
void xuatLC(int* kq, int n);
void changeLC(int* kq, int dem, int mon);
int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head);
NodeMon_Sv* DKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head);
//GV
void taoDKKH_Gv(int nam);
void askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT, int nam);
void xuatFile_DKKH(ThoiGian& tg, Time& tmBD, Time& tmKT, int nam);

