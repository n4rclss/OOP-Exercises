#include "DaGiac.h"
#include <iostream>
using namespace std;

// Phương thức khởi tạo với số đỉnh n
DaGiac::DaGiac(int soDinh) : n(soDinh) {
    Dinh = new Diem[n]; // Cấp phát bộ nhớ cho các đỉnh với toạ độ mặc định là (0,0)
}

// Phương thức khởi tạo sao chép
DaGiac::DaGiac(const DaGiac& other) : n(other.n) {
    Dinh = new Diem[n];
    for (int i = 0; i < n; ++i) {
        Dinh[i] = other.Dinh[i];
    }
}

// Hàm hủy
DaGiac::~DaGiac() {
    delete[] Dinh; // Giải phóng bộ nhớ
}

// Phương thức nhập
void DaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac (>= 3): ";
        cin >> n;
    } while (n < 3);
    delete[] Dinh;            // Giải phóng bộ nhớ cũ nếu có
    Dinh = new Diem[n];       // Cấp phát lại bộ nhớ cho số đỉnh mới
    for (int i = 0; i < n; ++i) {
        cout << "Nhap toa do dinh thu " << i + 1 << ": ";
        Dinh[i].Nhap();
    }
}

// Phương thức xuất
void DaGiac::Xuat() const {
    cout << "Da giac voi cac dinh: ";
    for (int i = 0; i < n; ++i) {
        Dinh[i].Xuat();
        if (i < n - 1) cout << "; ";
    }
    cout << endl;
}

// Phương thức tịnh tiến
void DaGiac::TinhTien(double dX, double dY) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].TinhTien(dX, dY);
    }
}

// Phương thức phóng to
void DaGiac::PhongTo(double k) {
    for (int i = 0; i < n; ++i) {
        double x = Dinh[i].GetHoanhDo();
        double y = Dinh[i].GetTungDo();
        Dinh[i].SetHoanhDo(x * k);
        Dinh[i].SetTungDo(y * k);
    }
}

// Phương thức thu nhỏ
void DaGiac::ThuNho(double k) {
    for (int i = 0; i < n; ++i) {
        double x = Dinh[i].GetHoanhDo();
        double y = Dinh[i].GetTungDo();
        Dinh[i].SetHoanhDo(x / k);
        Dinh[i].SetTungDo(y / k);
    }
}

// Phương thức quay
void DaGiac::Quay(double theta) {
    for (int i = 0; i < n; ++i) {
        double x = Dinh[i].GetHoanhDo();
        double y = Dinh[i].GetTungDo();
        Dinh[i].SetHoanhDo(x * cos(theta) - y * sin(theta));
        Dinh[i].SetTungDo(x * sin(theta) + y * cos(theta));
    }
}

double DaGiac::TinhDienTich() const {
    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n; // Chỉ số của đỉnh tiếp theo, quay về 0 nếu là đỉnh cuối
        area += Dinh[i].GetHoanhDo() * Dinh[j].GetTungDo();
        area -= Dinh[i].GetTungDo() * Dinh[j].GetHoanhDo();
    }

    return abs(area) / 2.0;
}