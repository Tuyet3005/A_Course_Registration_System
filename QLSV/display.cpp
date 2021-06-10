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
void viewDsSvLop(LopHoc A)
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
	NodeSvLop* p = A.headSvLop;
	int dem = 1;
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
	drawTable(dem,7,posCol);
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
	gotoXY(0,20);
	system("pause");
}
void viewDsMon(HocKy A,int ki, int namhoc)
{
	system("cls");
	cout << "-----------------------------DANH SACH MON KI " << ki << " NAM HOC "<<namhoc<<" - "<<namhoc+1<<"-----------------------------" << endl;
	string title[] = { "ID","TEN MON HOC","TEN GIANG VIEN","SO TIN CHI","SO SV TOI DA","LICH HOC" };
	int posCol[7] = { 0,10,40,70,85,100,130};
	for (int j = 0; j < 7; j++)
	{
		gotoXY(posCol[j] + 2, 3);
		cout << title[j];
	}
	cout.clear();
	NodeMon* p = A.headMon;
	int dem = 1;
	for (int i = 2; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, 2 * i + 1);
		cout << p->data.id;
		gotoXY(posCol[1] + 2, 2 * i + 1);
		cout << p->data.tenMon;
		gotoXY(posCol[2] + 2, 2 * i + 1);
		cout << p->data.tenGv;
		gotoXY(posCol[3] + 2, 2 * i + 1);
		cout << p->data.so_tc;
		gotoXY(posCol[4] + 2, 2 * i + 1);
		cout << p->data.MaxSv;
		gotoXY(posCol[5] + 2, 2 * i + 1);
		cout << p->data.bh1.buoi << "-" << p->data.bh1.thu << ", " << p->data.bh2.buoi << "-" << p->data.bh2.thu;
		p = p->pNext;
		dem++;
	}
	gotoXY(0, 2);
	drawTable(dem, 6, posCol);
}
void viewDsSvMon(MonHoc A)
{
	system("cls");
	cout << "----------------------------------------DANH SACH SINH VIEN MON " << A.tenMon << "--------------------------------------" << endl;
	string title[] = { "STT","MSSV","HO","TEN","DIEM GK","DIEM CK","DIEM CONG","TONG KET" };
	int posCol[9] = { 0,6,17,43,55,65,75,85 };
	for (int j = 0; j < 8; j++)
	{
		gotoXY(posCol[j] + 2, 3);
		cout << title[j];
	}
	cout.clear();
	NodeSvMon* p = A.head;
	int dem = 1;
	for (int i = 2; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, 2 * i + 1);
		cout << p->sv->sv.stt;
		gotoXY(posCol[1] + 2, 2 * i + 1);
		cout << p->sv->sv.id;
		gotoXY(posCol[2] + 2, 2 * i + 1);
		cout << p->sv->sv.ho;
		gotoXY(posCol[3] + 2, 2 * i + 1);
		cout << p->sv->sv.ten;
		gotoXY(posCol[4] + 2, 2 * i + 1);
		cout << p->diem.gk;
		gotoXY(posCol[5] + 2, 2 * i + 1);
		cout << p->diem.ck;
		gotoXY(posCol[6] + 2, 2 * i + 1);
		cout << p->diem.cong;
		gotoXY(posCol[7] + 2, 2 * i + 1);
		cout << p->diem.tongket;
		p = p->pNext;
		dem++;
	}
	gotoXY(0, 2);
	drawTable(dem, 8, posCol);
}
void viewDsKi(NamHoc A)
{
	system("cls");
	cout << "-----------------------------DANH SACH KI NAM HOC " << A.tg.ngay_bd.y << " - " << A.tg.ngay_bd.y+1 << "-----------------------------" << endl;
	string title[] = { "KI","THOI GIAN" };
	int posCol[3] = { 0,5,20 };
	for (int j = 0; j < 2; j++)
	{
		gotoXY(posCol[j] + 2, 3);
		cout << title[j];
	}
	cout.clear();
	for (int i = 2; i < 5; i++)
	{
		gotoXY(posCol[0]+2, 2*i+1);
		cout << i - 1;
	}
	gotoXY(posCol[1] + 2, 5);
	cout << A.hk1.tg.ngay_bd.d << "/" << A.hk1.tg.ngay_bd.m << "/" << A.hk1.tg.ngay_bd.y << " - " << A.hk1.tg.ngay_kt.d << "/" << A.hk1.tg.ngay_kt.m << "/" << A.hk1.tg.ngay_kt.y;
	gotoXY(posCol[1] + 2, 7);
	cout << A.hk2.tg.ngay_bd.d << "/" << A.hk2.tg.ngay_bd.m << "/" << A.hk2.tg.ngay_bd.y << " - " << A.hk2.tg.ngay_kt.d << "/" << A.hk2.tg.ngay_kt.m << "/" << A.hk2.tg.ngay_kt.y;
	gotoXY(posCol[1] + 2, 9);
	cout << A.hk3.tg.ngay_bd.d << "/" << A.hk3.tg.ngay_bd.m << "/" << A.hk3.tg.ngay_bd.y << " - " << A.hk3.tg.ngay_kt.d << "/" << A.hk3.tg.ngay_kt.m << "/" << A.hk3.tg.ngay_kt.y;
	gotoXY(0, 2);
	drawTable(4, 2, posCol);
}
void viewDsNam(ListNamHoc A)
{
	system("cls");
	cout << "---------------------------------------DANH SACH NAM HOC----------------------------------" << endl;
	string title[] = { "STT","NAM HOC" };
	int posCol[7] = { 0,6,16 };
	for (int j = 0; j < 2; j++)
	{
		gotoXY(posCol[j] + 2, 3);
		cout << title[j];
	}
	cout.clear();
	NodeNamHoc* p = A.pHead;
	int dem = 1;
	for (int i = 2; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, 2 * i + 1);
		cout << dem;
		gotoXY(posCol[1] + 2, 2 * i + 1);
		cout << p->data.tg.ngay_bd.y << " - " << p->data.tg.ngay_kt.y;
		p = p->pNext;
		dem++;
	}
	gotoXY(0, 2);
	drawTable(dem , 2, posCol);
}
void viewDsLop(NodeLop* head,int nam, int namhoc)
{
	system("cls");
	cout << "---------------------DANH SACH LOP HOC NAM "<<nam<<" NAM HOC "<<namhoc<<" - "<<namhoc+1<<"-----------------------" << endl;
	string title[] = { "STT","TEN LOP" };
	int posCol[7] = { 0,6,16 };
	for (int j = 0; j < 2; j++)
	{
		gotoXY(posCol[j] + 2, 3);
		cout << title[j];
	}
	cout.clear();
	NodeLop* p = head;
	int dem = 1;
	for (int i = 2; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, 2 * i + 1);
		cout << dem;
		gotoXY(posCol[1] + 2, 2 * i + 1);
		cout << p->lop.ten;
		p = p->pNext;
		dem++;
	}
	gotoXY(0, 2);
	drawTable(dem, 2, posCol);
}
