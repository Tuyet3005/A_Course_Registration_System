#include"staff.h"
//login.h??
//giao dien Giao vu
int InMenuGv()
{
	system("cls");
	cout << "------HE THONG QUAN LY SINH VIEN------\n";
	cout << "\t <Giao dien giao vu>\n";
	cout << "	1. Tao moi\n";
	cout << "	2. Cap nhat\n";
	cout << "	3. Hien thi\n";
	cout << "	4. Quay ve menu bat dau\n";
	cout << "	5. Thoat\n";
	cout << "--------------------------------------\n";
	return 5;//lua chon lon nhat la 5
}
int InMenuTaoMoi(int chon)//dung cho ca menu Cap nhat
{
	system("cls");
	if (chon == 1)
		cout << "----MENU TAO MOI----\n";
	else
		cout << "----MENU CAP NHAT----\n";
	cout << "1. Nam hoc\n";
	cout << "2. Lop hoc\n";
	cout << "3. Hoc ky\n";
	cout << "4. Quay ve\n";
	cout << "5. Thoat\n";
	return 5;
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
bool XlTaoMoi(int chon)
{
	switch (chon)
	{
	case 1:
	{
		cout << "nam hoc\n";
		system("pause");
		break;
	}
	case 2:
	{
		cout << "lop hoc\n";
		system("pause");
		break;
	}
	case 3:
	{
		cout << "hoc ky\n";
		system("pause");
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		char lenh;
		cout << "Ban thuc su muon thoat? Y/N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
		{
			exit(0);
		}
	}
	}
	return false;//ngoai tru lenh quay ve va thoat + chon y/Y
}
bool XlCapNhat(int chon)
{
	switch (chon)
	{
	case 1:
	{
		cout << "nam hoc\n";
		system("pause");
		break;
	}
	case 2:
	{
		cout << "lop hoc\n";
		system("pause");
		break;
	}
	case 3:
	{
		cout << "hoc ky\n";
		system("pause");
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		char lenh;
		cout << "Ban thuc su muon thoat? Y/N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
		{
			exit(0);
		}
	}
	}
	return false;//ngoai tru lenh quay ve va thoat + chon y/Y
}
bool XlMenuGv(int chon)
{
	char lenh;//thoat thi nhap Y/y
	bool Thoat = false;
	switch (chon)
	{
	case 1:
	{
		do
		{
			Thoat = XlTaoMoi(LuaChon(InMenuTaoMoi(chon)));
		} while (!Thoat);
		system("pause");
		break;
	}
	case 2:
	{
		do
		{
			Thoat = XlCapNhat(LuaChon(InMenuTaoMoi(chon)));
		} while (!Thoat);
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
void GiaoVu()
{
	bool Thoat = false;
	do
	{
		Thoat = XlMenuGv((LuaChon(InMenuGv())));
	} while (!Thoat);
	system("cls");
}
