#include "KySu.h"

// Khởi tạo mặc định
// Gọi khởi tạo mặc định của lớp cơ sở và số giờ làm thêm là 0
KySu::KySu() : NhanVien(), SoGioLamThem(0) {}

// Khởi tạo với đầy đủ thông tin
KySu::KySu(string MaNV, string hoten, double luongCB, int soGioLamThem) : NhanVien(MaNV, hoten, luongCB), SoGioLamThem(soGioLamThem) {}

// Tính tiền thưởng
// Tiền thường của kỹ sư = số giờ làm thêm * 100 000
double KySu::TienThuong() const
{
	return SoGioLamThem * 100000;
}

// Nhập thông tin
// Gọi phương thức nhập thông tin cơ bản của lớp cơ sở và nhập số giờ làm thêm
void KySu::Nhap()
{
	NhanVien::NhapThongTinCoBan();
	do {
		cout << "Nhap so gio lam them: ";
		cin >> SoGioLamThem;
	} while (SoGioLamThem < 0);
}

// Xuất thông tin
// Gọi phương thức xuất thông tin cơ bản của lớp cơ sở, sau đó xuất số giờ làm thêm và tiền thưởng
void KySu::Xuat() const
{
	NhanVien::XuatThongTinCoBan();
	cout << "So gio lam them: " << SoGioLamThem << "\n";
	cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << "\n";
}

