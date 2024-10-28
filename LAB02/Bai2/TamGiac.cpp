#include "TamGiac.h"
#include <iostream>
using namespace std;

TamGiac::TamGiac() : a(), b(), c() {}

TamGiac::TamGiac(double a1, double a2, double b1, double b2, double c1, double c2) : a(a1, a2), b(b1, b2), c(c1, c2) { Check(); }

TamGiac::TamGiac(Diem a, Diem b, Diem c) : a(a), b(b), c(c) { Check(); }

TamGiac::TamGiac(const TamGiac& other) : a(other.a), b(other.b), c(other.c) {}

bool TamGiac::Check()
{
	double x1 = a.GetHoanhDo();
	double y1 = a.GetTungDo();
	double x2 = b.GetHoanhDo();
	double y2 = b.GetTungDo();
	double x3 = c.GetHoanhDo(); 
	double y3 = c.GetTungDo();  

    if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1)) {
        cout << "[!] Ba diem thang hang, khong phai la tam giac hop le. Vui long nhap lai." << endl;
		return false;
    }
    else {
        cout << "Day la tam giac hop le." << endl;
		return true;
    }
}

void TamGiac::Nhap()
{
    do {
        a.Nhap();
        b.Nhap();
        c.Nhap();
    }
	while (!Check());
}

void TamGiac::Xuat()
{
    a.Xuat();
	cout << "; ";
    b.Xuat();
	cout << "; ";
    c.Xuat();
	cout << endl;
}

void TamGiac::TinhTien(double dx, double dy) {
    a.TinhTien(dx, dy);
    b.TinhTien(dx, dy);
    c.TinhTien(dx, dy);
}

void TamGiac::PhongTo(double k) {
	double x1 = a.GetHoanhDo();
	double y1 = a.GetTungDo();  
	double x2 = b.GetHoanhDo();
	double y2 = b.GetTungDo();
	double x3 = c.GetHoanhDo();
	double y3 = c.GetTungDo();
	a.SetHoanhDo(x1 * k);
	a.SetTungDo(y1 * k);        
	b.SetHoanhDo(x2 * k);   
	b.SetTungDo(y2 * k);
	c.SetHoanhDo(x3 * k);
	c.SetTungDo(y3 * k);
}

void TamGiac::ThuNho(double k) {
	double x1 = a.GetHoanhDo();
	double y1 = a.GetTungDo();
	double x2 = b.GetHoanhDo();
	double y2 = b.GetTungDo();
	double x3 = c.GetHoanhDo();
	double y3 = c.GetTungDo();
	a.SetHoanhDo(x1 / k);
	a.SetTungDo(y1 / k);
	b.SetHoanhDo(x2 / k);
	b.SetTungDo(y2 / k);
	c.SetHoanhDo(x3 / k);
	c.SetTungDo(y3 / k);
}

void TamGiac::Quay(double theta) {
	double x1 = a.GetHoanhDo();
	double y1 = a.GetTungDo();
	double x2 = b.GetHoanhDo();
	double y2 = b.GetTungDo();
	double x3 = c.GetHoanhDo();
	double y3 = c.GetTungDo();
	a.SetHoanhDo(x1 * cos(theta) - y1 * sin(theta));
	a.SetTungDo(x1 * sin(theta) + y1 * cos(theta));
	b.SetHoanhDo(x2 * cos(theta) - y2 * sin(theta));
	b.SetTungDo(x2 * sin(theta) + y2 * cos(theta));
	c.SetHoanhDo(x3 * cos(theta) - y3 * sin(theta));
	c.SetTungDo(x3 * sin(theta) + y3 * cos(theta));
}