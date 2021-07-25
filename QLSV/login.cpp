#include"login.h"
#include"display.h"

string typePass()
{
	string pass = "";
	int dem = 0;
	//luu toa do ban dau 
	int x = whereX();
	int y = whereY();
	do
	{
		char c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (dem == 0)
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			dem--;
			pass = pass.substr(0, dem);
		}
		else if (c == '\r' || c == '\n')
		{
			if (dem < 5)//ko dc enter khi mk it hon 5 ki tu 
				continue;
			else
				break;
		}
		else
		{
			pass += c;
			dem++;
			cout << "*";
		}
	} while (dem < 20);
	return pass;
}
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
	lc=LuaChon_Menu(2, title,4, HEIGHT / 2)-2;
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
		mk = typePass();
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
		oldpass = typePass();
		if (oldpass == mk) break;
		else cout << "\nNhap sai mat khau... moi nhap lai!" << endl;
	}
	while (true)
	{
		cout << "\nNhap mat khau moi (it nhat 5 ki tu, toi da 20 ki tu): ";
		cin.clear();
		newpass = typePass();
		if (newpass != mk)
			break;
		else
		{
			cout << "\nMat khau moi phai khac voi mat khau cu!\n";
			cout << "Ban co muon tiep tuc nhap mat khau moi? Nhap Y de tiep tuc: ";
			char lenh;
			cin >> lenh;
			if (lenh != 'Y' && lenh != 'y')
			{
				cout << "Doi mat khau khong thanh cong!\n";
				system("pause");
				return;
			}
		}
	}
	cout << "\nNhap lai mat khau moi de xac nhan: ";
	if (typePass() != newpass)
	{
		cout << "\nDoi mat khau khong thanh cong!\n";
		system("pause");
		return;
	}
	ifstream f;
	if (role) f.open("SinhVien.txt");
	else f.open("GiaoVu.txt");
	string s = "";
	ofstream t;
	t.open("trunggian.txt");
	int pos = -1;
	getline(f, s, ',');
	t << s << ',';
	//tr.hop tim thay tk ngay 1st line
	if (s == tk)
	{
		getline(f, s);//lay phan con lai cua line
		pos = s.find(mk);
		if (pos != string::npos)
		{
			s.replace(pos, mk.length(), newpass);
		}
		t << s;
	}
	else
	{
		while (true)//chac chan SE tim duoc tk thi moi den cuoi file !
		{
			getline(f, s);//lay tiep phan con lai cua dong truoc do (ko chua tk dang tim)
			t << s;
			f.clear();
			getline(f, s, ',');//chuyen sang dong ke (chac chan se tim thay tk roi moi eof)
			t << "\n" << s << ",";
			if (s == tk)
			{
				getline(f, s);
				pos = s.find(mk);
				if (pos != string::npos)
				{
					s.replace(pos, mk.length(), newpass);
				}
				t << s;
				break;
			}
		}
	}
	//da doi mk trong file --> sao chep toan bo du lieu con lai 
	while (!f.eof())
	{
		getline(f, s);
		if (s != "")
		{
			t << endl << s;
		}
	}
	mk = newpass;
	t.close();
	f.close();
	remove((role) ? "SinhVien.txt" : "GiaoVu.txt");
	rename("trunggian.txt", (role) ? "SinhVien.txt" : "GiaoVu.txt");
	cout << "\nDoi mat khau thanh cong!\n";
	system("pause");
}
