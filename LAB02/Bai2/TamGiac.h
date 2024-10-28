#include "Diem.h"
#pragma once

class TamGiac {
private:
    Diem a; // Điểm A
    Diem b; // Điểm B
    Diem c; // Điểm C
public:
    //Constructors
    TamGiac();      // Hàm tạo mặc định
    TamGiac(Diem a, Diem b, Diem c);        //Hàm tạo có tham số
    TamGiac(double a1, double a2, double b1, double b2, double c1, double c2);      //Hàm tạo có tham số
    TamGiac(const TamGiac& other);      //Hàm tạo sao chép

    // Các phương thức khác
    bool Check();
    void Nhap();
    void Xuat();
    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double theta);
};