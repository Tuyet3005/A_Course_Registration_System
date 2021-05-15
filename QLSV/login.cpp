#include"login.h"
void Split(string s, string& tk, string& mk) //oke
{
	bool flag = true;
	char k;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.') flag = false;
		else if (flag) tk += s[i];
		else mk += s[i];
	}
}
bool checkAccount(string tk, string mk, short lc)
{
	ifstream f;
	if (lc == 1) f.open("HocSinh.txt");
	else f.open("GiaoVu.txt");
	string acc, pass, s;
	while (!f.eof())
	{
		acc = "";
		pass = "";
		s = "";
		f >> s;
		Split(s, acc, pass);
		if (acc != tk)
		{
			continue;
		}
		if (pass == mk) return true;
	}
	f.close();
	return false;
}
bool checkLogIn(string& tk, string& mk, short& lc)
{
	cout << "--------------------DANG NHAP------------------------" << endl;
	cout << "Nhap 1 neu ban la hoc sinh, 0 neu ban la giao vu" << endl;
	cout << "Moi nhap: ";
	cin >> lc;
	cin.ignore();
	char dem = 0;
	while (dem < 5)
	{
		cout << "Tai khoan: ";
		cin.clear();
		getline(cin, tk, '\n');
		cout << "Mat khau: ";
		cin.clear();
		getline(cin, mk, '\n');
		if (checkAccount(tk, mk, lc)) return true;
		else if (dem < 4) cout << "Ban da nhap sai... Moi nhap lai" << endl;
		dem++;
	}
	cout << "Nhap sai qua 5 lan, ban bi buoc thoat !!!" << endl;
	return false;
}
void LogIn(string& tk, string& mk, short& lc)//tra ve gia tri j do de co the xd dc cu the doi tuong nao dang dang nhap 
{
	if (checkLogIn(tk, mk, lc))
	{
		cout << "DANG NHAP THANH CONG" << endl;
	}
	else
	{
		cout << "DANG NHAP THAT BAI" << endl;
		exit(0);
	}
}