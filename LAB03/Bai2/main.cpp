#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    SoPhuc p1, p2;
    int a;
    double b;
	cout << "***********************************\n";
	cout << "Nhap so phuc p1: ";
	cin >> p1;
	cout << "Nhap so phuc p2: ";
	cin >> p2;
	cout << "Nhap so nguyen a: ";
	cin >> a;
	cout << "Nhap so thuc b: ";
	cin >> b;

	cout << "\n***********************************\n";
	cout << "Hai so phuc vua nhap: \n";
	cout << "p1 = " << p1 << "\n";
	cout << "p2 = " << p2 << "\n";

	cout << "\n***********************************\n";
	cout << "p1 + p2 = " << p1 + p2 << "\n";
	cout << "p1 - p2 = " << p1 - p2 << "\n";
	cout << "p1 * p2 = " << p1 * p2 << "\n";
	cout << "p1 / p2 = " << p1 / p2 << "\n";
	cout << "p1 == p2: " << (p1 == p2) << "\n";
	cout << "p1 != p2: " << (p1 != p2) << "\n";

	cout << "\n***********************************\n";
	cout << "p1 + a = " << p1 + a << "\n";
	cout << "p1 - a = " << p1 - a << "\n";
	cout << "p1 * a = " << p1 * a << "\n";
	cout << "p1 / a = " << p1 / a << "\n";

	cout << "\n***********************************\n";
	cout << "p1 + b = " << p1 + b << "\n";
	cout << "p1 - b = " << p1 - b << "\n";
	cout << "p1 * b = " << p1 * b << "\n";
	cout << "p1 / b = " << p1 / b << "\n";
	
    
    return 0;
}