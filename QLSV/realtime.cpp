#include"realtime.h"
tm ThoiGianHeThong()
{
	time_t rawTime = time(0);
	tm tmTime;
	localtime_s(&tmTime, &rawTime);//chuyen gio he thong sang cau truc tm
	return tmTime;
}
int NHhientai_nambd()
{
	//nam hoc bat dau tu 5/9 nam X den 31/7 nam X+1 
	int nam_bd;
	tm tmTime = ThoiGianHeThong();
	if (tmTime.tm_mon < 8)
		nam_bd = tmTime.tm_year - 1;
	else
		nam_bd = tmTime.tm_year;
	return 1900 + nam_bd;//struct tm tinh nam tu nam 1900
}
NodeNamHoc* NodeNamHienTai(ListNamHoc& l)//ktra NH ht co dc tao chua, chua thi co the tao nam hoc hoac tra ve NULL, co roi thi tra ve node NH ht 
{
	int nam_bd = NHhientai_nambd();
	NodeNamHoc* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->data.tg.ngay_bd.y == nam_bd)
		{
			return temp;//luc nay, temp tro den node cua nam hoc hien tai
		}
		else
			temp = temp->pNext;
	}
	//CAN TAO NODE NAM HOC HT
	char lenh;
	cout << "Nam hoc hien tai chua duoc tao!!!\n";
	cout << "Ban co muon tao nam hoc hien tai ngay? Y/N?\n";
	cin.ignore();
	cin >> lenh;
	if (lenh == 'y' || lenh == 'Y')
	{
		NodeNamHoc* node = new NodeNamHoc;
		node->data.tg.ngay_bd.y = nam_bd;
		node->data.tg.ngay_kt.y = nam_bd + 1;
		node->pNext = NULL;
		ThemNodeNamHoc(l, node);
		fstream f;
		f.open("listnam.txt", ios::in | ios::app);
		f << nam_bd << ",";
		f.close();
		return node;
	}
	return NULL;
}
bool NamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	return false;
	// <=> return ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0);
}
int SoNgayTrongThang(int thang, int nam)
{
	int n = 31;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		n = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		n = 30;
		break;
	case 2:
		if (NamNhuan(nam))
		{
			n = 29;
		}
		else
		{
			n = 28;
		}
		break;
	}
	return n;
}
bool NgayHopLe(int ngay, int thang, int nam)
{
	if (nam < 0)
	{
		return false;
	}
	if (thang < 1 || thang > 12)
	{
		return false;
	}
	if (ngay < 1 || ngay > SoNgayTrongThang(thang, nam))
	{
		return false;
	}
	return true;
}
bool GioHopLe(Time t)
{
	if (t.gio > 24 || t.gio < 0)
		return false;
	else {
		if (t.phut < 0 || t.phut>60)
			return false;
		else {
			if (t.giay < 0 || t.giay>60)
				return false;
			return true;
		}
	}
}