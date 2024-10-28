#include "Diem.h"
#include <iostream>

using namespace std;

// Phương thức khởi tạo mặc định : Khởi tạo đối tượng Diem với hoành độ và tung độ mặc định
Diem::Diem() : iHoanh(0), iTung(0) {}

// Phương thức khởi tạo có tham số
Diem::Diem(double Hoanh, double Tung) : iHoanh(Hoanh), iTung(Tung) {}

// Phương thức khởi tạo sao chép
Diem::Diem(const Diem& x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

// Getter cho iTung (Tung độ)
double Diem::GetTungDo() const {
    return iTung;
}

// Getter cho iHoanh (Hoành độ)
double Diem::GetHoanhDo() const {
    return iHoanh;
}

// Setter cho iTung (Tung độ)
void Diem::SetTungDo(double Tung) {
    iTung = Tung;
}

// Setter cho iHoanh (Hoành độ)
void Diem::SetHoanhDo(double Hoanh) {
    iHoanh = Hoanh;
}

// Phương thức xuất
void Diem::Xuat() const {
    cout << "(" << iHoanh << ", " << iTung << ")\n";
}

void Diem::Nhap() {
    cout << "Nhap hoanh do va tung do: ";
    cin >> iHoanh >> iTung;
}

// Phương thức tịnh tiến
void Diem::TinhTien(double dX, double dY) {
    iHoanh += dX;
    iTung += dY;
}
