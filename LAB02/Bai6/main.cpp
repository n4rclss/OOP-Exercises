#include "TamGiac.h"
#include <iostream>
using namespace std;

int main() {
    TamGiac tamGiac;

    // Nhập tọa độ cho tam giác
    tamGiac.Nhap();

    // Nhập hướng và khoảng cách tịnh tiến
    float huong, khoangCach;
	cin >> huong >> khoangCach;

    // Thực hiện tịnh tiến tam giác
    tamGiac.TinhTien(huong, khoangCach);

    // In ra tọa độ sau khi tịnh tiến
    cout << "Toa do tam giac sau khi tinh tien:" << endl;
    tamGiac.Xuat();

    return 0;
}
