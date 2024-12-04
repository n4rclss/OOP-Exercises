#pragma once
#include "Phong.h"
class Premium : public Phong
{
private:
	double phiDichVu;	// Phi dich vu
public:
	// Các phương thức khởi tạo
	Premium();	
	Premium(int soDem, double phiDichVu);

	// Các phương thức khác (đã được định nghĩa là phương thức ảo ở lớp cơ sở)
	double tinhDoanhThu();	
	void Nhap();
	bool isPremium();
};

