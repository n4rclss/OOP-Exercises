#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class NhanVien
{
protected:
	string MaNhanVien;	// Mã nhân viên
	string HoTen;		// Họ tên
	double LuongCoBan;	// Lương cơ bản
public:
	// Các phương thức khởi tạo
	NhanVien();
	NhanVien(string MaNV, string hoten, double luongCB);

	// Phương thức nhập/xuất thông tin cơ bản
	void NhapThongTinCoBan();
	void XuatThongTinCoBan() const;
};

