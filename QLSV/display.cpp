#include"display.h"
#include"student.h"
#include"console.h"

void drawTable(int Row,int Col,int posCol[],int posRow)//posRow la hang bat dau ke bang
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
			gotoXY(posCol[j], posRow+1+2*i);
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
	int posRow = whereY();
	string title[] = { "STT","MSSV","HO","TEN","GIOI TINH","NGAY SINH","CMND" };
	int posCol[8] = { 0,6,17,43,55,67,81,95 };
	for (int j = 0; j < 8; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	NodeSv_Lop* p = A.headSvLop;
	int i = 1;
	for(;p!=NULL;i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << p->sv.stt;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout <<p->sv.id;
		gotoXY(posCol[2] + 2, posRow + 1 + 2 * i);
		cout << p->sv.ho;
		gotoXY(posCol[3] + 2, posRow + 1 + 2 * i);
		cout << p->sv.ten;
		gotoXY(posCol[4] + 2, posRow + 1 + 2 * i);
		cout << p->sv.gioi;
		gotoXY(posCol[5] + 2, posRow + 1 + 2 * i);
		cout << p->sv.ngayS.d << "/" << p->sv.ngayS.m << "/" << p->sv.ngayS.y;
		gotoXY(posCol[6] + 2, 2 * i + 1);
		cout << p->sv.cmnd;
		p = p->pNext;	
	}
	gotoXY(0, posRow);
	drawTable(i,7,posCol,posRow);
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
int viewDsMonHk(NodeMon* head,int ki)//đưa dô head moon của struct hk
{
	system("cls");
	cout << "---------------------------------------------DANH SACH MON KI " << ki <<"----------------------------------------" << endl;
	string title[] = {"STT", "ID","TEN MON HOC","TEN GIANG VIEN","SO TIN CHI","SO SV TOI DA","LICH HOC"};
	int posRow = whereY();
	int posCol[8] = { 0,5,15,45,75,90,105,135};
	for (int j = 0; j < 7; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	NodeMon* p =head;
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
	drawTable(i, 7, posCol,posRow);
	return i;
}
void viewDsSvMon(NodeMon A)
{
	system("cls");
	cout << "---------------------------------------DANH SACH SINH VIEN MON " << A.data.tenMon << "--------------------------------------" << endl;
	string title[] = { "STT","MSSV","HO","TEN","DIEM GK","DIEM CK","DIEM CONG","TONG KET" };
	int posRow = whereY();
	int posCol[9] = { 0,6,17,43,55,65,75,85 };
	for (int j = 0; j < 8; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	NodeSv_Mon* p = A.headSvMon;
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
	drawTable(i, 8, posCol,posRow);
}
void viewDsKi(NamHoc A)
{
	system("cls");
	cout << "-----------------------------DANH SACH KI NAM HOC " << A.tg.ngay_bd.y << " - " << A.tg.ngay_bd.y+1 << "-----------------------------" << endl;
	string title[] = { "KI","THOI GIAN" };
	int posRow = whereY();
	int posCol[3] = { 0,5,20 };
	for (int j = 0; j < 2; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	for (int i = 1; i < 4; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << A.hk[i].tg.ngay_bd.d << "/" << A.hk[i].tg.ngay_bd.m << "/" << A.hk[i].tg.ngay_bd.y << " - " << A.hk[i].tg.ngay_kt.d << "/" << A.hk[i].tg.ngay_kt.m << "/" << A.hk[i].tg.ngay_kt.y;
	}
	gotoXY(0, posRow);
	drawTable(4, 2, posCol,posRow);
}
void viewDsNam(ListNamHoc A)
{
	system("cls");
	cout << "---------------------------------------DANH SACH NAM HOC----------------------------------" << endl;
	string title[] = { "STT","NAM HOC" };
	int posRow = whereY();
	int posCol[7] = { 0,6,16 };
	for (int j = 0; j < 2; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	NodeNamHoc* p = A.pHead;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i + 1;;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->data.tg.ngay_bd.y << " - " << p->data.tg.ngay_kt.y;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i , 2, posCol,posRow);
}
void viewDsLop(NodeLop* head,int nam, int namhoc)
{
	system("cls");
	cout << "---------------------DANH SACH LOP HOC NAM "<<nam<<" NAM HOC "<<namhoc<<" - "<<namhoc+1<<"-----------------------" << endl;
	string title[] = { "STT","TEN LOP" };
	int posRow = whereY();
	int posCol[7] = { 0,6,16 };
	for (int j = 0; j < 2; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	NodeLop* p = head;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << i+1;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->lop.ten;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i, 2, posCol,posRow);
}
void viewSvScore(NodeSv_Lop* sv, int ki)//xem diem theo tung hoc ki
{
	system("cls");
	cout << "-------------------------------------KET QUA HOC TAP - HOC KI "<<ki<<"----------------------------------" << endl;
	cout << endl;
	NodeMon_Sv* p = sv->headMon[ki - 1];
	string title[] = { "STT","ID MON","TEN MON","GK","CK","CONG","TONG KET" };
	int posRow = whereY();
	int posCol[] = { 0,6,20, 30,9,9,9,9 };
	for (int j = 0; j < 7; j++)
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	int i = 1;
	for(; p!= NULL;i++)
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
		cout << i + 1;
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
	gotoXY(0,posRow);
	drawTable(i , 7, posCol,posRow);
}
void viewInfoSv(Sv A)
{
	system("cls");
	cout << endl;
	cout << "----------------------------------------THONG TIN CA NHAN--------------------------------------" << endl;
	string title[] = { "STT","MSSV","HO","TEN","GIOI TINH","NGAY SINH","CMND" };
	int posRow = whereY();
	int posCol[8] = { 0,6,17,43,55,67,85,95 };
	for (int j = 0; j < 7; j++)//ghi title
	{
		gotoXY(posCol[j] + 2, posRow+1);
		cout << title[j];
	}
	cout.clear();
	gotoXY(posCol[0] + 2, posRow + 3 );
	cout << A.stt;
	gotoXY(posCol[1] + 2, posRow + 3 );
	cout << A.id;
	gotoXY(posCol[2] + 2, posRow + 3 );
	cout << A.ho;
	gotoXY(posCol[3] + 2, posRow + 3 );
	cout << A.ten;
	gotoXY(posCol[4] + 2, posRow + 3 );
	cout << A.gioi;
	gotoXY(posCol[5] + 2, posRow + 3 );
	cout << A.ngayS.d << "/" << A.ngayS.m << "/" << A.ngayS.y;
	gotoXY(posCol[6] + 2, posRow + 3);
	cout << A.cmnd;
	gotoXY(0, posRow);
	drawTable(2, 7, posCol,posRow);
	system("pause");
}
void viewMondaDk(NodeMon_Sv* A, int ki)//show thong tin mon hoc cua 1 sv
{
	cout << "---------------------------------------KET QUA DANG KI HOC PHAN KI"<<ki<<"-------------------------------------" << endl;
	int posRow = whereY();
	string title[] = { "ID","TEN MON HOC","TEN GIANG VIEN","SO TIN CHI","SO SV TOI DA","LICH HOC" };
	int posCol[7] = { 0,10,40,70,85,100,130 };
	for (int j = 0; j < 6; j++)
	{
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	cout.clear();
	NodeMon_Sv* p = A;
	int i = 1;
	for (; p != NULL; i++)
	{
		gotoXY(posCol[0] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.id;
		gotoXY(posCol[1] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.tenMon;
		gotoXY(posCol[2] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.tenGv;
		gotoXY(posCol[3] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.so_tc;
		gotoXY(posCol[4] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.MaxSv;
		gotoXY(posCol[5] + 2, posRow + 1 + 2 * i);
		cout << p->mon->data.bh1.buoi << "-" << p->mon->data.bh1.thu << ", " << p->mon->data.bh2.buoi << "-" << p->mon->data.bh2.thu;
		p = p->pNext;
	}
	gotoXY(0, posRow);
	drawTable(i , 6, posCol,posRow);
}
void viewDiem_Lop(NodeLop* A,int ki)
{
	//TINH GPA
	bool flag=tinhGPA_SvvaLop(A, ki);
	//
	system("cls");
	cout << "-------------------------------------KET QUA HOC TAP - LOP "<<A->lop.ten<<" - KI << "<<ki<<"----------------------------------" << endl;
	cout << endl;
	//DIEM Cuoi ki all mon, GPA, GPA overall
	string title[] = { "STT","MSSV","HO","TEN","ID MON","TK","ID MON","TK","ID MON","TK","ID MON","TK","ID MON","TK","GPA" };
	int posRow = whereY();
	int posCol[16] = { 0,6,17,43,55,65,70,80,85,95,100,110,115,125,130,140 };
	for (int j = 0; j < 16; j++)
	{
		gotoXY(posCol[j] + 2, posRow + 1);
		cout << title[j];
	}
	cout.clear();
	NodeSv_Lop* pSv = A->lop.headSvLop;
	NodeMon_Sv* pMon;
	int i = 1;
	int j;
	for (; pSv != NULL; i++)
	{
		pMon = pSv->headMon[ki - 1];
		//
		gotoXY(posCol[0], posRow + 1 + 2 * i);
		cout << pSv->sv.stt;
		gotoXY(posCol[1], posRow + 1 + 2 * i);
		cout << pSv->sv.id;
		gotoXY(posCol[2], posRow + 1 + 2 * i);
		cout << pSv->sv.ho;
		gotoXY(posCol[3], posRow + 1 + 2 * i);
		cout << pSv->sv.ten;
		j = 4;
		for (; j < 4 + 5 && pMon!=NULL; j+=2)
		{
			gotoXY(posCol[j], posRow + 1 + 2 * i);
			cout << pMon->mon->data.id;
			gotoXY(posCol[j+1], posRow + 1 + 2 * i);
			cout << pMon->svMon->diem.tongket;
			pMon = pMon->pNext;
		}
		gotoXY(posCol[5], posRow + 1 + 2 * i);
		cout << pSv->GPA[ki];
		pSv = pSv->pNext;
	}
	gotoXY(posCol[10],posRow+ i + 2);
	cout << "Trung binh GPA: ";
	gotoXY(posCol[14] + 2,posRow +i + 2);
	if (flag)
		cout << A->lop.GPA;
	else
		cout << "Chua cap nhat";
	gotoXY(0, posRow);
	drawTable(i, 7, posCol, posRow);
}
//TINH GPA
bool tinhGPA_SvvaLop(NodeLop* t,int ki)
{
	NodeSv_Lop* pSv = t->lop.headSvLop;
	NodeMon_Sv* pMon;
	float sum;
	float temp;
	int tin;
	//lop
	int dem = 0;
	int sumlop = 0;
	while (pSv != NULL)
	{
		pMon = pSv->headMon[ki-1];
		sum = 0;
		tin = 0;
		while (pMon != NULL)
		{
			temp = pMon->svMon->diem.tongket;
			if (temp == -1)
				break;
			else
			{
				tin += pMon->mon->data.so_tc;
				sum += pMon->svMon->diem.tongket;
			}
			pMon = pMon->pNext;
		}
		if (temp != NULL)//co diem tk
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
	t->lop.GPA[ki - 1] = sumlop / dem;
	return true;
}