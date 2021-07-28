#include"display.h"
#include"student.h"
#include"console.h"
#include<conio.h>

void drawTable(int Row, int Col, int posCol[], int posRow)//posRow la hang bat dau ke bang
{
	//stt-mssv-ho-ten--gioitinh-ngaysinh-cmnd
	short a, b, c;
	for (int i = 0; i <= Row; i++)
	{
		if (i == 0)
		{
			a = 218;
			b = 194;
			c = 191;
		}
		else if (i == Row)
		{
			a = 192;
			b = 193;
			c = 217;
			gotoXY(posCol[0], posRow + 2 * Row);
			cout << char(a);
			for (int j = 0; j < Col - 1; j++)
			{
				for (int t = 0; t < posCol[j + 1] - posCol[j] - 1; t++) cout << char(196);
				cout << char(b);
			}
			for (int t = 0; t < posCol[Col] - posCol[Col - 1] - 1; t++) cout << char(196);
			cout << char(c);
			break;
		}
		else if (i == 1)
		{
			a = 195;
			b = 197;
			c = 180;
		}
		else
		{
		}
		//ve bien
		gotoXY(posCol[0], posRow + 2 * i);
		cout << char(a);
		for (int j = 0; j < Col - 1; j++)
		{
			for (int t = 0; t < posCol[j + 1] - posCol[j] - 1; t++) cout << char(196);
			cout << char(b);
		}
		for (int t = 0; t < posCol[Col] - posCol[Col - 1] - 1; t++) cout << char(196);
		cout << char(c);
		//ve hang de dien thong tin
		for (int j = 0; j < Col + 1; j++)
		{
			gotoXY(posCol[j], posRow + 1 + 2 * i);
			cout << char(179);
		}
	}
	cout << endl;
}

int viewDsSvLop(NodeLop* A)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ DANH SACH LOP ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence(A->lop.ten, 3);
	gotoXY(10, 6);
	if (A->lop.headSvLop == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Hien chua cap nhat du lieu...", whereY());
		return 0;
	}
	int posRow = whereY();
	string title[] = { "STT","MSSV","HO","TEN","GIOI TINH","NGAY SINH","CMND" };
	int posCol[8] = { 0,6,17,43,55,67,81,96 };
	int space = WIDTH / 2 - posCol[7] / 2;
	for (int j = 0; j < 7; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[7] += space;
	cout.clear();
	NodeSv_Lop* p = A->lop.headSvLop;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << p->sv.stt;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->sv.id;
		gotoXY(posCol[2] + 2, posRow + 1 + 2 * i);
		cout << p->sv.ho;
		gotoXY(posCol[3] + 2, posRow + 1 + 2 * i);
		cout << p->sv.ten;
		gotoXY(posCol[4] + 2, posRow + 1 + 2 * i);
		cout << p->sv.gioi;
		gotoXY(posCol[5] + 2, posRow + 1 + 2 * i);
		cout << p->sv.ngayS.d << "/" << p->sv.ngayS.m << "/" << p->sv.ngayS.y;
		gotoXY(posCol[6] + 2, posRow + 1 + 2 * i);
		cout << p->sv.cmnd;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 7, posCol, posRow);
	return i - 1;
}

void BackGround()
{
	system("cls");
	cout << endl;
	cout << "Welcome to..." << endl << endl << endl;
	cout << "            XXXX                       XXXX                 XXXX            XXXX            XXXX           " << endl;
	cout << "       XXX         XX              XXX        XX            XXX  XXX    XXX  XXX        XXX        XX       " << endl;
	cout << "    XXX                            XXX                      XXX      XXX     XXX        XXX                " << endl;
	cout << "  XXX                                   XXX                 XXX       X      XXX              XXX           " << endl;
	cout << "  XXX                                          XXX          XXX              XXX                    XXX     " << endl;
	cout << "    XXX                XX        XX             XXX         XXX              XXX        XX            XXX    " << endl;
	cout << "        XXX        XXX            XXX         XXX           XXX              XXX          XXX        XXX     " << endl;
	cout << "             XXXX                      XXXX                 XXX              XXX              XXXX         " << endl;
	cout << endl;
	cout << "                                     Course & Student Management System";
	gotoXY(0, 15);
}

int viewDsMonHk(NodeMon* head, int ki)//đưa dô head moon của struct hk
{
	int nam = NHhientai_nambd();
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ DANH SACH MON ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence("Ki " + to_string(ki) + "    Nam hoc : " + to_string(nam) + " - " + to_string(nam + 1), 3);
	gotoXY(10, 6);
	if (head == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Hien chua cap nhat du lieu...", whereY());
		return 0;
	}
	string title[] = { "STT", "ID","TEN MON HOC","TEN GIANG VIEN","SO TIN CHI","SO SV TOI DA","LICH HOC" };
	int posRow = whereY();
	int posCol[8] = { 0,6,15,45,75,90,105,140 };
	int space = WIDTH / 2 - posCol[7] / 2;
	for (int j = 0; j < 7; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[7] += space;
	cout.clear();
	NodeMon* p = head;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->data.id;
		gotoXY(posCol[2] + 2, posRow + 1 + 2 * i);
		cout << p->data.tenMon;
		gotoXY(posCol[3] + 2, posRow + 1 + 2 * i);
		cout << p->data.tenGv;
		gotoXY(posCol[4] + 2, posRow + 1 + 2 * i);
		cout << p->data.so_tc;
		gotoXY(posCol[5] + 2, posRow + 1 + 2 * i);
		cout << p->data.MaxSv;
		gotoXY(posCol[6] + 2, posRow + 1 + 2 * i);
		cout << p->data.bh1.buoi << "-" << p->data.bh1.thu << ", " << p->data.bh2.buoi << "-" << p->data.bh2.thu;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 7, posCol, posRow);
	return i - 1;
}

int viewDsSvMon(NodeMon* A)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ DANH SACH SINH VIEN MON ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence(A->data.tenMon, 3);
	gotoXY(10, 6);
	if (A->headSvMon == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Danh sach sinh vien dang trong...", whereY());
		return 0;
	}
	string title[] = { "STT","MSSV","HO","TEN","GK","CK","CONG","TONG KET" };
	int posRow = whereY();
	int posCol[9] = { 0,6,17,43,55,65,75,85,100 };
	int space = WIDTH / 2 - posCol[8] / 2;
	for (int j = 0; j < 8; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[8] += space;
	cout.clear();
	NodeSv_Mon* p = A->headSvMon;
	int i = 1;
	for (; p != NULL; i++)
	{
		Sv s = findInfo(p->lop, p->mssv);
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << s.stt;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << s.id;
		gotoXY(posCol[2] + 2, posRow + 1 + 2 * i);
		cout << s.ho;
		gotoXY(posCol[3] + 2, posRow + 1 + 2 * i);
		cout << s.ten;
		gotoXY(posCol[4] + 2, posRow + 1 + 2 * i);
		cout << p->diem.gk;
		gotoXY(posCol[5] + 2, posRow + 1 + 2 * i);
		cout << p->diem.ck;
		gotoXY(posCol[6] + 2, posRow + 1 + 2 * i);
		cout << p->diem.cong;
		gotoXY(posCol[7] + 2, posRow + 1 + 2 * i);
		cout << p->diem.tongket;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 8, posCol, posRow);
	return i - 1;
}

int viewDsKi(NodeNamHoc* A)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ DANH SACH KI ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence("Nam hoc: " + to_string(A->data.tg.ngay_bd.y) + " - " + to_string(A->data.tg.ngay_bd.y + 1), 3);
	gotoXY(10, 6);
	if (A->data.hk[0].tg.ngay_bd.d == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Hien chua co ki hoc nao duoc tao...", whereY());
		return 0;
	}
	string title[] = { "KI","THOI GIAN" };
	int posRow = whereY();
	int posCol[3] = { 0,5,35 };
	int space = WIDTH / 2 - posCol[2] / 2;
	for (int j = 0; j < 2; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[2] += space;
	cout.clear();
	int i = 0;
	for (; A->data.hk[i].tg.ngay_bd.d != NULL && i < 3; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 3 + 2 * i);
		cout << i + 1;
		gotoXY(posCol[1] + 2, posRow + 3 + 2 * i);
		cout << A->data.hk[i].tg.ngay_bd.d << "/" << A->data.hk[i].tg.ngay_bd.m << "/" << A->data.hk[i].tg.ngay_bd.y << " - " << A->data.hk[i].tg.ngay_kt.d << "/" << A->data.hk[i].tg.ngay_kt.m << "/" << A->data.hk[i].tg.ngay_kt.y;
	}
	gotoXY(0, posRow);
	drawTable(i + 1, 2, posCol, posRow);
	return i;
}

int viewDsNam(ListNamHoc A)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ DANH SACH NAM HOC ~", 2);
	setColor(background_color, title_color1);
	gotoXY(10, 6);
	if (A.pHead == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Hien chua cap nhat du lieu...", whereY());
		return 0;
	}
	string title[] = { "STT","NAM HOC" };
	int posRow = whereY();
	int posCol[3] = { 0,6,25 };
	int space = WIDTH / 2 - posCol[2] / 2;
	for (int j = 0; j < 2; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[2] += space;
	cout.clear();
	NodeNamHoc* p = A.pHead;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->data.tg.ngay_bd.y << " - " << p->data.tg.ngay_kt.y;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 2, posCol, posRow);
	return i - 1;
}

int viewDsLop(NodeLop* head)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ DANH SACH LOP HOC ~", 2);
	setColor(background_color, title_color1);
	int nam = NHhientai_nambd();
	printA_Sentence("Nam hoc : " + to_string(nam) + " - " + to_string(nam + 1), 3);
	gotoXY(10, 6);
	if (head == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Hien chua cap nhat du lieu...", whereY());
		return 0;
	}
	string title[] = { "STT","TEN LOP" };
	int posRow = whereY();
	int posCol[3] = { 0,6,20 };
	int space = WIDTH / 2 - posCol[2] / 2;
	for (int j = 0; j < 2; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[2] += space;
	cout.clear();
	NodeLop* p = head;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->lop.ten;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 2, posCol, posRow);
	return i - 1;
}

int viewSvScore(NodeSv_Lop* sv, int ki)//xem diem theo tung hoc ki
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ KET QUA HOC TAP ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence("Hoc ki : " + to_string(ki), 3);
	gotoXY(10, 6);
	if (sv->headMon[ki - 1] == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Ban chua dang ki mon hoc nao...", whereY());
		return 0;
	}
	NodeMon_Sv* p = sv->headMon[ki - 1];
	string title[] = { "STT","ID MON","TEN MON","GK","CK","CONG","TONG KET" };
	int posRow = whereY();
	int posCol[] = { 0,6,16,46,53,60,69,82 };
	int space = WIDTH / 2 - posCol[7] / 2;
	for (int j = 0; j < 7; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[7] += space;
	cout.clear();
	int i = 1;
	for (; p != NULL; i++)
	{
		//tim node svmon
		NodeSv_Mon* temp = p->mon->headSvMon;
		while (temp != NULL)
		{
			if (temp->mssv == sv->sv.id)
				break;
			temp = temp->pNext;
		}
		//
		gotoXY(posCol[0], posRow + 1 + 2 * i);
		cout << i;
		gotoXY(posCol[1], posRow + 1 + 2 * i);
		cout << p->mon->data.id;
		gotoXY(posCol[2], posRow + 1 + 2 * i);
		cout << p->mon->data.tenMon;
		gotoXY(posCol[3], posRow + 1 + 2 * i);
		cout << temp->diem.gk;
		gotoXY(posCol[4], posRow + 1 + 2 * i);
		cout << temp->diem.ck;
		gotoXY(posCol[5], posRow + 1 + 2 * i);
		cout << temp->diem.cong;
		gotoXY(posCol[6], posRow + 1 + 2 * i);
		cout << temp->diem.tongket;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 7, posCol, posRow);
	return i - 1;
}

void viewInfoSv(Sv A)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ THONG TIN CA NHAN ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence("SINH VIEN", 3);
	gotoXY(10, 6);
	string title[] = { "STT","MSSV","HO","TEN","GIOI TINH","NGAY SINH","CMND" };
	int posRow = whereY();
	int posCol[8] = { 0,6,17,43,55,67,85,98 };
	int space = WIDTH / 2 - posCol[7] / 2;
	setColor(background_color, title_color1);
	for (int j = 0; j < 7; j++)//ghi title
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[7] += space;
	cout.clear();
	gotoXY(posCol[0] + 2, posRow + 3);
	cout << A.stt;
	gotoXY(posCol[1] + 2, posRow + 3);
	cout << A.id;
	gotoXY(posCol[2] + 2, posRow + 3);
	cout << A.ho;
	gotoXY(posCol[3] + 2, posRow + 3);
	cout << A.ten;
	gotoXY(posCol[4] + 2, posRow + 3);
	cout << A.gioi;
	gotoXY(posCol[5] + 2, posRow + 3);
	cout << A.ngayS.d << "/" << A.ngayS.m << "/" << A.ngayS.y;
	gotoXY(posCol[6] + 2, posRow + 3);
	cout << A.cmnd;
	gotoXY(0, posRow);
	drawTable(2, 7, posCol, posRow);
	system("pause");
}

int viewMondaDk(NodeMon_Sv* A, int ki, int line)//show thong tin mon hoc cua 1 sv
{
	setColor(background_color, title_color);
	printA_Sentence("~ KET QUA DANG KI HOC PHAN ~", line);
	setColor(background_color, title_color1);
	printA_Sentence("Hoc ki : " + to_string(ki), line + 1);
	gotoXY(10, line + 2);
	if (A == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Ban chua dang ki mon nao...", whereY());
		return 0;
	}
	int posRow = whereY();
	string title[] = { "STT","ID","TEN MON HOC","TEN GIANG VIEN","SO TIN CHI","SO SV TOI DA","LICH HOC" };
	int posCol[8] = { 0,6,15,45,75,90,105,150 };
	int space = WIDTH / 2 - posCol[7] / 2;
	for (int j = 0; j < 7; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[7] += space;
	cout.clear();
	NodeMon_Sv* p = A;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.id;
		gotoXY(posCol[2] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.tenMon;
		gotoXY(posCol[3] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.tenGv;
		gotoXY(posCol[4] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.so_tc;
		gotoXY(posCol[5] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.MaxSv;
		gotoXY(posCol[6] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.bh1.buoi << "-" << p->mon->data.bh1.thu << ", " << p->mon->data.bh2.buoi << "-" << p->mon->data.bh2.thu;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 7, posCol, posRow);
	return i - 1;
}

int viewDiem_Lop(NodeLop* A, int ki)
{
	//TINH GPA
	bool flag = tinhGPA_SvvaLop(A, ki);
	//
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ KET QUA HOC TAP ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence("Hoc ki : " + to_string(ki), 3);
	printA_Sentence("Lop : " + A->lop.ten, 4);
	gotoXY(10, 6);
	if (A->lop.headSvLop == NULL)
	{
		setColor(background_color, text_color);
		printA_Sentence("Hien chua cap nhat du lieu...", whereY());
		return 0;
	}
	string title[] = { "STT","MSSV","HO","TEN","ID MON","TK","ID MON","TK","ID MON","TK","ID MON","TK","ID MON","TK","GPA" };
	int posRow = whereY();
	int posCol[16] = { 0,6,17,43,55,65,70,80,85,95,100,110,115,125,130,140 };
	int space = WIDTH / 2 - posCol[15] / 2;
	for (int j = 0; j < 15; j++)
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 1, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[15] += space;
	cout.clear();
	NodeSv_Lop* pSv = A->lop.headSvLop;
	NodeMon_Sv* pMon;
	int i = 1;
	int j;
	for (; pSv != NULL; i++)
	{
		pMon = pSv->headMon[ki - 1];
		//
		gotoXY(posCol[0] + 1, posRow + 1 + 2 * i);
		cout << pSv->sv.stt;
		gotoXY(posCol[1] + 1, posRow + 1 + 2 * i);
		cout << pSv->sv.id;
		gotoXY(posCol[2] + 1, posRow + 1 + 2 * i);
		cout << pSv->sv.ho;
		gotoXY(posCol[3] + 1, posRow + 1 + 2 * i);
		cout << pSv->sv.ten;
		j = 4;
		for (; j <= 4 + 10 && pMon != NULL; j += 2)
		{
			gotoXY(posCol[j] + 1, posRow + 1 + 2 * i);
			cout << pMon->mon->data.id;
			gotoXY(posCol[j + 1] + 1, posRow + 1 + 2 * i);
			cout << pMon->svMon->diem.tongket;
			pMon = pMon->pNext;
		}
		gotoXY(posCol[j] + 1, posRow + 1 + 2 * i);
		cout << pSv->GPA[ki - 1];
		pSv = pSv->pNext;
	}
	gotoXY(posCol[10], posRow + i * 2 + 2);
	cout << "Trung binh GPA: ";
	gotoXY(posCol[14] + 1, posRow + i * 2 + 2);
	if (flag)
		cout << A->lop.GPA;
	else
		cout << 0;
	gotoXY(0, posRow);
	drawTable(i, 15, posCol, posRow);
	gotoXY(0, posRow + i * 2 + 4);
	return i - 1;
}

//TINH GPA //co bug nhung chua fix
bool tinhGPA_SvvaLop(NodeLop* t, int ki)
{
	NodeSv_Lop* pSv = t->lop.headSvLop;
	NodeMon_Sv* pMon;
	float sum;
	int tin;
	//lop
	int dem = 0;
	int sumlop = 0;
	while (pSv != NULL)
	{
		if (pSv->headMon[ki - 1] == NULL)
		{
			pSv = pSv->pNext;
			continue;
		}
		pMon = pSv->headMon[ki - 1];
		sum = 0;
		tin = 0;
		while (pMon != NULL)
		{
			if (!pMon->svMon->diem.tongket)
				break;
			else
			{
				tin += pMon->mon->data.so_tc;
				sum += pMon->svMon->diem.tongket;
			}
			pMon = pMon->pNext;
		}
		if (pMon == NULL)//co diem tk
		{
			pSv->GPA[ki - 1] = sum / tin;
			sumlop += pSv->GPA[ki - 1];
			dem++;
		}
		else {
			return false;//chua cap nhat du gpa
		}
		pSv = pSv->pNext;
	}
	if (dem == 0)//chua co hs nao dk mon hoc
		return false;
	t->lop.GPA[ki - 1] = sumlop / dem;
	return true;
}

//TTGV
void viewInfoGV(Sv A)
{
	system("cls");
	setColor(background_color, title_color);
	printA_Sentence("~ THONG TIN CA NHAN ~", 2);
	setColor(background_color, title_color1);
	printA_Sentence("GIAO VU", 3);
	gotoXY(10, 6);
	string title[] = { "HO","TEN","GIOI TINH","NGAY SINH","CMND" };
	int posRow = whereY();
	int posCol[6] = { 0,26,38,50,68,80 };
	int space = WIDTH / 2 - posCol[5] / 2;
	for (int j = 0; j < 5; j++)//ghi title
	{
		posCol[j] += space;
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	setColor(background_color, text_color);
	posCol[5] += space;
	cout.clear();
	gotoXY(posCol[0] + 2, posRow + 3);
	cout << A.ho;
	gotoXY(posCol[1] + 2, posRow + 3);
	cout << A.ten;
	gotoXY(posCol[2] + 2, posRow + 3);
	cout << A.gioi;
	gotoXY(posCol[3] + 2, posRow + 3);
	cout << A.ngayS.d << "/" << A.ngayS.m << "/" << A.ngayS.y;
	gotoXY(posCol[4] + 2, posRow + 3);
	cout << A.cmnd;
	gotoXY(0, posRow);
	drawTable(2, 5, posCol, posRow);
	system("pause");
}

//HIEN THI
void background()
{
	cout << "Chao mung ban den voi he thong quan li sinh vien...";
	gotoXY(0, 6);
	setColor(background_color, title_color);
	cout << "                                              XXXX                       XXXX                 XXXX            XXXX            XXXX         " << endl;
	cout << "                                         XXX         XX              XXX        XX            XXX  XXX    XXX  XXX        XXX        XX    " << endl;
	cout << "                                      XXX                            XXX                      XXX      XXX     XXX        XXX              " << endl;
	cout << "                                    XXX                                   XXX                 XXX       X      XXX              XXX        " << endl;
	cout << "                                    XXX                                          XXX          XXX              XXX                    XXX  " << endl;
	cout << "                                      XXX                XX        XX              XXX        XXX              XXX        XX            XXX" << endl;
	cout << "                                          XXX        XXX            XXX          XXX          XXX              XXX          XXX        XXX " << endl;
	cout << "                                               XXXX                       XXXX                XXX              XXX              XXXX       " << endl;
	setColor(background_color, text_color);
	cout << endl;
	cout << "                                                                     Course & Student Management System";

}

void background_Sv()
{
	setColor(background_color, title_color);
	gotoXY(0, 6);
	cout << "                                      xxxxx     xx  xxxxx       xx   xxx       xx         xxx             xx   xx   xxxxxxxxxx  xxxxx       xx" << endl;
	cout << "                                   xxx     xx   xx  xxx xx      xx   xxx       xx          xxx           xx    xx   xxx         xxx xx      xx" << endl;
	cout << "                                  xxx           xx  xxx  xx     xx   xxx       xx           xxx         xx     xx   xxx         xxx  xx     xx" << endl;
	cout << "                                     xxxx       xx  xxx   xx    xx   xxx       xx            xxx       xx      xx   xxxxxx      xxx   xx    xx" << endl;
	cout << "                                         xxxx   xx  xxx    xx   xx   xxxxxxxxxxxx             xxx     xx       xx   xxxxxx      xxx    xx   xx" << endl;
	cout << "                                 xx         xxx xx  xxx     xx  xx   xxxxxxxxxxxx              xxx   xx        xx   xxx         xxx     xx  xx" << endl;
	cout << "                                  xxx      xxx  xx  xxx      xx xx   xxx       xx               xxx xx         xx   xxx         xxx      xx xx" << endl;
	cout << "                                      xxxx      xx  xxx       xxxx   xxx       xx                xxxx          xx   xxxxxxxxxxx xxx       xxxx" << endl;
	cout << endl << endl;
	setColor(background_color, text_color);
}

void background_Gv()
{
	setColor(background_color, title_color);
	gotoXY(0, 6);
	cout << "                                           xxxxx       xx         xxxx               xxxxx              xxx             xx  xxx          xx" << endl;
	cout << "                                        xxx      xx    xx        xxx xx          xxx        xx           xxx           xx   xxx          xx" << endl;
	cout << "                                      xxx              xx       xxx   xx       xxx            xx          xxx         xx    xxx          xx" << endl;
	cout << "                                     xxx               xx      xxx     xx     xxx              xx          xxx       xx     xxx          xx" << endl;
	cout << "                                     xxx         xxxxx xx     xxxxxxxxxxxx    xxx              xx           xxx     xx      xxx          xx" << endl;
	cout << "                                      xxx         xxx  xx    xxxxxxxxxxxxxx    xxx            xx             xxx   xx       xxx          xx" << endl;
	cout << "                                        xxx    xxxxxx  xx   xxx           xx      xxx      xx                 xxx xx         xxxx       xx " << endl;
	cout << "                                           xxxxx  xxx  xx  xxx             xx         xxxxx                    xxxx            xxxxxxxxx   " << endl;
	setColor(background_color, text_color);
	cout << endl << endl;
}

void background_Login()
{
	setColor(background_color, title_color);
	gotoXY(0, 7);
	cout << "                       xxxxxxxx             xxxx         xxxxx       xx         xxx            xxxx        xx  xxx        xx        xxxx         xxxxxxxx    " << endl;
	cout << "                       xxx     xxx         xxx xx        xxx xx      xx     xxx    xx          xxx xx      xx  xxx        xx       xxx xx        xxx    xxx  " << endl;
	cout << "                       xxx       xx       xxx   xx       xxx  xx     xx   xxx                  xxx  xx     xx  xxx        xx      xxx   xx       xxx      xx " << endl;
	cout << "                       xxx        xx     xxxxxxxxxx      xxx   xx    xx  xxx                   xxx   xx    xx  xxxxxxxxxxxxx     xxxxxxxxxx      xxx    xxx  " << endl;
	cout << "                       xxx        xx    xxxxxxxxxxxx     xxx    xx   xx  xxx     xxxxxx        xxx    xx   xx  xxxxxxxxxxxxx    xxxxxxxxxxxx     xxxxxxx     " << endl;
	cout << "                       xxx       xx    xxx         xx    xxx     xx  xx   xxx       xxx        xxx     xx  xx  xxx        xx   xxx         xx    xxx         " << endl;
	cout << "                       xxx     xxx    xxx           xx   xxx      xx xx     xxx    xxxx        xxx      xx xx  xxx        xx  xxx           xx   xxx         " << endl;
	cout << "                       xxxxxxxx      xxx             xx  xxx       xxxx       xxxxx xxx        xxx        xxx  xxx        xx xxx             xx  xxx         " << endl;
	setColor(background_color, text_color);
	cout << endl << endl;
}

void veHCN(int bd_x, int bd_y, int kt_x, int kt_y)
{
	setColor(background_color, title_color1);
	gotoXY(bd_x, bd_y);
	cout << (char)218;
	for (int i = 1; i < kt_x - bd_x; i++)
		cout << (char)196;
	cout << (char)191;
	for (int i = 1; i < kt_y - bd_y; i++)
	{
		gotoXY(bd_x, bd_y + i);
		cout << (char)179;
		gotoXY(kt_x, bd_y + i);
		cout << (char)179;
	}
	gotoXY(bd_x, kt_y);
	cout << (char)192;
	for (int i = 1; i < kt_x - bd_x; i++)
		cout << (char)196;
	cout << (char)217;
	setColor(background_color, text_color);
}

int LuaChon_Menu(int title_number, string title[], int cell_height, int line)
{
	int* pos_x = new int[title_number];
	for (int i = 0; i < title_number; i++)
		pos_x[i] = WIDTH / 2 - title[i].length() / 2;
	int bd_x, bd_y, kt_x, kt_y;
	bd_x = WIDTH / 2 - cell_width / 2;
	bd_y = line + ((title_number == 7) ? (-5) : 0);
	kt_x = bd_x + cell_width;
	kt_y = bd_y + cell_height;
	for (int i = 0; i < title_number; i++)
	{
		veHCN(bd_x, bd_y + i * (cell_height + 2), kt_x, kt_y + i * (cell_height + 2));
		gotoXY(pos_x[i], bd_y + i * (cell_height + 2) + cell_height / 2);
		cout << title[i];
	}
	//chon
	int lc = 0;
	int temp = 0;
	gotoXY(pos_x[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
	setColor(background_color, title_color1);
	cout << title[lc];
	setColor(background_color, text_color);
	while (temp != 13)//ko enter
	{
		if (_kbhit())
		{
			temp = _getch();
			if (temp == 72)//len
			{
				gotoXY(pos_x[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				cout << title[lc];
				if (lc == 0)
					lc = title_number - 1;
				else
					lc--;
				gotoXY(pos_x[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				setColor(background_color, title_color1);
				cout << title[lc];
				setColor(background_color, text_color);
				//mau
			}
			else if (temp == 80)//xuong
			{
				gotoXY(pos_x[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				cout << title[lc];
				if (lc == title_number - 1)
					lc = 0;
				else
					lc++;
				gotoXY(pos_x[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				setColor(background_color, title_color1);
				cout << title[lc];
				setColor(background_color, text_color);
			}
		}
	}
	return lc + 1;
}

int LuaChon_HienThi(int line, int max)
{
	line++;
	int bd_x, bd_y, kt_x, kt_y;
	int Cell_width = 22;
	int cell_height = 2;
	bd_x = WIDTH / 2 - Cell_width / 2;
	bd_y = line + 4;
	kt_x = bd_x + Cell_width;
	kt_y = bd_y + cell_height;
	string title[2] = { "QUAY VE","THOAT" };
	for (int i = 0; i < 2; i++)
	{
		veHCN(bd_x, bd_y + i * (cell_height + 2), kt_x, kt_y + i * (cell_height + 2));
		printA_Sentence(title[i], bd_y + i * (cell_height + 2) + cell_height / 2);
	}
	setColor(background_color, title_color1);
	printA_Sentence("Nhap lua chon (STT)", line);
	setColor(background_color, text_color);
	printA_Sentence("_________________________", line + 1);
	gotoXY(WIDTH / 2, line + 2);
	char temp;
	char lc = -1;
	string s = "";
	setColor(background_color, text_color);
	char key;
	while (true)//ko enter
	{
		if (_kbhit())
		{
			temp = _getch();
			//neu enter
			if (temp == 13)
			{
				if (lc == -1)
				{
					if (s.length() == 0)
						continue;
					else
					{
						key = stoi(s);
						if (key > 0 && key < max + 1)
							return key;
						else
						{
							setColor(background_color, red);
							printA_Sentence("Khong hop le !", line + 2);
							temp = _getch();
							printA_Sentence("                 ", line + 2);
							setColor(background_color, text_color);
							s = "";
							continue;
						}
					}
				}
				return lc - 1;//0 la thoat, -1 la quay ve
			}
			else if (temp == 72)//len
			{

				if (lc == -1)
				{
					printA_Sentence("Nhap lua chon (STT)", line);
					lc = 1;
				}
				else
				{
					printA_Sentence(title[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
					lc--;
					if (lc == -1)
					{
						setColor(background_color, title_color1);
						printA_Sentence("Nhap lua chon (STT)", line);
						gotoXY(WIDTH / 2, line + 2);
						setColor(background_color, text_color);
						continue;
					}
				}
				setColor(background_color, title_color1);
				printA_Sentence(title[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				setColor(background_color, text_color);
				//mau
			}
			else if (temp == 80)//xuong
			{
				if (lc == -1)
					printA_Sentence("Nhap lua chon (STT)", line);
				else
					printA_Sentence(title[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				if (lc == 1)
				{
					lc = -1;
					setColor(background_color, title_color1);
					printA_Sentence("Nhap lua chon (STT)", line);
					gotoXY(WIDTH / 2, line + 2);
				}
				else
				{
					lc++;
					setColor(background_color, title_color1);
					printA_Sentence(title[lc], bd_y + lc * (cell_height + 2) + cell_height / 2);
				}
				setColor(background_color, text_color);
			}
			else if (temp >= 48 && temp <= 57 && lc == -1)
			{
				setColor(background_color, title_color1);
				s += temp;
				printA_Sentence(s, line + 2);
				if (s.length() >= 10)
				{
					setColor(background_color, red);
					printA_Sentence("Khong hop le !", line + 2);
					temp = _getch();
					printA_Sentence("                 ", line + 2);
					gotoXY(WIDTH / 2, line + 2);
					s = "";
				}
				setColor(background_color, text_color);
			}
			else if (temp == 8 && lc == -1)//xoa
			{
				setColor(background_color, title_color1);
				if (s.length() == 0)
					continue;
				s.pop_back();
				printA_Sentence("  " + s + "  ", line + 2);
				setColor(background_color, text_color);
			}
			else
			{

			}
		}
	}
	return lc + 1;
}

void printA_Sentence(string a, int line)
{
	gotoXY(WIDTH / 2 - a.length() / 2, line);
	cout << a;
}

//DKKH
void nhapNgay_ve(int line)
{
	line++;
	gotoXY(55, line);
	setColor(background_color, text_color);
	cout << "Ngay / Thang / Nam";
	veHCN(80, line - 1, 80 + 36, line + 1);
	gotoXY(80 + 10, line);
	cout << '/';
	gotoXY(80 + 20, line);
	cout << '/';
}

Ngay nhapNgay_nhap(int line)
{
	line++;
	gotoXY(55, line);
	setColor(background_color, title_color1);
	cout << "Ngay / Thang / Nam";
	char pre = 0;
	char temp = 0;
	char state = 0;
	string day = "", month = "", year = "";
	gotoXY(80 + 2, line);
	Ngay t;
	setColor(background_color, text_color);
	while (true)
	{
		if (_kbhit())
		{
			temp = _getch();
			//enter
			if (temp == 13)
			{
				if (day == "" || month == "" || year == "")
				{
					setColor(background_color, red);
					gotoXY(82, line + 2);
					cout << "Khong duoc de trong !";
					temp = _getch();
					gotoXY(82, line + 2);
					cout << "                         ";
					setColor(background_color, text_color);
					gotoXY(80 + state * 10 + 2, line);
					continue;
				}
				t.d = stoi(day);
				t.m = stoi(month);
				t.y = stoi(year);
				if (NgayHopLe(t.d, t.m, t.y))
					break;
				setColor(background_color, red);
				gotoXY(82, line + 2);
				cout << "Thong tin khong hop le !";
				temp = _getch();
				gotoXY(82, line + 2);
				cout << "                         ";
				for (int i = 0; i < 3; i++)
				{
					gotoXY(80 + i * 10 + 2, line);
					cout << "     ";
				}
				setColor(background_color, text_color);
				gotoXY(80 + state * 10 + 2, line);
			}
			else if (temp == 75)//trai
			{
				if (state == 0)
					state = 2;
				else
					state--;
				gotoXY(80 + state * 10 + 2, line);
			}
			else if (temp == 77)//phai
			{
				if (state == 2)
					state = 0;
				else
					state++;
				gotoXY(80 + state * 10 + 2, line);
			}
			else if (temp == 8)//xoa
			{
				if (state == 0)
				{
					if (day == "")
						continue;
					day.pop_back();
					gotoXY(80 + state * 10 + 2, line);
					cout << day << " ";
					gotoXY(80 + state * 10 + 2 + day.length(), line);
				}
				else if (state == 1)
				{
					if (month == "")
						continue;
					month.pop_back();
					gotoXY(80 + state * 10 + 2, line);
					cout << month << " ";
					gotoXY(80 + state * 10 + 2 + month.length(), line);
				}
				else
				{
					if (year == "")
						continue;
					year.pop_back();
					gotoXY(80 + state * 10 + 2, line);
					cout << year << " ";
					gotoXY(80 + state * 10 + 2 + year.length(), line);
				}
			}
			else if (temp >= 48 && temp <= 57)// nhap so
			{
				cout << temp;
				if (state == 0)//nhap ngay
				{
					if ((pre < 48 || pre>57) && pre != 8)
					{
						gotoXY(80 + state * 10 + 2, line);
						cout << temp << "    ";
						day = "";
						gotoXY(80 + state * 10 + 2 + 1, line);
					}
					day += temp;
					if (stoi(day) > 31)
					{
						setColor(background_color, red);
						printA_Sentence("       Ngay khong hop le !       ", line + 2);
						temp = _getch();
						gotoXY(80 + state * 10 + 2, line);
						cout << "     ";
						printA_Sentence("                              ", line + 2);
						setColor(background_color, text_color);
						day = "";
						gotoXY(80 + state * 10 + 2, line);
					}
				}
				else if (state == 1)//nhap thang
				{
					if ((pre < 48 || pre>57) && pre != 8)
					{
						gotoXY(80 + state * 10 + 2, line);
						cout << temp << "    ";
						gotoXY(80 + state * 10 + 2 + 1, line);
						month = "";
					}
					month += temp;
					if (stoi(month) > 12)
					{
						setColor(background_color, red);
						printA_Sentence("       Thang khong hop le !       ", line + 2);
						temp = _getch();
						gotoXY(80 + state * 10 + 2, line);
						cout << "     ";
						printA_Sentence("                              ", line + 2);
						setColor(background_color, text_color);
						month = "";
						gotoXY(80 + state * 10 + 2, line);
					}
				}
				else
				{
					if ((pre < 48 || pre>57) && pre != 8)
					{
						gotoXY(80 + state * 10 + 2, line);
						cout << temp << "    ";
						gotoXY(80 + state * 10 + 2 + 1, line);
						year = "";
					}
					year += temp;
					if (year.length() >= 5)
					{
						setColor(background_color, red);
						printA_Sentence("       Nam khong hop le !       ", line + 2);
						temp = _getch();
						gotoXY(80 + state * 10 + 2, line);
						cout << "     ";
						printA_Sentence("                              ", line + 2);
						setColor(background_color, text_color);
						year = "";
						gotoXY(80 + state * 10 + 2, line);
					}
				}
			}
			else {
				continue;
			}
			pre = temp;
		}
	}
	gotoXY(55, line);
	cout << "Ngay / Thang / Nam";
	return t;
}

void nhapGio_ve(int line)
{
	line++;
	gotoXY(55, line);
	setColor(background_color, text_color);
	cout << "Gio : Phut";
	veHCN(80, line - 1, 80 + 20, line + 1);
	gotoXY(80 + 10, line);
	cout << ':';
}

Time nhapGio_nhap(int line)
{
	line++;
	gotoXY(55, line);
	setColor(background_color, title_color1);
	cout << "Gio : Phut";
	char pre = 0;
	char temp = 0;
	char state = 0;
	string hour = "", mins = "";
	gotoXY(80 + 2, line);
	Time t;
	setColor(background_color, text_color);
	while (true)
	{
		if (_kbhit())
		{
			temp = _getch();
			//enter
			if (temp == 13)
			{
				if (hour == "" || mins == "")
				{
					setColor(background_color, red);
					gotoXY(82, line + 2);
					cout << "Khong duoc de trong !";
					gotoXY(82, line + 2);
					temp = _getch();
					cout << "                         ";
					setColor(background_color, text_color);
					gotoXY(80 + state * 10 + 2, line);
					continue;
				}
				t.gio = stoi(hour);
				t.phut = stoi(mins);
				break;
			}
			else if (temp == 75)//trai
			{
				if (state == 0)
					state = 1;
				else
					state--;
				gotoXY(80 + state * 10 + 2, line);
			}
			else if (temp == 77)//phai
			{
				if (state == 1)
					state = 0;
				else
					state++;
				gotoXY(80 + state * 10 + 2, line);
			}
			else if (temp == 8)//xoa
			{
				if (state == 0)
				{
					if (hour == "")
						continue;
					hour.pop_back();
					gotoXY(80 + state * 10 + 2, line);
					cout << hour << " ";
					gotoXY(80 + state * 10 + 2 + hour.length(), line);
				}
				else
				{
					if (mins == "")
						continue;
					mins.pop_back();
					gotoXY(80 + state * 10 + 2, line);
					cout << mins << " ";
					gotoXY(80 + state * 10 + 2 + mins.length(), line);
				}
			}
			else if (temp >= 48 && temp <= 57)// nhap so
			{
				cout << temp;
				if (state == 0)//nhap gio
				{
					if ((pre < 48 || pre>57) && pre != 8)
					{
						gotoXY(80 + state * 10 + 2, line);
						cout << temp << "    ";
						hour = "";
						gotoXY(80 + state * 10 + 2 + 1, line);
					}
					hour += temp;
					if (stoi(hour) > 23)
					{
						setColor(background_color, red);
						printA_Sentence("       Gio khong hop le !       ", line + 2);
						temp = _getch();
						gotoXY(80 + state * 10 + 2, line);
						cout << "     ";
						printA_Sentence("                              ", line + 2);
						setColor(background_color, text_color);
						hour = "";
						gotoXY(80 + state * 10 + 2, line);
					}
				}
				else//nhap phut
				{
					if ((pre < 48 || pre>57) && pre != 8)
					{
						gotoXY(80 + state * 10 + 2, line);
						cout << temp << "    ";
						mins = "";
						gotoXY(80 + state * 10 + 2 + 1, line);
					}
					mins += temp;
					if (stoi(mins) > 59)
					{
						setColor(background_color, red);
						printA_Sentence("       Phut khong hop le !       ", line + 2);
						temp = _getch();
						gotoXY(80 + state * 10 + 2, line);
						cout << "     ";
						printA_Sentence("                              ", line + 2);
						setColor(background_color, text_color);
						mins = "";
						gotoXY(80 + state * 10 + 2, line);
					}
				}
			}
			else
			{
				continue;
			}
			pre = temp;
		}
	}
	gotoXY(55, line);
	cout << "Ngay : Gio";
	return t;
}