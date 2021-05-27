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
		break;
	}
	case 2:
	{
		system("cls");
		TaoLopNamNhat(l);
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
	bool filerong = true;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		if (s != "")
		{
			cout << ++i << ". Nam hoc " << s << " - " << stoi(s) + 1 << endl;//1. Nam hoc 2020 - 2021
			filerong = false;
		}
	}
	if (filerong) cout << "CHUA TAO NAM HOC NAO!!!\n";
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
	system("pause");
}
//lop hoc
NodeLop* TaoNodeLop()
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
int HienLopHoc(ListLopHoc l)
{
	cout << "\nCac lop hoc da tao:\n";
	NodeLop* temp = l.pHead;
	int i = 0;
	while (temp != NULL)
	{
		cout << i + 1 << ". ";
		cout << "Lop ";
		cout << temp->lop.ten << endl;
		temp = temp->pNext;
	}
	return i;
}
string TaiLopTuFile(ListNamHoc& l, NodeNamHoc* node)//tai file lop nam 234 cua nam truoc len he thong 
{//da co san node nh hien tai tren he thong
	fstream f;
	//cap nhat nam nhat 
	string file1 = to_string(node->data.tg.ngay_bd.y) + "n1.txt";
	f.open(file1, ios:: in | ios::app);//mo file de doc
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
	}
	f.close();
	//cap nhat nam hai, ba, tu
	//cach lam
	//ktra co nam hoc truoc nh hien tai chua
	//neu co thi tai dssv nam hoc truoc len nh ht theo quy tac
	//vd 2018n1.txt-> 2019n2.txt 2018n2.txt -> 2019n3.txt
	return file1;
}
void TaoLopNamNhat(ListNamHoc& l)
{
	//ktra nam hoc hien tai co dc tao chua, chua thi co the tao nam truoc, co roi thi tiep buoc sau
	NodeNamHoc* node = NodeNamHienTai(l);
	if (node == NULL)
		return;//ko tao nam hoc thi ko tao lop luon
	//khoi tao list lop hoc nam1 trong nam hoc hien tai 
	node->data.nam1.pHead = node->data.nam1.pTail = NULL;
	//mo file namhocn1.txt o 2 che do doc, ghi them o cuoi(neu file chua dc tao thi se tao file) -> tai du lieu lop tu file len he thong 	
	string file = TaiLopTuFile(l, node);
	int sl = 0;
	//nhap ten lop moi len file, tao node len he thong
	cout << "Nhap so luong lop nam nhat muon tao: ";
	cin >> sl;
	if (cin.fail()||sl<0)
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
		NodeLop* temp = node->data.nam1.pHead;
		bool trungTen = false;
		while (temp!=NULL)//temp -> pNext != NULL de luu lai node tail
		{
			if (temp->lop.ten == ten)
			{
				cout << "Loi: Lop nay da duoc tao truoc do tren he thong!!!\n";
				trungTen = true;
				break;
			}
			else if (temp->pNext == NULL)
			{
				break;
			}
			else
			{
				temp = temp->pNext;
			}
		} 
		//temp tro nodelop cuoi (node cuoi ko bi trung ten lop muon tao moi)
		//hoac (lop bi trung ten) -> co the nhap lai ten lop!
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
		f.open(file, ios::app);//file lop nam1 cua NH htai
		f << ten << ",";
		f.clear();
		f.close();
		ThemLopHoc(node->data.nam1, TaoNodeLop());
		//cap nhat dssv 
		cout << "File "<<ten<<".txt da duoc tao!\n";
		cout << "Ban co the cap nhat danh sach sinh vien cua lop " << ten<<" ngay bay gio!\n";
		cout <<"Huong dan: Mo file nay len, roi dien vao cac MSSV ngan cach nhau boi dau phay.\n";
		system("pause");
		string file_lop = ten + ".txt";
		f.open(file_lop, ios::app);
		f.close();		
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

	
