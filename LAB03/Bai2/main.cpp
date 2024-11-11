#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    SoPhuc a;
    double b;
    int c;
    int d = 3;
    cout << "=== Cac phep tinh se thuc hien voi a, b, c === \n";

    cout << "\n=== Nhap vao so phuc a (phan_thuc phan_ao, so thap phan b (double) va so nguyen c (int) === \n";
    cin >> a >> b >> c;

    cout << "\n=== Nguoi dung da nhap vao === \n"
        << "a = " << a
        << "\nb = " << b
        << "\nc = " << c << "\n";
     
	cout << SoPhuc(d) << "\n";
    cout << "\n=== Ket qua === \n";
	cout << a + b << "\n";
	cout << a - c << "\n";
    
    return 0;
}