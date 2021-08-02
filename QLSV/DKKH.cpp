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
	getline(fin, s, ',');
	if (s == "")//file trong
		throw - 1;
	//file da co data:
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

bool xoaLC(int dem, int mon, int ki, NodeSv_Lop* A, NodeMon* head)
{
	int x = WIDTH / 2 - 2;
	int y = whereY();
	if (dem == 0)
	{
		setColor(background_color, red);
		printA_Sentence("Ban chua dang ky mon hoc nao !", y + 2);
		_getch();
		printA_Sentence("                                ", y + 2);
		setColor(background_color, text_color);
		return false;
	}
	int lc;
	setColor(background_color, title_color1);
	printA_Sentence("Nhap STT mon muon xoa  ", y - 2);
	setColor(background_color, text_color);
	printA_Sentence("(theo danh sach mon ban da dang ki)", y - 1);
	printA_Sentence("______________________________________", y);
	y++;
	char c;
	string s = "";
	gotoXY(x, y);
	int x_now = x;
	do
	{
		c = _getch();
		gotoXY(x_now, y);
		if (c == '\b')//nhan phim backspace 
		{
			if (s == "")
			{
				gotoXY(x, y);
				continue;
			}
			x_now--;
			gotoXY(x_now, y);
			cout << " ";
			gotoXY(x_now, y);//quay lai vi tri " "
			s.pop_back();
		}
		else if (c == '\r' || c == '\n')
		{
			if (s == "")
				continue;
			lc = stoi(s);
			if (lc<1 || lc>dem)
			{
				setColor(background_color, red);
				printA_Sentence("Lua chon khong hop le !", y + 2);
				_getch();
				printA_Sentence("                             ", y + 2);
				gotoXY(x_now, y);
				setColor(background_color, text_color);
				continue;
			}
			break;
		}
		else if (c >= 48 && c <= 57)
		{
			if (s.length() >= 4)
			{
				setColor(background_color, red);
				printA_Sentence("Lua chon khong hop le !", y + 2);
				_getch();
				printA_Sentence("                             ", y + 2);
				gotoXY(x_now, y);
				setColor(background_color, text_color);
				continue;
			}
			x_now++;
			s += c;
			cout << c;
		}
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
		return true;
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
			return true;
		}
		svHead = svHead->pNext;
	}
}

int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head)
{
	system("cls");
	gotoXY(55, 1);
	int mon;// so mon dc mo
	//hien thi ds mon duoc mo
	mon = viewDsMonHk(head, ki);
	cout << endl;
	//hien thi ds mon da dk mot hoc sinh
	viewMondaDk(A,ki, whereY());
	int line = whereY() + 2;
	setColor(background_color, red);
	printA_Sentence("~ DANG KI HOC PHAN ~", 1);
	setColor(background_color, title_color1);
	printA_Sentence("-- HUONG DAN --", line);
	setColor(background_color, text_color);
	gotoXY(WIDTH / 3 + 5, line += 2);
	cout << "- Nhap STT mon hoc ban muon dang ki va nhan ENTER de nhap tiep ";
	gotoXY(WIDTH / 3 + 5, line += 1);
	cout << "- Nhan phim ESC de ket thuc dang ki";
	gotoXY(WIDTH / 3 + 5, line += 1);
	cout << "- Ban duoc chon toi da 5 mon hoc, cac mon khong duoc trung lich hoc";
	gotoXY(WIDTH / 3 + 5, line += 1);
	cout << "- Nhan phim G de xoa tat ca cac mon da dang ki";
	gotoXY(WIDTH / 3 + 5, line += 1);
	cout << "- Nhan phim H de xoa 1 mon da dang ki";
	setColor(background_color, title_color1);
	printA_Sentence("-- Moi nhap (STT) --", line += 2);
	setColor(background_color, text_color);
	printA_Sentence("__________________________", line += 1);
	gotoXY(0, line+=1);
	return mon;
}

bool BuoiHocHopLe(NodeMon* mon, NodeMon_Sv* dadk)//check siso, check mon da dk, check trung buoi hoc
{
	int line = whereY() + 2;
	if (mon->data.num_Sv == mon->data.MaxSv)
	{
		setColor(background_color, red);
		printA_Sentence("Mon hoc da du so luong sinh vien dang ki !", line);
		setColor(background_color, text_color);
		_getch();
		printA_Sentence("                                                                      ", line);
		//Sleep(1000);
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
		setColor(background_color, red);
		printA_Sentence("Mon hoc nay da trung voi lich hoc ma ban da dang ki truoc do !", line);
		setColor(background_color, text_color);
		_getch();
		printA_Sentence("                                                                                   ", line);
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
	int x = WIDTH / 2 - 2, y = whereY();
	int key;
	int dem = 0;
	NodeMon** keep;
	int nkeep = 0;
	if (A->headMon[ki-1] != NULL)//da dk
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
	int x_now = x;
	gotoXY(x_now, y);
	while (flag)
	{
		if (_kbhit())
		{
			//cin.clear();
			gotoXY(x_now, y);
			temp = _getch();
			if (temp == 13)//enter
			{
				if (s != "")
				{
					key = stoi(s);
					if (key == 0 || key > mon)// ko co stt trong ds
					{
						setColor(background_color, red);
						printA_Sentence("STT khong ton tai... Hay nhap lai !", y + 2);
						_getch();
						printA_Sentence("                                     ", y + 2);
						gotoXY(x_now, y);
						setColor(background_color, text_color);
						continue;
					}
					else
					{
						if (dem >= 5)
						{
							setColor(background_color, red);
							printA_Sentence("Da dang ki du 5 mon.. ban khong the dang ki them !", y + 2);
							_getch();
							//cin.clear();
							printA_Sentence("                                                    ", y + 2);
							gotoXY(x_now, y);
							setColor(background_color, text_color);
							gotoXY(x_now, y);
							continue;
						}
						if (themMon(A, ki, key, head))
						{
							dem++;
							s = "";
						}
						else
						{
							gotoXY(x_now, y);
							continue;
						}
					}
				}
				else
					continue;
			}
			else if (temp == 27)// nhan esc
			{
				break;
			}
			else if (temp == 8)//xoa
			{
				if (x_now != x)
				{
					x_now--;
					gotoXY(x_now, y);
					cout << ' ';
					gotoXY(x_now, y);
					s.pop_back();
				}
				continue;
			}
			else if (toupper(temp) == 'G')//Nhap lai tu dau
			{
				if (dem == 0)
				{
					setColor(background_color, red);
					printA_Sentence("Ban chua dang ky mon hoc nao !", y + 2);
					_getch();
					printA_Sentence("                                                 ", y + 2);
					gotoXY(x_now, y);
					setColor(background_color, text_color);
					continue;
				}
				setColor(background_color, red);
				printA_Sentence("Ban chac chan muon xoa tat ca cac mon da dang ki?", y - 2);
				string title[2] = { "Dung vay","No no, khong he" };
				if (LuaChon_Menu(2,title,2,y-1)-2)
				{
					A->headMon[ki - 1] = NULL;
					dem = 0;
					s = "";
				}
				setColor(background_color, text_color);
			}
			else if (toupper(temp) == 'H')//xoa
			{
				xoaLC(dem, mon, ki, A, head);
				dem--;
				gotoXY(x_now, y);
				s = "";
			}
			else if (temp < 48 || temp>57)
				continue;
			else
			{
				if (s.length() >= 4)
				{
					setColor(background_color, red);
					printA_Sentence("STT khong hop le... Hay nhap lai !", y + 2);
					_getch();
					printA_Sentence("                                     ", y + 2);
					gotoXY(x_now, y);
					setColor(background_color, text_color);
				}
				else
				{
					s += temp;
					cout << temp;
					x_now++;
				}
				continue;
			}
			viewDKKH_Sv(A->headMon[ki - 1], ki, head);
			x_now = x;
			y = whereY();
			gotoXY(x_now, y);
		}
	}
	/////ghi vo file
	NodeMon_Sv* pMon_Sv = A->headMon[ki - 1];
	bool flagkeep[5] = { false,false,false,false,false };
	int nam = NHhientai_nambd();
	string lop = timLop(A->sv.id);
	ofstream f;
	while (pMon_Sv)
	{
		flag = false;//reuse
		for (int i = 0; i < nkeep; i++)//ss mon nay dc dk trc do chua
		{
			if (pMon_Sv->mon == keep[i])//vi cac mon duoc them se nam o DAU
			{
				flagkeep[i] = true;
				flag = true;
				break;
			}
		}
		if (!flag)//ghi tt sv vao mon do vo file
		{
			f.open(to_string(nam) + "hk" + to_string(ki) + pMon_Sv->mon->data.id + ".txt", ios::app);
			if (pMon_Sv->mon->headSvMon->pNext)
				f << endl;
			f << A->sv.id << ',' << lop << ",0,0,0,0,";//mac dinh diem gk, ck, cong, tk = 0
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
	try
	{
		readFileDKKH(tg, tmBD, tmKT, ki);
	}
	catch (int)//catch throw -1 !
	{
		//okkkkk
	}
	NodeMon* head = HT->data.hk[ki - 1].headMon;
	if (lc == 1)//view
	{
		system("cls");
		viewDsMonHk(head, ki);
	}
	else {
		if (cobuoiDKKH(tg, tmBD, tmKT))
		{
			runDKKH_Sv(A, ki, head);
		}
		else
		{
			system("cls");
			printA_Sentence("Hien khong co buoi DKKH nao...", HEIGHT / 2 - 2);
		}
	}
	setColor(background_color, title_color1);
	char pause = _getch();
}


//GV
void taoDKKH_Gv(NodeNamHoc* H)
{
	system("cls");
	try
	{
		if (H == NULL)
			throw - 1;//ko tao nh hien tai thi ko cho tao dkkh
	}
	catch(int)
	{
		setColor(background_color, red);
		printA_Sentence("! NAM HOC NAY CHUA DUOC TAO !", HEIGHT / 2 - 1);
		setColor(background_color, text_color);
		printA_Sentence("Vao muc TAO MOI de tao nam hoc",HEIGHT / 2 + 1);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	//lay tg hien tai
	tm now = ThoiGianHeThong();
	Ngay Dnow;
	Dnow.d = now.tm_mday;
	Dnow.m = now.tm_mon + 1;
	Dnow.y = now.tm_year + 1900;
	Time Tnow;
	Tnow.gio = now.tm_hour;
	Tnow.phut = now.tm_min;
	setColor(background_color, title_color);
	printA_Sentence("~ TAO BUOI DANG KI KHOA HOC ~", 3);
	setColor(background_color, title_color1);
	printA_Sentence("~ HUONG DAN ~", 9);
	setColor(background_color, text_color);
	gotoXY(WIDTH / 4 + 3, 11);
	cout << "--Ban chi co the tao buoi dang ki khoa hoc cho hoc ki CHUA BAT DAU cua nam hoc nay";
	gotoXY(WIDTH / 4 + 3, 12);
	cout << "--Ban chi co the tao MOT buoi dang ki khoa hoc cho MOT ki hoc.";
	gotoXY(WIDTH / 4 + 3, 13);
	cout << "--Buoi DKKH chi duoc to chuc trong khoang thoi gian hoc ki hien tai dien ra.";
	gotoXY(WIDTH / 4 + 3, 14);
	cout << "--Ban can TAO MOI hoc ki va CAP NHAT danh sach mon hoc truoc khi tao buoi dang ki khoa hoc.";
	gotoXY(0, 16);
	if (!Ask_YN("Ban co that su muon tao buoi dang ki khoa hoc ?"))
		return;
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO BUOI DANG KI KHOA HOC ~", 3);
	int ki= chonKi("Ban muon tao buoi DKKH cho ki nao?");

	//KT KI HOC HOP LE
	system("cls");
	if (H->data.hk[ki - 1].tg.ngay_bd.d == NULL)//hk chua tao
	{
		setColor(background_color, red);
		printA_Sentence("! HOC KI NAY CHUA DUOC TAO !", HEIGHT / 2 - 2);
		setColor(background_color, text_color);
		printA_Sentence("Hay vao muc TAO MOI de tao hoc ki va them mon hoc", HEIGHT / 2 );
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	//hk da ket thuc hoac chua bd
	if (sosanhNgay(H->data.hk[ki - 1].tg.ngay_kt, Dnow))
	{
		setColor(background_color, red);
		printA_Sentence("! HOC KI NAY DA KET THUC !", HEIGHT / 2 - 1);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	if (!sosanhNgay(H->data.hk[ki - 1].tg.ngay_bd, Dnow))
	{
		setColor(background_color, red);
		printA_Sentence("! HOC KI NAY CHUA BAT DAU !", HEIGHT / 2 - 1);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	if (H->data.hk[ki - 1].headMon == NULL)//chua co mon nao
	{
		setColor(background_color, red);
		printA_Sentence("! CHUA TAO MON HOC CHO HOC KY NAY !", HEIGHT / 2 - 2);
		setColor(background_color, text_color);
		printA_Sentence("Hay vao muc CAP NHAT de them mon hoc cho ki nay", HEIGHT / 2);
		setColor(background_color, title_color1);
		printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
		_getch();
		return;
	}
	
	//da co buoi dkkh cho ki nay
	ThoiGian tg;
	Time tmBD, tmKT;
	tmBD.giay = tmKT.giay = 0;
	int File_Ki;
	try
	{
		readFileDKKH(tg, tmBD, tmKT, File_Ki);
	}
	catch (int)
	{
		//phai xu ly throw -1, ko catch se bi loi !
	}
	if (File_Ki == ki)
	{
		setColor(background_color, red);
		printA_Sentence("! DA TAO BUOI DANG KI KHOA HOC CHO KI NAY !", HEIGHT / 2 - 4);
		if (!Ask_YN("Ban co muon TAO LAI buoi dang ki khoa hoc cho ki nay?"))
			return;
	}	
  
	//SAU KHI NHAP KI THANH CONG

	ThoiGian tHK = H->data.hk[ki - 1].tg;//tg hocki
	//bool flagbd = true;//chua nhap ngay bd
	//do {
	//	system("cls");
	//	setColor(background_color, title_color);
	//	printA_Sentence("~ TAO BUOI DANG KI KHOA HOC ~", 5);
	//	//in ra tg hk va tg nam hoc
	//	setColor(background_color, text_color);
	//	printA_Sentence("Thoi gian HOC KI " + to_string(ki) + ": " + to_string(tHK.ngay_bd.d) + '/' + to_string(tHK.ngay_bd.m) + '/' + to_string(tHK.ngay_bd.y) + " - " + to_string(tHK.ngay_kt.d) + '/' + to_string(tHK.ngay_kt.m) + '/' + to_string(tHK.ngay_kt.y), 9);
	//	//in ra cho nhap ngay bd
	//	
	//	if (flagbd)
	//	{
	//		setColor(background_color, title_color1);
	//		printA_Sentence("- NGAY BAT DAU -", 11);
	//		nhapNgay_ve(13);
	//		nhapGio_ve(18);
	//		tg.ngay_bd=nhapNgay_nhap(13);
	//		tmBD = nhapGio_nhap(18);
	//		//nhapNgayGio(tg.ngay_bd, tmBD);
	//		//ss tg hien tai vs tgbd
	//		if (!sosanhNgayGio(Dnow, Tnow, tg.ngay_bd, tmBD))//so sanh voi tg hien tai
	//		{
	//			setColor(background_color, red);
	//			printA_Sentence("! BUOI DANG KI PHAI DUOC BAT DAU SAU THOI GIAN HIEN TAI !", HEIGHT - 8);
	//			_getch();
	//			continue;
	//		}
	//		//ss ngay bd voi ngay bd hk
	//		if(sosanhNgay(tg.ngay_bd,tHK.ngay_bd))
	//		{
	//			setColor(background_color, red);
	//			printA_Sentence("! BUOI DANG KI PHAI DUOC BAT DAU SAU KHI HOC KI BAT DAU !", HEIGHT - 8);
	//			_getch();
	//			continue;
	//		}
	//		setColor(background_color, title_color1);
	//		printA_Sentence("An phim bat ki de tiep tuc -->", HEIGHT - 8);
	//		_getch();
	//		flagbd = false;
	//		continue;
	//	}
	//	else
	//	{
	//		setColor(background_color, title_color1);
	//		printA_Sentence("- NGAY BAT DAU " + to_string(tmBD.gio) + 'h' + to_string(tmBD.phut) + "ph  ngay " + to_string(tg.ngay_bd.d) + "/" + to_string(tg.ngay_bd.m) + "/" + to_string(tg.ngay_bd.y), 11);
	//	}
	//	setColor(background_color, title_color1);
	//	printA_Sentence("- NGAY KET THUC -", 13);
	//	nhapNgay_ve(15);
	//	nhapGio_ve(21);
	//	tg.ngay_kt = nhapNgay_nhap(15);
	//	tmKT = nhapGio_nhap(21);
	//	//nhapNgayGio(tg.ngay_kt, tmKT);
	//	if (sosanhNgayGio(tg.ngay_bd, tmBD, tg.ngay_kt, tmKT))//ss tg bd vs tg kt
	//	{
	//		if (sosanhNgay(tHK.ngay_kt, tg.ngay_kt))
	//		{
	//			setColor(background_color, red);
	//			printA_Sentence("! BUOI DANG KI PHAI KET THUC TRUOC NGAY KET THUC HOC KI !", HEIGHT - 8);
	//			_getch();
	//		}
	//		else
	//			break;
	//	}
	//	else
	//	{
	//		setColor(background_color, red);
	//		printA_Sentence("! NGAY KET THUC PHAI SAU NGAY BAT DAU !", HEIGHT - 8);
	//		_getch();
	//	}
	//} while (true);
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO BUOI DANG KI KHOA HOC ~", 3);
	//in ra tg hk va tg nam hoc
	setColor(background_color, text_color);
	printA_Sentence("Thoi gian HOC KI " + to_string(ki) + ": " + to_string(tHK.ngay_bd.d) + '/' + to_string(tHK.ngay_bd.m) + '/' + to_string(tHK.ngay_bd.y) + " - " + to_string(tHK.ngay_kt.d) + '/' + to_string(tHK.ngay_kt.m) + '/' + to_string(tHK.ngay_kt.y), 7);
	//in ra cho nhap ngay bd
	setColor(background_color, title_color1);
	printA_Sentence("- NGAY BAT DAU -", 10);
	nhapNgay_ve(12);
	nhapGio_ve(18);
	setColor(background_color, text_color);
	printA_Sentence("- NGAY KET THUC -", 24);
	nhapNgay_ve(26);
	nhapGio_ve(32);
	while (true)//nhap ngay_bd
	{
		tg.ngay_bd = nhapNgay_nhap(12);
		if (sosanhNgay(tg.ngay_bd, tHK.ngay_bd))
		{
			setColor(background_color, red);
			printA_Sentence("! BUOI DANG KI PHAI DUOC BAT DAU SAU KHI HOC KI BAT DAU !", HEIGHT - 4);
			_getch();
			printA_Sentence("                                                              ", HEIGHT - 4);
			nhapNgay_Gio_xoa(12, 0);
			continue;
		}
		break;
	}
	while (true)//nhap gio_bd
	{
		tmBD = nhapGio_nhap(18);
		if (!sosanhNgayGio(Dnow, Tnow, tg.ngay_bd, tmBD))//so sanh voi tg hien tai
		{
			setColor(background_color, red);
			printA_Sentence("! BUOI DANG KI PHAI DUOC BAT DAU SAU THOI GIAN HIEN TAI !", HEIGHT - 4);
			_getch();
			printA_Sentence("                                                              ", HEIGHT - 4);
			nhapNgay_Gio_xoa(19, 1);
			continue;
		}
		break;
	}

	setColor(background_color, text_color);
	printA_Sentence("- NGAY BAT DAU -", 10);
	setColor(background_color, title_color1);
	printA_Sentence("- NGAY KET THUC -", 24);
	while (true)//nhap ngay_gio_kt
	{
		tg.ngay_kt = nhapNgay_nhap(26);
		if (sosanhNgay(tHK.ngay_kt, tg.ngay_kt))
		{
			setColor(background_color, red);
			printA_Sentence("! BUOI DANG KI PHAI KET THUC TRUOC NGAY KET THUC HOC KI !", HEIGHT - 4);
			_getch();
			printA_Sentence("                                                            ", HEIGHT - 4);
			nhapNgay_Gio_xoa(26, 0);
			continue;
		}
		tmKT = nhapGio_nhap(32);
		if (!sosanhNgayGio(tg.ngay_bd, tmBD, tg.ngay_kt, tmKT))//ss tg bd vs tg kt
		{
			setColor(background_color, red);
			printA_Sentence("! NGAY KET THUC PHAI SAU NGAY BAT DAU !", HEIGHT - 4);
			_getch();
			printA_Sentence("                                            ", HEIGHT - 4);
			nhapNgay_Gio_xoa(26, 0);
			nhapNgay_Gio_xoa(32, 1);
			continue;
		}
		break;
	}
	setColor(background_color, title_color1);
	printA_Sentence("An phim bat ki de tiep tuc -->", HEIGHT - 4);
	_getch();
	if (askforsure(tg, tmBD, tmKT, ki))
		if (xuatFile_DKKH(tg, tmBD, tmKT, ki))
		{
			system("cls");
			setColor(background_color, title_color);
			printA_Sentence("~ TAO THANH CONG BUOI DANG KI KHOA HOC ~", HEIGHT / 2);
			setColor(background_color, title_color1);
			printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
			_getch();
			return;
		}
	system("cls");
	setColor(background_color, red);
	printA_Sentence("! TAO BUOI DANG KI KHOA HOC THAT BAI !", HEIGHT / 2);
	setColor(background_color, title_color1);
	printA_Sentence("<-- Nhan nut bat ki de quay lai", HEIGHT - 4);
	_getch();
}

//void nhapNgayGio(Ngay& ngay, Time& t)
//{
//	cout << "-Nhap lan luot ngay, thang, nam : " << endl;
//	do
//	{
//		cout << "Hay nhap: " << endl;
//		cin >> ngay.d >> ngay.m >> ngay.y;//be careful
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore(100, '\n');
//			continue;
//		}
//		else if (NgayHopLe(ngay.d, ngay.m, ngay.y))
//		{
//			break;
//		}
//	} while (true);
//	cout << "-Nhap lan luot gio, phut :" << endl;
//	do
//	{
//		cout << "Hay nhap: " << endl;
//		cin >> t.gio >> t.phut;
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore(100, '\n');
//			continue;
//		}
//		else if (GioHopLe(t))
//		{
//			break;
//		}
//	} while (true);
//}

bool askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT, int ki)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ TAO BUOI DANG KI KHOA HOC ~", 5);
	setColor(background_color, title_color1);
	printA_Sentence("Ban da tao buoi dang ki khoa hoc ki " + to_string(ki), 10);
	setColor(background_color, text_color);
	gotoXY(WIDTH / 3, 13);
	cout << "-- BAT DAU vao luc :  ";
	gotoXY(WIDTH / 3 + 25, 13);
	cout<< tmBD.gio << "h" << tmBD.phut << "ph";
	gotoXY(WIDTH*4 / 7, 13);
	cout << "ngay " << tg.ngay_bd.d << '/' << tg.ngay_bd.m << '/' << tg.ngay_bd.y;
	gotoXY(WIDTH / 3, 15);
	cout << "-- KET THUC vao luc :  ";
	gotoXY(WIDTH / 3 + 25, 15);
	cout << tmKT.gio << "h" << tmKT.phut << "ph";
	gotoXY(WIDTH*4 / 7, 15);
	cout << "ngay " << tg.ngay_kt.d << '/' << tg.ngay_kt.m << '/' << tg.ngay_kt.y;
	return Ask_YN("Ban chac chan muon tao buoi DKKH nay ?");
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