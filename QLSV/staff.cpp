#define _CRT_SECURE_NO_WARNINGS
#include"staff.h"

//GIAO VU
int InMenuGv()
{
	system("cls");
	background_Gv();
	string title[5] = { "TAO MOI","CAP NHAT","HIEN THI","QUAY VE","THOAT" };
	return LuaChon_Menu(5, title, 2, HEIGHT / 2);//lua chon lon nhat la 5
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
	//file dssv lop
	int x = WIDTH / 7 + 5;
	int y = whereY() + 7;;
	if (chon == 0)
	{
		gotoXY(x, y);
		cout << "File chua danh sach sinh vien lop hoc la file text (.txt).";
		Sleep(100);
		y += 2;
		gotoXY(x, y);
		cout << "Thong tin moi sinh vien can nam rieng tren mot dong va theo cau truc nhu sau:";
		y++;
		gotoXY(x, y);
		cout << "<mssv,stt,ten,ho,gioi tinh,ngay sinh,cccd/cmnd,> (vd:  <19120789,4,Tram,Nguyen Ai,Nu,07052001,111111111,> ).";
		Sleep(200);
		y += 2;
		gotoXY(x, y);
		cout << "HAY CHAC CHAN FILE DA DUOC TAO theo dung cau truc de tien hanh ghi thong tin tu file len he thong!";
	}
	// file thong tin mon
	else
	{
		gotoXY(x, y);
		cout << "File chua thong tin cac mon hoc la file text (.txt) va thong tin moi mon duoc ghi rieng tren mot dong theo cau truc nhu sau:";
		gotoXY(x, ++y);
		cout << "id mon,ten mon,ten giao vien,so tin chi,ngay hoc 1,buoi hoc 1,ngay hoc 2,buoi hoc 2,si so toi da,";
		y += 2;
		gotoXY(x, y);
		cout << "Chu y khong nen co khoang cach sau cac dau phay!!!";
		gotoXY(x, ++y);
		cout << "Vi du: KTLT,Ky thuat lap trinh,Nguyen Le Hoang Dung,4,Thu Sau,S3,Thu Sau,S4,50,";
		Sleep(200);
		y += 2;
		gotoXY(x, y);
		cout << "HAY CHAC CHAN FILE DA DUOC TAO theo dung cau truc de tien hanh ghi thong tin tu file len he thong!";
	}
	setColor(background_color, title_color1);
	printA_Sentence("Nhan phim bat ki de tiep tuc -->", HEIGHT - 5);
	_getch();
	system("cls");
}
bool importFilehayNhapTay(bool chon)
{

	string title[2] = { "NHAP TAY","LAY TU FILE" };
	int x = WIDTH / 3 + 5, y = 10;
	string file;
	NodeMon* re = NULL;
	setColor(background_color, title_color1);
	printA_Sentence("Chon phuong thuc lay du lieu:", 10);
	int lc = LuaChon_Menu(2, title, 2, 12);
	if (lc == 1)
		return false;
	else
		ThongbaoCautrucFile(chon);
	return true;
}

//TAO MOI
int InMenuTaoMoi()
{
	system("cls");
	printA_Sentence("-- TAO MOI --", 1);
	background_Gv();
	string title[7] = { "NAM HOC","LOP HOC","HOC KI","MON HOC","BUOI DANG KI KHOA HOC","QUAY VE","THOAT" };
	return LuaChon_Menu(7, title, 2, HEIGHT / 2);
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
		if (n)
		{
			int nam = n->data.tg.ngay_bd.y;
			TaoMon(l, nam);
		}
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
NodeNamHoc* TaoNodeNam(ListNamHoc& l)
{
	NodeNamHoc* n = new NodeNamHoc;
	int nam_bd;
	fstream f;
	string temp;
	char c;
	f.open("listnam.txt", ios::in | ios::app);
	setColor(background_color, title_color1);
	cout << "Nhap nam bat dau nam hoc: ";
	int x = whereX() + 5;
	int y = whereY();
	gotoXY(x, y);
	setColor(background_color, text_color);
	do
	{
		char c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (temp == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			temp.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (temp == "")
				continue;
			if (stoi(temp) < NHhientai_nambd())
			{
				system("cls");
				if (Ask_YN("Ban co chac muon tao mot nam hoc cu da qua?"))
					break;
				else
					return NULL;
			}
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			temp += c;
			cout << c;
		}
	} while (true);
	string s = "";
	nam_bd = stoi(temp);
	while (!f.eof())//ktra lo nhap nam trung voi nam da tao!!!!
	{
		f.clear();
		getline(f, s, ',');
		if (s != "")//file da chua du lieu
		{
			if (stoi(s) == nam_bd)
			{
				setColor(background_color, red);
				printA_Sentence("! NAM HOC DA DUOC TAO TRUOC DO !", HEIGHT - 5);
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
	//tai data lop n234
	TaiNam234(l.pTail, n);
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
void TaiNam234(NodeNamHoc*& namT, NodeNamHoc*& namS)
{
	ifstream f;
	fstream g;
	string s;
	int nam = namS->data.tg.ngay_bd.y;
	if (namT == NULL)
		return;
	//namT != NULL
	for (int i = 1; i < 4; i++)
	{
		namS->data.headLop[i] = namT->data.headLop[i - 1];
		f.open(to_string(nam - 1) + 'n' + to_string(i) + ".txt", ios::in);
		g.open(to_string(nam) + 'n' + to_string(i + 1) + ".txt", ios::app);
		while (!f.eof())
		{
			f.clear();
			getline(f, s);
			if (s != "")
				g << s;
		}
	}
}
void TaoNam(ListNamHoc& l)
{
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI MOT NAM HOC ~", 5);
	gotoXY(WIDTH / 3 + 5, 12);
	NodeNamHoc* n = TaoNodeNam(l);
	ThemNodeNamHoc(l, n);
	if (n)
	{
		int nam = n->data.tg.ngay_bd.y;
		setColor(background_color, title_color);
		printA_Sentence("~ TAO NAM HOC " + to_string(nam) + " - " + to_string(nam + 1) + " THANH CONG ~", HEIGHT - 5);
	}
	_getch();
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
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI LOP HOC NAM NHAT ~", 5);
	gotoXY(WIDTH / 3, 10);
	setColor(background_color, title_color1);
	cout << "Nhap so luong lop nam nhat muon tao: ";
	string temp;
	char c;
	int x = whereX() + 5;
	int y = whereY();
	gotoXY(x, y);
	setColor(background_color, text_color);
	do
	{
		char c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (temp == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			temp.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (temp == "")
				continue;
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			temp += c;
			cout << c;
		}
	} while (true);
	sl = stoi(temp);////////////////////////////////////////ko tao
	if (sl == 0)
	{
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
		_getch();
		return;
	}
	/// an phim to continue
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI LOP HOC NAM NHAT ~", 5);
	setColor(background_color, title_color1);
	printA_Sentence("- Luu y: Ten lop hoc co cau truc <khoa><ma nganh><ma lop> -", 7);
	setColor(background_color, text_color);
	printA_Sentence("Vd: 20CTT3", 8);
	x = WIDTH / 3;
	y = 10;
	bool trungTen = false;
	int nam = NHhientai_nambd();
	for (int i = 0; i < sl; i++)
	{
		//y = whereY();
		trungTen = false;
		gotoXY(x, y);
		string ten;
		cout << "Nhap ten lop " << i + 1 << ": ";
		while (true)
		{
			gotoXY(x + 19, y);
			getline(cin, ten);
			if (ten.length() == 0)
			{
				cin.ignore();
				continue;
			}
			//kiem tra chi dung doi voi cac nh 2000~ 
			if (stoi(ten.substr(0, 2)) != nam % 2000)
			{
				setColor(background_color, red);
				printA_Sentence("! TEN LOP KHONG HOP LE !", y + 3);
				setColor(background_color, text_color);
				printA_Sentence("Cau truc ten lop: <khoa><ma nganh><ma lop>", y + 4);
				_getch();
				printA_Sentence("                               ", y + 3);
				printA_Sentence("                                           ", y + 4);
				gotoXY(x + 19, y);
				cout << "                              ";
				gotoXY(x + 19, y);
				ten = "";
				continue;
			}
			break;
		}
		//ktra co bi trung ten lop
		NodeLop* temp = node->data.headLop[0];
		while (temp != NULL)
		{
			if (temp->lop.ten == ten)
			{
				setColor(background_color, red);
				printA_Sentence("! LOP DA DUOC TAO TRUOC DO !", y + 3);
				_getch();
				printA_Sentence("                                ", y + 3);
				setColor(background_color, text_color);
				trungTen = true;
				break;
			}
			temp = temp->pNext;
		}
		if (trungTen)
		{
			ten = "";
			gotoXY(x, y);
			cout << "                          ";
			gotoXY(x, y);
			i--;
			cin.ignore();
			continue;
		}
		fstream f;
		f.open(to_string(node->data.tg.ngay_bd.y) + "n1.txt", ios::app);//file lop nam1 
		f << ten << ",";
		f.clear();
		f.close();
		NodeLop* n = TaoNodeLop(ten);
		ThemNodeLopHoc(node->data.headLop[0], n);
		n->lop.headSvLop = NULL;
		system("cls");
		setColor(background_color, title_color);
		printA_Sentence("~ TAO MOI LOP HOC NAM NHAT ~", 5);
		gotoXY(0, 8);
		viewDsLop(node->data.headLop[0]);
		y = whereY() + 3;
	}
	setColor(background_color, title_color1);
	printA_Sentence("Nhan phim bat ki de tiep tuc -->", HEIGHT - 5);
	_getch();
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI LOP HOC NAM NHAT THANH CONG ~", HEIGHT / 2 - 2);
	setColor(background_color, title_color1);
	printA_Sentence("Ban da co the cap nhat dssv cho (cac) lop hoc vua tao", HEIGHT / 2);
	printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
	_getch();
}
//hoc ky 
NodeNamHoc* TimNodeNamHoc(ListNamHoc& l, int nam_bd)//tim nam hoc de them hk vao
{
	int line = whereY() + 5;
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
	setColor(background_color, red);
	printA_Sentence("Nam hoc tuong ung chua duoc tao !", line);
	setColor(background_color, title_color1);
	printA_Sentence("Ban co muon tao nam hoc do ngay?", line + 2);
	string title[2] = { "Ok, Lam lien","No no, khong he" };
	if (LuaChon_Menu(2, title, 2, line + 2) == 1)
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
bool sosanhNgay(Ngay ngay_truoc, Ngay ngay_sau)//truoc hoac bang thi true, sai thi false
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
	system("cls");
	//chua tao hk truoc 
	if (hktruoc->tg.ngay_bd.d == 0)
	{
		setColor(background_color, text_color);
		printA_Sentence("Ban CHUA TAO hoc ki " + to_string(hkTr), HEIGHT / 2);
		return true;
	}
	//hk sau co thoi gian xung dot voi thoi gian hoc ky truoc 
	else if (sosanhNgay(hktruoc->tg.ngay_kt, ngBD_hksau) == false)
	{
		setColor(background_color, text_color);
		printA_Sentence(" Hoc ky " + to_string(hkS) + " co thoi gian XUNG DOT voi thoi gian cua hoc ki " + to_string(hkTr), HEIGHT / 2);
		return true;
	}
	return false;
}
bool TaoHocKy(ListNamHoc& l)
{
	int hk = 0;
	int nam_bd;//nam bat dau cua nam hoc tuong ung ngay kt do user nhap vao
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI HOC KI ~", 5);
	hk = chonKi("Ban muon tao ki may ?");
	//lay tg hien tai
	tm now = ThoiGianHeThong();
	Ngay Dnow;
	Dnow.d = now.tm_mday;
	Dnow.m = now.tm_mon + 1;
	Dnow.y = now.tm_year + 1900;
	//nhap thoi gian bat dau, ket thuc 
	Ngay ngBD;
	Ngay ngKT;
	//nhap tg
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI HOC KI ~", 5);
	setColor(background_color, title_color1);
	printA_Sentence("Hoc ki : " + to_string(hk), 7);
	setColor(background_color, text_color);
	printA_Sentence("- NGAY BAT DAU -", 11);
	nhapNgay_ve(13);
	setColor(background_color, text_color);
	printA_Sentence("- NGAY KET THUC -", 19);
	nhapNgay_ve(21);
	while (true)
	{
		ngBD = nhapNgay_nhap(13);
		ngKT = nhapNgay_nhap(21);
		if (!sosanhNgay(ngBD, ngKT))//ss tg bd vs tg kt
		{
			setColor(background_color, red);
			printA_Sentence("! NGAY KET THUC PHAI SAU NGAY BAT DAU !", HEIGHT - 8);
			_getch();
			continue;
		}
		break;
	}
	//do tim node nam hoc tuong ung de them hoc ky vao
	if (ngKT.m < 8)
		nam_bd = ngKT.y - 1;//nam hoc bat dau tu dau thang 9 nam X den het thang 7 nam X+1 
	else
		nam_bd = ngKT.y;
	NodeNamHoc* nodeNam = TimNodeNamHoc(l, nam_bd);
	bool flag = false;//xung dot tg
	if (nodeNam)
	{
		//da tao ki chua
		fstream f;
		string s = "";
		string filePath = to_string(nam_bd) + "hk" + to_string(hk) + ".txt";
		f.open(filePath, ios::in);
		//da tao hk truoc do roi -> return;
		if (f.is_open() && (f >> s) && (s != ""))
		{
			f.close();
			setColor(background_color, red);
			printA_Sentence("! KI HOC " + to_string(hk) + " CUA NAM HOC " + to_string(nam_bd) + " - " + to_string(nam_bd + 1) + " DA DUOC TAO !", HEIGHT - 5);
			_getch();
			return false;
		}
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
			flag = XungdotTg(hk1P, ngBD, hk - 1, hk);
			break;
		}
		case 3:
		{
			hockyP = &(nodeNam->data.hk[2]);
			HocKy* hk2P = &(nodeNam->data.hk[1]);
			flag = XungdotTg(hk2P, ngBD, hk - 1, hk);
			break;
		}
		}
		if (flag)
		{
			system("cls");
			setColor(background_color, red);
			printA_Sentence("! TAO MOI HOC KI KHONG THANH CONG !", HEIGHT / 2 - 2);
			setColor(background_color, title_color1);
			printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 4);
			_getch();
			return false;
		}
		hockyP->headMon = NULL;
		hockyP->tg.ngay_bd = ngBD;
		hockyP->tg.ngay_kt = ngKT;
		f.close();
		f.open(filePath, ios::out);
		//ghi du lieu thoi gian vao file theo cau truc "ddmmyyyy,ddmmyyyy,\n"
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
		f.close();
		setColor(background_color, title_color);
		printA_Sentence("~ TAO MOI HOC KI THANH CONG ~", HEIGHT - 5);
		_getch();
		return true;
	}
	//ko tao nam hoc tuong ung thi ko them hk vao 
	else
	{
		setColor(background_color, red);
		printA_Sentence("! TAO MOI HOC KI KHONG THANH CONG !", HEIGHT / 2 - 2);
		setColor(background_color, text_color);
		printA_Sentence("Ban chua tao nam hoc tuong ung nen khong the tao hoc ki", HEIGHT / 2);
		_getch();
		return false;
	}
}

//mon hoc 
HocKy* checkHocKy(NodeNamHoc* n, int& i)//i: so thu tu hoc ky
{
	if (n == NULL)
		return NULL;
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
	system("cls");
	HocKy* hk = checkHocKy(n, i);
	if (!hk)//Chua tao hk nao 
	{
		//tao hk1 ghi tg vo file truoc -> tao mon
		char lenh;
		setColor(background_color, red);
		printA_Sentence("! BAN CHUA TAO HOC KI NAO CHO NAM HOC HIEN TAI !", HEIGHT / 2 - 4);
		if (Ask_YN("Ban co muon tao hoc ki moi ngay bay gio?"))
		{
			if (!TaoHocKy(l))
				return NULL;
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
int HienLuaChonThu(int line)
{
	string title_buoihoc[] = { "Thu Hai","Thu Ba","Thu Tu","Thu Nam","Thu Sau","Thu Bay" };
	return LuaChon_Menu(6, title_buoihoc, 2, line);
}
string HienLuaChonGio(int line)
{
	string title_gio[] = { "S1 (07:30)","S2 (09:30)","S3 (13:30)","S4 (15:30)" };
	return 'S' + to_string(LuaChon_Menu(4, title_gio, 2, 12));
}
void NhapTgMon(NodeMon* n)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("- CHON BUOI HOC THU NHAT -", 8);
	XulyThu(HienLuaChonThu(12), n->data.bh1);

	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("- CHON KHUNG GIO BUOI HOC THU NHAT -", 8);
	n->data.bh1.buoi = HienLuaChonGio(12);

	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("- CHON BUOI HOC THU HAI -", 8);
	XulyThu(HienLuaChonThu(12), n->data.bh2);

	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("- CHON KHUNG GIO BUOI HOC THU HAI -", 8);
	n->data.bh2.buoi = HienLuaChonGio(12);
}
bool checkTrungMon(NodeMon* head, NodeMon* n)
{
	NodeMon* t = head;
	if (t == NULL)
		return false;//ds trong
	while (t)
	{
		if (t->data.id == n->data.id && t->data.tenGv == n->data.tenGv)
		{
			//trung tiep buoi hoc 
			if (t->data.bh1.thu == n->data.bh1.thu && t->data.bh1.buoi == n->data.bh1.buoi)
				return true;
			if (t->data.bh2.thu == n->data.bh2.thu && t->data.bh2.buoi == n->data.bh2.buoi)
				return true;
			if (t->data.bh1.thu == n->data.bh2.thu && t->data.bh1.buoi == n->data.bh2.buoi)
				return true;
			if (t->data.bh2.thu == n->data.bh1.thu && t->data.bh2.buoi == n->data.bh1.buoi)
				return true;
		}
		t = t->pNext;
	}
	return false;
}
bool NhapNodeMon(NodeMon* n)
{
	system("cls");
	int x = WIDTH / 3 + 5;
	int y = 2;
	n->pNext = NULL;
	printA_Sentence("- NHAP THONG TIN MON HOC -", y);
	y += 3;
	setColor(background_color, title_color1);
	gotoXY(x, y);
	cout << "Ten mon: ";
	string s;
	setColor(background_color, text_color);
	while (true)
	{
		gotoXY(x + 30, y);
		//cin.ignore();
		getline(cin, s);
		if (s.length() == 0)
		{
			continue;
		}
		n->data.tenMon = s;
		break;
	}
	y += 2;
	gotoXY(x, y);
	setColor(background_color, title_color1);
	cout << "Ma mon hoc: ";
	setColor(background_color, text_color);
	while (true)
	{
		gotoXY(x + 30, y);
		//cin.ignore();
		getline(cin, s);
		if (s.length() == 0)
		{
			continue;
		}
		n->data.id = s;
		break;
	}
	y += 2;
	gotoXY(x, y);
	setColor(background_color, title_color1);
	cout << "Ten giao vien giang day: ";
	setColor(background_color, text_color);
	while (true)
	{
		gotoXY(x + 30, y);
		getline(cin, s);
		if (s.length() == 0)
		{
			continue;
		}
		n->data.tenGv = s;
		break;
	}
	y += 2;
	x += 30;
	gotoXY(x - 30, y);
	setColor(background_color, title_color1);
	cout << "So tin chi: ";
	setColor(background_color, text_color);
	gotoXY(x, y);
	char c;
	s = "";
	do
	{
		c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (s == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			s.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (s == "")
				continue;
			if (stoi(s) == 0)
			{
				gotoXY(x, y);
				cout << "                             ";
				gotoXY(x, y);
				continue;
			}
			n->data.so_tc = stoi(s);
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			s += c;
			cout << c;
		}
	} while (true);
	y += 2;
	gotoXY(x - 30, y);
	setColor(background_color, title_color1);
	cout << "So luong sinh vien toi da: ";
	setColor(background_color, text_color);
	gotoXY(x, y);
	s = "";
	do
	{
		char c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (s == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			s.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (s == "")
				continue;
			if (stoi(s) == 0)
			{
				gotoXY(x, y);
				cout << "   ";
				gotoXY(x, y);
				continue;
			}
			n->data.MaxSv = stoi(s);
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			s += c;
			cout << c;
		}
	} while (true);
	while (true)
	{
		NhapTgMon(n);
		if ((n->data.bh1.buoi == n->data.bh2.buoi) && (n->data.bh1.thu == n->data.bh2.thu))
		{
			setColor(background_color, red);
			printA_Sentence("! HAI BUOI HOC TRUNG NHAU... NHAP LAI !", HEIGHT - 4);
			_getch();
			continue;
		}
		break;
	}
	return true;
}
void TaoMon(ListNamHoc& l, int nam)
{
	int i = 0;//i: stt hoc ky
	HocKy* hk = HkHienTai(l, NodeNamHienTai(l), i);
	if (hk == NULL)
		return;
	setColor(background_color, title_color);
	system("cls");
	printA_Sentence("~ TAO MOI MON HOC ~", 5);
	NodeMon* head;
	int x = WIDTH / 3 + 5, y = 10;
	string file;
	string s;
	NodeMon* re = NULL;
	if (importFilehayNhapTay(1))
	{
		ifstream f;
		while (true)
		{
			system("cls");
			setColor(background_color, title_color);
			printA_Sentence("~ TAO MOI MON HOC ~", 5);
			gotoXY(x, y);
			setColor(background_color, text_color);
			cout << "Nhap duong dan: " << endl;
			while (file.length() == 0)
			{
				gotoXY(x + 19, y);
				getline(cin, file, '\n');///////
			}
			f.open(file);
			if (f.is_open())
			{
				getline(f, s);
				f.close();
				if (s == "")
				{
					setColor(background_color, red);
					printA_Sentence("! FILE TRONG !", HEIGHT - 5);
					_getch();
				}
				break;
			}
			else
			{
				setColor(background_color, red);
				printA_Sentence("! KHONG THE MO FILE !", HEIGHT - 5);
				file = "";
				_getch();
			}
			system("cls");
			if (!Ask_YN("Ban co muon nhap duong dan file khac ?"))
			{
				system("cls");
				setColor(background_color, red);
				printA_Sentence("! TAO MON KHONG THANH CONG !", HEIGHT / 2 - 1);
				setColor(background_color, title_color1);
				printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 4);
				_getch();
				return;
			}
		}
		re = mondangmo_docfile(file, nam, i);
	}
	else
	{
		re = mondangmo_nhaptay(nam, i);
	}
	if (re == NULL)
	{
		system("cls");
		setColor(background_color, red);
		printA_Sentence("! TAO MOI MON HOC THAT BAI !", HEIGHT / 2 - 1);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	//in ra ds mon
	viewDsMonHk(re, i);
	setColor(background_color, title_color1);
	int line = whereY() + 3;
	printA_Sentence("            - DANH SACH MON VUA DUOC NHAP -              ", 3);
	printA_Sentence("                                                        ", 4);
	printA_Sentence("                                                        ", 5);
	setColor(background_color, red);
	printA_Sentence("Ban that su muon tao moi nhung mon hoc nay?", line);
	setColor(background_color, title_color1);
	printA_Sentence("- Luu y -", line + 10);
	setColor(background_color, text_color);
	printA_Sentence("- Cac mon hoc trong danh sach nay neu DA DUOC TAO thi se bi bo qua -", line + 11);
	printA_Sentence("- Nhung mon hoc nay se duoc them vao KI HOC HIEN TAI cua NAM HIEN TAI -", line + 12);
	string title[2] = { "Dung vay","No no, khong he" };
	if (LuaChon_Menu(2, title, 2, line + 1) == 2)
	{
		system("cls");
		setColor(background_color, red);
		printA_Sentence("! TAO MOI MON HOC THAT BAI !", HEIGHT / 2 - 1);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
		_getch();
		return;
	}

	printA_Sentence("                                                                                     ", HEIGHT - 4);
	NodeMon* n = re;
	while (n != NULL)
	{
		if (checkTrungMon(hk->headMon, n))//trung thi bo qua tiep mon khac...
		{
			n = n->pNext;
			continue;
		}
		//ghi vao file hk htai moi nhat 
		string fPath = to_string(nam) + "hk" + to_string(i) + ".txt";
		fstream f;
		f.open(fPath, ios::in | ios::app);
		f << endl;
		f << n->data.id << "," << n->data.tenMon << "," << n->data.tenGv << ",";
		f << n->data.so_tc << ",";
		f << n->data.bh1.thu << "," << n->data.bh1.buoi << ",";
		f << n->data.bh2.thu << "," << n->data.bh2.buoi << ",";
		f << n->data.MaxSv << ",";
		f.close();
		f.open(to_string(nam) + "hk" + to_string(i) + n->data.id + ".txt", ios::out);
		f.close();
		n = n->pNext;
	}
	n = re;
	while (n->pNext != NULL)
		n = n->pNext;
	n->pNext = hk->headMon;
	hk->headMon = re;
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI MON HOC THANH CONG ~", HEIGHT / 2);
	_getch();
};
NodeMon* mondangmo_docfile(string file, int nam, int stt_hk)//file nay chi co ds mon khong co tg bd
{
	NodeMon* head = NULL;
	ifstream f;
	f.open(file);
	if (!f.is_open())
	{
		return NULL;
	}
	string s;
	while (!f.eof())
	{
		getline(f, s, ',');
		if (s == "" || s == "\n")
		{
			return head;
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
				throw 0;
			}
			getline(f, s);//xoa "\n" ra khoi f
			f.clear();
		}
		catch (int error)
		{
			system("cls");
			setColor(background_color, red);
			printA_Sentence("! TAO MOI MON HOC THAT BAI !", HEIGHT / 2 - 2);
			setColor(background_color, text_color);
			printA_Sentence("Khong lay duoc du lieu tu file", HEIGHT / 2);
			_getch();
			return NULL;
		}
		n->pNext = NULL;
		n->headSvMon = NULL;
		ThemNodeMon(head, n);
	}
}
NodeMon* mondangmo_nhaptay(int nam, int stt_hk)
{
	NodeMon* head = NULL;
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO MOI MON HOC ~", 5);
	gotoXY(WIDTH / 3 + 5, 10);
	setColor(background_color, title_color1);
	cout << "Nhap so mon hoc muon tao: ";
	int x = whereX() + 5;
	int y = whereY();
	char c;
	string temp;
	gotoXY(x, y);
	setColor(background_color, text_color);
	do
	{
		c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (temp == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			temp.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (temp == "")
				continue;
			//if (stoi(temp) == 0)
			//{
			//	setColor(background_color, red);
			//	printA_Sentence("! SO MON IT NHAT BANG 1 !",HEIGHT-4);
			//	_getch();
			//	setColor(background_color, text_color);
			//	printA_Sentence("                            ", HEIGHT - 4);
			//	gotoXY(x, y);
			//	cout << "                       ";
			//	gotoXY(x, y);
			//}
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			temp += c;
			cout << c;
		}
	} while (true);
	int somon = stoi(temp);
	if (somon == 0)
		return NULL;
	system("cls");
	for (int i = 0; i < somon; i++)
	{
		NodeMon* n = new NodeMon;
		//cout << endl << "Mon hoc " << i + 1 << endl;
		if (!NhapNodeMon(n))
		{
			i--;
			continue;
		}
		if (checkTrungMon(head, n))
		{
			setColor(background_color, red);
			printA_Sentence("         ! MON HOC DA DUOC TAO !         ", HEIGHT - 3);
			_getch();
			continue;
		}
		ThemNodeMon(head, n);
	}
	_getch();
	return head;
}


//CAP NHAT
int InMenuCapNhat()
{
	system("cls");
	setColor(background_color, text_color);
	printA_Sentence("-- CAP NHAT --", 2);
	background_Gv();
	string title[5] = { "THEM SINH VIEN NAM NHAT","CAP NHAT MON HOC","DIEM SINH VIEN","QUAY VE","THOAT" };
	return LuaChon_Menu(5, title, 2, HEIGHT / 2);
}
int InMenuCapNhat2()
{
	system("cls");
	printA_Sentence("-- CAP NHAT MON HOC --", 2);
	background_Gv();
	string title[4] = { "SUA THONG TIN MON HOC","XOA MON HOC","QUAY VE","THOAT" };
	return LuaChon_Menu(4, title, 2, HEIGHT / 2);
}
int InMenuCapNhat3()
{
	system("cls");
	printA_Sentence("-- CAP NHAT DIEM SINH VIEN--", 2);
	background_Gv();
	string title[5] = { "XUAT FILE DE GV NHAP DIEM","NHAP DIEM TU FILE","CHINH SUA DIEM","QUAY VE","THOAT" };
	return LuaChon_Menu(5, title, 2, HEIGHT / 2);
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
		XuatFileCsv(nodeNam, hk, stt_hk);
		_getch();
		break;
	}
	case 2:
	{
		system("cls");
		NodeNamHoc* nodeNam = NodeNamHienTai(l);
		int stt_hk = 0;
		HocKy* hk = HkHienTai(l, nodeNam, stt_hk);
		NhapDiemTuFile(nodeNam, hk, stt_hk);
		_getch();
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
			Thoat = XlCapNhat2(l, InMenuCapNhat2());
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

//them sv 
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head)
{
	while (head && n)
	{
		if (head->sv.stt == n->sv.stt || n->sv.id == head->sv.id)
		{
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
void NhapThongtinSv(NodeSv_Lop* n, int i, int k)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ NHAP THONG TIN SINH VIEN " + to_string(i + 1) + " ~", 5);
	int x = WIDTH / 3 - 5;
	int y = whereY() + 6;
	setColor(background_color, title_color1);
	printA_Sentence("Luu y: MSSV co cau truc XXxxxxxx (XX la hai chu so cuoi cua nam hoc bat dau nam nhat cua sinh vien!!!)", y - 2);
	gotoXY(x, y);
	setColor(background_color, text_color);
	cout << "Nhap MSSV (vd: 20120399, 18120335, ...): ";
	char c;
	string s = "";
	x += 50;
	gotoXY(x, y);
	do
	{
		c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (s == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			s.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (s == "")
				continue;
			int temp = 0;
			if (s.length() == 8) //mssv co 8 chu so
				temp = stoi(s);
			if (temp < 10000000 || stoi(s.substr(0, 2)) != k)
			{
				setColor(background_color, red);
				printA_Sentence("MSSV khong hop le !", HEIGHT - 4);
				s = "";
				setColor(background_color, text_color);
				_getch();
				printA_Sentence("                          ", HEIGHT - 4);
				gotoXY(x, y);
				cout << "                                                       ";
				gotoXY(x, y);
				continue;
			}
			else
			{
				n->sv.id = temp;
				break;
			}
		}
		else if (c >= 48 && c <= 57)
		{
			s += c;
			cout << c;
		}
	} while (true);
	y += 3;
	gotoXY(x - 50, y);
	s = "";
	cout << "Nhap STT cua sinh vien trong lop:";
	gotoXY(x, y);
	do
	{
		c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (s == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			s.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (s == "")
				continue;
			if (stoi(s) < 0)
			{
				setColor(background_color, red);
				printA_Sentence("STT phai lon hon 0 !", y + 1);
				_getch();
				printA_Sentence("                         ", y + 1);
				gotoXY(x, y);
				cout << "                         ";
				gotoXY(x, y);
				continue;
			}
			n->sv.stt = stoi(s);
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			s += c;
			cout << c;
		}
	} while (true);
	y += 3;
	gotoXY(x - 50, y);
	s = "";
	cout << "Nhap ten: (vd: Lan)";
	while (true)
	{
		gotoXY(x, y);
		getline(cin, s);
		if (s.length() == 0)
		{
			continue;
		}
		n->sv.ten = s;
		break;
	}
	y += 3;
	gotoXY(x - 50, y);
	s = "";
	cout << "Nhap ho: (vd: Nguyen Thi)";
	while (true)
	{
		gotoXY(x, y);
		getline(cin, s);
		if (s.length() == 0)
		{
			continue;
		}
		n->sv.ho = s;
		break;
	}
	y += 3;
	gotoXY(x - 50, y);
	s = "";
	cout << "Nhap gioi tinh (Nu/Nam):";
	while (true)
	{
		gotoXY(x, y);
		getline(cin, s);
		if (s == "Nu" || s == "Nam")
		{
			n->sv.gioi = s;
			break;
		}
		gotoXY(x, y);
		cout << "                                ";
	}
	y += 3;
	printA_Sentence("Nhap lan luot ngay, thang, nam sinh", y);
	y++;
	nhapNgay_ve(y);
	n->sv.ngayS = nhapNgay_nhap(y);

	y += 4;
	gotoXY(x - 50, y);
	s = "";
	cout << "Nhap CMND/CCCD:";
	while (true)
	{
		gotoXY(x, y);
		getline(cin, s);
		if (s.length() == 0)
			continue;
		int size = s.length();
		if (size > 12)
		{
			setColor(background_color, red);
			printA_Sentence("CMND/CCCD khong hop le !", HEIGHT - 4);
			s = "";
			setColor(background_color, text_color);
			_getch();
			printA_Sentence("                          ", HEIGHT - 4);//xoa thong bao
			gotoXY(x, y);
			cout << "                                                         ";//xoa ket qua nhap
			gotoXY(x, y);
			continue;
		}
		else
		{
			n->sv.cmnd = new char[size + 1];
			strcpy_s(n->sv.cmnd, size + 1, s.c_str());
			break;
		}
	}
}
void GhiThongtinSv(NodeLop* nodeLop, NodeSv_Lop* n)//sau khi dien thong tin sv => check trung => ghi vao file
{
	fstream f("SinhVien.txt", ios::in | ios::app);
	string s;
	//kiem tra file co chua data chua?
	getline(f, s);
	f.close();
	f.open("SinhVien.txt", ios::app);
	if (s != "")
	{
		f << endl;
	}
	f << n->sv.id << ",abcd1234," << nodeLop->lop.ten << ",";//abcd1234 la mat khau mac dinh cua tai khoan sinh vien
	f.close();
	f.open(nodeLop->lop.ten + ".txt", ios::app);
	//<mssv, stt, ten, ho, gioi tinh, ngay sinh, cccd / cmnd,>
	if (nodeLop->lop.headSvLop)//file da co thong tin
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
	f.close();
}
NodeSv_Lop* ThemSvLop_tay(NodeLop* nodeLop)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("THEM SINH VIEN VAO LOP", 4);
	setColor(background_color, title_color1);
	printA_Sentence(nodeLop->lop.ten, 5);
	int x = WIDTH / 3 + 5;
	int y = 11;
	gotoXY(x, y);
	cout << "Nhap so luong sinh vien them vao: ";
	setColor(background_color, text_color);
	x += 40;
	int sl;
	char c;
	string temp;
	gotoXY(x, y);
	setColor(background_color, text_color);
	do
	{
		c = _getch();
		if (c == '\b')//nhan phim backspace 
		{
			if (temp == "")
			{
				gotoXY(x, y);
				continue;
			}
			gotoXY(whereX() - 1, y);
			cout << " ";
			gotoXY(whereX() - 1, y);//quay lai vi tri " "
			temp.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (temp == "")
				continue;
			if (stoi(temp) == 0)
			{
				setColor(background_color, red);
				printA_Sentence("! SO HOC SINH IT NHAT BANG 1 !", HEIGHT - 4);
				_getch();
				setColor(background_color, text_color);
				printA_Sentence("                                                        ", HEIGHT - 4);//xoa thong bao de tiep tuc...
				gotoXY(x, y);
				cout << "                       ";//xoa so luong sai vua nhap
				gotoXY(x, y);
				continue;
			}
			sl = stoi(temp);
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			temp += c;
			cout << c;
		}
	} while (true);
	NodeSv_Lop* nw = NULL;
	for (int i = 0; i < sl; i++)
	{
		NodeSv_Lop* n = new NodeSv_Lop;
		n->pNext = NULL;
		NhapThongtinSv(n, i, stoi(nodeLop->lop.ten.substr(0, 2)));
		if (checkTrungSv(n, nw))
		{
			setColor(background_color, red);
			printA_Sentence("! SINH VIEN VUA NHAP BI TRUNG MSSV HOAC STT VOI SINH VIEN TRUOC DO ! ", HEIGHT - 5);
			_getch();
			system("cls");
			if (Ask_YN("Ban co muon nhap lai thong tin cho sinh vien vua roi?"))
			{
				i--;
				continue;
			}
		}
		else
		{
			ThemNodeSvLop(nw, n);
		}
	}
	return nw;
	NodeLop* A = new NodeLop;
	A->lop.headSvLop = nw;
}
NodeSv_Lop* ThemSvLop_file(NodeLop* nodeLop)
{
	//nodeLop chac chan != NULL vi da hien thi dsLop de chon truoc do

	string file = "", s = "";
	ifstream f;
	int x = WIDTH / 3 + 5, y = 10;
	while (true)
	{
		system("cls");
		setColor(background_color, title_color);
		printA_Sentence("~ THEM SINH VIEN VAO LOP ~", 5);
		setColor(background_color, title_color1);
		printA_Sentence(nodeLop->lop.ten, 7);
		setColor(background_color, text_color);
		int x = WIDTH / 3, y = 11;
		gotoXY(x, y);
		cout << "Nhap duong dan: " << endl;
		while (file == "" || file == "\r" || file == "\n")
		{
			gotoXY(x + 19, y);
			getline(cin, file);///////
		}
		f.open(file);
		if (f.is_open())
		{
			getline(f, s);
			f.close();
			if (s == "")
			{
				setColor(background_color, red);
				printA_Sentence("! FILE TRONG !", HEIGHT - 5);
				_getch();
			}
			break;
		}
		else
		{
			setColor(background_color, red);
			printA_Sentence("! KHONG THE MO FILE !", HEIGHT - 5);
			file = "";
			_getch();
		}
		system("cls");
		if (!Ask_YN("Ban co muon nhap duong dan file khac ?"))
		{
			system("cls");
			setColor(background_color, red);
			printA_Sentence("! THEM SINH VIEN NAM NHAT THAT BAI !", HEIGHT / 2 - 1);
			_getch();
			return NULL;
		}
	}
	f.open(file);
	NodeSv_Lop* nw = NULL;
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
				int size = s.length() + 1;
				T.cmnd = new char[size];
				strcpy_s(T.cmnd, size, s.c_str());
				if (!f.good())
				{
					throw - 1;
				}
				getline(f, s);//lay \n 
				ThemNodeSvLop(nw, TaoNodeSv(T));
			}
		}
		catch (int)
		{
			setColor(background_color, red);
			printA_Sentence("! LAY DU LIEU TU FILE THAT BAI !", HEIGHT - 5);
			_getch();
			return NULL;
		}
	}
	f.close();
	return nw;
}
void ThemSvLopNam1(ListNamHoc& l)
{
	do
	{
		NodeLop* head = NULL;
		NodeNamHoc* nam = NodeNamHienTai(l);
		if (nam)
			head = nam->data.headLop[0];
		else
		{
			_getch();
			return;
		}
		int max = viewDsLop(head);
		int line = whereY() + 3;
		cout << endl;
		setColor(background_color, title_color);
		printA_Sentence("          ~ THEM SINH VIEN NAM NHAT VAO LOP ~          ", 2);
		string title[1] = { "QUAY VE" };
		int stt = LuaChon_HienThi(line, max, 1, title);
		if (stt == -1)
			return;
		NodeLop* pLop = head;
		for (int i = 1; i < stt; i++)
			pLop = pLop->pNext;
		system("cls");
		setColor(background_color, title_color);
		NodeSv_Lop* nw = NULL;
		printA_Sentence("          ~ THEM SINH VIEN NAM NHAT VAO LOP ~          ", 2);
		if (importFilehayNhapTay(0))
			nw = ThemSvLop_file(pLop);
		else
			nw = ThemSvLop_tay(pLop);
		if (!nw)
		{
			system("cls");
			setColor(background_color, red);
			printA_Sentence("! THEM SINH VIEN NAM NHAT THAT BAI !", HEIGHT / 2 - 1);
			_getch();
			return;
		}
		NodeLop* A = new NodeLop;
		A->lop.headSvLop = nw;
		viewDsSvLop(A);
		int y = whereY();
		setColor(background_color, title_color1);
		printA_Sentence("          - DANH SACH SINH VIEN VUA NHAP -          ", 2);
		printA_Sentence("                                                          ", 3);
		printA_Sentence("Nhan nut bat ki de tiep tuc -->", y + 3);
		_getch();
		system("cls");
		printA_Sentence("Luu y: Cac sinh vien trong danh sach truoc, neu bi trung thi se bo qua", HEIGHT - 4);
		if (!Ask_YN("Ban that su muon them nhung sinh vien nay?"))
		{
			system("cls");
			setColor(background_color, red);
			printA_Sentence("! THEM SINH VIEN NAM NHAT THAT BAI !", HEIGHT / 2 - 1);
			_getch();
			return;
		}
		NodeSv_Lop* n = nw;
		while (n != NULL)
		{
			if (checkTrungSv(n, pLop->lop.headSvLop))//so sanh dssv moi co trung voi cac dssv trong lop da co
			{
				n = n->pNext;
				continue;
			}
			else
			{
				//ghi vao file, them dssv vua nhap vao dssv cua lop
				NodeSv_Lop* sv_new = TaoNodeSv(n->sv);//copy data chu KO DUNG TRUC TIEP node n 
				GhiThongtinSv(pLop, sv_new);
				ThemNodeSvLop(pLop->lop.headSvLop, sv_new);
				sv_new->headMon[0] = sv_new->headMon[1] = sv_new->headMon[2] = NULL;
				n = n->pNext;
			}
		}
		system("cls");
		setColor(background_color, title_color);
		printA_Sentence("~ THEM SINH VIEN NAM NHAT THANH CONG ~", HEIGHT / 2 - 1);
		_getch();
		return;
	} while (true);
}

//nhap diem 
void XuatFileCsv(NodeNamHoc* nodeNam, HocKy* hk, int stt_hk) //nam, hk <hien tai>
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ XUAT CAC FILE CSV DSSV TUNG MON ~", 5);
	if (hk->headMon == NULL)
	{
		setColor(background_color, red);
		printA_Sentence("! HOC KI NAY CHUA CO MON HOC NAO !", HEIGHT / 2 - 1);
		setColor(background_color, text_color);
		printA_Sentence("Hay vao TAO MOI -> MON HOC de them mon cho hoc ki nay", HEIGHT / 2 + 1);
		return;
	}
	string Path = "";
	int x = WIDTH / 3 + 5, y = 12;
	gotoXY(x, y);
	setColor(background_color, text_color);
	printA_Sentence("Nhap duong dan den vi tri ban muon luu cac file danh sach sinh vien ", 10);
	gotoXY(x, y);
	cout << "Moi nhap: ";
	while (Path.length() == 0)
	{
		gotoXY(x + 17, y);
		getline(cin, Path, '\n');///////
	}
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
			setColor(background_color, red);
			printA_Sentence("! KHONG TIM THAY FILE CHUA DANH SACH SINH VIEN CUA MON !" + temp->data.id + " !", HEIGHT - 4);
			system("cls");
			if (!Ask_YN("Ban co muon tiep tuc xuat cac mon khac ?"))
			{
				system("cls");
				setColor(background_color, red);
				printA_Sentence("! XUAT FILE THAT BAI !", HEIGHT / 2 - 1);
				return;
			}
			else
			{
				temp = temp->pNext;
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
				setColor(background_color, red);
				printA_Sentence("Khong the tao file dssv mon " + temp->data.id + " theo duong dan ban vua nhap", HEIGHT / 2 - 3);
				_getch();
				f.close();
				system("cls");
				if (!Ask_YN("Ban co muon tiep tuc xuat cac mon khac ?"))
				{
					system("cls");
					setColor(background_color, red);
					printA_Sentence("! XUAT FILE THAT BAI !", HEIGHT / 2 - 1);
					return;
				}
				else
				{
					temp = temp->pNext;
					continue;
				}
			}
		}
		else
		{
			system("cls");
			if (Ask_YN("Chua co du lieu ve danh sach sinh vien cua mon " + temp->data.id + ". Ban co muon tiep tuc?"))
			{
				temp = temp->pNext;
				f.close();
				continue;//di tiep den mon hoc khac 
			}
			else
			{
				setColor(background_color, red);
				printA_Sentence("! XUAT FILE THAT BAI !", HEIGHT - 4);
				return;
			}
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
		//tiep tuc xuat file dssv cua mon hoc khac...
		temp = temp->pNext;
	}
	setColor(background_color, title_color);
	system("cls");
	printA_Sentence("~ XUAT FILE THANH CONG ~", HEIGHT / 2 - 1);
}
bool DocDiemTuFile(string file, NodeMon* mon, int siso)// doc tu file tai len he thong
{
	ifstream f(file);
	string s;
	Diem* dsDiem = new Diem[siso];
	while (siso > 0)
	{
		try
		{
			getline(f, s, ',');//mssv
			f.clear();
			getline(f, s, ',');//lop
			f.clear();
			getline(f, s, ',');
			dsDiem[siso - 1].gk = stof(s);//dssv trong file nguoc voi dssv tren he thong
			getline(f, s, ',');
			dsDiem[siso - 1].ck = stof(s);
			getline(f, s, ',');
			dsDiem[siso - 1].cong = stof(s);
			getline(f, s, ',');
			dsDiem[siso - 1].tongket = stof(s);
			if (f.fail())
			{
				throw - 1;
			}
		}
		catch (int)
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
	setColor(background_color, title_color);
	printA_Sentence("~ NHAP DIEM CHO SINH VIEN TU FILE ~", 5);
	if (hk->headMon == NULL)
	{
		setColor(background_color, red);
		printA_Sentence("! HOC KI NAY CHUA CO MON HOC NAO !", 5);
		return;
	}
	setColor(background_color, text_color);
	int x = 25, y = 10;
	gotoXY(x, y);
	cout << "- Mac dinh diem ban dau cua sinh vien trong file se bang 0.";
	y += 2;
	gotoXY(x, y);
	cout << "- Can chac chan giao vien chi nhap diem cho sinh vien ma khong thay doi cac noi dung khac trong file va ca ten file !";
	Sleep(300);
	y += 2;
	gotoXY(x, y);
	setColor(background_color, title_color1);
	printA_Sentence("- Nhap duong dan den vi tri luu cac file ma giao vien da nhap diem -", y += 3);
	setColor(background_color, text_color);
	string Path = "";
	gotoXY(x, y += 2);
	cout << "Moi nhap: " << endl;
	while (Path.length() == 0)
	{
		gotoXY(x + 17, y);
		getline(cin, Path, '\n');///////
	}
	int nam = nodeNam->data.tg.ngay_bd.y;
	NodeMon* temp = hk->headMon;
	bool flag = false;//danh dau nhap diem thanh cong (true) /that bai (false)
	while (temp)
	{
		//tim file 
		ifstream f(Path + "/" + to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
		if (!f.is_open())
		{
			system("cls");
			setColor(background_color, red);
			printA_Sentence("          ! KHONG TIM THAY FILE DIEM CUA SINH VIEN MON " + temp->data.id + " !          ", HEIGHT / 2 - 4);
			if (!Ask_YN("Ban co muon tiep tuc voi cac mon khac ?"))
			{
				break;
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
		getline(f, s);
		//copy sang file cua he thong 
		if (s != "")
		{
			ofs.open(to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt");
			if (!ofs.is_open())
			{
				ofs.close();
				system("cls");
				setColor(background_color, red);
				printA_Sentence("          ! KHONG THE GHI DIEM VAO FILE CHO SINH VIEN MON " + temp->data.id + " !          ", HEIGHT / 2 - 4);
				f.close();
				if (!Ask_YN("Ban co muon tiep tuc voi cac mon khac ?"))
				{
					break;
				}
				temp = temp->pNext;
				continue;
			}
		}
		else
		{
			setColor(background_color, red);
			system("cls");
			printA_Sentence("                    ! FILE MON " + temp->data.id + " TRONG !                    ", HEIGHT / 2 - 4);
			f.close();
			temp = temp->pNext;
			if (!Ask_YN("Ban co muon tiep tuc voi cac mon khac ?"))
			{
				break;
			}
			temp = temp->pNext;
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
		if (!DocDiemTuFile(to_string(nam) + "hk" + to_string(stt_hk) + temp->data.id + ".txt", temp, siso))
		{
			system("cls");
			setColor(background_color, title_color);
			if (!Ask_YN("Khong the nhap diem cho sinh vien mon " + temp->data.id + ". Ban co muon tiep tuc?"))
			{
				break;
			}
		}
		else
			flag = true;
		//tiep tuc xuat file dssv cua mon hoc khac...
		temp = temp->pNext;
	}
	system("cls");
	if (!flag)
	{
		//system("cls");
		setColor(background_color, red);
		printA_Sentence("! NHAP DIEM TU FILE THAT BAI !", HEIGHT / 2 - 1);
		return;
	}
	else
	{
		//system("cls");
		setColor(background_color, title_color);
		printA_Sentence("~ NHAP DIEM TU FILE THANH CONG ~", HEIGHT / 2 - 1);
	}
}
//line <tra ve>: dong hien tai, data: dong tiep theo
string NextLine(string& data) 
{
	size_t pos = data.find('\n');
	string line = data.substr(0, pos);
	data = pos != string::npos ? data.substr(pos + 1) : "";
	return line;
}

//sua diem
void NhapDiem(float& diem, int x, int y)//x, y: toa do 
{
	do
	{
		string nhap;
		gotoXY(x + 25, y);
		getline(cin, nhap);
		if (nhap == "")
		{
			return;
		}
		else
		{
			try
			{
				diem = stof(nhap);
			}
			catch (invalid_argument)
			{
				diem = -1;
			}
			if (diem < 0 || diem>10)
			{
				cin.clear();
				gotoXY(x + 25, y);
				cout << "                                    ";
			}
			else
				break;
		}
	} while (true);
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
		//check co sua thong tin?
		if (line.find(to_string(node_sv_mon->mssv) + "," + node_sv_mon->lop + ",") == 0)
		{
			file << node_sv_mon->mssv << ',' << node_sv_mon->lop << ','
				<< node_sv_mon->diem.gk << ','
				<< node_sv_mon->diem.ck << ','
				<< node_sv_mon->diem.cong << ','
				<< node_sv_mon->diem.tongket << ',';
			success = true;
		}
		else
		{
			file << line;
		}
		wrote = true;
	}
	/*if (!success)
		file << node_sv_mon->mssv << ',' << node_sv_mon->lop << ','
		<< node_sv_mon->diem.gk << ','
		<< node_sv_mon->diem.ck << ','
		<< node_sv_mon->diem.cong << ','
		<< node_sv_mon->diem.tongket << ',';*/
	file.close();
}
void CapNhatDiemSv(ListNamHoc& l)
{
	int ki;
	NodeNamHoc* nam = l.pHead;
	NodeMon* headMonHk = new NodeMon;
	NodeMon* pMon = timNodeMon_CapNhat(l, nam, ki, headMonHk);

	int si_so = viewDsSvMon(pMon);
	if (si_so == 0)
	{
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	int stt_sv;
	int line = whereY() + 3;
	setColor(background_color, title_color);
	printA_Sentence("~ CHINH SUA DIEM SINH VIEN ~", 1);
	NodeSv_Mon* node_sv_mon;
	string title = "QUAY VE";
	while (true)
	{
		stt_sv = LuaChon_HienThi(line, si_so, 1, &title);
		if (stt_sv == -1)//thoat
			return;
		node_sv_mon = pMon->headSvMon;
		for (int i = 1; i < stt_sv; i++)
			node_sv_mon = node_sv_mon->pNext;
		system("cls");
		setColor(background_color, title_color);
		printA_Sentence("~ CAP NHAT DIEM SINH VIEN ~", 5);
		setColor(background_color, title_color1);
		printA_Sentence("Nhap thong tin moi. De trong va nhan enter de giu nguyen", 9);
		setColor(background_color, text_color);
		int x = WIDTH / 3 + 5, y = 12;
		Diem& diem = node_sv_mon->diem;

		gotoXY(x, y);
		cout << "Diem giua ky (" << diem.gk << "): ";
		NhapDiem(diem.gk, x, y);
		y += 2;

		gotoXY(x, y);
		cout << "Diem cuoi ky (" << diem.ck << "): ";
		NhapDiem(diem.gk, x, y);
		y += 2;

		gotoXY(x, y);
		cout << "Diem cong (" << diem.cong << "): ";
		NhapDiem(diem.gk, x, y);
		y += 2;

		gotoXY(x, y);
		diem.tongket = min((diem.gk + diem.ck * 2.0) / 3 + diem.cong / 10, 10.0);
		cout << "Diem tong ket:";
		gotoXY(x + 25, y); 
		cout << diem.tongket;
		
		y += 2;
		gotoXY(x, y);
		cout << "TK = (GK + CK * 2)/3 + CONG/10).   (( TK > 10 --> TK = 10 ))";
		string filename = to_string(nam->data.tg.ngay_bd.y) + "hk" + to_string(ki) + pMon->data.id + ".txt";
		LuuDiemSv(filename, node_sv_mon);
		setColor(background_color, title_color);
		printA_Sentence("~ CAP NHAT DIEM THANH CONG ~", HEIGHT - 4);
		_getch();
		system("cls");
		viewDsSvMon(pMon);
		setColor(background_color, title_color);
		printA_Sentence("~ CHINH SUA DIEM SINH VIEN ~", 1);
	}
}

//sua, xoa mon
void GhiFileMon(string filename, NodeMon* mon, bool remove)//remove: xoa, !remove: sua info
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
				success = true;
			}
			else
			{
				file << "\n" << mon->data.id << ',' << mon->data.tenMon << ',' << mon->data.tenGv << ',' << mon->data.so_tc << ','
					<< mon->data.bh1.thu << ',' << mon->data.bh1.buoi << ','
					<< mon->data.bh2.thu << ',' << mon->data.bh2.buoi << ','
					<< mon->data.MaxSv << ',';
				success = true;
			}
		}
		else
		{
			file << '\n' << line;
		}
	}
	if (!success)
	{
		setColor(background_color, red);
		gotoXY(WIDTH / 3 + 15, 65);
		cout << "Khong the tim thay mon hoc " << mon->data.id << " - " << mon->data.tenMon << "!!!\n";
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
		_getch();
	}
	file.close();
}
void CapNhatMonHoc(ListNamHoc& l)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ CAP NHAT THONG TIN MON HOC ~", 5);
	int stt_hk;
	NodeNamHoc* nam = l.pHead;
	NodeMon* node_mon = NULL;
	NodeMon* headmonHK = NULL;
	node_mon = timNodeMon_CapNhat(l, nam, stt_hk, headmonHK);

	MonHoc& mon = node_mon->data;
	string input;
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ CAP NHAT THONG TIN MON HOC ~", 5);
	setColor(background_color, title_color1);
	printA_Sentence("Nhap thong tin moi. De trong va nhan enter de giu nguyen", 8);
	setColor(background_color, text_color);
	int  x = WIDTH / 3 + 5;
	int y = 10;

	gotoXY(x, y);
	cout << "Ten mon (" << mon.tenMon << "): ";
	gotoXY(x + 25, y);
	getline(cin, input);
	if (!input.empty()) mon.tenMon = input;

	y += 2;
	gotoXY(x, y);
	cout << "Ten giao vien (" << mon.tenGv << "): ";
	gotoXY(x + 25, y);
	getline(cin, input);
	if (!input.empty()) mon.tenGv = input;

	y += 2;
	gotoXY(x, y);
	cout << "So tin chi (" << mon.so_tc << "): ";
	while (true)
	{
		gotoXY(x + 25, y);
		getline(cin, input);
		if (input.empty())
			break;
		try
		{
			stoi(input);
		}
		catch (invalid_argument)
		{
			cin.clear();
			gotoXY(x + 25, y);
			cout << "                                                ";
			continue;
		}
		mon.so_tc = stoi(input);
		break;
	}
	
	y += 2;
	gotoXY(x, y);
	cout << "So sinh vien toi da (" << mon.MaxSv << "): ";
	while (true)
	{
		gotoXY(x + 25, y);
		getline(cin, input);
		if (input.empty())
			break;
		try
		{
			stoi(input);
		}
		catch (invalid_argument)
		{
			cin.clear();
			gotoXY(x + 25, y);
			cout << "                                                ";
			continue;
		}
		mon.MaxSv = stoi(input);
		break;
	}
	
	do
	{
		system("cls");
		NhapTgMon(node_mon);
		if ((mon.bh1.buoi == mon.bh2.buoi) && (mon.bh1.thu == mon.bh2.thu))
		{
			setColor(background_color, red);
			printA_Sentence("! HAI BUOI HOC TRUNG NHAU... NHAP LAI !", HEIGHT - 4);
			_getch();
		}
		else
		{
			bool remove = false;//sua mon hoc 
			GhiFileMon(to_string(nam->data.tg.ngay_bd.y) + "hk" + to_string(stt_hk) + ".txt", node_mon, remove);
			viewDsMonHk(headmonHK, stt_hk);
			_getch();
			system("cls");
			setColor(background_color, title_color);
			printA_Sentence("~ CAP NHAT THONG TIN MON HOC THANH CONG ~", HEIGHT / 2);
			setColor(background_color, title_color1);
			printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
			_getch();
			break;
		}
	} while (true);
}
void XoaMonHoc(ListNamHoc& l)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ XOA MON HOC ~", 5);
	bool xoa = true;//xoa mon hoc
	int stt_hk;
	NodeMon* headmonHK = NULL;
	NodeNamHoc* nodeNam = l.pHead;
	NodeMon* node_mon = timNodeMon_CapNhat(l, nodeNam, stt_hk, headmonHK);
	int nam = nodeNam->data.tg.ngay_bd.y;
	if (node_mon == NULL)
	{
		_getch();
		return;
	}
	system("cls");
	if (!Ask_YN("Ban co chac chan muon xoa mon " + node_mon->data.id + "?"))
	{
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
		_getch();
		return;
	}
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ XOA MON HOC ~", 5);

	//xoa mon ra khoi ds mon cua sv
	if (node_mon->headSvMon != NULL && !XoaMon_Sv(l, nodeNam, stt_hk, headmonHK, node_mon))
	{
		system("cls");
		setColor(background_color, red);
		printA_Sentence("XOA MON " + node_mon->data.id + " THAT BAI!!!", HEIGHT / 2);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
		_getch();
		return;
	}

	//sua thong tin mon hoc trong file truoc
	GhiFileMon(to_string(nam) + "hk" + to_string(stt_hk) + ".txt", node_mon, xoa);

	//xoa file dssv
	string filename = to_string(nam) + "hk" + to_string(stt_hk) + node_mon->data.id + ".txt";
	ifstream f(filename);
	if (f.is_open())
	{
		f.close();
		remove(filename.c_str());
	}
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ XOA MON HOC ~", 5);

	//xoa mon ra khoi ds mon cua hk
	NodeMon* next = node_mon->pNext;
	NodeMon** p;
	for (p = &headmonHK; *p != node_mon; p = &(*p)->pNext);
	(*p)->pNext = NULL;
	delete* p;
	*p = next;
	viewDsMonHk(headmonHK, stt_hk);
	_getch();
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ XOA MON HOC THANH CONG ~", HEIGHT / 2);
	setColor(background_color, title_color1);
	printA_Sentence("<-- Nhan phim bat ki de quay lai", HEIGHT - 5);
	_getch();
}
NodeMon* timNodeMon_CapNhat(ListNamHoc& l, NodeNamHoc*& nodeNam, int& ki, NodeMon*& headmonHK)
{
	string title[2] = { "QUAY VE", "THOAT" };
	int lc = LuaChon_HienThi(whereY(), viewDsNam(l), 2, title);
	if (lc == -1 || lc == 0)
	{
		//quay lai man hinh chinh
		return NULL;
	}
	for (int i = 1; i < lc; i++)
		nodeNam = nodeNam->pNext;
	system("cls");
	ki = chonKi("Chon hoc ki:");
	int c = viewDsMonHk(nodeNam->data.hk[ki - 1].headMon, ki);
	if (c == 0)
	{
		end(lc);
		return NULL;
	}
	lc = LuaChon_HienThi(whereY(), c, 2, title);
	if (lc == 0)
		return NULL;
	else if (lc == -1)
		return timNodeMon_CapNhat(l, nodeNam, ki, headmonHK);
	headmonHK = nodeNam->data.hk[ki - 1].headMon;
	NodeMon* temp1 = headmonHK;
	for (int i = 1; i < lc; i++)
		temp1 = temp1->pNext;
	return temp1;
}
bool XoaMon_Sv(ListNamHoc& l, NodeNamHoc* nodeNam, int ki, NodeMon*& headmonHK, NodeMon* mon)
{
	if (mon->headSvMon)
	{
		system("cls");
		setColor(background_color, title_color1);
		gotoXY(0, 10);
		if (Ask_YN("Mon nay da duoc mo cho sinh vien dang ky! Ban that su muon xoa?"))
		{
			//duyet dssv cua mon hoc
			NodeSv_Mon** temp = &(mon->headSvMon);
			while (*temp)
			{
				int year = nodeNam->data.tg.ngay_bd.y % 2000 - stoi((*temp)->lop.substr(0, 2)) + 1;//sv nam 1 2 3 4
				NodeLop* nodeLop = timNodeLop(nodeNam, year, (*temp)->lop);
				NodeSv_Lop* nodeSv = timNodeSv_Lop(nodeLop->lop.headSvLop, (*temp)->mssv);

				//duyet tim de xoa mon ra khoi ds mon cua sv 
				NodeMon_Sv* monSv = nodeSv->headMon[ki - 1];
				if (nodeSv->headMon[ki - 1]->svMon == *temp)
				{
					nodeSv->headMon[ki - 1] = monSv->pNext;
					delete monSv;
				}
				else
				{
					while (monSv->pNext)
					{
						if (monSv->pNext->svMon == *temp)
						{
							NodeMon_Sv* del = monSv->pNext;
							monSv->pNext = del->pNext;
							delete del;
							break;
						}
						else
							monSv = monSv->pNext;
					}
				}

				//giai phong vung nho dssv mon 
				NodeSv_Mon* next = (*temp)->pNext;
				delete* temp;
				*temp = next;
			}
			return true;
		}
		return false;
	}
	return true;
}

//HIEN THI
void hienthiNam(ListNamHoc l, int& lc)
{
	string title[2] = { "QUAY VE","THOAT" };
	lc = LuaChon_HienThi(whereY(), viewDsNam(l), 2, title);
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
		///////
		hienthiDsLop(temp->data.headLop[chonSt_Year() - 1], lc);
	}
	if (lc == -1)
		hienthiNam(l, lc);
}
int chonSt_Year()
{
	system("cls");
	setColor(background_color, title_color1);
	printA_Sentence("Ban muon chon lop cua hoc sinh nam may?", HEIGHT / 2 - 10);
	string title[] = { "NAM 1","NAM 2","NAM 3","NAM 4" };
	return LuaChon_Menu(4, title, 2, HEIGHT / 2 - 7);
}
//ki
void hienthiKi(NodeNamHoc* A, int& lc)
{
	string title[2] = { "QUAY VE","THOAT" };
	int c;
	while (true)
	{
		c = viewDsKi(A);
		if (c == 0)//ds trong
		{
			end(lc);
			return;
		}
		lc = LuaChon_HienThi(whereY(), c, 2, title);
		if (lc == 0 || lc == -1)//thoat
			return;
		hienthiDsMon(A->data.hk[lc - 1].headMon, lc);
		if (lc == -1)
			continue;
		if (lc == 0)
			return;
	}
}
void hienthiDsMon(NodeMon* head, int& lc)
{
	string title[2] = { "QUAY VE","THOAT" };
	int ki = lc;
	while (true)
	{
		system("cls");
		int c = viewDsMonHk(head, ki);
		if (c == 0)//ds trong
		{
			end(lc);
			return;
		}
		int lc2 = LuaChon_HienThi(whereY(), c, 2, title);
		if (lc2 == 0 || lc2 == -1)
			return;
		NodeMon* temp = head;
		for (int i = 1; i < lc2; i++)
			temp = temp->pNext;
		hienthiDsSv_Mon(temp, lc2);
		if (lc2 == -1)
			continue;
		if (lc2 == 0)
		{
			lc = 0;
			return;
		}
	}
}
void hienthiDsSv_Mon(NodeMon* A, int& lc)/////////
{
	viewDsSvMon(A);
	end(lc);
}
void end(int& lc)
{
	string title[] = { "QUAY LAI","THOAT" };
	lc = LuaChon_Menu(2, title, 2, whereY() + 3) - 2;
}
//lop 
bool ChonTThayDiem_Lop()//true la TT, false la diem
{
	system("cls");
	setColor(background_color, title_color1);
	printA_Sentence("Ban muon xem gi ?", HEIGHT / 2 - 5);
	string title[] = { "THONG TIN SINH VIEN","DIEM - GPA" };
	return LuaChon_Menu(2, title, 2, HEIGHT / 2 - 2) - 2;
}
void hienthiDsLop(NodeLop* head, int& lc)
{
	string title[] = { "QUAY LAI","THOAT" };
	int c;
	while (true)
	{
		c = viewDsLop(head);
		if (c == 0)
		{
			end(lc);
			return;
		}
		lc = LuaChon_HienThi(whereY(), c, 2, title);
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
			continue;
		if (lc == 0)
			return;
	}

}
void hienthiTTSv_Lop(NodeLop* A, int& lc)
{
	viewDsSvLop(A);
	end(lc);
}
void hienthiDiem_Lop(NodeLop* A, int& lc)
{
	system("cls");
	viewDiem_Lop(A, chonKi("Ban muon xem ket qua hoc tap o hoc ky may?"));
	end(lc);
}
bool ChonKihayLop()
{
	system("cls");
	setColor(background_color, title_color1);
	printA_Sentence("Ban muon xem gi ?", HEIGHT / 2 - 5);
	string title[] = { "KI HOC - MON HOC","LOP HOC - SINH VIEN" };
	return LuaChon_Menu(2, title, 2, HEIGHT / 2 - 2) - 2;
}