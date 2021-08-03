#pragma once
#include"variable.h"
bool checkAccount(string tk, string mk, bool lc);
bool changePass(bool role, string tk, string& mk);
void LogIn(string& tk, string& mk, bool& lc);
string typePass();
string typeAccount();