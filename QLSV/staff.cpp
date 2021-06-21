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
		cout << "TAO MOI LOP HOC NAM NHAT\n";
		NodeNamHoc* n = NodeNamHienTai(l);
		TaoLopNamNhat(n);
		cout << l.pHead->data.headLopNam1->lop.headSvLop->sv.ten << endl;
		system("pause");
		break;
	}
	case 3:
	{
		system("cls");
		TaoHocKy(l);
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
	f << nam_bd << ',';
	f.close();
	n->pNext = NULL;
	return n;
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
//hoc ky 
NodeNamHoc* TimNodeNamHoc(ListNamHoc&l, int nam_bd)//tim nam hoc de them hk vao
{
	NodeNamHoc* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->data.tg.ngay_bd.y == nam_bd)
		{
			return temp;
		}
		else
			temp = temp->pNext;
	}
	//CAN TAO NODE NAM HOC MOI
	char lenh;
	cout << "Nam hoc tuong ung chua duoc tao!!!\n";
	cout << "Ban co muon tao nam hoc do ngay? Y/N?\n";
	cin.ignore();
	cin >> lenh;
	if (lenh == 'y' || lenh == 'Y')
	{
		NodeNamHoc* node = new NodeNamHoc;
		node->data.tg.ngay_bd.y = nam_bd;
		node->data.tg.ngay_kt.y = nam_bd + 1;
		ThemNodeNamHoc(l, node);
		fstream f;
		f.open("listnam.txt", ios::in | ios::app);
		f << nam_bd << ",";
		f.close();
		return node;
	}
	return NULL;
}
void TaoHocKy(ListNamHoc& l)
{
	int hk = 0;
	Ngay ngBD;
	Ngay ngKT;
	int nam_bd;//nam bat dau cua nam hoc tuong ung de them hoc ky vao
	cout << "TAO MOI HOC KY\n";
	while (hk < 1 || hk>3)
	{
		cout << "Nhap vao so thu tu cua hoc ky (1,2,3): ";
		cin >> hk;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			hk = 0;
		}
	}
	//nhap thoi gian bat dau, ket thuc @@@ tr.hop ngay kt < ngay bd? @@@
	{
		ngBD.d = 0;
		ngKT.d = 0;
		do
		{
			if (ngBD.d == 0)
			{
				cout << "Nhap lan luot ngay, thang, nam bat dau cua hoc ky nhu vd sau '5 9 2021':\n";
				cin >> ngBD.d >> ngBD.m >> ngBD.y;
				if (cin.fail())//check ngay thang nam phu hop!
				{
					cin.clear();
					cin.ignore();
					ngBD.d = 0;
					continue;
				}
				else if (!NgayHopLe(ngBD.d, ngBD.m, ngBD.y))
				{
					ngBD.d = 0;
					continue;
				}
			}
			if (ngKT.d == 0)
			{
				cout << "Nhap lan luot ngay, thang, nam ket thuc cua hoc ky nhu vd sau '31 07 2021':\n";
				cin >> ngKT.d >> ngKT.m >> ngKT.y;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					ngKT.d = 0;
					continue;
				}
				else if (!NgayHopLe(ngKT.d, ngKT.m, ngKT.y))
				{
					ngKT.d = 0;
					continue;
				}
			}
		} while (ngBD.d == 0 || ngKT.d == 0);
	}
	//do tim node nam hoc tuong ung de them hoc ky vao
	if (ngKT.m < 8)
		nam_bd = ngKT.y - 1;//nam hoc bat dau tu dau thang 9 nam X den het thang 7 nam X+1 
	else
		nam_bd = ngKT.y;
	NodeNamHoc* nodeNam = TimNodeNamHoc(l, nam_bd);
	if (nodeNam)
	{
		HocKy* hockyP = NULL;
		switch (hk)
		{
		case 1:
		{
			hockyP = &(nodeNam->data.hk1);
			break;
		}
		case 2:
		{
			hockyP = &(nodeNam->data.hk2);
			break;
		}
		case 3:
		{
			hockyP = &(nodeNam->data.hk3);
		}
		}
		//da tao hk truoc do roi -> return;
		if ((hockyP->tg.ngay_bd.d == ngBD.d) && (hockyP->tg.ngay_bd.m == ngBD.m) && (hockyP->tg.ngay_bd.y == ngBD.y))
		{
			if ((hockyP->tg.ngay_kt.d == ngKT.d) && (hockyP->tg.ngay_kt.m == ngKT.m) && (hockyP->tg.ngay_kt.y == ngKT.y))
			{
				cout << "Ban da tao hoc ky nay truoc do roi!\n";
				return;
			}
		}
		//chua tao hoac can chinh sua hoc ky
		{
			hockyP->tg.ngay_bd = ngBD;
			hockyP->tg.ngay_kt = ngKT;
			// tao hoac chinh sua file hk tuong ung
			fstream f;
			string s;
			bool taomoi = true;
			string filePath = to_string(nam_bd) + "hk" + to_string(hk) + ".txt";
			f.open(filePath, ios::in | ios::app);
			getline(f, s);
			//ghi vao file goc neu file trong
			if (s != "")//ghi vao file trunggian neu file cu da co data 
			{
				f.close();
				f.open("trunggian.txt", ios::out);// tao file trung gian de thuc hien chinh sua 
				taomoi = false;
			}
			//ghi du lieu thoi gian vao file theo cau truc "ddmmyyyy,ddmmyyyy,\n"
			{
				//ghi ngay BD
				if (ngBD.d < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngBD.d;
				//ghi thang BD
				if (ngBD.m < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngBD.m;
				//ghi nam BD
				f << ngBD.y << ",";
				//ghi ngay KT
				if (ngKT.d < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngKT.d;
				//ghi thang KT
				if (ngKT.m < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngKT.m;
				//ghi nam KT
				f << ngKT.y << ",\n";
			}
			if (taomoi)
			{
				f << "buon qua di\n";
				f.close();
				cout << "Tao moi hoc ky thanh cong!\n";
				return;
			}
			//chinh sua file hoc ky da co thong tin truoc do thong qua file trung gian 
			else
			{
				ifstream g;
				g.open(to_string(nam_bd) + "hk" + to_string(hk) + ".txt");//mo file cu da co du lieu 
				getline(g, s);//bo qua thoi gian hk cu
				//sao chep cac du lieu mon hoc qua file trung gian 
				while (!g.eof())
				{
					getline(g, s);
					f << s;
				}
				g.close();//dong file cu
				f.close();//dong file trung gian 
				//chuyen doi data type tu string sang char* <de truyen vao ham rename, remove ben duoi>
				char* c = new char[filePath.size() + 1];
				copy(filePath.begin(), filePath.end(), c);
				c[filePath.size()] = '\0';
				remove(c);//xoa file cu 
				rename("trunggian.txt", c);//doi ten file trung gian 
				delete[] c;
				c = NULL;
			}
		}
	}
	//ko tao nam hoc tuong ung thi ko them hk vao 
	else
	{
		cout << "Tao moi hoc ky khong thanh cong!\n";
	}
}
//mon hoc 
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

