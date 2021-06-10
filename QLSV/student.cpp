#include"student.h"
void SinhVien(ListNamHoc& l)
{
	cout << "giao dien cho sinh vien" << endl;
	cout << "dang hoan thien, chuan bi quay lai giao dien LOG IN ...";
	system("pause");
	system("cls");
	return;
}
Sv findInfo(string tenlop, int tk)//tim Info sv
{
	ifstream f;
	f.open(tenlop+".txt");
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
