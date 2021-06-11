#pragma once
#include "variable.h"


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
}