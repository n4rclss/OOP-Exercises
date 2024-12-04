#include "Deluxe.h"

// Khởi tạo mặc định
// Đặt loại phòng là Deluxe
Deluxe::Deluxe() : Phong(), phiDichVu(0), phiPhucVu(0) {}

// Khởi tạo với số đêm, phí dịch vụ và phí phục vụ
// Đặt loại phòng là Deluxe
Deluxe::Deluxe(int soDem, double phiDichVu, double phiPhucVu) : Phong(soDem), phiDichVu(phiDichVu), phiPhucVu(phiPhucVu) {}

// Tính doanh thu
// Phòng Deluxe = 750000 * số đêm + phí dịch vụ + phí phục vụ
double Deluxe::tinhDoanhThu()
{
	return SoDem * 750000 + phiDichVu + phiPhucVu;
}

// Nhập thông tin phòng Deluxe
void Deluxe::Nhap()
{
	Phong::Nhap();
	do {
		cout << "Nhap phi dich vu: ";
		cin >> phiDichVu;
	} while (phiDichVu <= 0);
	do {
		cout << "Nhap phi phuc vu: ";
		cin >> phiPhucVu;
	} while (phiPhucVu <= 0);
}

// Kiểm tra loại phòng
bool Deluxe::isDeluxe()
{
	return true;
}