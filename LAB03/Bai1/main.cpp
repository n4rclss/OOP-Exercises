#include "PhanSo.h"
#include <iostream>
using namespace std;

int main() {
    PhanSo a, b;
    int c;
    cout << "=== Cac phep tinh se thuc hien voi a, b, c === \n";
    cout << "1. (a + 2c - 5b + 3) * 10\n"
        << "2. (10/9 + 5/2 * c) / a\n"
        << "3. (a + b) / c\n"
        << "4. flag1 = (a < b) ? 1 : 0\n"
        << "5. flag2 = (b > c) ? 1 : 0\n"
        << "6. flag3 = (a >= b+c) ? 1 : 0\n"
        << "7. flag4 = (c <= a+b) ? 1 : 0\n"
        << "8. flag5 = (a == c) ? 1 : 0\n"
        << "9. flag6 = (a != c) ? 1 : 0\n";

    cout << "\n=== Nhap vao 2 phan so a, b (tu mau) va so nguyen c === \n";
	cout << "Nhap a: ";
    cin >> a;
	cout << "Nhap b: ";
    cin >> b;
	cout << "Nhap c: ";
    cin >> c;

    cout << "\n=== Nguoi dung da nhap vao === \n"
        << "a = " << a
        << "\nb = " << b
        << "\nc = " << c << "\n";

    cout << "\n=== Ket qua === \n";
    cout << "1. (a + 2c - 5b + 3) * 10 = " << ((a + 2 * c - 5 * b + 3) * 10)
        << "\n2. (10/9 + 5/2 * c) / a = " << ((10 / 9 + 5 / 2 * c) / a)
        << "\n3. (a + b) / c = " << ((a + b) / c)
        << "\n4. flag1 = (a < b) ? 1 : 0 = " << (a < b)
        << "\n5. flag2 = (b > c) ? 1 : 0 = " << (b > c)
        << "\n6. flag3 = (a >= b+c) ? 1 : 0 = " << (a >= b + c)
        << "\n7. flag4 = (c <= a+b) ? 1 : 0 = " << (c <= a + b)
        << "\n8. flag5 = (a == c) ? 1 : 0 = " << (a == c)
        << "\n9. flag6 = (a != c) ? 1 : 0 = " << (a != c)
        << "\n";
    
    return 0;
}