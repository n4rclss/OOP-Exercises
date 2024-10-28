#include "Diem.h"
#pragma once

class TamGiac {
private:
    Diem a;
    Diem b;
    Diem c;
public:
    TamGiac();
    TamGiac(Diem a, Diem b, Diem c);
    TamGiac(double a1, double a2, double b1, double b2, double c1, double c2);
    TamGiac(const TamGiac& other);
    bool Check();
    void Nhap();
    void Xuat();
    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double theta);
};