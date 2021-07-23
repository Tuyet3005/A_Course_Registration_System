#include"staff.h"
//GIAO VU
int InMenuGv()
{
	system("cls");
	background_Gv();
	string title[5] = { "TAO MOI","CAP NHAT","HIEN THI","QUAY VE","THOAT" };
	return LuaChon_Dep(5,title);//lua chon lon nhat la 5
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
			Thoat = XlTaoMoi(InMenuTaoMoi(), l);
		} while (!Thoat);
		break;
	}
	case 2:
	{
		do
		{
			Thoat = XlCapNhat(InMenuCapNhat(), l);
		} while (!Thoat);
		break;
	}
	case 3:
	{

		int lc = 1;
		hienthiNam(l, lc);
		Thoat = true;
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		system("cls");
		background_Gv();
		if (Ask_YN("Ban thuc su muon THOAT?"))
		{
			gotoXY(0, HEIGHT - 4);
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
		Thoat = XlMenuGv(InMenuGv(), l);
	} while (!Thoat);
	system("cls");
}

void ThongbaoCautrucFile(bool chon)//import file dssv lop || file thong tin mon
{
	cout << endl << endl;
	//file dssv lop
	if (chon == 0)
	{
		cout << "File chua danh sach sinh vien lop hoc la file text (.txt).\n\n";
		Sleep(100);
		cout << "Thong tin moi sinh vien can nam rieng tren mot dong va theo cau truc nhu sau:\n";
		cout << "<mssv,stt,ten,ho,gioi tinh,ngay sinh,cccd/cmnd,> (vd:  <19120789,04,Tram,Nguyen Ai,Nu,07052001,111111111,> ).\n\n";
		Sleep(200);
		cout << "HAY CHAC CHAN FILE DA DUOC TAO theo dung cau truc de tien hanh ghi thong tin tu file len he thong!\n";
	}
	// file thong tin mon
	else
	{
		cout << "File chua thong tin cac mon hoc la file text (.txt) va thong tin moi mon duoc ghi rieng tren mot dong theo cau truc nhu sau:\n";
		cout << "id mon,ten mon,ten giao vien,so tin chi,ngay hoc 1,buoi hoc 1,ngay hoc 2,buoi hoc 2,si so toi da,\n\n";
		Sleep(100);
		cout << "Chu y khong nen co khoang cach sau cac dau phay!!!\n";
		cout << "Vi du: KTLT,Ky thuat lap trinh,Nguyen Le Hoang Dung,4,Thu Sau,S3,Thu Sau,S4,50,\n\n";
		Sleep(200);
		cout << "HAY CHAC CHAN FILE DA DUOC TAO theo dung cau truc de tien hanh ghi thong tin tu file len he thong!\n";
	}
}
bool importFilehayNhapTay(bool chon)
{
	cout << "--Chon phuong thuc lay thong tin : " << endl;
	cout << "1. Nhap TAY" << endl;
	cout << "2. Lay thong tin tu FILE" << endl;
	int lc;
	do {
		cout << "Nhap (1-2): ";
		cin >> lc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (lc == 1)
			return false;
		if (lc == 2)
		{
			cin.ignore();//xoa \n 
			ThongbaoCautrucFile(chon);
			system("pause");
			return true;
		}
	} while (true);
}

//TAO MOI
int InMenuTaoMoi()
{
	system("cls");
	printA_Sentence("-- TAO MOI --", 1);
	background_Gv();
	string title[7] = { "NAM HOC","LOP HOC","HOC KI","MON HOC","BUOI DANG KI KHOA HOC","QUAY VE","THOAT"};
	return LuaChon_Dep(7, title);
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
		break;
	}
	case 3:
	{
		system("cls");
		TaoHocKy(l);
		break;
	}
	case 4:
	{
		system("cls");
		NodeNamHoc* n = NodeNamHienTai(l);
		int nam = n->data.tg.ngay_bd.y;
		TaoMon(l, nam);
		break;
	}
	case 5:
	{
		taoDKKH_Gv(NodeNamHienTai(l));
		break;
	}
	case 6:
	{
		return true;
	}
	case 7:
	{
		system("cls");
		background_Gv();
		if (Ask_YN("Ban thuc su muon THOAT?"))
		{
			gotoXY(0, HEIGHT - 4);
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
		if (nam_bd < NHhientai_nambd())
		{
			cout << "Ban co chac muon tao mot nam hoc cu da qua? Y/N?\n";
			char lenh;
			cin >> lenh;
			if (lenh == 'Y' || lenh == 'y')
			{
				break;
			}
			else
				return NULL;
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
	n->data.headLop[0] = n->data.headLop[1] = n->data.headLop[2] = n->data.headLop[3] = NULL;
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
}
int HienNamHoc(ListNamHoc l)
{
	int i = 0;
	if (l.pHead)
	{
		cout << "Cac nam hoc da tao: \n";
		NodeNamHoc* n = l.pHead;
		while (n)
		{
			cout << ++i << ". Nam hoc ";
			cout << n->data.tg.ngay_bd.y << " - " << n->data.tg.ngay_kt.y << endl;
			n = n->pNext;
		}
	}
	else
		cout << "CHUA CO NAM HOC NAO!\n";
	return i;
}
void TaoNam(ListNamHoc& l)
  {
	cout << "TAO MOI 1 NAM HOC\n";
	NodeNamHoc* n = TaoNodeNam();
	ThemNodeNamHoc(l, n);
	if (n)
		cout << "Tao nam hoc moi thanh cong!!!" << endl;
}

//lop hoc  
NodeLop* TaoNodeLop(string ten)
{
	NodeLop* n = new NodeLop;
	n->lop.ten = ten;
	n->pNext = NULL;
	return n;
}
void ThemNodeLopHoc(NodeLop*& HeadLop, NodeLop* n)
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
	int sl = 0;
	//nhap ten lop moi len file, tao node len he thong
	cout << "------------------------TAO MOI LOP HOC NAM NHAT------------------------\n";
	cout << "Nhap so luong lop nam nhat muon tao: ";
	cin >> sl;
	if (cin.fail() || sl < 0)
	{
		cin.clear();
		cin.ignore();
		sl = 0;
	}
	if (sl == 0)
		return;
	for (int i = 0; i < sl; i++)
	{
		string ten;
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
		Sleep(500);
		n->lop.headSvLop = NULL;
	}
	cout << "Ban da co the cap nhat dssv cho (cac) lop hoc vua tao!\n";
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
void HienLuaChonThu(int buoi)
{
	cout << "\nBuoi " << buoi << ":\n";
	cout << "1. Thu hai \t 2. Thu ba \t 3. Thu tu\n";
	cout << "4. Thu nam \t 5. Thu sau \t 6. Thu bay\n";
}
void HienLuaChonGio()
{
	cout << "\nKhung gio:\n";
	cout << "1. S1 (07:30)\t 2. S2 (09:30)\n";
	cout << "3. S3 (13:30)\t 4. S4 (15:30)\n";
}
void NhapTgMon(NodeMon* n)
{
	do
	{
		cout << "Chon thoi gian cua hai buoi hoc trong tuan:\n";
		for (int i = 1; i < 3; i++)
		{
			int lc;
			HienLuaChonThu(i);
			do
			{
				cout << "Nhap lua chon (1-6): ";
				cin >> lc;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100,'\n');
					lc = 0;
				}
			} while (lc < 1 || lc>6);
			if (i == 1)
				XulyThu(lc, n->data.bh1);
			else
				XulyThu(lc, n->data.bh2);
			HienLuaChonGio();
			do
			{
				cout << "Nhap lua chon (1-4): ";
				cin >> lc;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					lc = 0;
				}
			}  while (lc < 1 || lc>4);
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
		if (t->data.id == n->data.id && t->data.tenGv == n->data.tenGv)
		{
			//trung tiep buoi hoc 
			if(t->data.bh1.thu == n->data.bh1.thu && t->data.bh1.buoi == n->data.bh1.buoi)
				return true;
			if (t->data.bh1.thu == n->data.bh1.thu && t->data.bh1.buoi == n->data.bh1.buoi)
				return true;
		}
		t = t->pNext;
	}
	return false;
}
void NhapNodeMon(NodeMon* n)
{
	n->pNext = NULL;
	cout << "\nNhap thong tin mon hoc:\n";
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
		cin >> n->data.MaxSv;
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
void TaoMon(ListNamHoc& l, int nam)
{
	int i = 0;//i: stt hoc ky
	HocKy* hk = HkHienTai(l, NodeNamHienTai(l), i);
	if (hk == NULL)
		return;
	cout << "TAO MOI MON HOC\n";
	NodeMon* head;
	if (importFilehayNhapTay(1))
	{
		system("cls");
		cout << "TAO MOI MON HOC\n\n";
		string file;
		ifstream f;
		do {
			cout << "Nhap duong dan: " << endl;
			getline(cin, file, '\n');
			f.open(file);
			if (f.good())
			{
				f.close();
				break;
			}
			cout << "Loi mo file!!!" << endl;
			cout << "Ban co muon nhap duong dan file khac? Nhap 'Y' de tiep tuc: ";
			char lenh;
			cin >> lenh;
			if (lenh != 'y' && lenh != 'Y')
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Tao mon khong thanh cong!!!\n";
				return;
			}
		} while (true);
		mondangmo_docfile(file, nam, hk, i);
	}
	else
	{
		mondangmo_nhaptay(nam, hk, i);
	}
};
void mondangmo_docfile(string file, int nam, HocKy* hk, int stt_hk)//file nay chi co ds mon khong co tg bd
{
	ifstream f;
	f.open(file);
	if (!f.is_open())
	{
		cout << "Loi: Khong the mo file!" << endl;
		return;
	}
	string s;
	while (!f.eof())
	{
		getline(f, s, ',');
		if (s == "" || s == "\n")
		{
			cout << "Da den cuoi file!!!\n";
			return;
		}
		NodeMon* n = new NodeMon;
		n->data.id = s;
		try
		{
			getline(f, n->data.tenMon, ',');
			getline(f, n->data.tenGv, ',');
			getline(f, s, ',');
			n->data.so_tc = stoi(s);
			getline(f, n->data.bh1.thu, ',');
			getline(f, n->data.bh1.buoi, ',');
			getline(f, n->data.bh2.thu, ',');
			getline(f, n->data.bh2.buoi, ',');
			getline(f, s, ',');
			n->data.MaxSv = stoi(s);
			if (!f.good())
			{
				throw "Loi lay du lieu tu file!!!\n";
			}
			getline(f, s);//xoa "\n" ra khoi f
			f.clear();
		}
		catch (const char* error)
		{
			cerr << error;
			cout << "\nTao moi mon hoc that bai!!!\n";
			return;
		}
		n->pNext = NULL;
		n->headSvMon = NULL;
		if (checkTrungMon(hk, n))
		{
			cout << "Ban da tao mon hoc nay truoc do roi!\n";
			return;
		}
		ThemNodeMon(hk->headMon, n);//them vao list mon cua hoc ky? A ko phai node hk , can ktra n co trung mon hay ko?
		//ghi vao file hk htai moi nhat 
		string fPath = to_string(nam) + "hk" + to_string(stt_hk) + ".txt";
		fstream f;
		f.open(fPath, ios::in | ios::app);
		f << endl;
		f << n->data.id << "," << n->data.tenMon << "," << n->data.tenGv << ",";
		f << n->data.so_tc << ",";
		f << n->data.bh1.thu << "," << n->data.bh1.buoi << ",";
		f << n->data.bh2.thu << "," << n->data.bh2.buoi << ",";
		f << n->data.MaxSv<<",";
		if (f.good())
		{
			cout << "\nTao moi mon hoc "<<n->data.id<<" vua nhap thanh cong!\n";
		}
		f.close();
		f.open(to_string(nam) + "hk" + to_string(stt_hk) + n->data.id + ".txt", ios::out);
		f.close();
		cout << "Ban da co the mo dang ky ghi danh vao mon hoc nay!\n";
	}
}
void mondangmo_nhaptay(int nam, HocKy* hk, int stt_hk)
{
	system("cls");
	cout << "TAO MOI MON HOC" << endl << endl;
	cout << "Nhap so mon hoc muon tao:" << endl;
	int somon = 0;
	while (true)
	{
		cout << "Moi nhap: " << endl;
		cin >> somon;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (somon > 0)
			break;
	}
	for (int i = 0; i < somon; i++)
	{
		NodeMon* n = new NodeMon;
		cout << endl << "--Mon hoc " << i + 1 << endl;
		NhapNodeMon(n);
		if (checkTrungMon(hk, n))
		{
			cout << "Ban da tao mon hoc nay truoc do roi!\n";
			continue;
		}
		ThemNodeMon(hk->headMon, n);
		//ghi vao file hk htai moi nhat 
		string fPath = to_string(nam) + "hk" + to_string(stt_hk) + ".txt";
		fstream f;
		f.open(fPath, ios::in | ios::app);
		f << endl;
		f << n->data.id << "," << n->data.tenMon << "," << n->data.tenGv << ",";
		f << n->data.so_tc << ",";
		f << n->data.bh1.thu << "," << n->data.bh1.buoi << ",";
		f << n->data.bh2.thu << "," << n->data.bh2.buoi << ",";
		f << n->data.MaxSv << ",";
		if (f.good())
		{
			cout << "Tao moi mon hoc thanh cong!\n";
		}
		f.close();
		//tao file de ghi dssv mon
		f.open(to_string(nam) + "hk" + to_string(stt_hk) + n->data.id + ".txt", ios::out);
		f.close();
		cout << "Ban da co the mo dang ky ghi danh vao mon hoc nay!\n";
	}
}


//CAP NHAT
int InMenuCapNhat()
{
	system("cls");
	printA_Sentence("-- CAP NHAT --", 2);
	background_Gv();
	string title[5] = { "THEM SINH VIEN NAM NHAT","CAP NHAT MON HOC","DIEM SINH VIEN","QUAY VE","THOAT" };
	return LuaChon_Dep(5,title);
}
int InMenuCapNhat2()
{
	system("cls");
	printA_Sentence("-- CAP NHAT MON HOC --", 2);
	background_Gv();
	string title[4] = { "SUA THONG TIN MON HOC","XOA MON HOC","QUAY VE","THOAT" };
	return LuaChon_Dep(4, title);
}
int InMenuCapNhat3()
{
	system("cls");
	printA_Sentence("-- CAP NHAT DIEM SINH VIEN--", 2);
	background_Gv();
	string title[5] = { "XUAT FILE DE GV NHAP DIEM","NHAP DIEM TU FILE","CHINH SUA DIEM","QUAY VE","THOAT" };
	return LuaChon_Dep(5, title);
}
bool XlCapNhat2(ListNamHoc& l, int chon)
{
	switch (chon)
	{
	case 1:
	{
		//sua thong tin mon
		system("cls");
		CapNhatMonHoc(l);
		break;
	}
	case 2:
	{
		//xoa mon
		system("cls");
		XoaMonHoc(l);
		break;
	}
	case 3:
	{
		return true;
	}
	case 4:
	{
		system("cls");
		background_Gv();
		if (Ask_YN("Ban thuc su muon THOAT?"))
		{
			gotoXY(0, HEIGHT - 4);
			exit(0);
		}
	}
	return false;//ngoai tru quay ve va thoat
	}
}
bool XlCapNhat3(ListNamHoc& l, int chon)
{
	switch (chon)
	{
	case 1:
	{
		system("cls");
		NodeNamHoc* nodeNam = NodeNamHienTai(l);
		int stt_hk = 0;
		HocKy* hk = HkHienTai(l, nodeNam, stt_hk);
		cin.ignore(100, '\n');
		XuatFileCsv(nodeNam, hk, stt_hk);
		break;
	}
	case 2:
	{
		system("cls");
		NodeNamHoc* nodeNam = NodeNamHienTai(l);
		int stt_hk = 0;
		HocKy* hk = HkHienTai(l, nodeNam, stt_hk);
		cin.ignore(100, '\n');
		NhapDiemTuFile(nodeNam, hk, stt_hk);
		break;
	}
	case 3:
	{
		system("cls");
		CapNhatDiemSv(l);
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		system("cls");
		background_Gv();
		if (Ask_YN("Ban thuc su muon THOAT?"))
		{
			gotoXY(0, HEIGHT - 4);
			exit(0);
		}
	}
	return false;//ngoai tru quay ve va thoat
	}
}
bool XlCapNhat(int chon, ListNamHoc& l)
{
	switch (chon)
	{
	case 1:
	{
		//them sv nam nhat
		ThemSvLopNam1(l);
		break;
	}
	case 2:
	{
		//cap nhat mon hoc
		bool Thoat = false;
		do
		{
			Thoat = XlCapNhat2(l,InMenuCapNhat2());
		} while (!Thoat);
		break;
	}
	case 3:
	{
		//cap nhat diem sinh vien 
		bool Thoat = false;
		do
		{
			Thoat = XlCapNhat3(l, InMenuCapNhat3());
		} while (!Thoat);
		break;
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		system("cls");
		background_Gv();
		if (Ask_YN("Ban thuc su muon THOAT?"))
		{
			gotoXY(0, HEIGHT - 4);
			exit(0);
		}
	}
	}
	return false;//ngoai tru lenh quay ve va thoat + chon y/Y
}

NodeNamHoc* ChonNamHoc(ListNamHoc l, int nam_hoc)
{
	NodeNamHoc* nam = l.pHead;
	while (nam != NULL)
	{
		if (nam->data.tg.ngay_bd.y == nam_hoc)
		{
			return nam;
		}
		nam = nam->pNext;
	}
	return NULL;
}
NodeNamHoc* NhapNamHoc(ListNamHoc l)
{
	int nam_hoc;
	NodeNamHoc* nam;

	while (true)
	{
		cout << "Nhap nam hoc: ";
		cin >> nam_hoc;
		cin.ignore();
		nam = ChonNamHoc(l, nam_hoc);
		if (nam != NULL)
		{
			return nam;
		}
		else
		{
			cout << "Nhap sai nam hoc.\n";
		}
	}
}
HocKy* NhapHocKy(NodeNamHoc* node_nam)
{
	int so_hoc_ky = -1;
	HocKy* hoc_ky;

	while (so_hoc_ky < 1 || so_hoc_ky > 3)
	{
		cout << "Nhap hoc ky (1 <= HK <= 3): ";
		cin >> so_hoc_ky;
		cin.ignore();
	}
	return &node_nam->data.hk[so_hoc_ky - 1];
}
HocKy* TimHocKy(ListNamHoc l)
{
	return NhapHocKy(NhapNamHoc(l));
}

//them sv 
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head)
{
	while (head&&n)
	{
		if (head->sv.stt == n->sv.stt || n->sv.id == head->sv.id)
		{
			cout << "Ban da them sinh vien co STT hoac MSSV tuong tu vao lop roi!\n";
			return true;
		}
		head = head->pNext;
	}
	return false;
}
void ThemNodeSvLop(NodeSv_Lop*& headSvLop, NodeSv_Lop* nodeSv)
{
	//them vao dau 
	if (headSvLop == NULL || nodeSv->sv.stt < headSvLop->sv.stt)
	{
		nodeSv->pNext = headSvLop;
		headSvLop = nodeSv;
	}
	//them vao giua hoac cuoi
	else
	{
		//duyet tim prenode cua node sv co stt lon hon stt cua node sv them vao
		NodeSv_Lop* temp = headSvLop;
		while (temp->pNext && (temp->pNext->sv.stt < nodeSv->sv.stt))
		{
			temp = temp->pNext;
		}
		//noi link prenode (temp) voi n va n voi after node (temp->pNext)
		nodeSv->pNext = temp->pNext;
		temp->pNext = nodeSv;
	}
}
void NhapThongtinSv(NodeSv_Lop* n, int i)
{
	cout << "\nNhap thong tin sinh vien " << i + 1 << ":\n";
	while (true)
	{
		cout << "Nhap MSSV (vd: 20120399, 18120335, ...):\n";
		cin >> n->sv.id;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		else if (n->sv.id < 10000000)
		{
			cout << "Nhap theo cau truc XXxxxxxx (XX la hai chu so cuoi cua nam hoc bat dau nam nhat cua sinh vien!!!)\n";
			continue;
		}
		else
			break;
	}
	while (true)
	{
		cout << "Nhap STT cua sinh vien trong lop:\n";
		cin >> n->sv.stt;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		else if (n->sv.stt < 1)
		{
			cout << "STT phai lon hon 0!!!\n";
			continue;
		}
		else
			break;
	}
	cout << "Nhap ten: (vd: Lan)\n";
	cin >> n->sv.ten;
	cin.ignore(100,'\n');
	cout << "Nhap ho: (Nguyen Thi)\n";
	getline(cin, n->sv.ho);
	while (true)
	{
		cout << "Nhap gioi tinh (Nu/Nam):\n";
		cin >> n->sv.gioi;
		if (n->sv.gioi == "Nu" || n->sv.gioi == "Nam")
			break;
	}
	while (true)
	{
		cout << "Nhap lan luot ngay, thang, nam sinh: (vd: neu sinh ngay 1/1/2001 thi nhap 1 1 2001)\n";
		cin >> n->sv.ngayS.d >> n->sv.ngayS.m >> n->sv.ngayS.y;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		if (NgayHopLe(n->sv.ngayS.d, n->sv.ngayS.m, n->sv.ngayS.y))
			break;
	}
	cin.ignore();
	cout << "CMND/CCCD: \n";//lieu co loi j se xay ra hon ta 
	cin >> n->sv.cmnd;
}
void ThemSvLop_tay(NodeLop* nodeLop)
{
	system("cls");
	cout << "----THEM SINH VIEN VAO LOP " << nodeLop->lop.ten << "----\n";
	cout << "Nhap so luong sinh vien them vao: ";
	int sl;
	cin >> sl;
	bool flag = false;//danh dau file co data roi hay chua?
	if (nodeLop->lop.headSvLop)
		flag = true;
	for (int i = 0; i < sl; i++)
	{
		NodeSv_Lop* n = new NodeSv_Lop;
		n->pNext = NULL;
		NhapThongtinSv(n, i);
		if (checkTrungSv(n, nodeLop->lop.headSvLop))
			continue;
		{
			fstream f(nodeLop->lop.ten + ".txt", ios::app);
			//<mssv, stt, ten, ho, gioi tinh, ngay sinh, cccd / cmnd,>
			if (flag)
				f << endl;
			f << n->sv.id << ',';
			f << n->sv.stt << ',';
			f << n->sv.ten << ',';
			f << n->sv.ho << ',';
			f << n->sv.gioi << ',';
			if (n->sv.ngayS.d < 10)
				f << '0';
			f << n->sv.ngayS.d;
			if (n->sv.ngayS.m < 10)
				f << '0';
			f << n->sv.ngayS.m;
			f << n->sv.ngayS.y << ',';
			f << n->sv.cmnd << ",";
			if (f.good())
				cout << "Them sinh vien vao lop thanh cong!\n";
			f.close();
		}
		ThemNodeSvLop(nodeLop->lop.headSvLop, n);
		flag = true;
	}
}
void ThemSvLop_file(NodeLop* nodeLop)
{
	if (nodeLop == NULL)
	{
		cout << "Loi! Chua tao lop!!!\n";
		return;
	}
	system("cls");
	cout << "----THEM SINH VIEN VAO LOP " << nodeLop->lop.ten << "----\n";
	string file, s;
	ifstream f;
	do
	{
		cout << "\nNhap duong dan den den file ban muon lay thong tin:\n";
		getline(cin, file);
		f.open(file);
		if (f.is_open())
		{
			getline(f, s);
			f.close();
			if (s == "")
			{
				cout << "File trong!!!\n";
				cout << "Them sinh vien tu file that bai!!!\n";
				return;
			}
			break;
		}
		f.close();
		cout << "Loi mo file!!!" << endl;
		cout << "Ban co muon nhap duong dan file khac? Nhap 'Y' de tiep tuc: ";
		char lenh;
		cin >> lenh;
		if (lenh != 'y' && lenh != 'Y')
		{
			cout << "Them sinh vien tu file khong thanh cong!!!\n";
			return;
		}
		else
		{
			cin.ignore(100, '\n');
			continue;
		}
	} while (true);
	f.open(file);
	fstream ofs(nodeLop->lop.ten + ".txt", ios::app);
	bool flag = false;
	if (nodeLop->lop.headSvLop)
		flag = true;
	while (!f.eof())
	{
		Sv T;
		f.clear();
		getline(f, s, ',');
		try
		{
			if (s != "")
			{
				f.clear();
				T.id = stoi(s);
				f.clear();
				getline(f, s, ',');
				T.stt = stoi(s);
				f.clear();
				getline(f, T.ten, ',');
				f.clear();
				getline(f, T.ho, ',');
				f.clear();
				getline(f, T.gioi, ',');
				f.clear();
				getline(f, s, ',');
				T.ngayS.d = stoi(s);
				T.ngayS.y = T.ngayS.d % 10000;
				T.ngayS.m = (T.ngayS.d / 10000) % 100;
				T.ngayS.d = T.ngayS.d / 1000000;
				f.clear();
				getline(f, s, ',');
				T.cmnd = atoi(s.c_str());
				if (!f.good())
				{
					throw - 1;
				}
				getline(f, s);//lay \n 
				NodeSv_Lop* n = TaoNodeSv(T);
				if (checkTrungSv(n, nodeLop->lop.headSvLop))
				{
					cout << "Thong bao: Sinh vien them vao bi trung thong tin (mssv, stt) voi sinh vien da co!\n\n";
					cout << "Ban co muon tiep tuc lay thong tin sinh vien khac tu file? Nhap Y/N: ";
					char lenh;
					cin >> lenh;
					cout << "\n";
					if (lenh == 'Y' || lenh == 'y')
						continue;
					else
						break;
				}
				else
				{
					//ghi vao file
					{
						//<mssv, stt, ten, ho, gioi tinh, ngay sinh, cccd / cmnd,>
						ofs.clear();
						if (flag)
							ofs << endl;
						ofs << n->sv.id << ',';
						ofs << n->sv.stt << ',';
						ofs << n->sv.ten << ',';
						ofs << n->sv.ho << ',';
						ofs << n->sv.gioi << ',';
						if (n->sv.ngayS.d < 10)
							ofs << '0';
						ofs << n->sv.ngayS.d;
						if (n->sv.ngayS.m < 10)
							ofs << '0';
						ofs << n->sv.ngayS.m;
						ofs << n->sv.ngayS.y << ',';
						ofs << n->sv.cmnd << ",";
					}
					ThemNodeSvLop(nodeLop->lop.headSvLop, n);
					n->headMon[0] = n->headMon[1] = n->headMon[2] = NULL;
					flag = true;
					cout << "Them sinh vien thanh cong!\n";
				}
			}
			else
			{
				cout << "Da den cuoi file!!!\n";
				ofs.close();
				return;
			}
		}
		catch (int)
		{
			cout << "Lay du lieu tu file that bai!!!\n";
			return;
		}
	}
}
void ThemSvLopNam1(ListNamHoc& l)
{
	do
	{
		NodeLop* head = NodeNamHienTai(l)->data.headLop[0];
		int max = viewDsLop(head);
		cout << endl;
		cout << "------THEM SINH VIEN NAM NHAT VAO LOP------\n";
		int stt;
		do
		{
			cout << "Nhap STT cua lop ma ban muon them sinh vien vao (1-" << max << "): ";
			cin >> stt;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
			}
			else if (stt<1 || stt>max)
				continue;
			else
				break;
		} while (true);
		cout << endl;
		NodeLop* n = head;
		for (int i = 1; i < stt; i++)
		{
			n = n->pNext;
		}
		if (importFilehayNhapTay(0))
			ThemSvLop_file(n);
		else
			ThemSvLop_tay(n);
		cout << "Ban co muon tiep tuc? Nhap Y/N: ";
		char lenh;
		cin >> lenh;
		if (lenh != 'y' && lenh != 'Y')
			break;
	} 	while (true);
}

//nhap diem 
void XuatFileCsv(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk) //nam, hk <hien tai>
{
	system("cls");
	cout << "------XUAT CAC FILE CSV DSSV TUNG MON-------\n\n";
	if (hk->headMon == NULL)
	{
		cout << "Hoc ky nay chua co mon hoc nao dang mo!!!\n";
		return;
	}
	cout << "Nhap duong dan den vi tri ban muon luu cac file danh sach sinh vien :\n";
	string Path;
	getline(cin, Path);
	cout << endl;
	//Duyet cac node mon trong hk 
	int nam = nodeNam->data.tg.ngay_bd.y;
	NodeMon* temp = hk->headMon;
	while (temp)
	{
		//mo file dssv mon
		ifstream f(to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
		if (!f.is_open())
		{
			cin.ignore(100, '\n');
			cout << "Loi!!! Khong tim thay file chua danh sach sinh vien cua mon " << temp->data.id << "!!!\n";
			cout << "Tiep tuc voi cac mon khac? Nhap Y/N: ";
			char lenh;
			cin >> lenh;
			cin.ignore(100, '\n');
			if (lenh != 'y' && lenh != 'Y')
			{
				cout << "\nXuat file that bai!\n";
				return;
			}
			else
			{
				temp = temp->pNext;
				f.close();
				continue;
			}
		}
		string s;
		ofstream ofs;
		//ktra file da co data chua?
		getline(f, s, '\n');
		if (s != "")
		{
			ofs.open(Path + "/" + to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
			if (!ofs.is_open())
			{
				ofs.close();
				cout << "Loi: Khong the tao file dssv mon " << temp->data.id << " theo duong dan ban vua nhap!!!\n\n";
				f.close();
				cout << "Xuat cac file CSV that bai!!!\n";
				return;
			}
		}
		else
		{
			cout << "Chua co du lieu ve danh sach sinh vien cua mon hoc nay!!!\n";
			cout << "Xuat file CSV danh sach sinh vien cua mon " << temp->data.id << " that bai!!!\n";
			temp = temp->pNext;
			f.close();
			system("pause");
			continue;//di tiep den mon hoc khac 
		}
		f.close();
		//BAT DAU SAO CHEP FILE GOC
		f.open(to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
		//lay du lieu tu file cho den het file 
		getline(f, s);//copy dong dau trong file goc vao s
		while (true)
		{
			if (s != "")
				ofs << s;
			f.clear();
			getline(f, s);//copy dong tiep theo trong file goc vao s
			//ktra neu nhu dong tiep theo co data thi \n => ghi data vao file o vong lap tiep theo
			//nguoc lai thi file trong => dung lai
			if (s != "")
				ofs << "\n";
			else
				break;
		}
		ofs.close();
		f.close();
		cout << "Xuat file CSV danh sach sinh vien cua mon " << temp->data.id << " thanh cong!\n";
		//tiep tuc xuat file dssv cua mon hoc khac...
		temp = temp->pNext;
	}
}
bool DocDiemTuFile(string file, NodeMon* mon, int siso)// doc tu file tai len he thong
{
	ifstream f(file);
	string s;
	Diem* dsDiem = new Diem[siso];
	while (siso > 0)
	{
		getline(f, s, ',');//mssv
		f.clear();
		getline(f, s, ',');//lop
		f.clear();
		getline(f, s, ',');//ki hieu danh dau nhap diem <R: roi, C: chua>
		if (s == "R")
		{
			getline(f, s, ',');
			dsDiem[siso - 1].gk = stof(s);//dssv trong file nguoc voi dssv tren he thong
			getline(f, s, ',');
			dsDiem[siso - 1].ck = stof(s);
			getline(f, s, ',');
			dsDiem[siso - 1].cong = stof(s);
			getline(f, s, ',');
			dsDiem[siso - 1].tongket = stof(s);
		}
		else
		{
			delete[] dsDiem;
			return false;
		}
		getline(f, s);//bo \n
		siso--;
	}
	NodeSv_Mon* temp = mon->headSvMon;
	//khi doc diem vao mang dong da ghi nguoc de doc diem vao ds he thong cho thuan chieu
	siso = 0;
	while (temp)
	{
		temp->diem = dsDiem[siso++];
		temp = temp->pNext;
	}
	delete[] dsDiem;
	return true;
}
void NhapDiemTuFile(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk)
{
	system("cls");
	cout << "------NHAP DIEM CHO SINH VIEN TU FILE-------\n\n";
	if (hk->headMon == NULL)
	{
		cout << "Hoc ky nay chua co mon hoc nao dang mo!!!\n";
		return;
	}
	cout << "Can chac chan giao vien chi nhap diem vao file cho sinh vien ma khong thay doi cau truc, trat tu noi dung da co trong file!!!\n";
	Sleep(300);
	cout << "Thong nhat tat ca sinh vien deu duoc nhap diem day du truoc khi tai diem len he thong!!!\n";
	cout << "Cau truc nhap diem cho sinh vien: diem gk, diem ck, diem cong, diem tong ket.\n";
	cout << "\nNhap duong dan den vi tri luu cac file ma giao vien da nhap diem:\n";
	string Path;
	getline(cin, Path);
	cout << endl;
	int nam = nodeNam->data.tg.ngay_bd.y;
	NodeMon* temp = hk->headMon;
	while (temp)
	{
		//tim file 
		ifstream f(Path + "/" + to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
		if (!f.is_open())
		{
			cout << "Loi!!! Khong tim thay file diem cua sinh vien mon " << temp->data.id << "!!!\n";
			cout << "Tiep tuc voi cac mon khac? Nhap Y/N: ";
			char lenh;
			cin >> lenh;
			cout << endl;
			cin.ignore(100, '\n');
			if (lenh != 'y' && lenh != 'Y')
			{
				cout << "\nNhap diem tu file that bai!\n";
				return;
			}
			else
			{
				temp = temp->pNext;
				f.close();
				continue;
			}
		}
		string s;
		ofstream ofs;
		getline(f, s, '\n');
		//copy sang file cua he thong 
		if (s != "")
		{
			ofs.open(to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
			if (!ofs.is_open())
			{
				ofs.close();
				cout << "Loi: Ghi diem vao file cho sinh vien mon " << temp->data.id << " that bai!!!\n\n";
				f.close();
				temp = temp->pNext;
				continue;
			}
		}
		else
		{
			cout << "\nFile trong!!!\n";
			cout << "Nhap diem tu file cho sinh vien mon " << temp->data.id << " that bai!!!\n";
			temp = temp->pNext;
			f.close();
			continue;//di tiep den mon hoc khac 
		}
		f.close();
		//BAT DAU SAO CHEP FILE 
		f.open(Path + "/" + to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
		//lay du lieu tu file cho den het file 
		getline(f, s);//copy dong dau trong file goc vao s
		int siso = 0;//si so sv cua mon
		while (true)
		{
			if (s != "")
			{
				ofs << s;
				siso++;
			}
			f.clear();
			getline(f, s);//copy dong tiep theo trong file goc vao s
			//ktra neu nhu dong tiep theo co data thi \n => ghi data vao file o vong lap tiep theo
			//nguoc lai thi file trong => dung lai
			if (s != "")
				ofs << "\n";
			else
				break;
		}
		ofs.close();
		f.close();
		//doc len he thong
		if (DocDiemTuFile(to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt", temp, siso))
			cout << "Nhap diem cho sinh vien mon " << temp->data.id << " thanh cong!\n";
		else
			cout << "Nhap diem cho sinh vien mon " << temp->data.id << " that bai!\n";
		//tiep tuc xuat file dssv cua mon hoc khac...
		temp = temp->pNext;
	}
}

string NextLine(string& data)
{
	size_t pos = data.find('\n');
	string line = data.substr(0, pos);
	data = pos != string::npos ? data.substr(pos + 1) : "";
	return line;
}

//sua diem
float NhapDiem(float diem)
{
	while (diem < 0 || diem > 10)
	{
		cout << "0 <= diem <= 10. Nhap diem: ";
		cin >> diem;
		cin.ignore();
	}
	return diem;
}
void LuuDiemSv(string filename, NodeSv_Mon* node_sv_mon)
{
	fstream file(filename, ios::in);
	string data = "", line;
	while (!file.eof())
	{
		getline(file, line);
		if (line.empty())
			break;
		data += line + '\n';
	}
	data = data.substr(0, data.length() - 1);
	file.close();

	file.open(filename, ios::out);
	bool success = false, wrote = false;

	while (!data.empty())
	{
		if (wrote)
			file << '\n';
		line = NextLine(data);

		if (line.find(to_string(node_sv_mon->mssv) + "," + node_sv_mon->lop + ",") == 0)
		{
			file << node_sv_mon->mssv << ',' << node_sv_mon->lop << ',' << "R" << ','
				<< node_sv_mon->diem.gk << ','
				<< node_sv_mon->diem.ck << ','
				<< node_sv_mon->diem.gk << ','
				<< node_sv_mon->diem.tongket << ',';
			success = true;
		}
		else
		{
			file << line;
		}
	}
	if (!success)
		file << node_sv_mon->mssv << ',' << node_sv_mon->lop << ',' << "R" << ','
		<< node_sv_mon->diem.gk << ','
		<< node_sv_mon->diem.ck << ','
		<< node_sv_mon->diem.gk << ','
		<< node_sv_mon->diem.tongket << ',';
	file.close();
	cout << "Luu diem thanh cong!!!\n";
}
void HienThiDSLop(NodeLop* head_lop)
{
	cout << "\nDanh sach lop:\n";
	for (NodeLop* node_lop = head_lop; node_lop != NULL; node_lop = node_lop->pNext)
	{
		cout << "Lop: " << node_lop->lop.ten << '\n';
	}
}
void HienThiDSSv(NodeSv_Lop* head_sv_lop)
{
	cout << "\nDanh sach SV:\n";
	for (NodeSv_Lop* node_sv_lop = head_sv_lop; node_sv_lop != NULL; node_sv_lop = node_sv_lop->pNext)
	{
		cout << "MSSV: " << node_sv_lop->sv.id << ", Ten: " << node_sv_lop->sv.ten << ", CMND: " << node_sv_lop->sv.cmnd << '\n';
	}
}
void CapNhatDiemSv(ListNamHoc& l)
{
	NodeNamHoc* node_nam = NhapNamHoc(l);
	int nam_hoc = node_nam->data.tg.ngay_bd.y;
	int nam_sv = -1;
	while (nam_sv < 1 || nam_sv > 4)
	{
		cout << "Nhap nam (sv nam 1, nam 2, ...): ";
		cin >> nam_sv;
		cin.ignore();
	}

	NodeLop* head_lop = node_nam->data.headLop[nam_sv - 1];
	NodeLop* node_lop;
	string ten_lop;
	while (true)
	{
		HienThiDSLop(head_lop);
		cout << "Ten lop: ";
		getline(cin, ten_lop);

		for (node_lop = head_lop; node_lop != NULL; node_lop = node_lop->pNext)
		{
			if (node_lop->lop.ten == ten_lop)
			{
				break;
			}
		}
		// Thu lai
		if (node_lop == NULL)
			continue;
		break;
	}

	NodeSv_Lop* node_sv_lop;
	int mssv;
	while (true)
	{
		HienThiDSSv(node_lop->lop.headSvLop);
		cout << "Nhap MSSV: ";
		cin >> mssv;
		cin.ignore();

		for (node_sv_lop = node_lop->lop.headSvLop; node_sv_lop != NULL; node_sv_lop = node_sv_lop->pNext)
		{
			if (node_sv_lop->sv.id == mssv)
				break;
		}
		if (node_sv_lop != NULL)
			break;
	}

	int hoc_ky = -1;
	while (hoc_ky < 1 || hoc_ky > 3)
	{
		cout << "Nhap hoc ky (1 <= HK <= 3): ";
		cin >> hoc_ky;
		cin.ignore();
	}

	NodeMon_Sv*& head_mon_sv = node_sv_lop->headMon[hoc_ky - 1];
	NodeMon_Sv* node_mon_sv;
	string id_mon;
	while (true)
	{
		HienThiDSMon(head_mon_sv->mon);
		cout << "Nhap ID mon: ";
		getline(cin, id_mon);
		for (node_mon_sv = head_mon_sv; node_mon_sv != NULL; node_mon_sv = node_mon_sv->pNext)
		{
			if (node_mon_sv->mon->data.id == id_mon)
				break;
		}
		if (node_mon_sv != NULL)
			break;
	}

	NodeSv_Mon* node_sv_mon;
	for (node_sv_mon = node_mon_sv->mon->headSvMon; node_sv_mon != NULL; node_sv_mon = node_sv_mon->pNext)
	{
		if (node_sv_mon->mssv == mssv && node_sv_mon->lop == ten_lop)
			break;
	}
	if (node_sv_mon == NULL)
	{
		// Tao NodeSv_Mon moi neu can
		node_sv_mon = new NodeSv_Mon;
		node_sv_mon->mssv = mssv;
		node_sv_mon->lop = ten_lop;
		node_sv_mon->pNext = node_mon_sv->mon->headSvMon;
		node_mon_sv->mon->headSvMon = node_sv_mon;
		ThemNodeMon_Sv(node_mon_sv, node_mon_sv->mon, node_sv_mon);
	}

	Diem& diem = node_sv_mon->diem;
	string input = "-1";

	cout << "Diem giua ky (" << diem.gk << "): ";
	getline(cin, input);
	try
	{
		diem.gk = NhapDiem(stof(input));
	}
	catch (invalid_argument) {}

	cout << "Diem cuoi ky (" << diem.ck << "): ";
	getline(cin, input);
	try
	{
		diem.ck = NhapDiem(stof(input));
	}
	catch (invalid_argument) {}

	cout << "Diem cong (" << diem.cong << "): ";
	getline(cin, input);
	try
	{
		diem.cong = NhapDiem(stof(input));
	}
	catch (invalid_argument) {}

	diem.tongket = min((diem.gk + diem.ck * 2.0) / 3 + diem.cong / 10, 10.0);

	string filename = to_string(nam_hoc) + "hk" + to_string(hoc_ky) + id_mon + ".txt";
	LuuDiemSv(filename, node_sv_mon);
}

//sua, xoa mon
NodeMon* ChonMonHoc(HocKy* hk, string id_mon_hoc)
{
	NodeMon* mon_hoc = hk->headMon;
	while (mon_hoc != NULL)
	{
		if (mon_hoc->data.id == id_mon_hoc)
		{
			return mon_hoc;
		}
		mon_hoc = mon_hoc->pNext;
	}
	return NULL;
}
void HienThiDSMon(NodeMon* head_mon)
{
	if (head_mon == NULL)
	{
		cout << "Danh sach mon hoc trong!\n";
		return;
	}
	cout << "\nDanh sach mon hoc:\n";
	for (NodeMon* node_mon = head_mon; node_mon != NULL; node_mon = node_mon->pNext)
	{
		cout << "ID: " << node_mon->data.id << ", Ten: " << node_mon->data.tenMon << ", Ten GV: " << node_mon->data.tenGv << '\n';
	}
}
NodeMon* NhapMonHoc(HocKy* hoc_ky)
{
	string id_mon_hoc;
	NodeMon* mon = NULL;

	while (true)
	{
		HienThiDSMon(hoc_ky->headMon);
		cout << "Nhap ID mon hoc: ";
		getline(cin, id_mon_hoc);
		mon = ChonMonHoc(hoc_ky, id_mon_hoc);
		if (mon != NULL)
		{
			return mon;
		}
		else
		{
			cout << "Nhap sai ID mon hoc.\n";
		}
	}
}
NodeMon* NhapMonHoc(ListNamHoc l)
{
	return NhapMonHoc(TimHocKy(l));
}
// Luu mon hoc vao file tuong ung
void GhiFileMon(string filename, NodeMon* mon, bool remove)
{
	fstream file(filename, ios::in);
	string data, line;
	getline(file, data);
	while (!file.eof())
	{
		getline(file, line);
		data += '\n' + line;
	}
	file.close();

	file.open(filename, ios::out);
	file << NextLine(data);
	bool success = false;

	while (!data.empty())
	{
		line = NextLine(data);
		if (line.find(mon->data.id + ",") == 0)
		{
			if (remove)
			{
				cout << "Xoa mon hoc thanh cong!!!\n";
				success = true;
			}
			else
			{
				file << mon->data.id << ',' << mon->data.tenMon << ',' << mon->data.tenGv << ',' << mon->data.so_tc << ','
					<< mon->data.bh1.thu << ',' << mon->data.bh1.buoi << ','
					<< mon->data.bh2.thu << ',' << mon->data.bh2.buoi << ','
					<< mon->data.MaxSv << ',';
				cout << "Luu mon hoc thanh cong!!!\n";
				success = true;
			}
		}
		else
		{
			file << '\n' <<  line;
		}
	}
	if (!success)
		cout << "Khong the tim thay mon hoc " << mon->data.id << " - " << mon->data.tenMon << "!!!\n";
	file.close();
}
// Tim va luu vao file tuong ung
void LuuMonHoc(ListNamHoc& l, NodeMon* node_mon, bool remove)
{
	for (NodeNamHoc* nam = l.pHead; nam != NULL; nam = nam->pNext)
	{
		for (int stt_hoc_ky = 0; stt_hoc_ky <= 2; stt_hoc_ky++)
		{
			HocKy hoc_ky = nam->data.hk[stt_hoc_ky];
			for (NodeMon* mon = hoc_ky.headMon; mon != NULL; mon = mon->pNext)
			{
				if (mon == node_mon)
				{
					GhiFileMon(to_string(nam->data.tg.ngay_bd.y) + "hk" + to_string(stt_hoc_ky + 1) + ".txt", node_mon, remove);
				}
			}
		}
	}
}
void CapNhatMonHoc(ListNamHoc& l)
{
	NodeMon* node_mon = NhapMonHoc(l);
	MonHoc& mon = node_mon->data;
	string input;

	cout << "Nhap thong tin moi. De trong va nhan enter de giu nguyen.\n";

	cout << "Ten mon (" << mon.tenMon << "): ";
	getline(cin, input);
	if (!input.empty()) mon.tenMon = input;

	cout << "Ten giao vien (" << mon.tenGv << "): ";
	getline(cin, input);
	if (!input.empty()) mon.tenGv = input;

	cout << "So tin chi (" << mon.so_tc << "): ";
	getline(cin, input);
	try
	{
		mon.so_tc = stoi(input);
	}
	catch (invalid_argument) {}

	cout << "So sinh vien toi da (" << mon.MaxSv << "): ";
	getline(cin, input);
	try
	{
		mon.MaxSv = stoi(input);
	}
	catch (invalid_argument) {}
	do
	{
		for (int i = 1; i < 3; i++)
		{
			int lc;
			HienLuaChonThu(i);
			do
			{
				cout << "Nhap lua chon (1-6): ";
				cin >> lc;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					lc = 0;
				}
			} while (lc < 1 || lc>6);
			if (i == 1)
				XulyThu(lc, mon.bh1);
			else
				XulyThu(lc, mon.bh2);
			HienLuaChonGio();
			do
			{
				cout << "Nhap lua chon (1-4): ";
				cin >> lc;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					lc = 0;
				}
			} while (lc < 1 || lc>4);
			if (i == 1)
			{
				mon.bh1.buoi = "S";
				mon.bh1.buoi += to_string(lc);
			}
			else
			{
				mon.bh2.buoi = "S";
				mon.bh2.buoi += to_string(lc);
			}
		}
		if ((mon.bh1.buoi == mon.bh2.buoi) && (mon.bh1.thu == mon.bh2.thu))
		{
			cout << "Hai buoi hoc trung nhau!!! Vui long nhap lai!\n";
		}
		else
		{
			LuuMonHoc(l, node_mon);
			break;
		}
	} 	while (true);	
}
void XoaMonHoc(ListNamHoc& l)
{
	system("cls");
	cout << "--------------------XOA MON HOC-------------------------\n";
	NodeNamHoc* node_nam = NhapNamHoc(l);
	int so_hoc_ky = -1;
	HocKy* hoc_ky;

	while (so_hoc_ky < 1 || so_hoc_ky > 3)
	{
		cout << "Nhap hoc ky (1 <= HK <= 3): ";
		cin >> so_hoc_ky;
		cin.ignore();
	}
	hoc_ky = &node_nam->data.hk[so_hoc_ky - 1];

	NodeMon* node_mon = NhapMonHoc(hoc_ky);
	LuuMonHoc(l, node_mon, true);
	string filename = to_string(node_nam->data.tg.ngay_bd.y) + "hk" + to_string(so_hoc_ky) + node_mon->data.id + ".txt";
	remove(filename.c_str());

	NodeMon* next = node_mon->pNext;
	NodeMon** p;
	for (p = &hoc_ky->headMon; *p != node_mon; p = &(*p)->pNext);
	(*p)->pNext = NULL;
	delete* p;
	*p = next;
}


//HIEN THI
void hienthiNam(ListNamHoc l, int& lc)
{
	lc = Chon(viewDsNam(l));
	if (lc == -1 || lc == 0)
	{
		//quay lai man hinh chinh
		return;
	}
	NodeNamHoc* temp = l.pHead;
	for (int i = 1; i < lc; i++)
		temp = temp->pNext;
	if (ChonKihayLop())
		hienthiKi(temp, lc);
	else		//view lop
	{
		system("cls");
		cout << "Ban muon xem lop cua hoc sinh nam may? 1/2/3/4?" << endl;
		cout << "Nhan phim tuong tu de chon.." << endl;
		char k = NULL;
		while (true)
		{
			k = _getch();
			if (k >= 49 && k <= 52)//1
				break;
		}
		hienthiDsLop(temp->data.headLop[(int)k - 49], lc);
	}
	if (lc == -1)
		hienthiNam(l, lc);
}
int Chon(int maxChoice)
{
	int key;
	char temp;
	string s;
	cout << "--Nhan ESC de thoat" << endl;
	cout << "--Nhan phim B de quay lai menu truoc" << endl << endl;
	cout << "Moi nhap (nhap STT): " << endl;
	int x = whereX();
	int y = whereY();
	while (true)
	{
		gotoXY(x, y);
		if (_kbhit())
		{
			temp = _getch();
			if (temp == 13)//enter
			{
				if (s != "")
				{
					key = stoi(s);
					if (key == 0 || key > maxChoice)
						cout << endl << "STT khong hop le... Hay nhap lai !";
					else
						return key;
					x = 0;
					y += 2;
				}
				s = "";
			}
			else if (temp == 27)
			{
				cout << "Ban that su muon thoat khoi Hien Thi? Y/N?" << endl;
				if (askY_N())
					return 0;
				else
					y += 2;
			}
			else if (temp == 'B' || temp == 'b')
				return -1;
			else if (temp == 8)//xoa
			{
				s.pop_back();//bo dau backspace
				s.pop_back();
				if (x != 0)
				{
					x--;
					gotoXY(x, y);
					cout << ' ';
					gotoXY(x, y);
				}
			}
			else if (temp < 48 || temp>57)
			{

			}
			else
			{
				s += temp;
				cout << temp;
				x++;
			}
		}
	}
}
//ki
void hienthiKi(NodeNamHoc* A, int& lc)
{
	lc = Chon(viewDsKi(A));
	if (lc == 0 || lc == -1)//thoat
		return;
	hienthiDsMon(A->data.hk[lc - 1].headMon, lc);
	if (lc == -1)
		hienthiKi(A, lc);
}
void hienthiDsMon(NodeMon* head, int& lc)
{
	system("cls");
	lc = Chon(viewDsMonHk(head, lc));
	if (lc == 0 || lc == -1)
		return;
	NodeMon* temp = head;
	for (int i = 1; i < lc; i++)
		temp = temp->pNext;
	hienthiDsSv_Mon(temp, lc);
	if (lc == -1)
		hienthiDsMon(head, lc);
}
void hienthiDsSv_Mon(NodeMon* A, int& lc)/////////
{
	viewDsSvMon(A);
	end(lc);
}
void end(int& lc)
{
	cout << "Nhan ESC de THOAT khoi HIEN THI" << endl;
	cout << "Nhan phim B de quay lai menu truoc" << endl;
	char temp = NULL;
	while (true)
	{
		temp = _getch();
		if (temp == 27)
		{
			cout << "Ban that su muon thoat khoi Hien Thi? Y/N?" << endl;
			if (askY_N())
			{
				lc = 0;
				return;
			}
		}
		else if (toupper(temp) == 'B')
		{
			lc = -1;
			return;
		}
	}
}
//lop 
bool ChonTThayDiem_Lop()
{
	system("cls");
	cout << "Nhan 1 neu ban muon xem THONG TIN SINH VIEN" << endl;
	cout << "Nhan 2 neu ban muon xem DIEM - GPA" << endl;
	char temp = NULL;
	while (true)
	{
		temp = _getch();
		if (temp == 49)//1
			return true;
		else if (temp == 50)//2
			return false;
	}
}
void hienthiDsLop(NodeLop* head, int& lc)
{
	lc = Chon(viewDsLop(head));
	if (lc == 0 || lc == -1) 
		return;
	NodeLop* temp = head;
	for (int i = 1; i < lc; i++)
		temp = temp->pNext;
	if (ChonTThayDiem_Lop())
		hienthiTTSv_Lop(temp, lc);
	else
		hienthiDiem_Lop(temp, lc);
	if (lc == -1)
		hienthiDsLop(head, lc);
}
void hienthiTTSv_Lop(NodeLop* A, int& lc)
{
	viewDsSvLop(A);
	end(lc);
}
void hienthiDiem_Lop(NodeLop* A, int& lc)
{
	viewDiem_Lop(A, 1);
	end(lc);
}
bool ChonKihayLop()
{
	system("cls");
	cout << "Nhan 1 neu ban muon xem KI HOC - MON HOC" << endl;
	cout << "Nhan 2 neu ban muon xem LOP HOC - SINH VIEN" << endl;
	char temp = NULL;
	while (true)
	{
		temp = _getch();
		if (temp == 49)//1
			return true;
		else if (temp == 50)//2
			return false;
	}
}