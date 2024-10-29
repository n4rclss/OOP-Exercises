#include "ThiSinh.h"
#include <iostream>
using namespace std;

// Phương thức nhập thông tin thí sinh.
void ThiSinh::Nhap() {
    cout << "Nhap ten: ";
    getline(cin, Ten);
    cout << "Nhap MSSV: ";
    getline(cin, MSSV);
    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> iNgay >> iThang >> iNam;
    cout << "Nhap diem Toan: ";
    cin >> fToan;
    cout << "Nhap diem Van: ";
    cin >> fVan;
    cout << "Nhap diem Anh: ";
    cin >> fAnh;
    cin.ignore();
}

// Phương thức xuất thông tin thí sinh.
void ThiSinh::Xuat() const {
    cout << "Ten: " << Ten << "\nMSSV: " << MSSV << "\nNgay sinh: " << iNgay << "/" << iThang << "/" << iNam;
    cout << "\nDiem Toan: " << fToan << "\nDiem Van: " << fVan << "\nDiem Anh: " << fAnh;
    cout << "\nTong diem: " << Tong() << endl;
}

// Phương thức tính tổng điểm.
float ThiSinh::Tong() const {
    return fToan + fVan + fAnh;
}


