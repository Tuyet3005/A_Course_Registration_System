#include"DKKH.h"
#include"begin.h"
#include<string>
#include<fstream>
//nho khoi tao nodemon_sv vs doc node mon
using namespace std;


//SV
void readFileDKKH(ThoiGian& tg, Time& tmBD, Time& tmKT, int& ki)
{
	fstream fin;
	fin.open("DKKH.txt", ios::in | ios::app);
	string s;
	//ngaybd
	getline(fin, s);
	if (s == "")//file trong
		throw - 1;
	fin.seekg(0);
	getline(fin, s, ',');
	tg.ngay_bd.d = stoi(s);
	getline(fin, s, ',');
	tg.ngay_bd.m = stoi(s);
	getline(fin, s, ',');
	tg.ngay_bd.y = stoi(s);
	getline(fin, s, ',');
	tmBD.gio = stoi(s);
	getline(fin, s, ',');
	tmBD.phut = stoi(s);
	//ngay kt
	getline(fin, s, ',');
	tg.ngay_kt.d = stoi(s);
	getline(fin, s, ',');
	tg.ngay_kt.m = stoi(s);
	getline(fin, s, ',');
	tg.ngay_kt.y = stoi(s);
	getline(fin, s, ',');
	tmKT.gio = stoi(s);
	getline(fin, s, ',');
	tmKT.phut = stoi(s);
	getline(fin, s, ',');
	ki = stoi(s);
	fin.close();
}

bool sosanhNgayGio(Ngay tg1, Time t1, Ngay tg2, Time t2)//return true neu tg1 truoc hoac bang tg2, false neu nguoc lai
{
	if (tg1.y < tg2.y)
		return true;
	if (tg1.y > tg2.y)
		return false;
	if (tg1.m < tg2.m)
		return true;
	if (tg1.m > tg2.m)
		return false;
	if (tg1.d < tg2.d)
		return true;
	if (tg1.d > tg2.d)
		return false;
	if (t1.gio < t2.gio)
		return true;
	if (t1.gio > t2.gio)
		return false;
	if (t1.phut < t2.phut)
		return true;
	return false;
}

bool cobuoiDKKH(ThoiGian tg, Time tmBD, Time tmKT)//doc file DKKH.txt
{
	//check
	tm temp = ThoiGianHeThong();
	Ngay Dnow;
	Dnow.y = temp.tm_year + 1900;
	Dnow.m = temp.tm_mon + 1;
	Dnow.d = temp.tm_mday;
	Time Tnow;
	Tnow.gio = temp.tm_hour;
	Tnow.phut = temp.tm_min;
	if (sosanhNgayGio(tg.ngay_bd, tmBD, Dnow, Tnow) && sosanhNgayGio(Dnow, Tnow, tg.ngay_kt, tmKT))
		return true;
	return false;
}

void xoaLC(int dem, int mon, int ki, NodeSv_Lop* A, NodeMon* head)
{
	if (dem == 0)
	{
		cout << "Ban chua dang ky mon hoc nao!" << endl;
		return;
	}
	char ask = 'Y';
	int lc;
	cout << "~ Nhap STT mon muon xoa (theo danh sach mon ban da dang ki)" << endl;
	do
	{
		cout << "- Hay nhap: ";
		cin >> lc;
		if (lc > 0 && lc <= dem)
			break;
		else
			cout << "Khong hop le... Hay nhap lai !" << endl;
	} while (true);

	//di chuyen den prenode cua nodeMon_sv muon xoa
	NodeMon_Sv* temp2 = A->headMon[ki - 1];
	for (int i = 1; i < lc - 1; i++)
		temp2 = temp2->pNext;
	//xoa nodeMon_sv ra khoi ds mon cua sv
	NodeMon_Sv* delMon_sv = NULL;
	if (lc == 1) //xoa mon dau (stt=1)
	{
		A->headMon[ki - 1] = temp2->pNext;
		delMon_sv = temp2;
	}
	else
	{
		delMon_sv = temp2->pNext;
		temp2->pNext = delMon_sv->pNext;
	}

	//xoa nodeSvMon ra khoi dssv cua mon
	//node sv dau cua mon dang muon xoa
	NodeSv_Mon* svHead = delMon_sv->mon->headSvMon;
	if (svHead->mssv == A->sv.id)
	{
		delMon_sv->mon->headSvMon = svHead->pNext;
		delete svHead;
		delMon_sv->mon->data.num_Sv--;
		delete delMon_sv;//xoa node Mon_sv sau khi da thay doi cac con tro tuong ung tren nam trong struct cua delMon_sv
		return;
	}
	//duyet toi pre-delSvMon (ko can thiet lam vi sv moi dc them vao DAU => sure! )
	while (svHead->pNext) 
	{
		if (svHead->pNext->mssv == A->sv.id)
		{
			NodeSv_Mon* delSv = svHead->pNext;
			svHead->pNext = delSv->pNext;
			delete delSv;
			delMon_sv->mon->data.num_Sv--;
			delete delMon_sv;
			return;
		}
		svHead = svHead->pNext;
	}
}

int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head)
{
	system("cls");
	gotoXY(55, 1);
	int mon;// so mon dc mo
	cout << "DANG KI HOC PHAN" << endl << endl;
	//hien thi ds mon duoc mo
	mon = viewDsMonHk(head, ki);
	cout << endl;
	//hien thi ds mon da dk mot hoc sinh
	viewMondaDk(A,ki, whereY());
	cout << endl << endl;
	cout << "~ HUONG DAN ~" << endl;
	cout << "--Nhap STT mon hoc ban muon dang ki va nhan ENTER de nhap tiep " << endl;
	cout << "--Nhan phim ESC de thoat dang ki" << endl;
	cout << "--Ban duoc chon toi da 5 mon hoc" << endl;
	cout << "--Nhan phim G de xoa tat ca cac mon da dang ki" << endl;
	cout << "--Nhan phim H de xoa 1 lua chon" << endl;
	cout << endl;
	cout << "- Hay nhap: " << endl;
	return mon;
}

bool BuoiHocHopLe(NodeMon* mon, NodeMon_Sv* dadk)//check siso, check mon da dk, check trung buoi hoc
{
	cout << endl;
	if (mon->data.num_Sv == mon->data.MaxSv)
	{
		cout << "Mon hoc da du so luong sinh vien dang ki... Hay chon mon khac !" << endl;
		Sleep(1000);
		return false;
	}
	NodeMon_Sv* pdadk = dadk;
	while (pdadk != NULL)
	{
		//bh1
		if (pdadk->mon->data.bh1.thu == mon->data.bh1.thu && pdadk->mon->data.bh1.buoi == mon->data.bh1.buoi)
			break;
		if (pdadk->mon->data.bh1.thu == mon->data.bh2.thu && pdadk->mon->data.bh1.buoi == mon->data.bh2.buoi)
			break;
		if (pdadk->mon->data.bh2.thu == mon->data.bh1.thu && pdadk->mon->data.bh2.buoi == mon->data.bh1.buoi)
			break;
		if (pdadk->mon->data.bh2.thu == mon->data.bh2.thu && pdadk->mon->data.bh2.buoi == mon->data.bh2.buoi)
			break;
		pdadk = pdadk->pNext;
	}
	if (pdadk)
	{
		cout << "Mon hoc nay da trung voi lich hoc ma ban da dang ki truoc do... Hay chon mon khac !" << endl;
		return false;
	}
	return true;
}

bool themMon(NodeSv_Lop* A, int ki, int stt, NodeMon* head)//them dau
{
	NodeMon* temp = head;
	for (int i = 1; i < stt; i++)
	{
		temp = temp->pNext;
	}
	//check buoi hoc hop le
	if (!BuoiHocHopLe(temp, A->headMon[ki - 1]))
		return false;
	//them mon vao ds mon cua hs
	NodeMon_Sv* nw = new NodeMon_Sv;
	nw->mon = temp;
	nw->pNext = A->headMon[ki - 1];
	A->headMon[ki - 1] = nw;
	//tang si so
	temp->data.num_Sv++;
	//them sv vao ds sv cua mon
	NodeSv_Mon* nw2 = new NodeSv_Mon;
	nw2->mssv = A->sv.id;
	nw2->lop = timLop(A->sv.id);
	nw2->pNext = temp->headSvMon;
	temp->headSvMon = nw2;
	return true;
}

void runDKKH_Sv(NodeSv_Lop* A, int ki, NodeMon*& head)
{
	int mon = viewDKKH_Sv(A->headMon[ki - 1], ki, head);
	string s = "";
	char temp;
	int x = whereX(), y = whereY();
	int key;
	int dem = 0;
	NodeMon** keep;
	int nkeep = 0;
	if (A != NULL)//da dk
	{
		NodeMon_Sv* t = A->headMon[ki - 1];
		while (t != NULL)
		{
			dem++;
			t = t->pNext;
		}
		keep = new NodeMon * [dem];
		t = A->headMon[ki - 1];
		while (t != NULL)//giu nhung mon ban dau
		{
			keep[nkeep] = t->mon;
			nkeep++;
			t = t->pNext;
		}
	}
	else
		keep = NULL;
	bool flag = true;//co dung
	while (flag)
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
					if (key == 0 || key > mon)// ko co stt trong ds
					{
						cout << endl;
						cout << "STT khong ton tai... Hay nhap lai !" << endl;
						y += 2;
						x = 0;
					}
					else
					{
						if (dem >= 5)
						{
							cout << "! Da dang ki du 5 mon, ban khong the dang ki them.. " << endl << endl;
							system("pause");
						}
						if (themMon(A, ki, key, head))
						{
							dem++;
							viewDKKH_Sv(A->headMon[ki - 1], ki, head);
							x = whereX();
							y = whereY();
							s = "";
							continue;
						}
						s = "";
					}
				}
				else
				{
					s = "";
					continue;
				}
			}
			else if (temp == 27)// nhan esc
			{
				break;
			}
			else if (temp == 8)//xoa
			{
				if (x != 0)
				{
					x--;
					gotoXY(x, y);
					cout << ' ';
					gotoXY(x, y);
					continue;
				}
			}
			else if (toupper(temp) == 'G')//Nhap lai tu dau
			{
				if (dem == 0)
				{
					cout << "Ban chua dang ky mon hoc nao!" << endl;
					continue;
				}
				cout << "~ Ban chac chan muon xoa tat ca cac mon da dang ki? Y/N?" << endl;
				if (askY_N())
				{
					A->headMon[ki - 1] = NULL;
					dem = 0;
					s = "";
				}
			}
			else if (toupper(temp) == 'H')//xoa
			{
				xoaLC(dem, mon, ki, A, head);
			}
			else if (temp < 48 || temp>57)
				continue;
			else
			{
				cout << temp;
				x++;
				continue;
			}
			//temp = NULL;//xoa du lieu cu
			//temp = _getch();
			viewDKKH_Sv(A->headMon[ki - 1], ki, head);
			x = whereX();
			y = whereY();
		}
	}
	///////ghi vo file
	if (keep == NULL)
	{
		if (A->headMon[ki - 1] == NULL)
			return;
	}
	NodeMon_Sv* pMon_Sv = A->headMon[ki - 1];
	bool flagkeep[5] = { false,false,false,false,false };
	int nam = NHhientai_nambd();
	string lop = timLop(A->sv.id);
	ofstream f;
	while (pMon_Sv)
	{
		flag = false;//reuse
		for (int i = 0; i < nkeep; i++)
		{
			if (pMon_Sv->mon == keep[i])
			{
				flagkeep[i] = true;
				flag = true;
				break;
			}
		}
		if (!flag)//ghi tt sv vao mon do vo file
		{
			f.open(to_string(nam) + "hk" + to_string(ki) + pMon_Sv->mon->data.id + ".txt", ios::app);
			f << A->sv.id << ',' << lop << ",C," << endl;
			f.close();
		}
		pMon_Sv = pMon_Sv->pNext;
	}
	//xoa sv khoi mon
	ifstream fin;
	int pos;
	string ss;
	string file;
	for (int i = 0; i < nkeep; i++)
	{
		if (!flagkeep[i])//xoa tt khoi ds
		{
			f.open("trunggian.txt");
			pos = -1;
			file = to_string(nam) + "hk" + to_string(ki) + keep[i]->data.id + ".txt";
			fin.open(file);
			while (!fin.eof())
			{
				getline(fin, ss);
				pos = ss.find(to_string(A->sv.id));
				if (pos != string::npos)
					continue;
				if (ss == "")
					break;
				f << ss << endl;
			}
			f.close();
			fin.close();
			remove((char*)file.c_str());
			rename("trunggian.txt", (char*)file.c_str());
		}
	}
}

void DKKH_Sv(NodeNamHoc* HT, NodeSv_Lop*& A, int lc)
{
	ThoiGian tg;
	Time tmBD, tmKT;
	int ki;
	readFileDKKH(tg, tmBD, tmKT, ki);
	NodeMon* head = HT->data.hk[ki - 1].headMon;
	if (lc == 1)//view
	{
		system("cls");
		viewDsMonHk(head, ki);
		return;
	}
	if (cobuoiDKKH(tg, tmBD, tmKT))
	{
		runDKKH_Sv(A, ki, head);
	}
	else
	{
		system("cls");
		printA_Sentence("Hien khong co buoi DKKH nao...", HEIGHT / 2 - 2);
		cout << endl << endl;
	}	
}


//GV
void taoDKKH_Gv(NodeNamHoc* H)//tao cho nam hien tai cho ca 4 nam///////chi tao 1 buoi cho 1 hoc ki duy nhat
{
	system("cls");
	cout << "----------------------------------TAO BUOI DANG KI KHOA HOC-------------------------------" << endl;
	cout << endl;
	cout << "~ HUONG DAN ~" << endl;
	cout << "--Ban chi co the tao buoi dang ki khoa hoc cho hoc ki CHUA BAT DAU cua nam hoc nay" << endl;
	cout << "--Ban chi co the tao MOT buoi dang ki khoa hoc cho MOT ki hoc" << endl;
	cout << "--Thoi gian cho 1 buoi dang ki khoa hoc KHONG QUA 30 ngay" << endl;
	cout << "--Ban can TAO MOI hoc ki va CAP NHAT danh sach mon hoc truoc khi tao buoi dang ki khoa hoc" << endl << endl;
	cout << "Ban co that su muon tao buoi dang ki khoa hoc ? Y/N?" << endl;
	char check;
	/*cin.clear();
	cin.ignore();*/
	if (!askY_N())
		return;
	system("cls");
	cout << "----------------------------------TAO BUOI DANG KI KHOA HOC-------------------------------" << endl;
	cout << endl;
	int ki;
	cin.clear();
	cout << "--Nhap ki hoc " << endl;
	do {
		cout << "Hay nhap: ";
		cin >> ki;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		else if (ki < 1 || ki>3)
		{
			continue;
		}
		else
			break;
	} while (true);

	//KT KI HOC HOP LE

	if (H->data.hk[ki - 1].tg.ngay_bd.d == NULL)//hk chua tao
	{
		cout << "! HOC KI NAY CHUA DUOC TAO !" << endl;
		cout << "--Hay vao muc TAO MOI de tao hoc ki va them mon hoc!-- " << endl;
		return;
	}
	//hk da ket thuc hoac da bd
	tm now = ThoiGianHeThong();
	Ngay Dnow;
	Dnow.d = now.tm_mday;
	Dnow.m = now.tm_mon + 1;
	Dnow.y = now.tm_year + 1900;
	Time Tnow;
	Tnow.gio = now.tm_hour;
	Tnow.phut = now.tm_min;
	if (sosanhNgay(H->data.hk[ki - 1].tg.ngay_kt, Dnow))
	{
		cout << "! HOC KI NAY DA KET THUC !" << endl;
		return;
	}
	if (sosanhNgay(H->data.hk[ki - 1].tg.ngay_bd, Dnow))
	{
		cout << "! HOC KI NAY DA BAT DAU !" << endl;
		return;
	}
	//da co buoi dkkh cho ki nay
	ThoiGian tg;
	Time tmBD, tmKT;
	tmBD.giay = tmKT.giay = 0;
	try {
		int File_Ki;
		string s;
		readFileDKKH(tg, tmBD, tmKT, File_Ki);
		if (File_Ki == ki)
		{
			cout << endl << "! DA TAO BUOI DANG KI KHOA HOC CHO KI NAY !" << endl << endl;
			cout << "Ban co muon TAO LAI buoi dang ki khoa hoc cho ki nay? Y/N?" << endl;
			if (!askY_N())
				return;
		}
	}
	catch (int error)
	{
		if (error == 0)//file trong 
		{
			//OK!!!
		}
	}
	if (H->data.hk[ki - 1].headMon == NULL)//chua co mon nao
	{
		cout << "! CHUA TAO MON HOC CHO HOC KY NAY !" << endl << endl;
		cout << "--Hay quay ve menu truoc va vao muc TAO MOI de them mon hoc cho ki nay!" << endl;
		return;
	}

	//SAU KHI NHAP KI THANH CONG

	ThoiGian tHK = H->data.hk[ki - 1].tg;//tg hocki
	bool flagbd = true;//chua nhap ngay bd
	do {
		system("cls");
		cout << "----------------------------------TAO BUOI DANG KI KHOA HOC-------------------------------" << endl;
		cout << endl;
		//in ra tg hk va tg nam hoc
		cout << "Thoi gian HOC KI " << ki << ": " << tHK.ngay_bd.d << '/' << tHK.ngay_bd.m << '/' << tHK.ngay_bd.y << " - " << tHK.ngay_kt.d << '/' << tHK.ngay_kt.m << '/' << tHK.ngay_kt.y << endl;
		if (flagbd)
		{
			cout << endl << "--NGAY BAT DAU " << endl;
			nhapNgayGio(tg.ngay_bd, tmBD);
			//ss tg hien tai vs tgbd
			if (!sosanhNgayGio(Dnow, Tnow, tg.ngay_bd, tmBD))//so sanh voi tg hien tai
			{
				cout << "! BUOI DANG KI PHAI DUOC BAT DAU SAU THOI GIAN HIEN TAI !" << endl << endl;
				system("pause");
				continue;
			}
			system("pause");
			flagbd = false;
			continue;
		}
		else
		{
			cout << endl << "--NGAY BAT DAU " << tmBD.gio << "h" << tmBD.phut << "ph  ngay " << tg.ngay_bd.d << "/" << tg.ngay_bd.m << endl;
		}

		cout << "--NGAY KET THUC " << endl;
		nhapNgayGio(tg.ngay_kt, tmKT);
		if (sosanhNgayGio(tg.ngay_bd, tmBD, tg.ngay_kt, tmKT))//ss tg bd vs tg kt + 
		{
			if (sosanhNgayGio(tg.ngay_kt, tmKT, _30ngaysau(tg.ngay_bd), tmBD))//thoi han buoi dk là khong qua 30 ngay
			{
				if (sosanhNgay(tg.ngay_kt, tHK.ngay_bd))
					break;
				cout << "! BUOI DANG KI PHAI KET THUC TRUOC NGAY BAT DAU HOC KI !" << endl;
			}
			else
				cout << "! THOI HAN BUOI DANG KI KHONG QUA 30 NGAY !" << endl;
		}
		else
			cout << "! NGAY KET THUC PHAI SAU NGAY BAT DAU !" << endl;
		system("pause");
	} while (true);
	system("pause");
	if (askforsure(tg, tmBD, tmKT, ki))
		if (xuatFile_DKKH(tg, tmBD, tmKT, ki))
		{
			system("cls");
			cout << "~ TAO THANH CONG BUOI DANG KI KHOA HOC ~" << endl;
			return;
		}
	system("cls");
	cout << endl << "! TAO BUOI DANG KI KHOA HOC THAT BAI !" << endl << endl;
}

void nhapNgayGio(Ngay& ngay, Time& t)
{
	cout << "-Nhap lan luot ngay, thang, nam : " << endl;
	do
	{
		cout << "Hay nhap: " << endl;
		cin >> ngay.d >> ngay.m >> ngay.y;//be careful
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		else if (NgayHopLe(ngay.d, ngay.m, ngay.y))
		{
			break;
		}
	} while (true);
	cout << "-Nhap lan luot gio, phut :" << endl;
	do
	{
		cout << "Hay nhap: " << endl;
		cin >> t.gio >> t.phut;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		else if (GioHopLe(t))
		{
			break;
		}
	} while (true);
}

bool askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT, int ki)
{
	system("cls");
	cout << "-------------------------TAO BUOI DANG KI KHOA HOC-------------------------" << endl << endl;
	cout << "Ban da tao buoi dang ki khoa hoc ki " << ki << ": " << endl;
	cout << "--BAT DAU vao luc  :  " << tmBD.gio << "h" << tmBD.phut << "ph  ngay " << tg.ngay_bd.d << "/" << tg.ngay_bd.m << endl;
	cout << "--KET THUC vao luc :  " << tmKT.gio << "h" << tmKT.phut << "ph  ngay " << tg.ngay_kt.d << "/" << tg.ngay_kt.m << endl;
	cout << endl;
	cout << "Nhan 1 de XAC NHAN, 2 de HUY" << endl;
	int lc;
	do
	{
		cout << "Hay nhap: " << endl;
		cin >> lc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		else if (lc == 1)
		{
			return true;
		}
		else if (lc == 2)
		{
			cout << "Ban co chac chan HUY buoi hoc vua tao? Y/N?" << endl;
			if (askY_N())
				return false;
			return askforsure(tg, tmBD, tmKT, ki);
		}
	} while (true);
}

bool askY_N()
{
	char yn;
	while (true)
	{
		yn = _getch();
		if ('Y' == toupper(yn))
			return true;
		else if ('N' == toupper(yn))
			return false;
	}
}

bool xuatFile_DKKH(ThoiGian tg, Time tmBD, Time tmKT, int ki)
{
	//Cau truc file
	//ngay-thang bd
	//tg bd
	//ngay-thang kt
	//tg kt
	//ki,
	//tenfile lay mon hoc
	ofstream fout;
	fout.open("DKKH.txt");
	if (fout.is_open())
	{
		fout << tg.ngay_bd.d << "," << tg.ngay_bd.m << "," << tg.ngay_bd.y << "," << endl;
		fout << tmBD.gio << "," << tmBD.phut << "," << endl;
		fout << tg.ngay_kt.d << "," << tg.ngay_kt.m << "," << tg.ngay_kt.y << "," << endl;
		fout << tmKT.gio << "," << tmKT.phut << "," << endl;
		fout << ki << "," << endl;
	}
	else
		return false;
	fout.close();
	return true;
}