#pragma once
#include"variable.h"
#include"login.h"
#include"staff.h"
#include"student.h"
#include"display.h"
#include"console.h"
#include"windows.h"
int InMenuBatDau(int ma_tk);
//xai ke ham void LuaChon(int maxSelect); cua staff.cpp
bool XlMenuBD(int chon, short lc, string tk, string& mk);
