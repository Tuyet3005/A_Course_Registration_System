#pragma once
#include "variable.h"


// Tra ve hoc ky tuong ung
HocKy ChonHocKy(NamHoc nam_hoc, int hoc_ky)
{
	switch (hoc_ky)
	{
	case 1:
		return nam_hoc.hk1;
		break;
	case 2:
		return nam_hoc.hk2;
		break;
	case 3:
		return nam_hoc.hk3;
		break;
	default:
		break;
	}
}