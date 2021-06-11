#pragma once
#include "variable.h"


// Tra ve nam hoc tuong ung
NodeNamHoc* ChonNamHoc(ListNamHoc l, int nam_hoc)
{
	NodeNamHoc* nam = l.pHead;
	while (nam != NULL)
	{
		if (nam->data.tg.ngay_bd.y == nam_hoc)
		{
			return nam;
		}
		nam = nam->pNext;
	}
}