#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class SIM
{
protected:
	string m_SoSerial;		// Số serial của SIM
	string m_MaNhaMang;		// Mã nhà mạng
	string m_SoDienThoai;	// Số điện thoại
	bool m_TrangThai;		// Trạng thái (true: Kích hoạt, false: Chưa kích hoạt)
public:
	// Phương thức khởi tạo
	SIM();
	SIM(string t_SoSerial, string t_MaNhaMang, string t_SoDienThoai, bool t_TrangThai);

	// Phương thức hủy (hàm ảo)
	virtual ~SIM();

	// Phương thức nhập/xuất thông tin SIM
	virtual void Nhap();
	virtual void Xuat();

	// Phương thức tính khuyen mai (hàm thuần ảo)
	virtual double TinhKhuyenMai() = 0;

	// Phương thức trả về true nếu SIM là trả sau, ngược lại trả về false
	virtual bool isTraSau();
	virtual bool isTraTruoc();

	// Phương thức trả về mã nhà mạng
	string getMaNhaMang();

	// Phương thức trả về số ghi nợ ở SIM trả sau (hàm thuần ảo)
	virtual double getSoGhiNo();
};

