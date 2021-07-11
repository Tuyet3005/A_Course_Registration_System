#pragma once
#include "variable.h"
#include "staff.h"
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
			cout << "Nhap sai ID mon hoc.\n";
		}
	}
}

NodeSv_Mon* ChonDiemSv(NodeMon* node_mon, int mssv, string lop)
{
	NodeSv_Mon* diem = node_mon->headSvMon;

	while (diem != NULL)
	{
		if (diem->mssv == mssv && diem->lop == lop)
		{
			return diem;
		}
		diem = diem->pNext;
	}
	return NULL;
}

NodeSv_Mon* NhapDiemSv(ListNamHoc l)
{
	NodeMon* node_mon = NhapMonHoc(l);
	int mssv;
	string lop;
	NodeSv_Mon* diem_sv;

	while (true)
	{
		cout << "Nhap mssv: ";
		cin >> mssv;
		cout << "Nhap lop: ";
		cin >> lop;
		diem_sv = ChonDiemSv(node_mon, mssv, lop);
		if (diem_sv != NULL)
		{
			return diem_sv;
		}
		else
		{
			cout << "Nhap sai thong tin sinh vien.\n";
		}
	}
}

// Luu mon hoc vao file tuong ung
void LuuMonHoc(string filename, NodeMon* mon)
{
	ifstream file(filename);
	string lines[999];
	int n = 0;
	while (!file.eof())
	{
		getline(file, lines[n++]);
	}
	file.close();

	ofstream out_file(filename, ios::out);
	out_file << lines[0];
	bool saved = false;

	for (int i = 1; i < n; i++)
	{
		string line = lines[i];
		out_file << '\n';
		if (line.find(mon->data.id + ",") == 0)
		{
			out_file << mon->data.id << ',' << mon->data.tenMon << ',' << mon->data.tenGv << ',' << mon->data.so_tc << ','
				<< mon->data.bh1.thu << ',' << mon->data.bh1.buoi << ','
				<< mon->data.bh2.thu << ',' << mon->data.bh2.buoi << ',';
			cout << "Luu mon hoc thanh cong!!!\n";
			saved = true;
		}
		else
		{
			out_file << line;
		}
	}
	if (!saved)
		cout << "Khong the tim thay mon hoc " << mon->data.id << " - " << mon->data.tenMon << "!!!\n";
}

// Tim va luu vao file tuong ung
void LuuMonHoc(ListNamHoc& l, NodeMon* node_mon)
{
	for (NodeNamHoc* nam = l.pHead; nam != NULL; nam = nam->pNext)
	{
		for (int stt_hoc_ky = 0; stt_hoc_ky <= 2; stt_hoc_ky++)
		{
			HocKy hoc_ky = nam->data.hk[stt_hoc_ky];
			for (NodeMon* mon = hoc_ky.headMon; mon != NULL; mon = mon->pNext)
			{
				if (mon == node_mon)
				{
					LuuMonHoc(to_string(nam->data.tg.ngay_bd.y) + "hk" + to_string(stt_hoc_ky + 1) + ".txt", node_mon);
				}
			}
		}
	}
}

void CapNhatMonHoc(ListNamHoc& l)
{
	NodeMon* node_mon = NhapMonHoc(l);
	MonHoc& mon = node_mon->data;
	string input;

	cout << "Nhap thong tin moi. De trong de giu nguyen.\n";

	cout << "Ten mon (" << mon.tenMon << "): ";
	getline(cin, input);
	if (!input.empty()) mon.tenMon = input;

	cout << "Ten giao vien (" << mon.tenGv << "): ";
	getline(cin, input);
	if (!input.empty()) mon.tenGv = input;

	cout << "So tin chi (" << mon.so_tc << "): ";
	getline(cin, input);
	try
	{
		mon.so_tc = stoi(input);
	}
	catch (invalid_argument) {}

	cout << "So sinh vien toi da (" << mon.MaxSv << "): ";
	getline(cin, input);
	try
	{
		mon.MaxSv = stoi(input);
	}
	catch (invalid_argument) {}

	for (int stt_buoi = 1; stt_buoi <= 2; stt_buoi++)
	{
		BuoiHoc buoi;
		if (stt_buoi == 1)
		{
			BuoiHoc& buoi = mon.bh1;
		}
		else
		{
			BuoiHoc& buoi = mon.bh2;
		}

		cout << "Buoi hoc " << stt_buoi << " - thu (" << buoi.thu << ")\n";
		HienLuaChonThu(1);
		getline(cin, input);
		try
		{
			XulyThu(stoi(input), buoi);
		}
		catch (invalid_argument) {}

		cout << "Buoi hoc " << stt_buoi << " - gio (" << buoi.buoi << "): ";
		HienLuaChonGio();
		getline(cin, input);
		try
		{
			int selection = stoi(input);
			if (selection >= 1 && selection <= 4)
			{
				buoi.buoi = "S" + input;
			}
		}
		catch (invalid_argument) {}
	}

	LuuMonHoc(l, node_mon);
}

void CapNhatDiemSv(ListNamHoc& l)
{
	NodeSv_Mon* diem_sv = NhapDiemSv(l);
	Diem diem = diem_sv->diem;
	string input;

	cout << "Diem giua ky (" << diem.gk << "): ";
	getline(cin, input);
	try
	{
		diem.gk = stof(input);
	}
	catch (invalid_argument) {}

	cout << "Diem cuoi ky (" << diem.ck << "): ";
	getline(cin, input);
	try
	{
		diem.ck = stof(input);
	}
	catch (invalid_argument) {}

	cout << "Diem cong (" << diem.cong << "): ";
	getline(cin, input);
	try
	{
		diem.cong = stof(input);
	}
	catch (invalid_argument) {}

	diem.tongket = min((diem.gk + diem.ck * 2.0) / 3 + diem.cong / 10, 10.0);
}