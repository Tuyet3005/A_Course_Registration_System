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
bool daTaoNamHT(ListNamHoc& l, NodeNamHoc*& node, int nam_bd)
{
	NodeNamHoc* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->data.tg.ngay_bd.y == nam_bd)
		{
			node = temp;
			return true;
		}
		else
			temp = temp->pNext;
	}
	return false;
}
NodeNamHoc* NodeNamHienTai(ListNamHoc& l)//ktra NH ht co dc tao chua, chua thi co the tao nam hoc hoac tra ve NULL, co roi thi tra ve node NH ht 
{
	int nam_bd = NHhientai_nambd();
	NodeNamHoc* node = NULL;
	if (daTaoNamHT(l, node, nam_bd))
	{
		return node;
	}
	//CAN TAO NODE NAM HOC HT
	char lenh;
	system("cls");
	printA_Sentence("! NAM HOC HIEN TAI CHUA DUOC TAO !", HEIGHT / 2 - 4);
	if (Ask_YN("Ban co muon tao nam hoc hien tai ngay?"))
	{
		NodeNamHoc* node = new NodeNamHoc;
		node->data.tg.ngay_bd.y = nam_bd;
		node->data.tg.ngay_kt.y = nam_bd + 1;
		node->data.headLop[0] = node->data.headLop[1] = node->data.headLop[2] = node->data.headLop[3] = NULL;
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
	if (t.gio >= 24 || t.gio < 0)
		return false;
	else {
		if (t.phut < 0 || t.phut >= 60)
			return false;
		else {
			if (t.giay < 0 || t.giay >= 60)
				return false;
			return true;
		}
	}
}

Ngay _30ngaysau(Ngay ngaybd)
{
	Ngay A = ngaybd;
	A.d += 30;
	int ngaydu = A.d - SoNgayTrongThang(A.m, A.y);
	if (ngaydu != 0)
	{
		A.d = ngaydu;
		if (A.m == 12)
		{
			A.m = 1;
			A.y += 1;
		}
		else
			A.m += 1;
	}
	return A;
}