#include "Premium.h"

// Khởi taọ mặc định
// Đặt loại phòng là Premium
Premium::Premium() : phiDichVu(0) {}

// Khởi tạo với số đêm và phí dịch vụ
// Đặt loại phòng là Premium
Premium::Premium(int soDem, double phiDichVu) : Phong(soDem), phiDichVu(phiDichVu) {}

// Tính doanh thu
// Phòng Premium = 500000 * số đêm + phí dịch vụ
double Premium::tinhDoanhThu()
{
	return SoDem * 500000 + phiDichVu;
}

// Nhập thông tin phòng Premium
void Premium::Nhap()
{
	Phong::Nhap();
	do {
		cout << "Nhap phi dich vu: ";
		cin >> phiDichVu;
	} while (phiDichVu <= 0);
}

// Kiểm tra loại phòng
bool Premium::isPremium()
{
	return true;
}