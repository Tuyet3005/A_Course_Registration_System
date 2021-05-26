#include"staff.h"//GIAO VU
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
bool XlMenuGv(int chon, ListNamHoc& l)
{
	char lenh;//thoat thi nhap Y/y
	bool Thoat = false;
	switch (chon)
	{
	case 1:
	{
		do
		{
			Thoat = XlTaoMoi(LuaChon(InMenuTaoMoi(chon)), l);
		} while (!Thoat);
		system("pause");
		break;
	}
	case 2:
	{
		do
		{
			Thoat = XlCapNhat(LuaChon(InMenuTaoMoi(chon)), l);
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
void GiaoVu(ListNamHoc& l)
{
	bool Thoat = false;
	do
	{
		Thoat = XlMenuGv((LuaChon(InMenuGv())), l);
	} while (!Thoat);
	system("cls");
}
//TAO MOI
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
	cout << "4. Mon hoc\n";
	cout << "5. Quay ve\n";
	cout << "6. Thoat\n";
	return 6;
}
bool XlTaoMoi(int chon, ListNamHoc& l)
{
	switch (chon)
	{
	case 1:
	{
		system("cls");
		TaoNam(l);
		system("pause");
		break;
	}
	case 2:
	{
		system("cls");
		TaoCacLopNamNhat(l);
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
		cout << "mon hoc\n";
		system("pause");
		break;
	}
	case 5:
	{
		return true;
	}
	case 6:
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
//nam hoc
NodeNamHoc* TaoNodeNam()
{
	NodeNamHoc* n = new NodeNamHoc;
	int nam_bd;
	string file = "listnam.txt";
	fstream f;
	f.open(file, ios::in| ios::app);
	cout << "Nhap nam bat dau nam hoc: ";
	cin >> nam_bd;
	string temp = "";
	while (!f.eof())//ktra lo nhap nam trung voi nam da tao!!!!
	{
		f.clear();
		getline(f, temp, ',');
		if (temp != "")//file da chua du lieu
		{
			if (stoi(temp) == nam_bd)
			{
				cout << "Loi! Nam hoc da duoc tao truoc do!!!" << endl << endl;
				return NULL;
			}
		}		
	}
	n->data.tg.ngay_bd.y = nam_bd;
	n->data.tg.ngay_kt.y = nam_bd + 1;
	f.clear();
	f << nam_bd<<',';
	f.close();
	n->pNext = NULL;
	return n;
}
void ThemNamHoc(ListNamHoc& l, NodeNamHoc* n)
{
	if (n == NULL)//nhap nam trung voi nam da tao
		return;
	//else
	if (l.pHead == NULL)
	{
		l.pHead = n;
		l.pTail = n;
	}
	// ds co roi: pTail-> next = node; pTail = node
	else
	{
		l.pTail->pNext = n;
		l.pTail = n;
	}
}
void TaiNamTuFile(ListNamHoc& l)
{
	string file = "listnam.txt";
	fstream f;
	f.open(file, ios::in);
	string temp = "";
	while (!f.eof())
	{
		f.clear();
		getline(f, temp, ',');
		if (temp != "")//file da chua du lieu
		{
			int nam_bd = stoi(temp);
			NodeNamHoc* n = new NodeNamHoc;
			n->pNext = NULL;
			n->data.tg.ngay_bd.y = nam_bd;
			n->data.tg.ngay_kt.y = nam_bd + 1;
			ThemNamHoc(l, n);
			f.clear();//xoa du lieu da lay truoc do trong file
		}
	}
}
int HienNamHoc()
{
	fstream f;
	string file = "listnam.txt";
	f.open(file, ios::in);
	cout << "Cac nam hoc da tao:\n";
	string s = "";
	int i = 0;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		if (s != "")
		{
			cout << ++i << ". Nam hoc " << s << " - " << stoi(s) + 1 << endl;//1. Nam hoc 2020 - 2021
		}
	}
	if (s == "") cout << "CHUA TAO NAM HOC NAO!!!\n";
	f.clear();
	f.close();
	return i;//so nh hien tai
}
void TaoNam(ListNamHoc& l)
{
	cout << "TAO MOI 1 NAM HOC\n";
	ThemNamHoc(l, TaoNodeNam());
	system("pause");
	system("cls");
	HienNamHoc();
}
//lop hoc
NodeLop* TaoNodeLop(ListNamHoc&l)
{
	NodeLop* n = new NodeLop;
	n->pNext = NULL;
	return n;
}
void ThemLopHoc(ListLopHoc& l, NodeLop* n)
{
	// ds rong: them dau
	if (l.pHead == NULL)
	{
		l.pHead = n;
		l.pTail = n;
	}
	// ds co roi: pTail-> next = node; pTail = node
	else
	{
		l.pTail->pNext = n;
		l.pTail = n;
	}
}
int HienLopHoc()
{

}
NodeNamHoc* CheckNamHienTai(ListNamHoc& l, string& nam_bd)//check nam co dc nhap trong listnam
{
	cout << "Nhap nam bat dau nam hoc hien tai:\n";
	cin >> nam_bd;
	NodeNamHoc* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->data.tg.ngay_bd.y == stoi(nam_bd))
		{
			return temp;//luc nay, temp tro den node cua nam hoc hien tai
		}
		temp = temp->pNext;
	}
	return NULL;
}
void TaiLopTuFile(ListNamHoc& l, string& file)
{
	string nam_bd;//luu nam bd cua nam hoc hien tai 
	NodeNamHoc* node = CheckNamHienTai(l, nam_bd);//tra ve nam hoc hien tai neu da duoc tao
	if (node!=NULL)
	{
		fstream f;
		file = nam_bd + "n1.txt";
		f.open(file, ios::app | ios::in);//mo file de doc va ghi them o cuoi
		//NodeLop* n = temp->data.nam1.pHead;//n tro den nodelop pHead trong list lop nam1 cua namhoc hien tai
		while (!f.eof())
		{
			string s;
			getline(f, s, ',');
			if (s != "")
			{
				NodeLop* n = new NodeLop;
				n->pNext = NULL;
				n->lop.ten = s;
				ThemLopHoc(node->data.nam1, n);
			}
			f.clear();
		}
		return;
	}
	cout << "Ban da nhap sai hoac nam hoc tuong ung chua duoc tao!!!\n";
}
void TaoLopNamNhat(ListNamHoc& l)
{
	l.pHead->data.nam1.pHead = l.pTail->data.nam1.pTail = NULL;
	TaiLopTuFile(l);
	//ktra nam hoc hien tai co dc tao chua, chua thi tao nam truoc, co roi thi tiep buoc sau 
	//mo file o che do ghi cuoi/doc namhocn1.txt ->tai du lieu lop tu file len he thong 
	//nhap ten lop moi len file
	//ghi vo he thong(tao node moi, them vo listlopnam1 trong namhoc hien tai 
	//cap nhat dssv 
}

//thay vi nhap nam hoc hien tai -> cai tien len la nhap ngay thang nam -> xd nam hoc 
//TUYET cap nhat file listlop cho nam hai,ba,tu cua nam hoc hien tai


	
