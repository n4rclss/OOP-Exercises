#include "NhanVien.h"

// Khởi taọ mặc định
NhanVien::NhanVien() : MaNhanVien(""), HoTen(""), LuongCoBan(0) {}

// Khởi tạo với đầy đủ thông tin cơ bản
NhanVien::NhanVien(string MaNV, string hoten, double luongCB) : MaNhanVien(MaNV), HoTen(hoten), LuongCoBan(luongCB) {}

// Nhập thông tin cơ bản của nhân viên
void NhanVien::NhapThongTinCoBan()
{
	cout << "Nhap ma nhan vien: ";
	getline(cin, MaNhanVien);
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	do {
		cout << "Nhap luong co ban: ";
		cin >> LuongCoBan;
	} while (LuongCoBan <= 0);
}

// Xuất thông tin cơ bản của nhân viên
void NhanVien::XuatThongTinCoBan() const
{
	cout << "Ma nhan vien: " << MaNhanVien << "\n";
	cout << "Ho ten: " << HoTen << "\n";
	cout << "Luong co ban: " << fixed << setprecision(2) << LuongCoBan << "\n";
}
