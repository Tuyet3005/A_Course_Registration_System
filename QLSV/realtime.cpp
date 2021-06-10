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
	while (temp!=NULL)
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
		node->pNext = NULL;
		ThemNodeNamHoc(l, node);
		fstream f;
		f.open("listnam.txt", ios::in | ios::app);
		f << nam_bd << ",";
		return node;
	}
	return NULL;
}