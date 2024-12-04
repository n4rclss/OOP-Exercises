#pragma once
#include "Phong.h"
class Business : public Phong
{
public:
	// Các phương thức khởi tạo
	Business();		
	Business(int soDem);

	// Các phương thức khác (đã được định nghĩa là phương thức ảo ở lớp cơ sở)
	double tinhDoanhThu();
	void Nhap();
	bool isBusiness();
};

