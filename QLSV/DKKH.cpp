#include"DKKH.h"
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
int viewDKKH(NodeMon_Sv* A, int ki, NodeMon* head)
{
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
NodeMon_Sv* runDKKH(NodeMon_Sv* A, int ki, NodeMon* head)//node mon la ds mon dc mo, nodemonofsv la ds mon ma sv da dk
{
	int mon = viewDKKH(A, ki, head);
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
					system("cls");
					mon = viewDKKH(A, ki, head);
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
//GV
void taoDKKH()//tao cho nam nay
{

}
