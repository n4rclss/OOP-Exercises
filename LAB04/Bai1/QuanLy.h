#pragma once
#include "NhanVien.h"
class QuanLy : public NhanVien
{
private:
	double TyLeThuong;	// Tỷ lệ thưởng (từ 0-100)
public:
	// Các phương thức khởi tạo
	QuanLy();
	QuanLy(string MaNV, string hoten, double luongCB, double tlThuong);

	// Phương thức tính tiền thưởng
	double TienThuong() const;

	// Phương thức nhập/xuất thông tin
	void Nhap();
	void Xuat() const;
};

