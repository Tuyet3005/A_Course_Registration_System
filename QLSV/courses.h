#pragma once
#include "variable.h"
#include "semesters.h"


// Tra ve mon hoc tuong ung
NodeMon* ChonMonHoc(HocKy hk, string id_mon_hoc)
{
	NodeMon* mon_hoc = hk.headMon;
	while (mon_hoc != NULL)
	{
		if (mon_hoc->data.id == id_mon_hoc)
		{
			return mon_hoc;
		}
		mon_hoc = mon_hoc->pNext;
	}
	return NULL;
}

NodeMon* NhapMonHoc(ListNamHoc l)
{
	string id_mon_hoc;
	HocKy hoc_ky = NhapHocKy(l);
	NodeMon* mon = NULL;

	while (true)
	{
		cout << "Nhap ID mon hoc: ";
		getline(cin, id_mon_hoc);
		mon = ChonMonHoc(hoc_ky, id_mon_hoc);
		if (mon != NULL)
		{
			return mon;
		}
		else
		{
			cout << "Nhap sai nam hoc.\n";
		}
	}
}