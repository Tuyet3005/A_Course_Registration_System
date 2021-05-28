#include"student.h"
void SinhVien()
{
	cout << "giao dien cho sinh vien" << endl;
	cout << "dang hoan thien, chuan bi quay lai giao dien LOG IN ...";
	system("pause");
	system("cls");
	return;
}
void Init(ListSv& list)
{
	list.pHead = NULL;
	list.pTail = NULL;
}
Sv findInfo(string tk)//tim Info, tui viet de lam cai xuat ds lop thu voi tien dung sau luon
{
	ifstream f;
	f.open("SinhVien.txt");
	string acc, s;
	bool flag = false;
	while (!f.eof())
	{
		f.clear();
		getline(f, acc, ',');
		if (acc == tk)
		{
			f.clear();
			getline(f, s, ',');
			flag = true;
			break;
		}
		f.clear();
		getline(f, s);
	}
	Sv T;
	if (flag)
	{
		T.id = stoi(tk);
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
	else
	{
		T.stt = NULL;
	}
	return T;
}
