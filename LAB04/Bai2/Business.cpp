#include "Business.h"

// Khởi tạo mặc định
// Đặt loại phòng là Business
Business::Business() {}

// Khởi tạo với số đêm
// Đặt loại phòng là Business
Business::Business(int soDem) : Phong(soDem) {}

// Tính doanh thu
// Phòng Business = 300000 * số đêm
double Business::tinhDoanhThu()
{
	return SoDem * 300000;
}

// Nhập thông tin phòng Business
void Business::Nhap()
{
	Phong::Nhap();
}

// Kiểm tra loại phòng
bool Business::isBusiness()
{
	return true;
}
