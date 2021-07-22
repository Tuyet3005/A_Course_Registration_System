#pragma once
#include "variable.h"
#include "years.h"


HocKy* NhapHocKy(NodeNamHoc* node_nam)
{
	int so_hoc_ky = -1;
	HocKy* hoc_ky;

	while (so_hoc_ky < 1 || so_hoc_ky > 3)
	{
		cout << "Nhap hoc ky (1 <= HK <= 3): ";
		cin >> so_hoc_ky;
		cin.ignore();
	}
	return &node_nam->data.hk[so_hoc_ky - 1];
}

HocKy* NhapHocKy(ListNamHoc l)
{
	return NhapHocKy(NhapNamHoc(l));
}