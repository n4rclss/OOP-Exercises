#include "QuanLy.h"

// Khởi tạo mặc định
// Gọi khởi tạo mặc định của lớp cơ sở và tỷ lệ thưởng là 0
QuanLy::QuanLy() : NhanVien(), TyLeThuong(0) {}

// Khởi tạo với đầy đủ thông tin
QuanLy::QuanLy(string MaNV, string hoten, double luongCB, double tlThuong) : NhanVien(MaNV, hoten, luongCB), TyLeThuong(tlThuong) {}

// Tính tiền thưởng
// Tiền thưởng của quản lý = lương cơ bản * (tỷ lệ thưởng * 0.01)
// Với tỷ lệ thưởng là phần trăm
double QuanLy::TienThuong() const
{
	return LuongCoBan * (TyLeThuong * 0.01);
}

// Nhập thông tin
// Gọi phương thức nhập thông tin cơ bản của lớp cơ sở và nhập tỷ lệ thưởng
void QuanLy::Nhap()
{
	NhanVien::NhapThongTinCoBan();
	do {
		cout << "Nhap phan tram ty le thuong (0-100%): ";
		cin >> TyLeThuong;
	} while (TyLeThuong < 0 || TyLeThuong > 100);
}

// Xuất thông tin
// Gọi phương thức xuất thông tin cơ bản của lớp cơ sở, sau đó xuất tiền thưởng
void QuanLy::Xuat() const
{
	NhanVien::XuatThongTinCoBan();
	cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << "\n";
}

