#include "TamGiac.h"
#include <iostream>
using namespace std;

// Các phương thức khởi tạo đối tượng TamGiac
TamGiac::TamGiac() : a(), b(), c() {}

TamGiac::TamGiac(double a1, double a2, double b1, double b2, double c1, double c2) : a(a1, a2), b(b1, b2), c(c1, c2) { Check(); }

TamGiac::TamGiac(Diem a, Diem b, Diem c) : a(a), b(b), c(c) { Check(); }

TamGiac::TamGiac(const TamGiac& other) : a(other.a), b(other.b), c(other.c) {}

// Phương thức kiểm tra xem ba điểm có tạo thành một tam giác không
// Nếu ba điểm thẳng hàng thì không tạo thành tam giác
// Sử dụng định thức tam giác (x2 - x1)(y3 − y1) - (y2 − y1)(x3 − x1) != 0 để kiểm tra
bool TamGiac::Check()
{
	double x1 = a.GetHoanhDo();
	double y1 = a.GetTungDo();
	double x2 = b.GetHoanhDo();
	double y2 = b.GetTungDo();
	double x3 = c.GetHoanhDo();
	double y3 = c.GetTungDo();

	if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1)) {
		cout << "[!] Ba diem thang hang, khong phai la tam giac hop le." << endl;
		return false;
	}
	else {
		cout << "Day la tam giac hop le." << endl;
		return true;
	}
}

// Phương thức nhập thông tin cho tam giác
void TamGiac::Nhap()
{
	do {
		a.Nhap();
		b.Nhap();
		c.Nhap();
	} while (!Check());
}

// Phương thức xuất thông tin của tam giác
void TamGiac::Xuat()
{
	a.Xuat();
	cout << "; ";
	b.Xuat();
	cout << "; ";
	c.Xuat();
	cout << endl;
}

// Phương thức tịnh tiến tam giác
void TamGiac::TinhTien(double dx, double dy) {
	a.TinhTien(dx, dy);
	b.TinhTien(dx, dy);
	c.TinhTien(dx, dy);
}

// Phương thức phóng to tam giác
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

// Phương thức thu nhỏ tam giác
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

// Phương thức quay tam giác
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