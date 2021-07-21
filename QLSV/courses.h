#pragma once
#include "variable.h"
#include "staff.h"
#include "semesters.h"


// Tra ve mon hoc tuong ung
NodeMon* ChonMonHoc(HocKy* hk, string id_mon_hoc)
{
	NodeMon* mon_hoc = hk->headMon;
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
	HocKy* hoc_ky = NhapHocKy(l);
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

NodeMon* TimNodeMon(ListNamHoc l, string id_mon)
{
	for (NodeNamHoc* node_nam = l.pHead; node_nam != NULL; node_nam = node_nam->pNext)
	{
		for (HocKy hoc_ky : node_nam->data.hk)
		{
			for (NodeMon* node_mon = hoc_ky.headMon; node_mon != NULL; node_mon = node_mon->pNext)
			{
				if (node_mon->data.id == id_mon)
				{
					return node_mon;
				}
			}
		}
	}
	return NULL;
}

string NextLine(string& data)
{
	size_t pos = data.find('\n');
	string line = data.substr(0, pos);
	data = pos != string::npos ? data.substr(pos + 1) : "";
	return line;
}

// Luu mon hoc vao file tuong ung
void LuuMonHoc(string filename, NodeMon* mon, bool remove)
{
	fstream file(filename, ios::in);
	string data, line;
	getline(file, data);
	while (!file.eof())
	{
		getline(file, line);
		data += '\n' + line;	
	}
	file.close();

	file.open(filename, ios::out);
	file << NextLine(data);
	bool success = false;

	while (!data.empty())
	{
		line = NextLine(data);
		file << '\n';

		if (line.find(mon->data.id + ",") == 0)
		{
			if (remove)
			{
				cout << "Xoa mon hoc thanh cong!!!\n";
				success = true;
			}
			else
			{
				file << mon->data.id << ',' << mon->data.tenMon << ',' << mon->data.tenGv << ',' << mon->data.so_tc << ','
					<< mon->data.bh1.thu << ',' << mon->data.bh1.buoi << ','
					<< mon->data.bh2.thu << ',' << mon->data.bh2.buoi << ','
					<< mon->data.MaxSv << ',';
				cout << "Luu mon hoc thanh cong!!!\n";
				success = true;
			}
		}
		else
		{
			file << line;
		}
	}
	if (!success)
		cout << "Khong the tim thay mon hoc " << mon->data.id << " - " << mon->data.tenMon << "!!!\n";
	file.close();
}

// Tim va luu vao file tuong ung
void LuuMonHoc(ListNamHoc& l, NodeMon* node_mon, bool remove=false)
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
					LuuMonHoc(to_string(nam->data.tg.ngay_bd.y) + "hk" + to_string(stt_hoc_ky + 1) + ".txt", node_mon, remove);
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

void XoaMonHoc(ListNamHoc& l)
{
	NodeMon* node_mon = NhapMonHoc(l);
	LuuMonHoc(l, node_mon, true);
}