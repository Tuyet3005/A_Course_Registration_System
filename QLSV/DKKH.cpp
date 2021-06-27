#include"DKKH.h"
//CON NHIEU CAI CHUA CODE XONG :'(
//SV
void xuatLC(int* kq, int n)
{
	cout << "Ban da chon " << n << " mon hoc co STT lan luot la: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << kq[i] << "    ";
	}
	cout << endl;
}
void changeLC(int* kq, int dem, int mon)
{
	char ask = 'Y';
	int lc;
	int re;
	do
	{
		cout << "Ban muon thay doi lua chon thu: ";
		cin >> lc;
		if (lc > 0 && lc <= dem)
			break;
		else
			cout << "Khong hop le... Hay nhap lai !" << endl;
	} while (true);
	//thay doi
	do
	{
		cout << "Ban muon chon mon co STT la: ";
		cin >> re;
		if (re > 0 && re <= mon)
			break;
		else
			cout << "Khong hop le... Hay nhap lai !" << endl;
	} while (true);
	kq[lc - 1] = re;
	xuatLC(kq, kq[0]);
}
int viewDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head)//return so mon
{
	system("cls");
	gotoXY(30, 1);
	int mon;// so mon dc mo
	cout << "DANG KI HOC PHAN" << endl << endl;
	//hien thi ds mon da dk mot hoc sinh
	viewMondaDk(A, ki);
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
//Xl trung buoi, Xl si so mon
bool checkBuoiHoc(NodeMon* mon)
{

}
bool checkSiSo()
{

}
NodeMon_Sv* runDKKH_Sv(NodeMon_Sv* A, int ki, NodeMon* head)//node mon la ds mon dc mo, nodemonofsv la ds mon ma sv da dk
{
	int mon = viewDKKH_Sv(A, ki, head);
	string s = "";
	char temp;
	int* kq = new int[6];//kq[0] so mon hoc da dang ki- là phan tu dau cua mang 
	kq[0] = 0;
	int x = whereX(), y = whereY();
	int key;
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
						y+=2;
						x = 0;
					}
					else
					{
						//check si so
						//check buoi hoc
						kq[kq[0]] = key;
						kq[0]++;
						s = "";
						y++;
						x = 0;
					}
					if (kq[0] == 5)//da dk du
					{
						cout << endl;
						xuatLC(kq, kq[0]);
						do
						{
							cout << "Ban co muon thay doi lua chon? Y/N?" << endl;
							cout << "Moi nhap: ";
							char t;
							cin >> t;
							if ('Y' == toupper(t))
							{
								changeLC(kq, kq[0],mon);
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
										if (check == 27) return 0;
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
				cout << "Ban that su muon thoat? Y/N?" << endl;
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
					kq[0] = 0;
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
				xuatLC(kq, kq[0]);
				char t;
				do
				{
					cout << "Ban co muon thay doi lua chon? Y/N?" << endl;
					cout << "Moi nhap: ";
					cin >> t;
					if ('Y' == toupper(t))
					{
						changeLC(kq, kq[0],mon);
					}
					else if ('N' == toupper(t))
					{
						cout << "Ban co muon tiep tuc dang ki mon? Y/N?" << endl;
						char ask;
						cin >> ask;
						if ('Y' == toupper(ask))
						{
							y = whereY();
							//x = 0;
							s = "";
							break;
						}
						else
						{
							cout << "Nhan ESC de thoat.";
							while (true)
							{
								int check;
								if (_kbhit())
								{
									check = _getch();
									if (check == 27) return 0;
								}
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
			else if (temp < 48 || temp>57)
			{
				cout << "Khong hop le... Moi nhap lai !" << endl;
				y ++;
				x = 0;
			}
			else
			{
				cout << temp;
				x++;
			}
		}
	}
	NodeMon_Sv* re = new NodeMon_Sv[kq[0]];
	NodeMon* giu;
	for (int i = 0; i < kq[0]; i++)
	{
		giu = head;
		for (int j = 1; j < kq[i + 1]; j++)
			giu = giu->pNext;
		re[i].mon = giu;
	}
	return re;
}
//Can tao  dau vao Sv sau do check xem Sv
void DKKH_Sv(NodeSv_Lop* sv,int ki)
{
	NodeMon_Sv* p = sv->headMon[ki-1];
	int dem = 1;
	for (; p != NULL; dem++)
	{
		p = p->pNext;
	}
	if (dem == 5)
	{
		//thong bao
	}
	//chon them mon
}
//GV
//check neu da ton tai 3 ki
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
	cout << "--Nhap lan luot ngay, thang bat dau " << endl;
	do
	{
		cout << "Hay nhap: " << endl;
		cin >> tg.ngay_bd.d >> tg.ngay_bd.m;//be careful
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		else if (NgayHopLe(tg.ngay_bd.d, tg.ngay_bd.m, nam))
		{
			break;
		}
	} while (true);
	Time tmBD, tmKT;
	tmBD.giay = tmKT.giay = 0;
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
	cout << "--Nhap lan luot ngay, thang ket thuc ";
	do
	{
		cout << "Hay nhap: " << endl;
		cin >> tg.ngay_kt.d >> tg.ngay_kt.m;//be careful
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			continue;
		}
		else if (NgayHopLe(tg.ngay_kt.d,tg.ngay_kt.m,nam))
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
	system("pause");
	askforsure(tg, tmBD, tmKT, nam);
}
void askforsure(ThoiGian& tg, Time& tmBD, Time& tmKT, int nam)
{
	system("cls");
	cout << "-------------------------TAO BUOI DANG KI KHOA HOC-------------------------" << endl << endl;
	cout << "Ban da tao buoi dang ki khoa hoc : " << endl;
	cout << "--Bat dau vao luc  :" << tmBD.gio << "h" << tmBD.phut << "ph  ngay " << tg.ngay_bd.d << "/" << tg.ngay_bd.m << endl;
	cout << "--Ket thuc vao luc :" << tmKT.gio << "h" << tmKT.phut << "ph  ngay " << tg.ngay_kt.d << "/" << tg.ngay_kt.m << endl;
	cout << endl;
	cout << "Nhan 1 de XAC NHAN, 2 de HUY";
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
			//ghi vao file
			xuatFile_DKKH(tg, tmBD, tmKT, nam);
		}
		else if (lc == 2)
		{
			cout << "Ban co chac chan HUY buoi hoc vua tao? Y/N?" << endl;
			int yn;
			do {
				cout << "Moi nhap: ";
				cin >> yn;//xu li y/n
				if ('Y' == toupper(yn))
					break;
				else
				{
					askforsure(tg,tmBD,tmKT,nam);
					break;
				}
			} while (true);
			break;
		}
	} while (true);
}
void xuatFile_DKKH(ThoiGian& tg, Time& tmBD, Time& tmKT, int nam)
{
	//Cau truc file
	//1/0: 1-co buoi dk khoa hoc, 0 nguoc lai
	//ngay-thang bd
	//tg bd
	//ngay-thang kt
	//tg kt
	ofstream fout;
	fout.open("DKKH.txt");
	fout << 1 << endl;
	fout << tg.ngay_bd.d << "," << tg.ngay_bd.m << endl;
	fout << tmBD.gio << "," << tmBD.phut << endl;
	fout << tg.ngay_kt.d << "," << tg.ngay_kt.m << endl;
	fout << tmKT.gio << "," << tmKT.phut << endl;
	fout.close();
}
//