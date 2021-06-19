#pragma once
#include"variable.h"


NodeSv_Mon* findScore(NodeMon* mon, int mssv)
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