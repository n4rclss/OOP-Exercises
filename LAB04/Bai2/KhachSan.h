#pragma once
#include "Phong.h"
#include "Deluxe.h"
#include "Business.h"
#include "Premium.h"
#include <iostream>
#include <iomanip>
using namespace std;

class KhachSan
{
private:
	int SoPhong;	// Số lượng phòng
	Phong** phong;	// Danh sách các phòng
public:
	// Các phương thức khởi tạo và huỷ
	KhachSan();
	KhachSan(int soPhong);
	~KhachSan();
	// Các phương thức khác
	void Nhap();
	void XuatDoanhThu();
	void DoanhThuLonNhatTheoLoai();
};

