#pragma once
#include "SIM.h"
#include "TraTruoc.h"
#include "TraSau.h"

class DaiLySIM
{
private:
	int m_SoLuong;			// Số lượng SIM
	SIM** m_pDsSIM;			// Mảng chứa danh sách các SIM

public:
	// Phương thức khởi tạo
	DaiLySIM();
	DaiLySIM(int t_SoLuong);

	// Phương thức hủy
	~DaiLySIM();

	// Phương thức nhập/xuất danh sách SIM
	void NhapDs();
	void XuatDs();

	// Phương thức tính tổng khuyến mãi của SIM trả trước của một nhà mạng (string t_MaNhaMang)
	double TinhTongKhuyenMai_SIMTraTruoc(string t_MaNhaMang);

	// Phương thức tìm SIM trả sau có số ghi nợ lớn nhất
	void MaxSoGhiNo_SIMTraSau();
};

