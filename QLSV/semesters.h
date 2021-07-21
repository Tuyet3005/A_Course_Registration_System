#pragma once
#include "variable.h"
#include "years.h"


// Tra ve hoc ky tuong ung
HocKy* ChonHocKy(NamHoc nam_hoc, int hoc_ky)
{
	hoc_ky -= 1;
	if (hoc_ky < size(nam_hoc.hk))
	{
		return &nam_hoc.hk[hoc_ky];
	}
	else {
		return NULL;
	}
}

HocKy* NhapHocKy(NodeNamHoc* node_nam)
{
	int so_hoc_ky;
	HocKy* hoc_ky;

	while (true)
	{
		cout << "Nhap hoc ky: ";
		cin >> so_hoc_ky;
		cin.ignore();
		hoc_ky = ChonHocKy(node_nam->data, so_hoc_ky);
		if (hoc_ky != NULL)
		{
			return hoc_ky;
		}
		else
		{
			cout << "Nhap sai hoc ky.\n";
		}
	}
}

HocKy* NhapHocKy(ListNamHoc l)
{
	return NhapHocKy(NhapNamHoc(l));
}