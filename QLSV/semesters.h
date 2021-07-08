#pragma once
#include "variable.h"
#include "years.h"


// Tra ve hoc ky tuong ung
HocKy* ChonHocKy(NamHoc nam_hoc, int hoc_ky)
{
	switch (hoc_ky)
	{
	case 1:
		return &nam_hoc.hk[0];
		break;
	case 2:
		return &nam_hoc.hk[1];
		break;
	case 3:
		return &nam_hoc.hk[2];
		break;
	default:
		return NULL;
		break;
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