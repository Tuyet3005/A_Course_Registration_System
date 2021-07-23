#include"login.h"
#include"display.h"

bool checkAccount(string tk, string mk, bool lc)
{
	ifstream f;
	if (lc) f.open("SinhVien.txt");
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

void LogIn(string& tk, string& mk, bool& lc)
{
	system("cls");
	background_Login();
	string title[2] = { "SINH VIEN","GIAO VU" };
	lc=LuaChon_Dep(2, title)-2;
	system("cls");
	background_Login();
	setColor(background_color, title_color1);
	gotoXY(65, HEIGHT / 2 + 3);
	cout << "Tai khoan: ";
	gotoXY(65, HEIGHT / 2 + 7);
	cout << "Mat khau: ";//check mk bnh ki tu
	setColor(background_color, text_color);
	char dem = 0;
	while (dem < 5)
	{
		gotoXY(80, HEIGHT / 2 + 3);
		cin >> tk;
		cin.ignore();//xoa \n
		gotoXY(80, HEIGHT / 2 + 7);
		cin.clear();
		getline(cin, mk);
		if (checkAccount(tk, mk, lc)) break;
		else if (dem < 4)
		{
			setColor(background_color, red);
			printA_Sentence("! MAT KHAU HOAC TAI KHOAN KHONG DUNG !", HEIGHT - 6);
			setColor(background_color, text_color);
			char a = _getch();
			printA_Sentence("                                          ", HEIGHT - 6);
			gotoXY(80, HEIGHT / 2 + 3);
			cout << "                                          ";
			gotoXY(80, HEIGHT / 2 + 7);
			cout << "                                          ";
		}
		dem++;
	}
	if (dem == 5)
	{
		setColor(background_color, red);
		printA_Sentence("! DANG NHAP THAT BAI !", HEIGHT - 7);
		printA_Sentence("Nhap sai 5 lan... Ban bi buoc thoat", HEIGHT - 5);
		cout << endl;
		system("pause");
		exit(0);
	}
	else
	{
		setColor(background_color, title_color);
		printA_Sentence("~ DANG NHAP THANH CONG ~", HEIGHT - 6);
	}
	cout << endl;
	setColor(background_color, text_color);
	system("pause");
}

void changePass(bool role, string tk, string& mk)
{
	string oldpass, newpass;
	system("cls");
	cout << "-----------------DOI MAT KHAU-----------------------" << endl;
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
	if (role) f.open("SinhVien.txt");
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
	}
	mk = newpass;
	t.close();
	f.close();
	remove((role) ? "SinhVien.txt" : "GiaoVu.txt");
	rename("trunggian.txt", (role) ? "SinhVien.txt" : "GiaoVu.txt");
}
