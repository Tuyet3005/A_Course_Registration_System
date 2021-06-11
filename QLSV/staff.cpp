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
	{
		cout << "----MENU TAO MOI----\n";
	}
	else
	{
		cout << "----MENU CAP NHAT----\n";
	}
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
		break;
	}
	case 2:
	{
		system("cls");
		NodeNamHoc* n = NodeNamHienTai(l);
		TaoLopNamNhat(n);
		cout << l.pHead->data.headLopNam1->lop.headSvLop->sv.ten << endl;
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
// Nhap node nam tu ban phim, tra ve node
NodeNamHoc* NhapNodeNam()
{
	NodeNamHoc* n = new NodeNamHoc;
	int nam_bd;
	fstream f;
	f.open("listnam.txt", ios::in | ios::app);
	do
	{
		cout << "Nhap nam bat dau nam hoc: ";
		cin >> nam_bd;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			nam_bd = -1;
		}
	} while (nam_bd < NHhientai_nambd());
	n->data.tg.ngay_bd.y = nam_bd;
	n->data.tg.ngay_kt.y = nam_bd + 1;
	n->pNext = NULL;
}
// Luu node nam vao file, tra ve true neu luu thanh cong, false neu bi trung
bool LuuNodeNam(NodeNamHoc* n)
{
	int nam_bd = n->data.tg.ngay_bd.y;
	fstream f;
	f.open("listnam.txt", ios::in | ios::app);
	string temp = "";
	while (!f.eof())//ktra lo nhap nam trung voi nam da tao!!!!
	{
		if (nam_bd == temp->data.tg.ngay_bd.y)
    {
			if (stoi(temp) == nam_bd)
			{
				cout << "Loi! Nam hoc da duoc tao truoc do!!!" << endl << endl;
				return false;
			}
		}
	}
	f.clear();
	f << nam_bd << ',';
	f.close();
	return true;
}
//nam hoc
NodeNamHoc* TaoNodeNam()
{
	NodeNamHoc* n = NhapNodeNam();

	if (!LuuNodeNam(n))
	{
		return NULL;
	}
	else
	{
		return n;
  }
}
void ThemNodeNamHoc(ListNamHoc& l, NodeNamHoc* n)
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
	cout << "Tao nam hoc moi thanh cong!!!" << endl;
}
void HienNamHoc(ListNamHoc l)
{
	if (l.pHead)
	{
		cout << "Cac nam hoc da tao: \n";
		NodeNamHoc* n = l.pHead;
		int i = 0;
		while (n)
		{
			cout << ++i << ". Nam hoc ";
			cout << n->data.tg.ngay_bd.y << " - " << n->data.tg.ngay_kt.y << endl;
			n = n->pNext;
		}
	}
	cout << "CHUA CO NAM HOC NAO!\n";
}
void TaoNam(ListNamHoc& l)
{
	cout << "TAO MOI 1 NAM HOC\n";
	NodeNamHoc* n = TaoNodeNam();
	ThemNodeNamHoc(l, n);
	system("pause");
	system("cls");
	HienNamHoc(l);
	system("pause");
}
//lop hoc  /cap nhat dssv lop!!! 
NodeLop* TaoNodeLop(string ten)
{
	NodeLop* n = new NodeLop;
	n->lop.ten = ten;
	n->pNext = NULL;
	return n;
}
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop*& n)
{
	// ds rong: them dau
	if (HeadLop == NULL)
	{
		HeadLop = n;
	}
	else//them dau 
	{
		n->pNext = HeadLop;
		HeadLop = n;
	}
}
void HienLopHoc(NodeLop* HeadLop)
{
	cout << "\nCac lop hoc da tao:\n";
	NodeLop* temp = HeadLop;
	int i = 0;
	while (temp != NULL)
	{
		cout << ++i << ". ";
		cout << "Lop ";
		cout << temp->lop.ten << endl;
		temp = temp->pNext;
	}
}
void TaoLopNamNhat(NodeNamHoc* node)
{
	if (node == NULL)
		return;
	node->data.headLopNam1 = NULL;
	int sl = 0;
	//nhap ten lop moi len file, tao node len he thong
	cout << "Nhap so luong lop nam nhat muon tao: ";
	cin >> sl;
	if (cin.fail() || sl < 0)
	{
		cin.clear();
		cin.ignore();
		sl = 0;
	}
	for (int i = 0; i < sl; i++)
	{
		string ten;
		system("cls");
		cout << "Nhap ten lop " << i + 1 << ": ";
		cin >> ten;
		//ktra co bi trung ten lop
		NodeLop* temp = node->data.headLopNam1;
		bool trungTen = false;
		while (temp != NULL)
		{
			if (temp->lop.ten == ten)
			{
				cout << "Loi: Lop nay da duoc tao truoc do tren he thong!!!\n";
				trungTen = true;
				break;
			}
			else
			{
				temp = temp->pNext;
			}
		}
		if (trungTen)
		{
			char lenh;
			cout << "Ban co muon nhap lai ten lop " << i + 1 << "? Y/N?\n";
			cin >> lenh;
			if (lenh == 'Y' || lenh == 'y')
			{
				i--;
			}
			continue;//chay vong lap for ke tiep, bo qua cac lenh ben duoi
		}
		//ko bi trung thi tao node va ghi ten lop vo file
		fstream f;
		f.open(to_string(node->data.tg.ngay_bd.y) + "n1.txt", ios::app);//file lop nam1 
		f << ten << ",";
		f.clear();
		f.close();
		NodeLop* n = TaoNodeLop(ten);
		ThemNodeLopHoc(node->data.headLopNam1, n);
		//da cap nhat du lieu lop moi vao file trong ham TaoNodeLop
		cout << "Tao lop thanh cong!!!" << endl;
		system("pause");
	}
}
//CAP NHAT
bool XlCapNhat(int chon, ListNamHoc& l)
{
	switch (chon)
	{
	case 1:
	{
		//cap nhat nh
		system("pause");
		break;
	}
	case 2:
	{
		//cap nhat lop hoc 
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
