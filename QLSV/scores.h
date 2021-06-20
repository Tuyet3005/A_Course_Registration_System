#pragma once
#include"variable.h"
#include"courses.h"


NodeSv_Mon* ChonDiem(NodeMon* mon, int mssv)
{
	NodeSv_Mon* temp = mon->headSvMon;
	while (temp != NULL)
	{
		if (temp->mssv == mssv)
		{
			return temp;
		}
		temp = temp->pNext;
	}
	return NULL;
}


NodeSv_Mon* NhapDiem(ListNamHoc& l)
{
	NodeMon* mon = NhapMonHoc(l);
	NodeSv_Mon* diem;
	int mssv;

	do {
		cout << "Nhap MSSV: ";
		cin >> mssv;
		diem = ChonDiem(mon, mssv);
	} while (diem == NULL);

	return diem;
}