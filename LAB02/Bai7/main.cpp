#include "DaGiac.h"
#include <iostream>
using namespace std;

int main() {
    DaGiac a;

    // Nhập tọa độ cho đa giác
    a.Nhap();
	cout << "Dien tich da giac: " << a.TinhDienTich() << endl;

    return 0;
}