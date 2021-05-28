#include"startMenu.h"
int InMenuBatDau(int ma_tk)//0 gv 1 sv lay tu login tra vector
{
	system("cls");
	BackGround();
	cout << endl << endl << endl;
	cout << "\t \t \t CHAO MUNG BAN DEN VOI HE THONG QUAN LY SINH VIEN\n";
	cout << "\t \t \t \t \t 1. Vao he thong chinh\n";
	cout << "\t \t \t \t \t 2. Xem thong tin cua ban\n";
	cout << "\t \t \t \t \t 3. Doi mat khau\n";
	cout << "\t \t \t \t \t 4. Dang xuat\n";
	cout << "\t \t \t \t \t 5. Thoat\n";
	return 5;//tra ve maxSelect
}
bool XlMenuBD(int chon, short lc, string tk, string& mk, ListNamHoc& l)//lc la maTk  0:Giao vu, 1: Sinh vien
{
	char lenh;
	switch (chon)
	{
	case 1:
	{
		if (lc == 0)
			GiaoVu(l);
		else
			SinhVien(l);
		break;
	}
	case 2:
	{
		cout << "Hien thi thong tin cua tai khoan";
		system("pause");
		break;
	}
	case 3:
	{
		changePass(lc, tk, mk);
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