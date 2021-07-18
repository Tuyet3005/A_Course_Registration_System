#include"student.h"
#include"display.h"
#include"begin.h"
#include"DKKH.h"
int InMenuSv()
{
	system("cls");
	cout << "------HE THONG QUAN LY SINH VIEN------\n";
	cout << "\t <Giao dien sinh vien>\n";
	cout << "	1. Cac mon hoc cua toi\n";
	cout << "	2. Dang ky mon hoc \n";//co the dk them hoac xoa -> check conflict 
	cout << "	3. Cac mon hoc dang mo\n";
	cout << "	4. Quay ve \n";
	cout << "	5. Thoat\n";
	cout << "--------------------------------------\n";
	return 5;//lua chon lon nhat la 6
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
void SinhVien(ListNamHoc& l,int tk)
{
	NodeNamHoc* t = NodeNamHienTai(l);
	int namhientai = t->data.tg.ngay_bd.y;
	string tenlop = timLop(tk);
	NodeLop* plop;
	for (int i = 1; i <= 4; i++)
	{
		plop = timNodeLop(t, i,tenlop);
		if (plop == NULL)
			continue;
		break;
	}
	NodeSv_Lop* SV = timNodeSv_Lop(plop->lop.headSvLop, tk);
	bool Thoat = false;
	do
	{
		Thoat = XlMenuSv((LuaChon(InMenuSv())), l,SV);
	} while (!Thoat);
	system("cls");
}
bool XlMenuSv(int chon, ListNamHoc& l, NodeSv_Lop* A)
{
	char lenh;//thoat thi nhap Y/y
	bool Thoat = false;
	switch (chon)
	{
	case 1:
	{
		Xlviewmondk(A);
		system("pause");
		break;
	}
	case 2:
	{
		
		DKKH_Sv(NodeNamHienTai(l),A, 0);
		//course registration
		//xem cac mon da dk trong hk hien tai 
		//dk mon hoc, chinh sua dk mon <chuc nang chi hoat dong trong tg mo dk mon hoc
		system("pause");
		break;
	}
	case 3:
	{
		DKKH_Sv(NodeNamHienTai(l), A, 1);
		//opened course
		//hien thi cac mon
		system("pause");
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
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
//viewmondk
char chonKi()
{
	system("cls");
	cout << "Ban muon xem mon da dk cua ki may ? 1/2/3?" << endl;
	cout << "Hay nhan phim tuong uong" << endl;
	char k;
	while (true)
	{
		if (_kbhit())
		{
			k = _getch();
			if (k >= 49 && k <= 51)
			{
				return k - 48;
			}
		}
	}
}
void Xlviewmondk(NodeSv_Lop* A)
{
	char ki = chonKi();
	system("cls");
	viewMondaDk(A->headMon[ki-1], (int)ki);
}
