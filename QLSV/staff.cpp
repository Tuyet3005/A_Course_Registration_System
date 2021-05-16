#include"staff.h"
#include"login.h"//phuc vu chuc nang log out
//giao dien Giao vu
int InMenuGv()
{
	system("cls");
	cout << "------HE THONG QUAN LY SINH VIEN------\n";
	cout << "	1. Tao moi\n";
	cout << "	2. Cap nhat\n";
	cout << "	3. Hien thi\n";
	cout << "	4. Dang xuat\n";
	cout << "	5. Thoat\n";
	cout << "--------------------------------------\n";
	return 5;//lua chon lon nhat la 5
}
int LuaChon(int maxChoice)
{
	int chon;
	do
	{
		cout << "Nhap lua chon cua ban: " << endl;
		cin >> chon;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			chon = 0;
		}
	}
	//trong khoang lua chon, dung kieu du lieu
	while (cin.fail() || chon < 1 || chon > maxChoice);
	return chon;
}
bool XlMenuGv(int chon)
{
	char lenh;//thoat thi nhap Y/y
	switch (chon)
	{
	case 1:
	{
		cout << "tao moi" << endl;
		system("pause");
		break;
	}
	case 2:
	{
		cout << "cap nhat" << endl;
		system("pause");
		break;
	}
	case 3:
	{
		cout << "hien thi" << endl;
		system("pause");
		break;
	}
	case 4:
	{
		cout << "Ban se dang xuat ra khoi tai khoan nay? Y?N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
			return true;
		system("pause");
		break;
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
void GiaoVu()
{
	bool Thoat = false;
	do
	{
		Thoat = XlMenuGv((LuaChon(InMenuGv())));
	} while (!Thoat);
	system("cls");
}
