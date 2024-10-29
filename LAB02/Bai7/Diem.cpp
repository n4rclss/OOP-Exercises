#include "Diem.h"
#include <iostream>

using namespace std;

// Phương thức khởi tạo mặc định : Khởi tạo đối tượng Diem với hoành độ và tung độ mặc định
Diem::Diem() : dHoanh(0), dTung(0) {}

// Phương thức khởi tạo có tham số
Diem::Diem(double Hoanh, double Tung) : dHoanh(Hoanh), dTung(Tung) {}

// Phương thức khởi tạo sao chép
Diem::Diem(const Diem& x) : dHoanh(x.dHoanh), dTung(x.dTung) {}

// Getter cho dTung (Tung độ)
double Diem::GetTungDo() const {
    return dTung;
}

// Getter cho dHoanh (Hoành độ)
double Diem::GetHoanhDo() const {
    return dHoanh;
}

// Setter cho dTung (Tung độ)
void Diem::SetTungDo(double Tung) {
    dTung = Tung;
}

// Setter cho dHoanh (Hoành độ)
void Diem::SetHoanhDo(double Hoanh) {
    dHoanh = Hoanh;
}

// Phương thức xuất
void Diem::Xuat() const {
    cout << "(" << dHoanh << ", " << dTung << ")";
}

void Diem::Nhap() {
    // cout << "Nhap hoanh do va tung do: ";
    cin >> dHoanh >> dTung;
}

// Phương thức tịnh tiến
void Diem::TinhTien(double dX, double dY) {
    dHoanh += dX;
    dTung += dY;
}
