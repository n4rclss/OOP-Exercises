#pragma once
#include <string>
using namespace std;

class ThiSinh {
private:
    string Ten;
    string MSSV;
    int iNgay;
    int iThang;
    int iNam;
    float fToan;
    float fVan;
    float fAnh;

public:
    // Phương thức nhập thông tin thí sinh
    void Nhap();

    // Phương thức xuất thông tin thí sinh
    void Xuat() const;

    // Phương thức tính tổng điểm
    float Tong() const;
};
