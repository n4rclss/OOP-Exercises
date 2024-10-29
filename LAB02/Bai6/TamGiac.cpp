#include <iostream>
#include <iomanip>
#include <cmath>
#include "TamGiac.h"
using namespace std;

// Phương thức khởi tạo mặc định
TamGiac::TamGiac() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {}

// Phương thức khởi tạo có tham số
TamGiac::TamGiac(float ax1, float ay1, float bx2, float by2, float cx3, float cy3)
    : x1(ax1), y1(ay1), x2(bx2), y2(by2), x3(cx3), y3(cy3) {}

// Phương thức nhập tọa độ tam giác
void TamGiac::Nhap() {
    // Nhap toa do diem A
    cin >> x1 >> y1;
    //Nhap toa do diem B
    cin >> x2 >> y2;
	//Nhap toa do diem C
    cin >> x3 >> y3;
}

// Phương thức xuất tọa độ tam giác
void TamGiac::Xuat() const {
    cout << fixed << setprecision(5);
    cout << "(" << x1 << "," << y1 << ")" << endl;
    cout << "(" << x2 << "," << y2 << ")" << endl;
    cout << "(" << x3 << "," << y3 << ")" << endl;
}

// Phương thức tịnh tiến tam giác
void TamGiac::TinhTien(float huong, float khoangCach) {
    float huongRadian = huong * PI / 180.0; // Chuyển đổi từ độ sang radian
    float dx = khoangCach * cos(huongRadian);
    float dy = khoangCach * sin(huongRadian);

    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}
