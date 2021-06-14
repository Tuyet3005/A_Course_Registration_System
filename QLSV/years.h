#pragma once
#include "variable.h"


// Tra ve nam hoc tuong ung
NodeNamHoc* ChonNamHoc(ListNamHoc l, int nam_hoc)
{
	NodeNamHoc* nam = l.pHead;
	while (nam != NULL)
	{
		if (nam->data.tg.ngay_bd.y == nam_hoc)
		{
			return nam;
		}
		nam = nam->pNext;
	}
	return NULL;
}

NodeNamHoc* NhapNamHoc(ListNamHoc l)
{
	int nam_hoc;
	NodeNamHoc* nam;

	while (true)
	{
		cout << "Nhap nam hoc: ";
		cin >> nam_hoc;
		cin.ignore();
		nam = ChonNamHoc(l, nam_hoc);
		if (nam != NULL)
		{
			return nam;
		}
		else
		{
			cout << "Nhap sai nam hoc.\n";
		}
	}
}