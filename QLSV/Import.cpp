#include"variable.h"

void readFile(ListNamHoc& L)
{
	InitListNam(L);
	getYears(L);
}
void InitListNam(ListNamHoc& l)
{
	l.pHead = l.pTail = NULL;
}
void addYear(ListNamHoc& l, int year)//them dau
{
	NodeNamHoc* A = new NodeNamHoc;
	A->data.tg.ngay_bd.y = year;
	A->pNext = NULL;
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = A;
	}
	else
	{
		A->pNext = l.pHead;
		l.pHead = A;
	}
}
void getYears(ListNamHoc& L)
{
	ifstream f;
	f.open("listnam.txt");
	string stemp;
	while (!f.eof())
	{
		f.clear();
		getline(f, stemp, ',');
		addYear(L, stoi(stemp));
	}
	f.close();
}
void getClasses(ListNamHoc l)
{
	NodeNamHoc* t = l.pHead;
	ifstream f;
	string s = "";
	while (t != NULL)
	{
		for (int i = 1; i < 5; i++)
		{
			f.open(to_string(t->data.tg.ngay_bd.y)+'n'+to_string(i)+".txt");
			getline(f, s);

		}
		t = t->pNext;
	}
}