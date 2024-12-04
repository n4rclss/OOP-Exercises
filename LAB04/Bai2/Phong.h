#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Phong
{
protected:
	int SoDem;		// Số đêm
public:
	// Các phương thức khởi tạo
	Phong();
	Phong(int soDem);

	// Phương thức thuần ảo tính doanh thu
	virtual double tinhDoanhThu() = 0;
	// Phương thức ảo nhập thông tin
	virtual void Nhap();
	// Phương thức ảo kiểm tra loại phòng
	virtual bool isBusiness();
	virtual bool isDeluxe();
	virtual bool isPremium();
};

