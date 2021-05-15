#pragma once
#include"variable.h"
void Split(string s, string& tk, string& mk);
bool checkAccount(string tk, string mk, short lc);
bool checkLogIn(string& tk, string& mk, short& lc);
void changePass(short lc, string tk, string& mk);
void LogIn(string& tk, string& mk, short& lc);
