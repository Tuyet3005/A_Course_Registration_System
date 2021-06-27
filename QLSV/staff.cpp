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
		cout << l.pHead->data.headLop[0]->lop.headSvLop->sv.ten << endl;
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
		system("cls");
		NodeNamHoc* n = NodeNamHienTai(l);
		int hk;
		int nam = n->data.tg.ngay_bd.y;
		TaoMon(l, nam);
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
	else
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
	node->data.headLop[0] = NULL;
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
		NodeLop* temp = node->data.headLop[0];
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
		ThemNodeLopHoc(node->data.headLop[0], n);
		//da cap nhat du lieu lop moi vao file trong ham TaoNodeLop
		cout << "Tao lop thanh cong!!!" << endl << endl;
		cout << "Thong bao!\n";
		cout << "Ban co the thoat chuong trinh hien tai va tien hanh them sinh vien vao lop bang cach dien cac MSSV vao file "
			<< "'" << ten << ".txt'!\n";
		system("pause");
	}
}

//hoc ky 
NodeNamHoc* TimNodeNamHoc(ListNamHoc& l, int nam_bd)//tim nam hoc de them hk vao
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
bool sosanhNgay(Ngay ngay_truoc, Ngay ngay_sau)
{
	//ngay_sau.y<ngay_truoc.y -> loi!
	//ngay_sau.y=ngay_truoc.y -> so sanh tiep m ( m sau > m truoc ->ok; neu = thi so sanh d, d sau phai > d truoc)
	//ngay_sau.y>ngay_truoc.y -> ok
	if (ngay_sau.y > ngay_truoc.y)
		return true;
	if (ngay_sau.y < ngay_truoc.y)
		return false;
	if (ngay_sau.m > ngay_truoc.m)
		return true;
	if ((ngay_sau.m == ngay_truoc.m) && (ngay_sau.d > ngay_truoc.d))
		return true;
	return false;
}
bool XungdotTg(HocKy* hktruoc, Ngay ngBD_hksau, int hkTr, int hkS)
{
	//chua tao hk truoc 
	if (hktruoc->tg.ngay_bd.d == 0)
	{
		cout << "LOI!!! Ban chua tao hoc ky " << hkTr << "!\n";
		return true;
	}
	//hk sau co thoi gian xung dot voi thoi gian hoc ky truoc 
	else if (sosanhNgay(hktruoc->tg.ngay_kt, ngBD_hksau) == false)
	{
		cout << "LOI!!! Hoc ky " << hkS << " co thoi gian xung dot voi thoi gian cua hoc ky " << hkTr << "!!!\n";
		return true;
	}
	return false;
}
void TaoHocKy(ListNamHoc& l)
{
	int hk = 0;
	Ngay ngBD;
	Ngay ngKT;
	int nam_bd;//nam bat dau cua nam hoc tuong ung ngay kt do user nhap vao
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
	//nhap thoi gian bat dau, ket thuc 
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
			if (!sosanhNgay(ngBD, ngKT))
			{
				cout << "LOI! Ngay bat dau phai TRUOC ngay ket thuc!!!\nVui long nhap lai!\n";
				ngBD.d = 0;
				ngKT.d = 0;
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
			hockyP = &(nodeNam->data.hk[0]);
			break;
		}
		case 2:
		{
			//hk1 da tao chua? co trung ko?
			hockyP = &(nodeNam->data.hk[1]);
			HocKy* hk1P = &(nodeNam->data.hk[0]);
			bool flag = XungdotTg(hk1P, ngBD, hk - 1, hk);
			if (flag)
				return;
			break;
		}
		case 3:
		{
			hockyP = &(nodeNam->data.hk[2]);
			HocKy* hk2P = &(nodeNam->data.hk[1]);
			bool flag = XungdotTg(hk2P, ngBD, hk - 1, hk);
			if (flag)
				return;
			break;
		}
		}
		fstream f;
		string s;
		string filePath = to_string(nam_bd) + "hk" + to_string(hk) + ".txt";
		f.open(filePath, ios::in);
		//da tao hk truoc do roi -> return;
		if (f.is_open() && (f >> s) && (s != " "))
		{
			f.close();
			cout << "Ban da tao hoc ky nay truoc do roi!!!\n";
			return;
		}
		else
		{
			f.close();
			hockyP->headMon = NULL;
			hockyP->tg.ngay_bd = ngBD;
			hockyP->tg.ngay_kt = ngKT;
			f.open(filePath, ios::out);
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
				f << ngKT.y << ",";
			}
			f.close();
			cout << "Tao moi hoc ky thanh cong!\n";
			return;
		}
	}
	//ko tao nam hoc tuong ung thi ko them hk vao 
	else
	{
		cout << "Tao moi hoc ky khong thanh cong!\n";
	}
}

//mon hoc 
HocKy* checkHocKy(NodeNamHoc* n, int& i)//i: so thu tu hoc ky
{
	HocKy* hk = NULL;
	i = 3;
	for (i; i > 0; i--)
	{
		hk = &(n->data.hk[i - 1]);
		if (NgayHopLe(hk->tg.ngay_bd.d, hk->tg.ngay_bd.m, hk->tg.ngay_bd.y))
		{
			return hk;
		}
	}
	//neu chua co hk nao dc tao
	i = 1;
	return NULL;
}
HocKy* HkHienTai(ListNamHoc& l, NodeNamHoc* n, int& i)//i la thu tu hk
{
	if (!n)
		return NULL;
	HocKy* hk = checkHocKy(n, i);     
	if (!hk)//Chua tao hk nao 
	{
		//tao hk1 ghi tg vo file truoc -> tao mon
		char lenh;
		cout << "Ban chua tao hoc ky nao cho nam hoc hien tai!!!\n";
		cout << "Ban co muon tao hoc ky moi ngay bay gio? Y/N?\n ";
		cin >> lenh;
		if (lenh == 'y' || lenh == 'Y')
		{
			TaoHocKy(l);
			if (n->data.hk[0].tg.ngay_bd.d == 0)
			{
				cout << "LOI THOI GIAN THUC!!!\n Tao hoc ky moi khong thanh cong do nhap sai thoi gian!\n";
				return NULL;
			}
			cout << endl;
			return &(n->data.hk[0]);
		}
	}
	return hk;
}
void XulyThu(int lc, BuoiHoc& bh)
{
	switch (lc)
	{
	case 1:
	{
		bh.thu = "Thu Hai";
		break;
	}
	case 2:
	{
		bh.thu = "Thu Ba";
		break;
	}
	case 3:
	{
		bh.thu = "Thu Tu";
		break;
	}
	case 4:
	{
		bh.thu = "Thu Nam";
		break;
	}
	case 5:
	{
		bh.thu = "Thu Sau";
		break;
	}
	case 6:
	{
		bh.thu = "Thu Bay";
		break;
	}
	}
}
void NhapTgMon(NodeMon* n)
{
	do
	{
		cout << "Chon thoi gian cua hai buoi hoc trong tuan:\n";
		for (int i = 1; i < 3; i++)
		{
			cout << "Buoi " << i << ":\n";
			cout << "1. Thu hai \t 2. Thu ba \t 3. Thu tu\n";
			cout << "4. Thu nam \t 5. Thu sau \t 6. Thu bay\n";
			int lc;
			do
			{
				cout << "Nhap lua chon (1-6): ";
				cin >> lc;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					lc = 0;
				}
			} while (lc < 1 || lc>6);
			if (i == 1)
				XulyThu(lc, n->data.bh1);
			else
				XulyThu(lc, n->data.bh2);
			cout << "Khung gio:\n";
			cout << "1. S1 (07:30)\t 2. S2 (09:30)\n";
			cout << "3. S3 (13:30)\t 4. S4 (15:30)\n";
			cout << "Nhap lua chon (1-4): ";
			cin >> lc;
			if (i == 1)
			{
				n->data.bh1.buoi = "S";
				n->data.bh1.buoi += to_string(lc);
			}
			else
			{
				n->data.bh2.buoi = "S";
				n->data.bh2.buoi += to_string(lc);
			}
		}
		if ((n->data.bh1.buoi == n->data.bh2.buoi) && (n->data.bh1.thu == n->data.bh2.thu))
		{
			cout << "Hai buoi hoc trung nhau!!! Vui long nhap lai!\n";
		}
		else
			break;
	} while (true);
}
bool checkTrungMon(HocKy* hk, NodeMon* n)
{
	NodeMon* t = hk->headMon;
	if (t == NULL)
		return false;//ds trong
	while (t)
	{
		if (t->data.id == n->data.id && t->data.tenGv == n->data.tenGv && t->data.bh1.thu == n->data.bh1.thu && t->data.bh1.buoi == n->data.bh1.buoi)
		{
			return true;
		}
		t = t->pNext;
	}
	return false;
}
void NhapNodeMon(NodeMon* n)
{
	n->pNext = NULL;
	cout << "Nhap thong tin mon hoc:\n";
	cout << "Ten mon: ";
	cin.ignore();
	getline(cin, n->data.tenMon);
	cout << "Ma mon hoc: ";
	getline(cin, n->data.id);
	cout << "Ten giao vien giang day: ";
	getline(cin, n->data.tenGv);
	do
	{
		cout << "So tin chi: ";
		cin >> n->data.so_tc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			n->data.so_tc = 0;
		}
	} while (n->data.so_tc < 1);
	do
	{
		cout << "So luong sinh vien toi da: ";
		cin >> n->data.MaxSv;//check cin
		if (cin.fail() || n->data.MaxSv < 0)
		{
			cout << "Nhap sai kieu du lieu cho so luong sinh vien!\n";
			cout << "Vui long nhap lai!\n";
			cin.clear();
			cin.ignore();
			n->data.MaxSv = 0;
		}
	} while (n->data.MaxSv == 0);
	NhapTgMon(n);
}
void TaoMon(ListNamHoc& l, int nam)//hk hien tai vua moi tao   
{
	int i = 0;//i: stt hoc ky
	HocKy* hk = HkHienTai(l, NodeNamHienTai(l), i);
	if (hk == NULL)
		return;
	cout << "TAO MOI MON HOC\n";
	NodeMon* n = new NodeMon;
	NhapNodeMon(n);
	if (checkTrungMon(hk, n))
	{
		cout << "Ban da tao mon hoc nay truoc do roi!\n";
		return;
	}
	if (hk->headMon)
	{
		n->pNext = hk->headMon;
	}
	hk->headMon = n;
	//ghi vao file hk htai moi nhat 
	string fPath = to_string(nam) + "hk" + to_string(i) + ".txt";
	fstream f;
	f.open(fPath, ios::in | ios::app);
	f << endl;
	f << n->data.id << "," << n->data.tenMon << "," << n->data.tenGv << ",";
	f << n->data.so_tc << ",";
	f << n->data.bh1.thu << "," << n->data.bh1.buoi << ",";
	f << n->data.bh2.thu << "," << n->data.bh2.buoi << ",";
	if (f.good())
	{
		cout << "Tao moi mon hoc thanh cong!\n";
	}
	f.close();
	f.open(to_string(nam) + "hk" + to_string(i) + n->data.id + ".txt", ios::out);
	f.close();
	cout << "Ban da co the mo dang ky ghi danh vao mon hoc nay!\n";
};

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

