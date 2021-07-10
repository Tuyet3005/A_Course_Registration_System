#pragma once
#include "variable.h"
#include "years.h"


// Tra ve hoc ky tuong ung
HocKy* ChonHocKy(NamHoc nam_hoc, int hoc_ky)
{
	if (hoc_ky < size(nam_hoc.hk))
	{
		return &nam_hoc.hk[hoc_ky];
	}
	else {
		return NULL;
	}
}

HocKy NhapHocKy(ListNamHoc l)
{
	int so_hoc_ky;
	NodeNamHoc* nam = NhapNamHoc(l);
	HocKy* hoc_ky;

	while (true)
	{
		cout << "Nhap hoc ky: ";
		cin >> so_hoc_ky;
		cin.ignore();
		hoc_ky = ChonHocKy(nam->data, so_hoc_ky);
		if (hoc_ky != NULL)
		{
			return *hoc_ky;
		}
		else
		{
			cout << "Nhap sai nam hoc.\n";
		}
	}
}