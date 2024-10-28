#include "TamGiac.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int main() {
    cout << "*************************************************\n";
    
	// Khoi tạo một đối tượng tam giác và nhập toạ độ 3 điểm
    TamGiac a;
	cout << "Nhap toa do 3 diem trong tam giac: \n";
    a.Nhap();

	cout << "*************************************************\n";
    
	// Sao chép đối tượng tam giác a vào b và thực hiện tịnh tiến
	TamGiac b(a);
    double x, y;
	cout << "Nhap vector tinh tien (x, y) de tinh tien tam giac (x y): ";
	cin >> x >> y;
	b.TinhTien(x, y);

	cout << "*************************************************\n";
	// Sao chép đối tượng tam giác a vào c và thực hiện phóng to
	TamGiac c(a);
	double k;
	do {
		cout << "Nhap he so phong to (>0) de phong to tam giac: ";
		cin >> k;
	}
	while (k > 1);
	c.PhongTo(k);

	cout << "*************************************************\n";
	// Sao chép đối tượng tam giác a vào d và thực hiện thu nhỏ
	TamGiac d(a);	
	do {
		cout << "Nhap he so thu nho (>0) de thu nho tam giac: ";
		cin >> k;
	}
	while (k > 1);
	d.ThuNho(k);

	cout << "*************************************************\n";
	// Sao chép đối tượng tam giác a vào e và thực hiện quay
	TamGiac e(a);	
	double theta;
	cout << "Nhap goc quay de quay tam giac (don vi radian): ";
	cin >> theta;
	theta = fmod(theta, 2 * M_PI);
	e.Quay(theta);

	cout << "*************************************************\n";
	// Xuat tam giac a, b, c, d, e
	cout << "[+] Tam giac ban dau: ";
	a.Xuat();
	cout << "[+] Tam giac sau tinh tien: ";
	b.Xuat();
	cout << "[+] Tam giac sau phong to: ";
	c.Xuat();
	cout << "[+] Tam giac sau thu nho: ";
	d.Xuat();
	cout << "[+] Tam giac sau quay: ";
	e.Xuat();

    return 0;
}