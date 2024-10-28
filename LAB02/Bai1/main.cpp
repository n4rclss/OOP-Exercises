#include "Diem.h"
#include <iostream>
using namespace std;

int main() {
    // Khởi tạo đối tượng Diem a
    Diem a;
    cout << "**********************************************************\n";
    cout << "Diem khoi tao mac dinh: ";
    a.Xuat();

    cout << "**********************************************************\n";
	// Gọi phương thức nhập
    cout << "Nhap lai hoanh do va tung do cho diem vua khoi tao: \n";
    a.Nhap();
    cout << "Diem vua nhap duoc: ";
    a.Xuat();

	cout << "**********************************************************\n";
	// Sao chép đối tượng a vào đối tượng b và tịnh tiến điểm b
	Diem b(a);
    double x, y;
    cout << "Nhap vector (x, y) de tinh tien diem vua nhap (x y): ";
    cin >> x >> y;
    // Thực thi phương thức tịnh tiến
    b.TinhTien(x, y);
    cout << "Diem sau khi tinh tien: ";
    b.Xuat();

    cout << "**********************************************************\n";
	// Nhập lại giá trị hoành và tung của điểm bằng phương thức Set
	double hoanh, tung;
	cout << "Nhap lai hoanh do va tung do cho diem vua tinh tien: "; 
	cin >> hoanh >> tung;
	b.SetHoanhDo(hoanh);
	b.SetTungDo(tung);

    cout << "**********************************************************\n";
	// In ra giá trị hoành và tung của điểm bằng phương thức Get
	cout << "Diem sau khi tinh tien va nhap lai: \n";
    cout << "Hoanh do: " << b.GetHoanhDo() << endl;
	cout << "Tung do: " << b.GetTungDo() << endl;
    cout << "\nDiem ban dau:\n";
	cout << "Hoanh do: " << a.GetHoanhDo() << endl;
	cout << "Tung do: " << a.GetTungDo() << endl;

    return 0;
}