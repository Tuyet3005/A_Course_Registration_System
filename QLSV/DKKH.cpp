#include"DKKH.h"
#include"begin.h"
#include<string>
#include<fstream>
//nho khoi tao nodemon_sv vs doc node mon
using namespace std;

//HAM THEM SV VAO MON HOC 
void ThemSvMon(NodeMon*& mon, NodeSv_Lop*& svLop, int hk)
{
	// cach lam:
	// ktra sv do co hoc mon nao trung gio voi mon nay ko <thong qua svLop->headMon[hk-1]
	// dong thoi, dem so nodeMonSv do da dk hoc trong hk (phai <5 moi dc them) <cho svLop->headMon[hk-1]->pNext den khi nao = NULL thi dung>
	// neu ok het thi tao nodeSvMon 
	// them nodeSvMon vua tao vao headSvMon cua nodeMon truyen vao 
}
//SV
bool readFileDKKH(ThoiGian& tg, Time& tmBD, Time& tmKT,int& ki,string& file)
{
	ifstream fin;
	fin.open("DKKH.txt");
	string s;
	//ngaybd
	if (!fin.good())
		return false;
	getline(fin,s, ',');
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
	getline(fin, file, ',');
	return true;
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
void xuatLC(NodeMon_Sv* A)
{
	cout << "Ban da chon cac mon hoc sau: " << endl;
	NodeMon_Sv* temp = A;
	for (int i = 1; temp!=NULL; i++)
	{
		cout << i  << ". " << temp->mon->data.tenMon << endl;
		temp = temp->pNext;
	}
	cout << endl;
}
void xoaLC(int dem, int mon, NodeMon_Sv*& A,NodeMon* head)
{
	char ask = 'Y';
	int lc;
	do
	{
		cout << "Ban muon xoa lua chon nao (nhap stt cua lua chon): ";
		cin >> lc;
		if (lc > 0 && lc <= dem)
			break;
		else
			cout << "Khong hop le... Hay nhap lai !" << endl;
	} while (true);
	//xoa node mon cu
	//xoanodemon_sv
	if (lc == 1)
		A = A->pNext;
	else
	{
		NodeMon_Sv* temp2 = A;
		for (int i = 1; i < lc - 1; i++)
			temp2 = temp2->pNext;
		temp2->pNext = temp2->pNext->pNext;
	}
	xuatLC(A);
}
int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head)//return so mon
{
	system("cls");
	gotoXY(30, 1);
	int mon;// so mon dc mo
	cout << "DANG KI HOC PHAN" << endl << endl;
	//hien thi ds mon da dk mot hoc sinh
	//viewMondaDk(A, ki);
	cout << endl;
	//hien thi ds mon duoc mo
	mon = viewDsMonHk(head, ki);
	cout << endl << endl;
	cout << "~ HUONG DAN ~" << endl;
	cout << "--Nhap STT mon hoc ban muon dang ki va nhan ENTER de nhap tiep " << endl;
	cout << "--Nhan phim ESC de thoat dang ki" << endl;
	cout << "--Ban duoc chon toi da 5 mon hoc" << endl;
	cout << "--Nhan phim R de nhap lai tu dau" << endl;
	cout << "--Nhan phim A de thay doi lua chon" << endl;
	cout << endl;
	cout << "  Hay nhap: " << endl;
	return mon;
}
bool BuoiHocHopLe(NodeMon* mon, NodeMon_Sv* dadk)//check siso, check mon da dk, check trung buoi hoc
{
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
void themMon(NodeMon_Sv*& A, int stt,NodeMon* head)//them dau
{
	NodeMon* temp = head;
	for (int i = 0; i < stt; i++)
	{
		temp = temp->pNext;		
	}
	//them mon vao ds mon cua hs
	NodeMon_Sv* nw = new NodeMon_Sv;
	nw->mon = temp;
	nw->pNext = A;
	A = nw;
	//tang si so
	temp->data.num_Sv++;
}
void runDKKH_Sv(NodeMon_Sv*& A, int ki, NodeMon* head)//node mon la ds mon dc mo, nodemonofsv la ds mon ma sv da dk
{
	int mon = viewDKKH_Sv(A, ki, head);
	string s = "";
	char temp;
	int x = whereX(), y = whereY();
	int key;
	NodeMon_Sv* pMon_Sv = A;
	NodeMon* pMon = head;
	int dem=1;
	if (A != NULL)//chua dk mon nao
	{
		NodeMon_Sv* t = A;
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
						pMon = head;
						for (int i = 1; i < key; i++)
							pMon = pMon->pNext;
						if (BuoiHocHopLe(pMon, pMon_Sv))
						{
							themMon(pMon_Sv, key, head);
							dem++;
						}
						s = "";
						y++;
						x = 0;
					}
					if (dem >= 5)//da dk du
					{
						cout << endl;
						xuatLC(A);
						do
						{
							cout << "Ban co muon xoa lua chon? Y/N?" << endl;
							cout << "Moi nhap: ";
							char t;
							cin >> t;
							if ('Y' == toupper(t))
							{
								xoaLC(dem, mon, A, head);
							}
							else if ('N' == toupper(t))
							{
								cout << "Nhan ESC de thoat.";
								while (true)
								{
									int check;
									if (_kbhit())
									{
										check = _getch();
										if (check == 27) return;
									}
								}
							}
							else
							{
								cout << endl;
								cout << "Lua chon khong hop le !!!" << endl;
							}
						} while (true);
					}
				}
			}
			else if (temp == 27)// nhan esc
			{
				cout << "Ban that su muon thoat DKKH? Y/N?" << endl;
				cout << "Hay nhap: ";
				char t;
				cin >> t;
				if ('Y' == toupper(t))
				{
					break;
				}
				else
					y += 2;
			}
			else if (temp == 8)
			{
				if (x != 0)
				{
					x--;
					gotoXY(x, y);
					cout << ' ';
					gotoXY(x, y);
				}
			}
			else if (toupper(temp) == 'R')//Nhap lai tu dau
			{
				cout << "Ban chac chan muon nhap lai tu dau? Y/N?" << endl;
				cout << "Hay nhap: ";
				char t;
				cin >> t;
				if ('Y' == toupper(t))
				{
					//nhap lai
					mon = viewDKKH_Sv(A, ki, head);
					dem = 0;
					x = whereX();
					y = whereY();
					s = "";
				}
				else
				{
					cout << endl << "Hay tiep tuc nhap~" << endl;
					y = whereY();
				}
			}
			else if (toupper(temp) == 'A')//Thay doi lua chon
			{
				xuatLC(A);
				char t;
				do
				{
					cout << "Ban co muon xoa lua chon? Y/N?" << endl;
					cout << "Moi nhap: ";
					cin >> t;
					if ('Y' == toupper(t))
					{
						xoaLC(dem, mon, A, head);
					}
					else if ('N' == toupper(t))
					{
						y = whereY();
						x = 0;
						s = "";
						break;
					}
					else
					{
						cout << endl;
						cout << "Lua chon khong hop le !!!" << endl;
					}
				} while (true);
			}
			else if (temp < 48 || temp>57)
			{
				cout << "Khong hop le... Moi nhap lai !" << endl;
				y+=2;
				x = 0;
			}
			else
			{
				cout << temp;
				x++;
			}
		}
	}
}
void DKKH_Sv(NodeMon_Sv*& A, NodeMon* head)
{
	ThoiGian tg;
	Time tmBD, tmKT;
	int ki;
	string file = "";
	if (readFileDKKH(tg, tmBD, tmKT, ki, file))
	{
		if (cobuoiDKKH(tg, tmBD, tmKT))
		{
			//doc file mon//k can dua vao cai head
			runDKKH_Sv(A, ki, head);
		}
		else
			cout << "Hien khong co buoi DKKH nao..." << endl;
	}
	else
		cout << "Khong mo duoc File !!!";

	system("pause");
}
//GV
void taoDKKH_Gv(int nam)//tao cho nam hien tai cho ca 4 nam
{
	cout << "-------------------------TAO BUOI DANG KI KHOA HOC-------------------------" << endl;
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
		else if (ki < -1 || ki>3)
		{
			continue;
		}
		else
			break;
	} while (true);
	ThoiGian tg;
	Time tmBD, tmKT;
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
	system("pause");
	system("cls");
	cout << "-------------------------TAO BUOI DANG KI KHOA HOC-------------------------" << endl;
	bool flag = importFilehayNhapTay();
	system("pause");
	system("cls");
	cout << "-------------------------TAO BUOI DANG KI KHOA HOC-------------------------" << endl;
	string file = "";
	if (flag)
	{
		cout << "File text luu cac mon theo dong co cau truc:" << endl;
		cout<< "id mon,ten mon,ten giao vien,so tin chi,ngay hoc 1,buoi hoc 1,ngay hoc 2,buoi hoc 2," << endl;
		ifstream f;
		do {
			cout << "Nhap duong dan: " << endl;
			cin.clear();
			cin.ignore();
			getline(cin, file,'\n');
			f.open(file);
			if (f.good())
			{
				f.close();
				break;
			}
			cout << "File loi... Hay nhap link khac !" << endl;
		} while (true);
		
	}
	else
	{
		//Nhap tay 
		//ghi vo file dat ten bat ki
		//roi doc nhu bth
	}
	if (askforsure(tg, tmBD, tmKT, ki))
		if (xuatFile_DKKH(tg, tmBD, tmKT, ki, file))
		{
			system("cls");
			cout << "TAO THANH CONG BUOI DANG KI KHOA HOC" << endl;
			return;
		}
	system("cls");
	cout << "TAO BUOI DANG KI KHOA HOC THAT BAI" << endl;
}
//true: file, false: nhap tay
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
bool xuatFile_DKKH(ThoiGian tg, Time tmBD, Time tmKT,int ki,string file)
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
		fout << file << "," << endl;
	}
	else
		return false;
	fout.close();
	return true;
}
