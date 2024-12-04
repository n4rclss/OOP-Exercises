#pragma once
#include "Phong.h"
class Deluxe : public Phong
{
private:
	double phiDichVu;	// Phí dịch vụ
	double phiPhucVu;	// Phí phục vụ
public:
	// Các phương thức khởi tạo
	Deluxe();
	Deluxe(int soDem, double phiDichVu, double phiPhucVu);

	// Các phương thức khác (đã được định nghĩa là phương thức ảo ở lớp cơ sở)
	double tinhDoanhThu();
	void Nhap();
	bool isDeluxe();
};

