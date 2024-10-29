#pragma once
#include "Diem.h"
#include <iostream>

class DaGiac {
private:
    int n;        // Số đỉnh của đa giác
    Diem* Dinh;   // Mảng con trỏ tới các đối tượng Diem

public:
    // Phương thức khởi tạo và hủy
    DaGiac(int soDinh = 3);      // Khởi tạo với số đỉnh mặc định là 3 (Tam giác)
    DaGiac(const DaGiac& other); // Khởi tạo sao chép
    ~DaGiac();                    // Hàm hủy

    // Phương thức nhập và xuất
    void Nhap();
    void Xuat() const;

    // Phương thức tịnh tiến
    void TinhTien(double dX, double dY);

    // Phương thức phóng to
    void PhongTo(double k);

    // Phương thức thu nhỏ
    void ThuNho(double k);

    // Phương thức quay
    void Quay(double theta);

	// Phương thức tính diện tích
    double TinhDienTich() const;
};


