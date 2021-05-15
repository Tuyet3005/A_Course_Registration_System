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
//bool checkAccount(string tk, string mk, short lc)
//{
//	ifstream f;
//	if (lc == 1) f.open("SinhVien.txt");
//	else f.open("GiaoVu.txt");
//	string acc, pass, s;
//	while (!f.eof())
//	{
//		acc = "";
//		pass = "";
//		s = "";
//		f >> s;
//		Split(s, acc, pass);
//		if (acc != tk)
//		{
//			continue;
//		}
//		if (pass == mk) return true;
//	}
//	f.close();
//	return false;
//}
bool checkAccount(string tk, string mk, short lc)
{
	ifstream f;
	if (lc == 1) f.open("HocSinh.txt");
	else f.open("GiaoVu.txt");
	string acc, pass, s;
	while (!f.eof())
	{
		f.clear();
		getline(f, acc, ',');
		f.clear();
		getline(f, pass, ',');
		f.clear();
		if (acc == tk && mk == pass) return true;
		getline(f, s);
	}
	f.close();
	return false;
}
bool checkLogIn(string& tk, string& mk, short& lc)
{
	do
	{
		system("cls");
		cout << "--------------------DANG NHAP------------------------" << endl;
		cout << "Nhap 1 neu ban la hoc sinh, 0 neu ban la giao vu" << endl;
		cout << "Moi nhap: ";
		cin >> lc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			lc = -1;
		}
	} while (lc != 0 && lc != 1);
	cout << endl;
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
	cout << "Nhap sai qua 5 lan!!!" << endl;
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
void changePass(short lc, string tk, string& mk)
{
	string oldpass, newpass;
	cout << "-----------------DOI MAT KHAU-----------------------" << endl;
	//cin.ignore();
	bool flag = false;
	while (!flag)
	{
		cout << "Nhap mat khau cu: ";
		cin.clear();
		getline(cin, oldpass);
		if (oldpass == mk) break;
		else cout << "Nhap sai mat khau... moi nhap lai !" << endl;
	}
	cout << "Nhap mat khau moi: ";
	cin.clear();
	getline(cin, newpass);
	ifstream f;
	if (lc == 1) f.open("HocSinh.txt");
	else f.open("GiaoVu.txt");
	string s = "";
	ofstream t;
	t.open("trunggian.txt");
	int pos = -1;
	while (!f.eof())
	{
		getline(f, s);
		pos = s.find(mk);
		if (pos != string::npos)
			s.replace(pos, mk.length(), newpass);
		t << s << endl;
		pos = -1;
	}
	mk = newpass;
	t.close();
	f.close();
	remove((lc == 1) ? "HocSinh.txt" : "GiaoVu.txt");
	rename("trunggian.txt", (lc == 1) ? "HocSinh.txt" : "GiaoVu.txt");
}