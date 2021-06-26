#include"student.h"
int InMenuSv()
{
	system("cls");
	cout << "------HE THONG QUAN LY SINH VIEN------\n";
	cout << "\t <Giao dien sinh vien>\n";
	cout << "	1. Cac mon hoc cua toi\n";
	cout << "	2. Dang ky mon hoc \n";//co the dk them hoac xoa -> check conflict 
	cout << "	3. Cac lop hoc dang mo\n";
	cout << "	4. Cac mon hoc dang mo\n";
	cout << "	5. Quay ve \n";
	cout << "	6. Thoat\n";
	cout << "--------------------------------------\n";
	return 6;//lua chon lon nhat la 6
}
Sv findInfo(string tenlop, int tk)//tim Info sv
{
	ifstream f;
	f.open(tenlop + ".txt");
	string s;
	int acc;
	bool flag = false;
	Sv T;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		acc = stoi(s);
		if (acc == tk)
		{
			flag = true;
			T.id = tk;
			f.clear();
			getline(f, s, ',');
			T.stt = stoi(s);
			f.clear();
			getline(f, T.ten, ',');
			f.clear();
			getline(f, T.ho, ',');
			f.clear();
			getline(f, T.gioi, ',');
			f.clear();
			getline(f, s, ',');
			T.ngayS.d = stoi(s);
			T.ngayS.y = T.ngayS.d % 10000;
			T.ngayS.m = (T.ngayS.d / 10000) % 100;
			T.ngayS.d = T.ngayS.d / 1000000;
			f.clear();
			getline(f, s, ',');
			T.cmnd = stoi(s);
		}
		f.clear();
		getline(f, s);
	}
	if (flag)
	{

	}
	else
	{
		T.stt = NULL;
	}
	return T;
}
void SinhVien(ListNamHoc& l)
{
	bool Thoat = false;
	do
	{
		Thoat = XlMenuSv((LuaChon(InMenuSv())), l);
	} while (!Thoat);
	system("cls");
}
bool XlMenuSv(int chon, ListNamHoc& l)
{
	char lenh;//thoat thi nhap Y/y
	bool Thoat = false;
	switch (chon)
	{
	case 1:
	{
		//my course 
		//hien thi cac mon hoc cua sv da hoc va dk 
		system("pause");
		break;
	}
	case 2:
	{
		//course registration
		//xem cac mon da dk trong hk hien tai 
		//dk mon hoc, chinh sua dk mon <chuc nang chi hoat dong trong tg mo dk mon hoc
		system("pause");
		break;
	}
	case 3:
	{
		//opened class
		//hien thi cac lop hoc, dssv_lop 
		system("pause");
		break;
	}
	case 4:
	{
		//opened course
		//hien thi cac mon va dssv_mon  
	}
	case 5:
	{
		return true;
	}
	case 6:
	{
		cout << "Ban thuc su muon thoat? Y/N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
		{
			exit(0);
		}
	}
	}
	return false;
}
//sv log in (doc tu file -> biet lop -> tim node lop cua sv do -> tim nodesv)
