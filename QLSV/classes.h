#pragma once
#include"courses.h"


float NhapDiem(float diem = -1)
{
	while (diem < 0 || diem > 10)
	{
		cout << "0 <= diem <= 10. Nhap diem: ";
		cin >> diem;
		cin.ignore();
	}
	return diem;
}

void LuuDiemSv(string filename, NodeSv_Mon* node_sv_mon)
{
	fstream file(filename, ios::in);
	string data = "", line;
	while (!file.eof())
	{
		getline(file, line);
		if (line.empty())
			break;
		data += line + '\n';
	}
	data = data.substr(0, data.length() - 1);
	file.close();

	file.open(filename, ios::out);
	bool success = false, wrote = false;

	while (!data.empty())
	{
		if (wrote)
			file << '\n';
		line = NextLine(data);

		if (line.find(to_string(node_sv_mon->mssv) + "," + node_sv_mon->lop + ",") == 0)
		{
			file << node_sv_mon->mssv << ',' << node_sv_mon->lop << ',' << "R" << ','
				<< node_sv_mon->diem.gk << ','
				<< node_sv_mon->diem.ck << ','
				<< node_sv_mon->diem.gk << ','
				<< node_sv_mon->diem.tongket << ',';
			success = true;
		}
		else
		{
			file << line;
		}
	}
	if (!success)
		file << node_sv_mon->mssv << ',' << node_sv_mon->lop << ',' << "R" << ','
		<< node_sv_mon->diem.gk << ','
		<< node_sv_mon->diem.ck << ','
		<< node_sv_mon->diem.gk << ','
		<< node_sv_mon->diem.tongket << ',';
	file.close();
	cout << "Luu diem thanh cong!!!\n";
}

void HienThiDSLop(NodeLop* head_lop)
{
	cout << "\nDanh sach lop:\n";
	for (NodeLop* node_lop = head_lop; node_lop != NULL; node_lop = node_lop->pNext)
	{
		cout << "Lop: " << node_lop->lop.ten << '\n';
	}
}

void HienThiDSSv(NodeSv_Lop* head_sv_lop)
{
	cout << "\nDanh sach SV:\n";
	for (NodeSv_Lop* node_sv_lop = head_sv_lop; node_sv_lop != NULL; node_sv_lop = node_sv_lop->pNext)
	{
		cout << "MSSV: " << node_sv_lop->sv.id << ", Ten: " << node_sv_lop->sv.ten << ", CMND: " << node_sv_lop->sv.cmnd << '\n';
	}
}

void CapNhatDiemSv(ListNamHoc& l)
{
	NodeNamHoc* node_nam = NhapNamHoc(l);
	int nam_hoc = node_nam->data.tg.ngay_bd.y;
	int nam_sv = -1;
	while (nam_sv < 1 || nam_sv > 4)
	{
		cout << "Nhap nam (sv nam 1, nam 2, ...): ";
		cin >> nam_sv;
		cin.ignore();
	}

	NodeLop* head_lop = node_nam->data.headLop[nam_sv - 1];
	NodeLop* node_lop;
	string ten_lop;
	while (true)
	{
		HienThiDSLop(head_lop);
		cout << "Ten lop: ";
		getline(cin, ten_lop);

		for (node_lop = head_lop; node_lop != NULL; node_lop = node_lop->pNext)
		{
			if (node_lop->lop.ten == ten_lop)
			{
				break;
			}
		}
		// Thu lai
		if (node_lop == NULL)
			continue;
		break;
	}

	NodeSv_Lop* node_sv_lop;
	int mssv;
	while (true)
	{
		HienThiDSSv(node_lop->lop.headSvLop);
		cout << "Nhap MSSV: ";
		cin >> mssv;
		cin.ignore();

		for (node_sv_lop = node_lop->lop.headSvLop; node_sv_lop != NULL; node_sv_lop = node_sv_lop->pNext)
		{
			if (node_sv_lop->sv.id == mssv)
				break;
		}
		if (node_sv_lop != NULL)
			break;
	}

	int hoc_ky = -1;
	while (hoc_ky < 1 || hoc_ky > 3)
	{
		cout << "Nhap hoc ky (1 <= HK <= 3): ";
		cin >> hoc_ky;
		cin.ignore();
	}

	NodeMon_Sv*& head_mon_sv = node_sv_lop->headMon[hoc_ky - 1];
	NodeMon_Sv* node_mon_sv;
	string id_mon;
	while (true)
	{
		HienThiDSMon(head_mon_sv->mon);
		cout << "Nhap ID mon: ";
		getline(cin, id_mon);
		for (node_mon_sv = head_mon_sv; node_mon_sv != NULL; node_mon_sv = node_mon_sv->pNext)
		{
			if (node_mon_sv->mon->data.id == id_mon)
				break;
		}
		if (node_mon_sv != NULL)
			break;
	}

	NodeSv_Mon* node_sv_mon;
	for (node_sv_mon = node_mon_sv->mon->headSvMon; node_sv_mon != NULL; node_sv_mon = node_sv_mon->pNext)
	{
		if (node_sv_mon->mssv == mssv && node_sv_mon->lop == ten_lop)
			break;
	}
	if (node_sv_mon == NULL)
	{
		// Tao NodeSv_Mon moi neu can
		node_sv_mon = new NodeSv_Mon;
		node_sv_mon->mssv = mssv;
		node_sv_mon->lop = ten_lop;
		node_sv_mon->pNext = node_mon_sv->mon->headSvMon;
		node_mon_sv->mon->headSvMon = node_sv_mon;
		ThemNodeMon_Sv(node_mon_sv, node_mon_sv->mon, node_sv_mon);
	}

	Diem& diem = node_sv_mon->diem;
	string input;

	cout << "Diem giua ky (" << diem.gk << "): ";
	getline(cin, input);
	try
	{
		diem.gk = NhapDiem(stof(input));
	}
	catch (invalid_argument) {}

	cout << "Diem cuoi ky (" << diem.ck << "): ";
	getline(cin, input);
	try
	{
		diem.ck = NhapDiem(stof(input));
	}
	catch (invalid_argument) {}

	cout << "Diem cong (" << diem.cong << "): ";
	getline(cin, input);
	try
	{
		diem.cong = NhapDiem(stof(input));
	}
	catch (invalid_argument) {}

	diem.tongket = min((diem.gk + diem.ck * 2.0) / 3 + diem.cong / 10, 10.0);

	string filename = to_string(nam_hoc) + "hk" + to_string(hoc_ky) + id_mon + ".txt";
	LuuDiemSv(filename, node_sv_mon);
}