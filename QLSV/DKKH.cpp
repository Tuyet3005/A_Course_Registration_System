#include"DKKH.h"
#include"begin.h"
#include<string>
#include<fstream>
//nho khoi tao nodemon_sv vs doc node mon
using namespace std;


//SV
void readFileDKKH(ThoiGian& tg, Time& tmBD, Time& tmKT,int& ki)
{
	ifstream fin;
	fin.open("DKKH.txt");
	string s;
	//ngaybd
	if (!fin.is_open())
		throw 0;
	getline(fin,s, ',');
	if(sizeof(s)==0)//file trong
		throw - 1;
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
	getline(fin,s, ',');
	ki = stoi(s);
	fin.close();
}

bool sosanhNgayGio(Ngay tg1, Time t1,Ngay tg2,Time t2)//return true neu tg1 truoc hoac bang tg2, false neu nguoc lai
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

bool cobuoiDKKH(ThoiGian tg,Time tmBD,Time tmKT)//doc file DKKH.txt
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
	if (sosanhNgayGio(tg.ngay_bd, tmBD,Dnow,Tnow) && sosanhNgayGio(Dnow,Tnow,tg.ngay_kt, tmKT))
		return true;
	return false;
}

void xoaLC(int dem, int mon, int ki,NodeSv_Lop* A,NodeMon* head)
{
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
	if (lc == 1)
		A->headMon[ki-1] = A->headMon[ki-1]->pNext;
	else
	{
		NodeMon_Sv* temp2 = A->headMon[ki-1];
		for (int i = 1; i < lc-1; i++)
			temp2 = temp2->pNext;
		//xoa sv trong ds mon
		NodeSv_Mon* temp = temp2->pNext->svMon;
		if (temp->mssv == A->sv.id)
		{
			temp = temp->pNext;
		}
		else
		{
			while (temp->pNext->mssv != A->sv.id)
			{
				temp = temp->pNext;
			}
			temp->pNext = temp->pNext->pNext;
		}
		//xoa mon trong ds mon cua sv
		temp2->pNext = temp2->pNext->pNext;
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
	viewMondaDk(A, ki);
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
		return false;
	}
	NodeMon_Sv* pdadk = dadk;
	bool flag = true;
	while (pdadk != NULL)
	{
		//bh1
		if (pdadk->mon->data.bh1.thu == mon->data.bh1.thu && pdadk->mon->data.bh1.buoi == mon->data.bh1.buoi)
			flag = false;
		if (pdadk->mon->data.bh1.thu == mon->data.bh1.thu && pdadk->mon->data.bh2.buoi == mon->data.bh2.buoi)
			flag = false;
		if (pdadk->mon->data.bh2.thu == mon->data.bh2.thu && pdadk->mon->data.bh1.buoi == mon->data.bh1.buoi)
			flag = false;
		if (pdadk->mon->data.bh2.thu == mon->data.bh2.thu && pdadk->mon->data.bh2.buoi == mon->data.bh2.buoi)
			flag = false;
		pdadk = pdadk->pNext;
	}
	if(flag)
		return true;
	else {
		cout << "Mon hoc nay da trung voi lich hoc ma ban da dang ki truoc do... Hay chon mon khac !" << endl;
		return false;
	}
}

bool themMon(NodeSv_Lop* A,int ki, int stt,NodeMon* head)//them dau
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
	nw->pNext = A->headMon[ki-1];
	A->headMon[ki-1] = nw;
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

void runDKKH_Sv(NodeSv_Lop* A, int ki, NodeMon*& head)//node mon la ds mon dc mo, nodemonofsv la ds mon ma sv da dk
{
	int mon = viewDKKH_Sv(A->headMon[ki-1], ki, head);
	string s = "";
	char temp;
	int x = whereX(), y = whereY();
	int key;
	int dem=0;
	if (A != NULL)//da dk
	{
		NodeMon_Sv* t = A->headMon[ki-1];
		while (t != NULL)
		{
			dem++;
			t = t->pNext;
		}
	}
	while (true)
	{
		gotoXY(x, y);
		if (_kbhit())
		{
			temp = _getch();
			s += temp;
			if (temp == 13)//enter
			{
				if (s != "")
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
			}
			else if (temp == 27)// nhan esc
			{
				cout << "~ Ban that su muon thoat DKKH? Y/N?" << endl;
				char t;
				do {
					cout << "- Hay nhap: ";
					cin >> t;
					if ('Y' == toupper(t))
						return;
					else if ('N' == toupper(t))
						break;
					cout << "! Lua chon khong hop le" << endl;
				} while (true);
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
				cout << "~ Ban chac chan muon xoa tat ca cac mon da dang ki? Y/N?" << endl;
				cout << "- Hay nhap: ";
				char t;
				cin >> t;
				if ('Y' == toupper(t))
				{
					//nhap lai
					A->headMon[ki - 1] = NULL;
					dem = 0;
					s = "";
				}

			}
			else if (toupper(temp) == 'H')//xoa
			{
				xoaLC(dem, mon,ki, A, head);
			}
			else if (temp < 48 || temp>57)
			{
				cout << "Khong hop le... Moi nhap lai !" << endl;
			}
			else
			{
				cout << temp;
				x++;
				continue;
			}
			temp = _getch();
			viewDKKH_Sv(A->headMon[ki - 1], ki, head);
			x = whereX();
			y = whereY();
		}
	}
	
}////hien thi lai ds da dk

void DKKH_Sv(NodeNamHoc* HT,NodeSv_Lop*& A,int lc)
{
	ThoiGian tg;
	Time tmBD, tmKT;
	int ki;
	try {
		readFileDKKH(tg, tmBD, tmKT, ki);
		if (cobuoiDKKH(tg, tmBD, tmKT))
		{
			//doc file mon//k can dua vao cai head
			NodeMon* head = HT->data.hk[ki - 1].headMon;
			if (lc == 1)//view
			{
				system("cls");
				viewDsMonHk(head, ki);
				return;
			}
			runDKKH_Sv(A, ki, head);
		}
		else
			cout << "Hien khong co buoi DKKH nao..." << endl;
	}
	catch (int error)
	{
		if (error == 0)
			cout << "Khong mo duoc File !!!" << endl;
		else
			cout << "Hien khong co buoi DKKH nao..." << endl;
	}
	system("pause");
}


//GV
void taoDKKH_Gv(NodeNamHoc* H)//tao cho nam hien tai cho ca 4 nam///////chi tao 1 buoi cho 1 hoc ki duy nhat
{
	system("cls");
	cout << "----------------------------------TAO BUOI DANG KI KHOA HOC-------------------------------" << endl;
	cout << endl;
	cout << "~ HUONG DAN ~" << endl;
	cout << "--Ban chi co the tao buoi dang ki khoa hoc cho hoc ki chua bat dau cua nam hoc nay" << endl;
	cout << "--Ban chi co the tao MOT buoi dang ki khoa hoc cho MOT ki hoc" << endl;
	cout << "--Ban can TAO MOI hoc ki va CAP NHAT danh sach mon hoc truoc khi tao buoi dang ki khoa hoc" << endl << endl;
	cout << "Ban co that su muon tao buoi dang ki khoa hoc ? Y/N?" << endl;
	char check;
	cin.clear();
	do {
		cout << "Hay nhap: ";
		check = getchar();
		if (toupper(check) == 'Y')
			break;
		else if (toupper(check) == 'N')
			return;
	} while (true);
	system("cls");
	cout << "----------------------------------TAO BUOI DANG KI KHOA HOC-------------------------------" << endl;
	cout << endl;
	int ki;
	cout << "--Nhap ki hoc " << endl;
	do {
		cout << "Hay nhap: ";
		cin >> ki;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		else if (ki < 1 || ki>3)
		{
			continue;
		}
		else
			break;
	} while (true);
	//hk chua tao
	if (H->data.hk[ki - 1].tg.ngay_bd.d == NULL)////////////nguy hiem
	{
		cout << "! HOC KI NAY CHUA DUOC TAO " << endl;
		cout << "--Hay vao muc TAO MOI de tao hoc ki, sau do vao muc CAP NHAT de them mon hoc cho ki nay " << endl;
		system("pause");
		return;
	}
	//da co buoi dkkh cho ki nay
	ThoiGian tg;
	Time tmBD, tmKT;
	try {
		int File_Ki;
		string s;
		readFileDKKH(tg, tmBD, tmKT, File_Ki);
		if (File_Ki == ki)
		{
			cout << "! DA TAO BUOI DANG KI KHOA HOC CHO KI NAY " << endl;
			system("pause");
			return;
		}
	}
	catch (int error)
	{
		if (error == 0)//KO MO FILE DC
		{
			cout << "! KHONG THE KIEM TRA THAO TAC NAY.. QUAY LAI SAU" << endl;
			system("pause");
			return;
		}
		else if (error == -1)//file trong
		{
			//ko lam gi
		}
	}

	//
	system("cls");
	cout << "----------------------------------TAO BUOI DANG KI KHOA HOC-------------------------------" << endl;
	cout << endl;
	if (H->data.hk[ki - 1].headMon == NULL)//chua co mon nao
	{
		cout << "! CAC MON HOC CHO HOC KI NAY CHUA DUOC CAP NHAT " << endl;
		cout << "--Hay vao muc CAP NHAT de them mon hoc cho ki nay " << endl;
		system("pause");
		return;
	}

	//in ra tg hk va tg nam hoc
	ThoiGian tY = H->data.tg;
	ThoiGian tHK = H->data.hk[ki-1].tg;
	cout << "Thoi gian NAM HOC: " << tY.ngay_bd.d << '/' << tY.ngay_bd.m << '/' << tY.ngay_bd.y << " - " << tY.ngay_kt.d << '/' << tY.ngay_kt.m << '/' << tY.ngay_kt.y << endl;
	cout<<"Thoi gian HOC KI "<<ki<<": "<< tHK.ngay_bd.d << '/' << tHK.ngay_bd.m << '/' << tHK.ngay_bd.y << " - " << tHK.ngay_kt.d << '/' << tHK.ngay_kt.m << '/' << tHK.ngay_kt.y << endl;

	tmBD.giay = tmKT.giay = 0;
	do {
		cout << "--Nhap lan luot ngay, thang, nam bat dau cach nhau boi phim ENTER" << endl;
		do
		{
			cout << "Hay nhap: " << endl;
			cin >> tg.ngay_bd.d >> tg.ngay_bd.m >> tg.ngay_bd.y;//be careful
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				continue;
			}
			else if (NgayHopLe(tg.ngay_bd.d, tg.ngay_bd.m, tg.ngay_bd.y))
			{
				break;
			}
		} while (true);
		cout << "---Nhap lan luot gio, phut bat dau" << endl;
		do
		{
			cout << "Hay nhap: " << endl;
			cin >> tmBD.gio >> tmBD.phut;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				continue;
			}
			else if (GioHopLe(tmBD))
			{
				break;
			}
		} while (true);
		cout << "--Nhap lan luot ngay, thang, nam ket thuc " << endl;
		do
		{
			cout << "Hay nhap: " << endl;
			cin >> tg.ngay_kt.d >> tg.ngay_kt.m >> tg.ngay_kt.y;//be careful
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				continue;
			}
			else if (NgayHopLe(tg.ngay_kt.d, tg.ngay_kt.m, tg.ngay_kt.y))
			{
				break;
			}
		} while (true);
		cout << "---Nhap lan luot gio, phut ket thuc " << endl;
		do
		{
			cout << "Hay nhap: " << endl;
			cin >> tmKT.gio >> tmKT.phut;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				continue;
			}
			else if (GioHopLe(tmKT))
			{
				break;
			}
		} while (true);
		if (sosanhNgayGio(tg.ngay_bd, tmBD, tg.ngay_kt, tmKT))//ss tg bd vs tg kt
		{
			//ss tg hien tai vs tgbdfnơ
			tm now = ThoiGianHeThong();
			Ngay Dnow;
			Dnow.d = now.tm_mday;
			Dnow.m = now.tm_mon + 1;
			Dnow.y = now.tm_year;
			Time Tnow;
			Tnow.gio = now.tm_hour;
			Tnow.phut = now.tm_min;
			if(sosanhNgayGio(Dnow,Tnow,tg.ngay_bd,tmBD))
				break;
		}
		cout << "Ngay bat dau va ket thuc khong hop le... Hay nhap lai !" << endl;
	} while (true);
	//tg k phu hop voi hoc ki: sau tg bd nam hoc, trc tg bd hoc ki
	if (!sosanhNgay(tY.ngay_bd, tg.ngay_bd) || sosanhNgay(tHK.ngay_bd, tg.ngay_kt))
	{
		cout << "! TAO BUOI DANG KI KHOA HOC KHONG THANH CONG !" << endl;
		cout << "--Ban chi duoc tao buoi dang ki khoa hoc cho nam hoc nay" << endl;
		cout << "--Thoi gian cua buoi dang ki phai xay ra giua 2 moc thoi gian:" << endl;
		cout << "   +Thoi gian bat dau nam hoc" << endl;
		cout << "   +Thoi gian bat dau hoc ki" << endl;
		system("pause");
		return;
	}
	system("pause");
	if (askforsure(tg, tmBD, tmKT, ki))
		if (xuatFile_DKKH(tg, tmBD, tmKT, ki))
		{
			system("cls");
			cout << "~ TAO THANH CONG BUOI DANG KI KHOA HOC ~" << endl;
			return;
		}
	system("cls");
	cout << "! TAO BUOI DANG KI KHOA HOC THAT BAI !" << endl << endl;
	system("pause");
	system("cls");
}

bool askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT,int ki)
{
	system("cls");
	cout << "-------------------------TAO BUOI DANG KI KHOA HOC-------------------------" << endl << endl;
	cout << "Ban da tao buoi dang ki khoa hoc ki "<<ki<<": " << endl;
	cout << "--Bat dau vao luc  :  " << tmBD.gio << "h" << tmBD.phut << "ph  ngay " << tg.ngay_bd.d << "/" << tg.ngay_bd.m << endl;
	cout << "--Ket thuc vao luc :  " << tmKT.gio << "h" << tmKT.phut << "ph  ngay " << tg.ngay_kt.d << "/" << tg.ngay_kt.m << endl;
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
		else if (lc==1)
		{
			return true;
		}
		else if (lc == 2)
		{
			cout << "Ban co chac chan HUY buoi hoc vua tao? Y/N?" << endl;
			int yn;
			do {
				cout << "Moi nhap: ";
				cin.clear();
				cin.ignore();
				cin >> yn;//xu li y/n
				if ('Y' == toupper(yn))
					return false;
				else
				{
					return askforsure(tg,tmBD,tmKT,ki);
				}
			} while (true);
			break;
		}
	} while (true);
}

bool xuatFile_DKKH(ThoiGian tg, Time tmBD, Time tmKT,int ki)
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

//sua lai buoi dkkh