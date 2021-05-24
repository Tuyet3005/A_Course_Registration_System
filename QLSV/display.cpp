#include"display.h"


void drawTable(int Row,int Col,int posCol[])
{
	//stt-mssv-ho-ten--gioitinh-ngaysinh-cmnd
	short a, b, c;
	for (int i = 0; i <= Row ; i++)
	{
		if(i==0)
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
			cout << char(a);
			for (int j = 0; j < Col; j++)
			{
				for (int t = 0; t < posCol[j+1]-posCol[j]-1; t++) cout << char(196);
				if (j != Col-1) cout << char(b);
			}
			cout << char(c) << endl;
			break;
		}
		else if(i==1)
		{
			a= 195;
			b = 197;
			c = 180;
		}
		else
		{
		}
		//ve bien
		cout << char(a);
		for (int j = 0; j < Col; j++)
		{
			for (int t = 0; t < posCol[j+1]-posCol[j]-1; t++) cout << char(196);
			if(j!=Col-1) cout << char(b);
		}
		cout << char(c) << endl;
		//ve hang de dien thong tin
		for (int j = 0; j < Col+1; j++)
		{
			gotoXY(posCol[j], 2*i+3);
			cout << char(179);
		}
		cout << endl;
	}
}
void viewDsLop(LopHoc A)
{
	system("cls");
	cout << endl;
	cout << "----------------------------------------DANH SACH LOP "<< A.ten<<"--------------------------------------" << endl;
	string title[] = { "STT","MSSV","HO","TEN","GIOI TINH","NGAY SINH","CMND" };
	int posCol[8] = { 0,6,17,43,55,67,81,95 };
	for (int j = 0; j < 8; j++)
	{
		gotoXY(posCol[j] + 2, 3);
		cout << title[j];
	}
	cout.clear();
	NodeSv* p = A.listsv.pHead;
	int dem = 0;
	for(int i=2;p!=NULL;i++)
	{
		gotoXY(posCol[0] + 2, 2 * i + 1);
		cout << p->sv.stt;
		gotoXY(posCol[1] + 2, 2 * i + 1);
		cout <<p->sv.id;
		gotoXY(posCol[2] + 2, 2 * i + 1);
		cout << p->sv.ho;
		gotoXY(posCol[3] + 2, 2 * i + 1);
		cout << p->sv.ten;
		gotoXY(posCol[4] + 2, 2 * i + 1);
		cout << p->sv.gioi;
		gotoXY(posCol[5] + 2, 2 * i + 1);
		cout << p->sv.ngayS.d << "/" << p->sv.ngayS.m << "/" << p->sv.ngayS.y;
		gotoXY(posCol[6] + 2, 2 * i + 1);
		cout << p->sv.cmnd;
		p = p->pNext;
		dem++;
	}
	gotoXY(0, 2);
	drawTable(dem+1,sizeof(posCol)-1,posCol);
}

void chaythu()
{
	// chay thu ham viewDsLop trong khi doi mb lam doc info tu file...hao huc qua a~

	LopHoc A;
	A.ten = "12C1";
	Init(A.listsv);
	NodeSv* t = new NodeSv;
	t->sv = findInfo("20120435");
	t->pNext = new NodeSv;
	A.listsv.pHead = t;
	t = t->pNext;
	t->sv = findInfo("20120440");
	t->pNext = NULL;
	A.listsv.pTail = t;
	cout.clear();
	viewDsLop(A);
	gotoXY(0, 20);
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
	cout << "                                     Course & Student Management System" << endl << endl << endl << endl;
	system("pause");
}
void viewDsMon(ListMon A)
{

}
void viewDsSvMon(MonHoc A)
{

}
void viewDsKi(NamHoc A)
{

}
void viewDsNam(ListNamHoc A)
{

}
