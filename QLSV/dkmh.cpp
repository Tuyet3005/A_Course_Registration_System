#include<iostream>
#include"variable.h"
#include"console.h"
using namespace std;
struct Time {
	int h, m, s;
};
void Timer(Time t, int posx, int posy)
{
	while (true)
	{
		gotoXY(posx, posy);
		cout << t.h << " : " << t.m << " : " << t.s << "             ";
		Beep(10, 1000);
		if (t.s == 0)
		{
			if (t.m == 0)
			{
				if (t.h == 0) break;
				else t.h--;
			}
			else t.m--;
		}
		else t.s--;
	}
	gotoXY(posx, posy);
	cout << "HET GIO                                 ";
	system("pause");
}
