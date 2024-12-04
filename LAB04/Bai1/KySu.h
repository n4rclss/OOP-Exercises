#pragma once
#include "NhanVien.h"
class KySu : public NhanVien
{
private:
	int SoGioLamThem;	// Số giờ làm thêm
public:
	// Các phương thức khởi tạo
	KySu();
	KySu(string MaNV, string hoten, double luongCB, int soGioLamThem);

	// Phương thức tính tiền thưởng
	double TienThuong() const;

	// Phương thức nhập/xuất thông tin
	void Nhap();
	void Xuat() const;
};

