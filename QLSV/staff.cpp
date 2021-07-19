#include"staff.h"//GIAO VU
#include"display.h"
#include"courses.h"
#include <conio.h>
#include<string>

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
			Thoat = XlTaoMoi(LuaChon(InMenuTaoMoi()), l);
		} while (!Thoat);
		system("pause");
		break;
	}
	case 2:
	{
		do
		{
			Thoat = XlCapNhat(LuaChon(InMenuCapNhat()), l);
		} while (!Thoat);
		system("pause");
		break;
	}
	case 3:
	{

		int lc = 1;
		hienthiNam(l, lc);
		Thoat = true;
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
int InMenuTaoMoi()
{
	system("cls");
	cout << "----MENU TAO MOI----\n";
	cout << "1. Nam hoc\n";
	cout << "2. Lop hoc\n";
	cout << "3. Hoc ky\n";
	cout << "4. Mon hoc\n";
	cout << "5. Buoi dang ky khoa hoc\n";
	cout << "6. Quay ve\n";
	cout << "7. Thoat\n";
	return 7;
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
		int nam = n->data.tg.ngay_bd.y;
		TaoMon(l, nam);
		system("pause");
		break;
	}
	case 5:
	{
		taoDKKH_Gv(NodeNamHienTai(l));
		system("pause");
		break;
	}
	case 6:
	{
		return true;
	}
	case 7:
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
	system("pause");
	system("cls");
	HienNamHoc(l);
	system("pause");
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
bool checkTrungSv(NodeSv_Lop* n, NodeSv_Lop* head)
{
	while (head)
	{
		if (head->sv.stt == n->sv.stt || n->sv.id == head->sv.id)
		{
			cout << "Ban da them sinh vien co STT hoac MSSV tuong tu vao lop roi!\n";
			return false;
		}
		head = head->pNext;
	}
	return true;
}
//themsv vao theo thu tu tang dan stt
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
void ThemSvLop(NodeLop* nodeLop)
{
	system("cls");
	cout << "----THEM SINH VIEN VAO LOP----\n";
	cout << "Nhap so luong sinh vien: ";
	int sl;
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		NodeSv_Lop* n = new NodeSv_Lop;
		n->pNext = NULL;
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
		cin.ignore();
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
		if (!checkTrungSv(n, nodeLop->lop.headSvLop))
			return;
		ThemNodeSvLop(nodeLop->lop.headSvLop, n);
		//ghi vao file
		fstream f(nodeLop->lop.ten + ".txt", ios::app);
		//<mssv, stt, ten, ho, gioi tinh, ngay sinh, cccd / cmnd,>
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
		f << n->sv.cmnd << ",\n";
		if (f.good())
			cout << "Them sinh vien vao lop thanh cong!\n";
		f.close();
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
		system("pause");
		n->lop.headSvLop = NULL;
		cout << "\n \nThong bao!\n";
		cout << "Ban co the thoat chuong trinh hien tai va tien hanh them sinh vien vao lop...\n";
		cout << "...bang cach dien thong tin sinh vien vao file \"" << ten << ".txt\".\n \n";
		Sleep(200);
		cout << "Thong tin moi sinh vien can nam rieng tren mot dong va theo cau truc sau:\n";
		cout << "<mssv,stt,ten,ho,gioi tinh,ngay sinh,cccd/cmnd,> vd: <19120789,04,Tram,Nguyen Ai,Nu,07052001,111111111,>\n";
		Sleep(200);
		cout << "\n \nHoac ban co the them sinh vien bang cach nhap tay ngay bay gio! Y/N???\n";
		char lc;
		cin >> lc;
		if (lc == 'y' || lc == 'Y')
		{
			system("pause");
			ThemSvLop(n);
		}
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
void HienLuaChonThu(int buoi)
{
	cout << "Buoi " << buoi << ":\n";
	cout << "1. Thu hai \t 2. Thu ba \t 3. Thu tu\n";
	cout << "4. Thu nam \t 5. Thu sau \t 6. Thu bay\n";
	cout << "Nhap lua chon (1-6): ";
}
void HienLuaChonGio()
{
	cout << "Khung gio:\n";
	cout << "1. S1 (07:30)\t 2. S2 (09:30)\n";
	cout << "3. S3 (13:30)\t 4. S4 (15:30)\n";
	cout << "Nhap lua chon (1-4): ";
}
void NhapTgMon(NodeMon* n)
{
	do
	{
		cout << "Chon thoi gian cua hai buoi hoc trong tuan:\n";
		for (int i = 1; i < 3; i++)
		{
			int lc;
			do
			{
				HienLuaChonThu(i);
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
			HienLuaChonGio();
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
void TaoMon(ListNamHoc& l, int nam)
{
	int i = 0;//i: stt hoc ky
	HocKy* hk = HkHienTai(l, NodeNamHienTai(l), i);
	if (hk == NULL)
		return;
	cout << "TAO MOI MON HOC\n";
	NodeMon* head;
	if (importFilehayNhapTay())
	{
		string file;
		cout << "File text luu cac mon theo dong co cau truc nhu sau: " << endl;
		cout << "id mon,ten mon,ten giao vien,so tin chi,ngay hoc 1,buoi hoc 1,ngay hoc 2,buoi hoc 2," << endl << endl;
		ifstream f;
		do {
			cout << "Nhap duong dan: " << endl;
			cin.clear();
			cin.ignore();
			getline(cin, file, '\n');
			f.open(file);
			if (f.good())
			{
				f.close();
				break;
			}
			cout << "File loi... Hay nhap link khac !" << endl;
		} while (true);
		head = mondangmo_docfile(file);
		if (head == NULL)
		{
			cout << "Loi: Khong mo duoc File.." << endl;
			cout << endl << "! TAO MOI MON HOC THAT BAI !" << endl;
			system("pause");
			return;
		}
	}
	else
	{
		head= mondangmo_nhaptay(hk);
	}
	NodeMon* p = head;
	while (p->pNext != NULL)
		p = p->pNext;
	NodeMon* temp = hk->headMon;
	if (hk->headMon)
		p->pNext = hk->headMon;
	hk->headMon = head;
	//ghi vao file hk htai moi nhat 
	string fPath = to_string(nam) + "hk" + to_string(i) + ".txt";
	fstream f (fPath, ios::app);
	if (!f.is_open())
	{
		cout << "Loi: Khong mo duoc File.." << endl;
		cout << endl << "! TAO MOI MON HOC THAT BAI !" << endl;
		system("pause");
		return;
	}
	p = head;
	while (p != temp)
	{
		f << endl;
		f << p->data.id << "," << p->data.tenMon << "," << p->data.tenGv << ",";
		f << p->data.so_tc << ",";
		f << p->data.bh1.thu << "," << p->data.bh1.buoi << ",";
		f << p->data.bh2.thu << "," << p->data.bh2.buoi << ",";
		f << p->data.MaxSv << ',';
		p = p->pNext;
	}
	f.close();

	cout <<endl<< "~ TAO MOI MON HOC THANH CONG ~" << endl;
	cout << "Ban da co the mo dang ky ghi danh vao mon hoc nay!\n";
};
bool importFilehayNhapTay()
{
	cout << "--Chon phuong thuc lay thong tin : " << endl;
	cout << "1. Nhap TAY" << endl;
	cout << "2.Lay thong tin tu FILE" << endl;
	int lc;
	do {
		cout << "Moi nhap: ";
		cin >> lc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		if (lc == 1 || lc == 2)
			break;
	} while (true);
	if (lc == 1)
		return false;
	return true;
}
NodeMon* mondangmo_docfile(string file)////file nay chi co ds mon khong co tg bd
{
	NodeMon* A = NULL;
	ifstream f;
	f.open(file);
	if (!f.is_open())
	{
		cout << "Loi: Khong the mo file" << endl;
		return NULL;
	}
	string s;
	while (!f.eof())
	{
		getline(f, s, ',');
		if (s == "" || s == "\n")
		{
			break;
		}
		NodeMon* t = new NodeMon;
		t->data.id = s;
		getline(f, t->data.tenMon, ',');
		getline(f, t->data.tenGv, ',');
		getline(f, s, ',');
		t->data.so_tc = stoi(s);
		getline(f, t->data.bh1.thu, ',');
		getline(f, t->data.bh1.buoi, ',');
		getline(f, t->data.bh2.thu, ',');
		getline(f, t->data.bh2.buoi, ',');
		getline(f, s, ',');
		t->data.MaxSv = stoi(s);
		getline(f, s);//xoa "\n" ra khoi f
		t->pNext = NULL;
		t->headSvMon = NULL;
		//tai dssv cua mon trong file mon len 
		ThemNodeMon(A, t);//them vao list mon cua hoc ky
	}
}
NodeMon* mondangmo_nhaptay(HocKy* hk)
{
	cout << "TAO MOI MON HOC" << endl << endl;
	NodeMon* head = NULL;
	cout << "Nhap so mon hoc" << endl;
	int somon = 0;
	while (true)
	{
		cout << "Moi nhap: " << endl;
		cin >> somon;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
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
		ThemNodeMon(head, n);
	}
	return head;
}

//CAP NHAT
int InMenuCapNhat()//dung cho ca menu Cap nhat
{
	system("cls");
	cout << "----MENU CAP NHAT----\n";
	cout << "1. Them sinh vien nam nhat\n";
	cout << "2. Mon hoc\n"; // xoa, sua thong tin 
	cout << "3. Diem sinh vien\n";//xuat file csv dssv mon, nhap diem, sua diem 
	cout << "4. Thoat\n";
	return 4;
}
int InMenuCapNhat2()
{
	system("cls");
	cout << "----CAP NHAT MON HOC----\n";
	cout << "1. Sua thong tin mon hoc\n";
	cout << "2. Xoa mon hoc\n";
	cout << "3. Quay ve\n";
	cout << "4. Thoat\n";
	return 4;
}
int InMenuCapNhat3()
{
	system("cls");
	cout << "----CAP NHAT DIEM SINH VIEN----\n";
	cout << "1. Xuat file CSV gui giao vien nhap diem\n";
	cout << "2. Nhap diem len he thong\n";
	cout << "3. Chinh sua diem\n";
	return 3;
}
bool XlCapNhat(int chon, ListNamHoc& l)
{
	switch (chon)
	{
	case 1:
	{
		//cap nhat mon hoc
		CapNhatMonHoc(l);
		system("pause");
		break;
	}
	case 2:
	{
		//cap nhat diem sinh vien 
		CapNhatDiemSv(l);
		system("pause");
		break;
	}
	case 3:
	{
		return true;
	}
	case 4:
	{
		char lenh;
		cout << "Ban thuc su muon thoat? Y/N?" << endl;
	}
	}
	return false;//ngoai tru lenh quay ve va thoat + chon y/Y
}
////
//void XuatFileCsv()
//{
//	//file dssv mon
//	//copy file he thong vao filePath giao vu nhap
//	char* Path = new char[100]
//	cout << "------XUAT FILE CSV DSSV MON-------\n";
//	cout << "Nhap vao duong dan den vi tri ban muon luu file:\n";
//
//}

//HIEN THI
void hienthiNam(ListNamHoc l, int& lc)
{
	lc = Chon(viewDsNam(l));
	if (lc == -1||lc==0)
	{
		//quay lai man hinh chinh
		return ;
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
			if (_kbhit())
			{
				k = _getch();
				if (k >= 49 && k <= 52)//1
					break;
			}
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
			s += temp;
			if (temp == 13)//enter
			{
				if (s != "\r")
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
				cout << "Hay nhap: ";
				char t;
				cin >> t;
				if ('Y' == toupper(t))
				{
					return 0;
				}
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
				cout << temp;
				x++;
			}
		}
	}
}
//ki
void hienthiKi(NodeNamHoc* A, int&lc)
{
	lc = Chon(viewDsKi(A));
	if (lc == 0 || lc == -1)//thoat
		return;
	hienthiDsMon(A->data.hk[lc-1].headMon,lc);
	if (lc == -1)
		hienthiKi(A, lc);
}
void hienthiDsMon(NodeMon* head,int& lc)
{
	system("cls");
	lc = Chon(viewDsMonHk(head,lc));
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
		if (_kbhit())
		{
			temp = _getch();
			if (temp == 27)
			{
				cout << "Ban that su muon thoat khoi Hien Thi? Y/N?" << endl;
				cout << "Hay nhap: ";
				char t;
				cin >> t;
				if ('Y' == toupper(t))
				{
					lc = 0;
					return;
				}
			}
			else if (temp == 'B' || temp == 'b')
			{
				lc = -1;
				return;
			}
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
		if (_kbhit())
		{
			temp = _getch();
			if (temp == 49)//1
				return true;
			else if (temp == 50)//2
				return false;
		}
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
	viewDiem_Lop(A, 1);//////////////////////////////////////1 co dinh ha con quy
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
		if (_kbhit())
		{
			temp = _getch();
			if (temp == 49)//1
				return true;
			else if (temp == 50)//2
				return false;
		}
	}
}
