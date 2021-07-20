#pragma once
#include"variable.h"
#include"staff.h"
tm ThoiGianHeThong();
int NHhientai_nambd();
NodeNamHoc* NodeNamHienTai(ListNamHoc& l);
//check nhap ngay thang nam hop le 
bool NgayHopLe(int nDay, int nMonth, int nYear);
int SoNgayTrongThang(int nMonth, int nYear);
bool NamNhuan(int nYear);
bool GioHopLe(Time t);
Ngay _30ngaysau(Ngay ngaybd);