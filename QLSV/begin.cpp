#include"begin.h"
#include"display.h"
using namespace std;
int InMenuBatDau(int ma_tk)//0 gv 1 sv lay tu login tra vector
{
	system("cls");
	BackGround();
	cout << endl << endl << endl;
	cout << "\t \t \t CHAO MUNG BAN DEN VOI HE THONG QUAN LY SINH VIEN\n";
	cout << "\t \t \t \t \t 1. Vao he thong chinh\n";
	cout << "\t \t \t \t \t 2. Xem thong tin cua ban\n";
	cout << "\t \t \t \t \t 3. Doi mat khau\n";
	cout << "\t \t \t \t \t 4. Dang xuat\n";
	cout << "\t \t \t \t \t 5. Thoat\n";
	return 5;//tra ve maxSelect
}
bool XlMenuBD(int chon, short lc, int tk, string& mk)//lc la maTk  0:Giao vu, 1: Sinh vien
{
	char lenh;
	switch (chon)
	{
	case 1:
	{
		if (lc == 0)
			GiaoVu(l);
		else
			SinhVien(l);
		break;
	}
	case 2:
	{
		cout << "Hien thi thong tin cua tai khoan";
		viewInfoSv(findInfo(timLop(tk), tk));
		break;
	}
	case 3:
	{
		changePass(lc, tk, mk);
	}
	case 4:
	{
		cout << "Ban se dang xuat ra khoi tai khoan nay? Y?N?" << endl;
		cin >> lenh;
		if (lenh == 'Y' || lenh == 'y')
			return true;
		system("pause");
		break;
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
//Nam
NodeNamHoc* timNodeNam(int nam)
{
	if (l.pHead == NULL) return NULL;
	NodeNamHoc* t = l.pHead;
	while (t != NULL && t->data.tg.ngay_bd.y != nam)
	{
		t = t->pNext;
	}
	exit(1);
}
void TaiData_Nam()
{
	fstream f;
	f.open("listnam.txt", ios::in | ios::app);
	string temp = "";
	while (!f.eof())
	{
		f.clear();
		getline(f, temp, ',');
		if (temp != "")//file co san du lieu
		{
			int nam_bd = stoi(temp);
			NodeNamHoc* n = new NodeNamHoc;
			n->pNext = NULL;
			n->data.tg.ngay_bd.y = nam_bd;
			n->data.tg.ngay_kt.y = nam_bd + 1;
			TaiData_Lop(n);
			//TaiData_Mon
			ThemNodeNamHoc(l, n);
		}
	}
	f.close();
}
//Lop,Sv
NodeSvLop* TaoNodeSv(Sv sv)
{
	NodeSvLop* n = new NodeSvLop;
	n->sv = sv;
	n->pNext = NULL;
	return n;
}
void ThemNodeSvLop(NodeSvLop*& headSvLop, NodeSvLop* n)
{
	if (headSvLop == NULL)
	{
		headSvLop = n;
	}
	else
	{
		n->pNext = headSvLop;
		headSvLop = n;
	}
}
NodeLop* timNodeLop(int nam,int styear,string lop)
{
	NodeNamHoc* namhoc = timNodeNam(nam);
	NodeLop* list;
	if (styear == 1)
		list = namhoc->data.headLopNam1;
	else if (styear == 2)
		list = namhoc->data.headLopNam2;
	else if (styear == 3)
		list = namhoc->data.headLopNam3;
	else
		list = namhoc->data.headLopNam4;
	while (list != NULL)
	{
		if (list->lop.ten == lop) return list;
		list = list->pNext;
	}
	exit(1);
}
string timLop(int id)//tra ve ten lop cua sv co id tuong ung 
{
	ifstream f;
	f.open("SinhVien.txt");
	string s;
	bool flag = false;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		if (s == to_string(id))
		{
			f.clear();
			getline(f, s, ',');//bo qua pass 
			f.clear();
			getline(f, s, ',');//chi doc ten lop
			break;
		}
		f.clear();
		getline(f, s);//bo qua cac data thua cua sv khac
	}
	f.close();
	return s;
}
NodeSvLop* timNodeSvLop(NodeSvLop* head, int mssv)
{
	NodeSvLop* t = head;
	while (t != NULL)
	{
		if (t->sv.id == mssv) return t;
		t = t->pNext;
	}
	exit(1);
}
Sv findInfo(int id)//co mssv -> mo file sv.txt, doc ten lop cua sv->mo file lop.txt len ->doc info sv
{
	string tenLop = timLop(id);
	string s;
	Sv T;
	ifstream f;
	f.open(tenLop + ".txt");
	//do tim sv trong lop 
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		if (s == to_string(id))
		{
			break;
		}
		f.clear();
		getline(f, s);//bo qua cac data thua cua sv khac
	}
	f.clear();
	getline(f, s, ',');
	T.stt = atoi(s.c_str());
	f.clear();
	getline(f, T.ten, ',');
	f.clear();
	getline(f, T.ho, ',');
	f.clear();
	getline(f, T.gioi, ',');
	f.clear();
	getline(f, s, ',');
	T.ngayS.d = atoi(s.c_str());
	T.ngayS.y = T.ngayS.d % 10000;
	T.ngayS.m = (T.ngayS.d / 10000) % 100;
	T.ngayS.d = T.ngayS.d / 1000000;
	f.clear();
	getline(f, s, ',');
	T.cmnd = atoi(s.c_str());
	f.close();
	return T;
}
NodeSvLop* TaiData_DsLop(NodeLop* nodeLop)//!!TEST LAI CHO DOC FILE LOP
{
	NodeSvLop* headSvLop = NULL;
	fstream f;
	f.open(nodeLop->lop.ten + ".txt", ios::in | ios::app);//mo file lop tuong ung 
	string s;
	while (!f.eof())//doc file ghi vo T, tao node sv cho T
	{
		Sv T;
		f.clear();
		getline(f, s, ',');
		if (s != "")
		{
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
			ThemNodeSvLop(headSvLop, TaoNodeSv(T));
		}
	}	
	f.close();
	return headSvLop;
}
void TaiData_Lop(NodeNamHoc* n)
{
	fstream f;
	string s;
	n->data.headLopNam1 = n->data.headLopNam2 = n->data.headLopNam3 = n->data.headLopNam4 = NULL;
	for (int i = 1; i <= 4; i++)
	{
		//mo file ds lop
		{
			if (i == 1)
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "n1.txt", ios::in | ios::app);
			}
			else if (i == 2)
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "n2.txt", ios::in | ios::app);
				//mo file nam ngoai n1.txt
				//neu file nam nay rong thi...
				//ghi du lieu nam cu qua file nam nay<ios::out>?
			}
			else if (i == 3)
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "n3.txt", ios::in | ios::app);
			}
			else
			{
				f.open(to_string(n->data.tg.ngay_bd.y) + "n4.txt", ios::in | ios::app);
			}
		}
		//doc file, tao node, them node
		while (!f.eof())
		{
			f.clear();
			getline(f, s, ',');
			if (s != "")
			{
				NodeLop* node = new NodeLop;
				node->pNext = NULL;
				node->lop.ten = s;
				node->lop.headSvLop = TaiData_DsLop(node);
				if (i == 1)
					ThemNodeLopHoc(n->data.headLopNam1, node);
				else if (i == 2)
					ThemNodeLopHoc(n->data.headLopNam2, node);
				else if (i == 3)
					ThemNodeLopHoc(n->data.headLopNam3, node);
				else
					ThemNodeLopHoc(n->data.headLopNam4, node);
			}
		}
		f.close();
	}
}
//Mon
void themNodeMon(NodeMon*& A,NodeMon* T)//themdau
{
	if (A == NULL)
		A=T;
	else
	{
		T->pNext = A;
		A = T;
	}
}
void taiData_Mon(NodeNamHoc* n)
{
	fstream f;
	string s;
	n->data.hk1.headMon = n->data.hk2.headMon = n->data.hk3.headMon = NULL;
	HocKy* A;
	for (int i = 1; i <= 3; i++)//xem tung hk 
	{
		//mo file thong tin cac hoc ky
		if (i == 1)
		{
			f.open(to_string(n->data.tg.ngay_bd.y) + "hk1.txt", ios::in | ios::app);
			A = &(n->data.hk1);
		}
		else if (i == 2)
		{
			f.open(to_string(n->data.tg.ngay_bd.y) + "hk2.txt", ios::in | ios::app);
			A = &(n->data.hk2);
		}
		else 
		{
			f.open(to_string(n->data.tg.ngay_bd.y) + "hk3.txt", ios::in | ios::app);
			A = &(n->data.hk3);
		}
		//doc file, tao node, them node
		//lay tg bd hk
		f.clear();
		getline(f, s, ',');
		A->tg.ngay_bd.d = atoi(s.c_str());
		A->tg.ngay_bd.y = A->tg.ngay_bd.d % 10000;
		A->tg.ngay_bd.m = (A->tg.ngay_bd.d / 10000) % 100;
		A->tg.ngay_bd.d = A->tg.ngay_bd.d / 1000000;
		//lay tg ket thuc hk
		f.clear();
		getline(f, s, ',');
		A->tg.ngay_kt.d = atoi(s.c_str());
		A->tg.ngay_kt.y = A->tg.ngay_kt.d % 10000;
		A->tg.ngay_kt.m = (A->tg.ngay_kt.d / 10000) % 100;
		A->tg.ngay_kt.d = A->tg.ngay_kt.d / 1000000;

		while (!f.eof())
		{
				//doc cac mon trong hoc ky
				//mo file cac mon doc dssv tung mon
				//node->lop.headSvLop = TaiData_DsMon(node);
			NodeMon* t = new NodeMon;
			f.clear();
			getline(f,t->data.id, '\n');
			getline(f, t->data.tenMon, '\n');
			getline(f, t->data.tenGv, '\n');
			getline(f, s, '\n');
			t->data.so_tc = stoi(s);
			getline(f, t->data.bh1.thu, '\n');
			getline(f, t->data.bh1.buoi, '\n');
			getline(f, t->data.bh2.thu, '\n');
			getline(f, t->data.bh2.buoi, '\n');			
			t->pNext = NULL;
			t->headSvMon = NULL;
			taiData_SvMon(A->headMon, n->data.tg.ngay_bd.y, i);
			themNodeMon(A->headMon, t);

		}
		f.close();

	}
}
void themNodelistMonSv(NodeMonofSv*& head,NodeMon* A)//them dau
{
	NodeMonofSv* n = new NodeMonofSv;
	n->mon = A;
	n->pNext = head;
	head = n;
}
void taiData_SvMon(NodeMon*& mon,int nam,int ki)
{
	ifstream f;
	f.open(nam+'/'+"hk"+ki+'/'+mon->data.tenMon + ".txt");
	//trong file chua: mssv,lop,diem-gk,ck,cong,tk
	string s;
	while (!f.eof())
	{
		NodeSvMon* t = new NodeSvMon;
		f.clear();
		getline(f, s, '\n');
		t->mssv = stoi(s);
		getline(f, t->lop, '\n');
		getline(f, s, '\n');
		t->diem.gk = stoi(s);
		getline(f, s, '\n');
		t->diem.ck = stoi(s);
		getline(f, s, '\n');
		t->diem.cong = stoi(s);
		getline(f, s, '\n');
		t->diem.tongket = stoi(s);
		//them node vao dau list sv mon
		t->pNext = mon->headSvMon;
		mon->headSvMon = t;
		//tim nodesvlop de no tro vao node mon
		int styear;//nam nhat, nam hia, nam 3, nam 4
		string s="";
		s = t->lop[0] + t->lop[1];
		styear = nam - stoi(s) + 1;
		NodeSvLop* A;
		A = timNodeSvLop(timNodeLop(nam, styear, t->lop)->lop.headSvLop, t->mssv);
		if (ki == 1)
			themNodelistMonSv(A->headMonhk1, mon);
		else if (ki == 2)
			themNodelistMonSv(A->headMonhk2, mon);
		else
			themNodelistMonSv(A->headMonhk3, mon);
	}
	f.close();
}

//tui nghi la nen de may cai them node cua cac struct vo ham luon neu ko tai su dung de de quan li
//dung liist nam lam bien toan cuc
//bo trong cac file de de quan li

