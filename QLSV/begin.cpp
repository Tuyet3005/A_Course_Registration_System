#include"begin.h"
int InMenuBatDau(int ma_tk)//0 gv 1 sv lay tu login tra vector
{
	system("cls");
	BackGround1();
	cout << endl << endl << endl;
	cout << "\t \t \t CHAO MUNG BAN DEN VOI HE THONG QUAN LY SINH VIEN\n";
	cout << "\t \t \t \t \t 1. Vao he thong chinh\n";
	cout << "\t \t \t \t \t 2. Xem thong tin cua ban\n";
	cout << "\t \t \t \t \t 3. Doi mat khau\n";
	cout << "\t \t \t \t \t 4. Dang xuat\n";
	cout << "\t \t \t \t \t 5. Thoat\n";
	return 5;//tra ve maxSelect
}
bool XlMenuBD(int chon, short lc, string tk, string& mk, ListNamHoc& l)//lc la maTk  0:Giao vu, 1: Sinh vien
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
		/*if (lc == 1)//tra ve sinh vien 
		{
			findInfo(stoi(tk));
		}*/
		//viet them ham hien thi thong tin sv da tra ve !!!!!!!!!!!!!!!
		system("pause");
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
			TaiData_Lop(n);
			//TaiData_Mon
			ThemNodeNamHoc(l, n);
		}
	}
	f.close();
}
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
//void TaiData_Mon(NodeNamHoc* n)
//{
//	fstream f;
//	string s;
//	n->data.hk1.headMon = n->data.hk2.headMon = n->data.hk3.headMon = NULL;
//	for (int i = 1; i <= 3; i++)//xem tung hk 
//	{
//		//mo file thong tin cac hoc ky
//		{
//			if (i == 1)
//			{
//				f.open(to_string(n->data.tg.ngay_bd.y) + "hk1.txt", ios::in | ios::app);
//			}
//			else if (i == 2)
//			{
//				f.open(to_string(n->data.tg.ngay_bd.y) + "hk2.txt", ios::in | ios::app);
//			}
//			else if (i == 3)
//			{
//				f.open(to_string(n->data.tg.ngay_bd.y) + "hk3.txt", ios::in | ios::app);
//			}
//			else
//			{
//				f.open(to_string(n->data.tg.ngay_bd.y) + "hk4.txt", ios::in | ios::app);
//			}
//		}
//		//doc file, tao node, them node
//		while (!f.eof())
//		{
//			f.clear();
//			getline(f, s, ',');
//			if (s != "")
//			{
//				//doc du lieu thoi gian
//				//doc cac mon trong hoc ky
//				//mo file cac mon doc dssv tung mon
//				//node->lop.headSvLop = TaiData_DsMon(node);
//				if (i == 1)
//				{
//					n->data.hk1.tg.ngay_bd.d = stoi(s);
//					f.clear();
//					getline(f, s, ',');
//					n->data.hk1.tg.ngay_bd.m = stoi(s);
//					f.clear();
//					getline(f, s, ',');
//					n->data.hk1.tg.ngay_bd.y = stoi(s);
//					f.clear();
//				}
//				else if (i == 2)
//					ThemNodeLopHoc(n->data.headLopNam2, node);
//				else if (i == 3)
//					ThemNodeLopHoc(n->data.headLopNam3, node);
//				else
//					ThemNodeLopHoc(n->data.headLopNam4, node);
//			}
//		}
//		f.close();
//	}
//}