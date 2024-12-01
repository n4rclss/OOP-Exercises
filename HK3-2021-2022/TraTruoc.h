#pragma once
#include "SIM.h"
class TraTruoc :
    public SIM
{
private:
	double m_SoDuTK;		// Số dư tài khoản
	int m_SoLanNap;			// Số lần nạp tiền
public:
	// Phương thức khởi tạo
	TraTruoc();
	TraTruoc(string t_SoSerial, string t_MaNhaMang, string t_SoDienThoai, bool t_TrangThai, double t_SoDuTK, int t_SoLanNap);

	// Phương thức hủy
	~TraTruoc();

	// Phương thức nhập/xuất thông tin
	void Nhap();
	void Xuat();

	// Phương thức tính khuyến mãi
	double TinhKhuyenMai();

	// Phương thức trả về true nếu là SIM trả trước
	bool isTraTruoc();

};

