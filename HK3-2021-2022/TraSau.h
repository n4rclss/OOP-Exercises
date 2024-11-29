#pragma once
#include "SIM.h"
class TraSau :
    public SIM
{
private:
	string m_GoiCuoc;		// Loại gói cước
	double m_SoGhiNo;		// Số ghi nợ
public:
	// Phương thức khởi tạo
	TraSau();
	TraSau(string t_SoSerial, string t_MaNhaMang, string t_SoDienThoai, bool t_TrangThai, string t_GoiCuoc, double t_SoGhiNo);

	// Phương thức hủy
	~TraSau();

	// Phương thức nhập/xuất thông tin
	void Nhap();
	void Xuat();

	// Phương thức tính khuyến mãi
	double TinhKhuyenMai();

	// Phương thức trả về true nếu là SIM trả sau
	bool isTraSau();
};

