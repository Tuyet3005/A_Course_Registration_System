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

void LuuMonHoc(ListNamHoc& l)
{
	// Luu tung mon hoc vao file
}

void CapNhatMonHoc(ListNamHoc& l)
{
	NodeMon* node_mon = NhapMonHoc(l);
	MonHoc mon = node_mon->data;
	string input;

	cout << "Nhap thong tin moi. De trong de giu nguyen.\n";

	input = "";
	cout << "Ten mon (" << mon.tenMon << "): ";
	getline(cin, input);
	if (!input.empty()) mon.tenMon = input;

	input = "";
	cout << "Ten giao vien (" << mon.tenGv << "): ";
	getline(cin, input);
	if (!input.empty()) mon.tenGv = input;

	input = "";
	cout << "So tin chi (" << mon.so_tc << "): ";
	getline(cin, input);
	try
	{
		mon.so_tc = stoi(input);
	}
	catch (invalid_argument) {}

	input = "";
	cout << "So sinh vien toi da (" << mon.MaxSv << "): ";
	getline(cin, input);
	try
	{
		mon.MaxSv = stoi(input);
	}
	catch (invalid_argument) {}

	input = "";
	cout << "Buoi hoc 1 - thu (" << mon.bh1.thu << "): ";
	getline(cin, input);
	if (!input.empty()) mon.bh1.thu = input;

	input = "";
	cout << "Buoi hoc 1 - buoi (" << mon.bh1.buoi << "): ";
	getline(cin, input);
	if (!input.empty()) mon.bh1.buoi = input;

	input = "";
	cout << "Buoi hoc 2 - thu (" << mon.bh2.thu << "): ";
	getline(cin, input);
	if (!input.empty()) mon.bh2.thu = input;

	input = "";
	cout << "Buoi hoc 2 - buoi (" << mon.bh2.buoi << "): ";
	getline(cin, input);
	if (!input.empty()) mon.bh2.buoi = input;

	LuuMonHoc(l);
}