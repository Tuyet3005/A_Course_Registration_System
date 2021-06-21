#include"staff.h"
void TaoHocKy(ListNamHoc& l)
{
	int hk = 0;
	Ngay ngBD;
	Ngay ngKT;
	int nam_bd;//nam bat dau cua nam hoc tuong ung de them hoc ky vao
	cout << "TAO MOI HOC KY\n";
	while (hk < 1 || hk>3)
	{
		cout << "Nhap vao so thu tu cua hoc ky (1,2,3): ";
		cin >> hk;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			hk = 0;
		}
	}
	//nhap thoi gian bat dau, ket thuc @@@ tr.hop ngay kt < ngay bd? @@@
	{
		ngBD.d = 0;
		ngKT.d = 0;
		do
		{
			if (ngBD.d == 0)
			{
				cout << "Nhap lan luot ngay, thang, nam bat dau cua hoc ky nhu vd sau '5 9 2021':\n";
				cin >> ngBD.d >> ngBD.m >> ngBD.y;
				if (cin.fail())//check ngay thang nam phu hop!
				{
					cin.clear();
					cin.ignore();
					ngBD.d = 0;
					continue;
				}
				else if (!NgayHopLe(ngBD.d, ngBD.m, ngBD.y))
				{
					ngBD.d = 0;
					continue;
				}
			}
			if (ngKT.d == 0)
			{
				cout << "Nhap lan luot ngay, thang, nam ket thuc cua hoc ky nhu vd sau '31 07 2021':\n";
				cin >> ngKT.d >> ngKT.m >> ngKT.y;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore();
					ngKT.d = 0;
					continue;
				}
				else if (!NgayHopLe(ngKT.d, ngKT.m, ngKT.y))
				{
					ngKT.d = 0;
					continue;
				}
			}
		} while (ngBD.d == 0 || ngKT.d == 0);
	}
	//do tim node nam hoc tuong ung de them hoc ky vao
	if (ngKT.m < 8)
		nam_bd = ngKT.y - 1;//nam hoc bat dau tu dau thang 9 nam X den het thang 7 nam X+1 
	else
		nam_bd = ngKT.y;
	NodeNamHoc* nodeNam = TimNodeNamHoc(l, nam_bd);
	if (nodeNam)
	{
		HocKy* hockyP = NULL;
		switch (hk)
		{
		case 1:
		{
			hockyP = &(nodeNam->data.hk1);
			break;
		}
		case 2:
		{
			hockyP = &(nodeNam->data.hk2);
			break;
		}
		case 3:
		{
			hockyP = &(nodeNam->data.hk3);
		}
		}
		//da tao hk truoc do roi -> return;
		if ((hockyP->tg.ngay_bd.d == ngBD.d) && (hockyP->tg.ngay_bd.m == ngBD.m) && (hockyP->tg.ngay_bd.y == ngBD.y))
		{
			if ((hockyP->tg.ngay_kt.d == ngKT.d) && (hockyP->tg.ngay_kt.m == ngKT.m) && (hockyP->tg.ngay_kt.y == ngKT.y))
			{
				cout << "Ban da tao hoc ky nay truoc do roi!\n";
				return;
			}
		}
		//chua tao hoac can chinh sua hoc ky
		{
			hockyP->tg.ngay_bd = ngBD;
			hockyP->tg.ngay_kt = ngKT;
			// tao hoac chinh sua file hk tuong ung
			fstream f;
			string s;
			bool taomoi = true;
			string filePath = to_string(nam_bd) + "hk" + to_string(hk) + ".txt";
			f.open(filePath, ios::in | ios::app);
			getline(f, s);
			//ghi vao file goc neu file trong
			if (s != "")//ghi vao file trunggian neu file cu da co data 
			{
				f.close();
				f.open("trunggian.txt", ios::out);// tao file trung gian de thuc hien chinh sua 
				taomoi = false;
			}
			//ghi du lieu thoi gian vao file theo cau truc "ddmmyyyy,ddmmyyyy,\n"
			{
				//ghi ngay BD
				if (ngBD.d < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngBD.d;
				//ghi thang BD
				if (ngBD.m < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngBD.m;
				//ghi nam BD
				f << ngBD.y << ",";
				//ghi ngay KT
				if (ngKT.d < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngKT.d;
				//ghi thang KT
				if (ngKT.m < 10)
				{
					f << "0";//neu ngay <10 thi ghi them so 0 o truoc 
				}
				f << ngKT.m;
				//ghi nam KT
				f << ngKT.y << ",\n";
			}
			if (taomoi)
			{
				f << "buon qua di\n";
				f.close();
				cout << "Tao moi hoc ky thanh cong!\n";
				return;
			}
			//chinh sua file hoc ky da co thong tin truoc do thong qua file trung gian 
			else
			{
				ifstream g;
				g.open(to_string(nam_bd) + "hk" + to_string(hk) + ".txt");//mo file cu da co du lieu 
				getline(g, s);//bo qua thoi gian hk cu
				//sao chep cac du lieu mon hoc qua file trung gian 
				while (!g.eof())
				{
					getline(g, s);
					f << s;
				}
				g.close();//dong file cu
				f.close();//dong file trung gian 
				//chuyen doi data type tu string sang char* <de truyen vao ham rename, remove ben duoi>
				char* c = new char[filePath.size() + 1];
				copy(filePath.begin(), filePath.end(), c);
				c[filePath.size()] = '\0';
				remove(c);//xoa file cu 
				rename("trunggian.txt", c);//doi ten file trung gian 
				delete[] c;
				c = NULL;
			}
		}
	}
	//ko tao nam hoc tuong ung thi ko them hk vao 
	else
	{
		cout << "Tao moi hoc ky khong thanh cong!\n";
	}
}