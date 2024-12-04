#include "QuanLy.h"
#include "KySu.h"

int main()
{
	QuanLy ql;
	KySu ks;
	// Nhập thông tin cho quản lý
	cout << "Nhap thong tin quan ly: \n";
	ql.Nhap();
	cin.ignore();

	cout << "\n";

	// Nhập thông tin cho kỹ sư
	cout << "Nhap thong tin ky su: \n";
	ks.Nhap();

	// Xuất thông tin
	cout << "\n====Thong tin nhan vien====\n";
	ql.Xuat();
	cout << "-----------------------------\n";
	ks.Xuat();
	return 0;
}