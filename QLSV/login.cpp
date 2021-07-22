#include"login.h"
#include"display.h"

bool checkAccount(string tk, string mk, short lc)
{
	ifstream f;
	if (lc == 1) f.open("SinhVien.txt");
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

void LogIn(string& tk, string& mk, short& lc)
{
	system("cls");
	background_Login();
	string title[2] = { "SINH VIEN","GIAO VU" };
	lc=LuaChon_Dep(2, title);
	/*cout << "Nhap 1 neu ban la hoc sinh, 0 neu ban la giao vu" << endl;
	do
	{
		cout << "Moi nhap (0-1): ";
		cin >> lc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			lc = 2;
		}
	} 	while (lc < 0 || lc>1);*/
	system("cls");
	background_Login();
	setColor(background_color, title_color1);
	gotoXY(70, HEIGHT / 2 + 3);
	cout << "Tai khoan: ";
	gotoXY(70, HEIGHT / 2 + 7);
	cout << "Mat khau: ";//check mk bnh ki tu
	setColor(background_color, text_color);
	char dem = 0;
	while (dem < 5)
	{
		gotoXY(84, HEIGHT / 2 + 3);
		cin >> tk;
		cin.ignore();//xoa \n
		gotoXY(84, HEIGHT / 2 + 7);
		cin.clear();
		getline(cin, mk);
		if (checkAccount(tk, mk, lc)) break;
		else if (dem < 4)
		{
			gotoXY(88, 40);
			setColor(background_color, red);
			cout << "! MAT KHAU HOAC TAI KHOAN KHONG DUNG !";
			setColor(background_color, text_color);
			char a = _getch();
			gotoXY(88, 40);
			cout << "                                             ";
			gotoXY(84, HEIGHT / 2 + 3);
			cout << "                                          ";
			gotoXY(84, HEIGHT / 2 + 7);
			cout << "                                          ";
		}
		dem++;
	}
	if (dem == 5)
	{
		setColor(background_color, red);
		gotoXY(92, 38);
		cout << "! DANG NHAP THAT BAI !" << endl;
		gotoXY(88, 40);
		cout << "Nhap sai 5 lan... Ban bi buoc thoat" << endl;
		system("pause");
		exit(0);
	}
	else
	{
		setColor(background_color, title_color);
		gotoXY(92, 40);
		cout << "~ DANG NHAP THANH CONG ~" << endl;
	}
	cout << endl;
	setColor(background_color, text_color);
	system("pause");
}

void changePass(short lc, string tk, string& mk)
{
	string oldpass, newpass;
	system("cls");
	cout << "-----------------DOI MAT KHAU-----------------------" << endl;
	cin.ignore();
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
	if (lc == 1) f.open("SinhVien.txt");
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
	remove((lc == 1) ? "SinhVien.txt" : "GiaoVu.txt");
	rename("trunggian.txt", (lc == 1) ? "SinhVien.txt" : "GiaoVu.txt");
}
