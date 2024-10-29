#include "DaGiac.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int main() {
	cout << "*************************************************\n";

	// Khoi tạo một đối tượng đa giác và nhập toạ độ 3 điểm
	DaGiac a;
	cout << "Nhap toa do cac diem trong da giac: \n";
	a.Nhap();

	cout << "*************************************************\n";

	// Sao chép đối tượng đa giác a vào b và thực hiện tịnh tiến
	DaGiac b(a);
	double x, y;
	cout << "Nhap vector tinh tien (x, y) de tinh tien da giac (x y): ";
	cin >> x >> y;
	b.TinhTien(x, y);

	cout << "*************************************************\n";
	// Sao chép đối tượng đa giác a vào c và thực hiện phóng to
	DaGiac c(a);
	double k = 0;
	do {
		cout << "Nhap he so phong to (>=1) de phong to da giac: ";
		cin >> k;
	} while (k < 1);
	c.PhongTo(k);

	cout << "*************************************************\n";
	// Sao chép đối tượng đa giác a vào d và thực hiện thu nhỏ
	DaGiac d(a);
	k = 0;
	do {
		cout << "Nhap he so thu nho (>=1) de thu nho da giac: ";
		cin >> k;
	} while (k < 1);
	d.ThuNho(k);

	cout << "*************************************************\n";
	// Sao chép đối tượng đa giác a vào e và thực hiện quay
	DaGiac e(a);
	double theta;
	cout << "Nhap goc quay de quay da giac (don vi radian): ";
	cin >> theta;
	theta = fmod(theta, 2 * M_PI);
	e.Quay(theta);

	cout << "*************************************************\n";
	// Xuat da giac a, b, c, d, e
	cout << "[+] Da giac ban dau: ";
	a.Xuat();
	cout << "[+] Da giac sau tinh tien: ";
	b.Xuat();
	cout << "[+] Da giac sau phong to: ";
	c.Xuat();
	cout << "[+] Da giac sau thu nho: ";
	d.Xuat();
	cout << "[+] Da giac sau quay: ";
	e.Xuat();

	return 0;
}