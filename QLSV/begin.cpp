#include"begin.h"

int InMenuBatDau(int ma_tk)//0 gv 1 sv lay tu login tra vector
{
	system("cls");
	gotoXY(0, 1);
	background();
	cout << endl << endl;
	string title[5] = { "HE THONG CHINH","THONG TIN CA NHAN","DOI MAT KHAU","DANG XUAT","THOAT" };
	return LuaChon_Dep(5, title);
}

bool XlMenuBD(int chon, bool role, string tk, string& mk, ListNamHoc& l)//false la giao vu, true la sv
{
	switch (chon)
	{
	case 1:
	{
		if (!role)
			GiaoVu(l);
		else
			SinhVien(l, stoi(tk));
		break;
	}
	case 2:
	{
		cout << "Hien thi thong tin cua tai khoan";
		if (true)//tra ve sinh vien
		{
			viewInfoSv(findInfo(stoi(tk)));
			break;
		}
		else 
		{
			viewInfoGV(taiTT_GV(tk));
			break;
		}
	}
	case 3:
	{
		changePass(role, tk, mk);
	}
	case 4:
	{
		system("cls");
		gotoXY(0, 1);
		background();
		if (Ask_YN("Ban se DANG XUAT ra khoi tai khoan nay?"))
		{
			gotoXY(0, HEIGHT - 4);
			system("pause");
			return true;
		}
		break;
	}
	case 5:
	{
		system("cls");
		gotoXY(0, 1);
		background();
		if (Ask_YN("Ban that su muon THOAT ?"))
		{
			gotoXY(0, HEIGHT - 4);
			exit(0);
		}
	}
	}
	return false;
}
bool Ask_YN(string cauhoi)//hang in ra cau hoi
{
	setColor(background_color, red);
	printA_Sentence(cauhoi,HEIGHT/2-3);
	setColor(background_color, text_color);
	string title[2] = { "Dung vay","No no, Khong he"};
	return LuaChon_Dep(2, title)-2;
}

//NAM HOC 
void TaiData_Nam(ListNamHoc& l)
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
			n->data.headLop[0] = n->data.headLop[1] = n->data.headLop[2] = n->data.headLop[3] = NULL;
			ThemNodeNamHoc(l, n);
			TaiData_Lop(n);
			TaiData_Mon(n);
		}
	}
	f.close();
}


//LOP HOC
NodeSv_Lop* TaoNodeSv(Sv sv)
{
	NodeSv_Lop* n = new NodeSv_Lop;
	n->sv = sv;
	n->pNext = NULL;
	return n;
}

NodeSv_Lop* TaiData_SvLop(NodeLop* nodeLop)
{
	NodeSv_Lop* headSvLop = NULL;
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
			NodeSv_Lop* temp = TaoNodeSv(T);
			ThemNodeSvLop(headSvLop, temp);
			temp->headMon[0] = temp->headMon[1] = temp->headMon[2] = NULL;
		}
	}
	f.close();
	return headSvLop;
}

void TaiData_Lop(NodeNamHoc* n)
{
	fstream f;
	string s;
	for (int i = 1; i <= 4; i++)
	{
		//mo file ds lop
		f.open(to_string(n->data.tg.ngay_bd.y) + 'n'+to_string(i)+".txt", ios::in | ios::app);
		if(i!=1)
		{
			//neu file nam nay chua dc tao -> sao chep data file nam ngoai sang 
			//vd: 2020n2.txt chua tao -> sao chep 2019n1.txt sang 
			getline(f, s);
			if (s == "")//file trong thi sao chep du lieu nam hoc cu
			{
				f.close();
				f.open(to_string(n->data.tg.ngay_bd.y) + 'n' + to_string(i) + ".txt", ios::app);
				fstream f1;
				f1.open(to_string(n->data.tg.ngay_bd.y - 1) + 'n'+to_string(i-1)+".txt");
				if (!f1.is_open())
					continue;
				while (!f1.eof())
				{
					f.clear();
					getline(f1, s);
					f << s;
					if (!f.good())
					{
						cout << "Loi sao chep lop nam cu sang !\n";
						system("pause");
					}
				}
				f1.close();//dong file nam cu
			}
			f.close();//dong lai file de khoi phuc lai con tro file 
			f.open(to_string(n->data.tg.ngay_bd.y) + 'n' + to_string(i) + ".txt", ios::in);//mo file moi o che do doc de doc lai tu dau file
		}
		//doc file, tao node, them node
		while (!f.eof())
		{
			getline(f, s, ',');
			if (s != "")
			{
				NodeLop* node = new NodeLop;
				node->pNext = NULL;
				node->lop.ten = s;
				node->lop.headSvLop = TaiData_SvLop(node);
				ThemNodeLopHoc(n->data.headLop[i - 1], node);
			}
		}
		f.close();
	}
}


//MON HOC 
void ThemNodeMon(NodeMon*& A, NodeMon* T)//themdau
{
	if (A == NULL)
		A = T;
	else
	{
		T->pNext = A;
		A = T;
	}
}

void TaiData_Mon(NodeNamHoc* n)
{
	fstream f;
	string s;
	n->data.hk[0].headMon = n->data.hk[1].headMon = n->data.hk[2].headMon = NULL;
	HocKy* A;
	for (int i = 0; i < 3; i++)//xem tung hk 
	{
		//mo file thong tin cac hoc ky
		f.open(to_string(n->data.tg.ngay_bd.y) + "hk"+to_string(i+1)+".txt", ios::in | ios::app);
		A = &(n->data.hk[i]);
		//lay tg hoc ky
		getline(f, s, ',');
		if (s != "" && s!="\n")
		{
			A->tg.ngay_bd.d = atoi(s.c_str());
			A->tg.ngay_bd.y = A->tg.ngay_bd.d % 10000;
			A->tg.ngay_bd.m = (A->tg.ngay_bd.d / 10000) % 100;
			A->tg.ngay_bd.d = A->tg.ngay_bd.d / 1000000;
			getline(f, s, ',');
			A->tg.ngay_kt.d = atoi(s.c_str());
			A->tg.ngay_kt.y = A->tg.ngay_kt.d % 10000;
			A->tg.ngay_kt.m = (A->tg.ngay_kt.d / 10000) % 100;
			A->tg.ngay_kt.d = A->tg.ngay_kt.d / 1000000;
			getline(f, s);//xoa "/n" ra khoi f truoc khi den thong tin mon
		}
		else
		{
			f.close();
			return;
		}
		//doc info mon trong file hoc ky NEU CO 
		A->headMon = NULL;
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
			TaiData_SvMon(t, n, i+1);
			ThemNodeMon(A->headMon, t);//them vao list mon cua hoc ky
		}
		f.close();
	}
}

NodeLop* timNodeLop(NodeNamHoc* namhoc, int styear, string lop)
{
	NodeLop* n = namhoc->data.headLop[styear - 1];
	while (n != NULL)
	{
		if (n->lop.ten == lop) 
			return n;
		n = n->pNext;
	}
	return NULL;
}

NodeSv_Lop* timNodeSv_Lop(NodeSv_Lop* head, int mssv)
{
	NodeSv_Lop* t = head;
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
	T.id = id;
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

void ThemNodeMon_Sv(NodeMon_Sv*& head, NodeMon* A, NodeSv_Mon* sv_mon)//them dau
{
	NodeMon_Sv* n = new NodeMon_Sv;
	n->mon = A;
	//tao link tu <nodeMon cua 1 sv: (node n)> den <nodeSv cua chinh sv do trong mon A: sv_mon>
	n->svMon = sv_mon;
	//them <node mon vua tao cua 1 sv> vao dau <ds mon cua sv do>
	if (head == NULL)
	{
		head = n;
		head->pNext = NULL;
		return;
	}
	n->pNext = head;
	head = n;
}

void TaiData_SvMon(NodeMon*& mon, NodeNamHoc* nodeNam, int ki)
{
	fstream f;
	int nam = nodeNam->data.tg.ngay_bd.y;
	string filePath = to_string(nam) + "hk" + to_string(ki) + mon->data.id + ".txt";
	f.open(filePath, ios::in | ios::app);//chua tao file thi tao
	//trong file chua: mssv,lop,diem-gk,ck,cong,tk
	string s;
	while (!f.eof())
	{
		//doc du lieu len nodesv_mon
		f.clear();
		getline(f, s, ',');
		if (s != "")
		{
			NodeSv_Mon* t = new NodeSv_Mon;
			t->mssv = stoi(s);
			getline(f, t->lop, ',');
			getline(f, s, ',');
			if (s == "R")//neu da co diem 
			{
				getline(f, s, ',');
				t->diem.gk = stof(s);
				getline(f, s, ',');
				t->diem.ck = stof(s);
				getline(f, s, ',');
				t->diem.cong = stof(s);
				getline(f, s, ',');
				t->diem.tongket = stof(s);
			}
			getline(f, s);//bo "\n" o dong cu 

			//them <node sv_mon> vua tao vao dau <list sv_mon>
			t->pNext = mon->headSvMon;
			mon->headSvMon = t;

			//them con tro den nodesv_mon vao list mon cua nodesv_lop
			int study_year;//nam nhat,2,3,4
			int K = stoi(t->lop.substr(0, 2));//lay ra 2 ki tu dau cua ten lop 
			study_year = nam % 2000 - K + 1;//chi dung doi voi cac nam hoc 2000~
			NodeLop* nodeLop = timNodeLop(nodeNam, study_year, t->lop);
			NodeSv_Lop* A = timNodeSv_Lop(nodeLop->lop.headSvLop, t->mssv);
			ThemNodeMon_Sv(A->headMon[ki-1], mon, mon->headSvMon);
		}
	}
	f.close();
}

string timLop(int id)//tra ve ten lop cua sv co id tuong ung 
{
	ifstream f;
	f.open("SinhVien.txt");
	string s;
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


//GIAO VU
Sv taiTT_GV(string id)
{
	ifstream f;
	f.open("GiaoVu.txt");
	string s;
	Sv gv;
	while (!f.eof())
	{
		f.clear();
		getline(f, s, ',');
		if (s == id)
		{
			f.clear();
			getline(f, s, ',');//pass
			f.clear();
			getline(f, gv.ten, ',');
			f.clear();
			getline(f, gv.ho, ',');
			f.clear();
			getline(f, gv.gioi, ',');
			f.clear();
			getline(f, s, ',');
			gv.ngayS.d = stoi(s);
			gv.ngayS.y = gv.ngayS.d % 10000;
			gv.ngayS.m = (gv.ngayS.d / 10000) % 100;
			gv.ngayS.d = gv.ngayS.d / 1000000;
			f.clear();
			getline(f, s, ',');
			gv.cmnd = stoi(s);
			break;
		}
		f.clear();
		getline(f, s);
	}
	f.close();
	return gv;
}
