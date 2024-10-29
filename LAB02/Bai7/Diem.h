#pragma once

class Diem {
private:
    double dHoanh;  // Tọa độ hoành
    double dTung;   // Tọa độ tung

public:
    // Constructors
    Diem(); // Hàm tạo mặc định
    Diem(double Hoanh, double Tung); // Hàm tạo có tham số
    Diem(const Diem& x); // Hàm tạo sao chép

    // Getters và Setters
    double GetTungDo() const;
    double GetHoanhDo() const;
    void SetTungDo(double Tung);
    void SetHoanhDo(double Hoanh);

    // Phương thức xuất
    void Xuat() const;

    // Phương thức nhập
    void Nhap();

    // Phương thức tịnh tiến
    void TinhTien(double dX, double dY);
};
