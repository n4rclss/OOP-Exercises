#include "TraTruoc.h"

// Phương thức khởi tạo 
// Khởi tạo mặc định cho một SIM trả trước, số dư tài khoản và số lần nạp tiền mặc định là 0
TraTruoc::TraTruoc() : m_SoDuTK(0), m_SoLanNap(0) {}

// Phương thức khởi tạo có tham số
// Khởi tạo một SIM trả trước với các thông số truyền vào
TraTruoc::TraTruoc(string t_SoSerial, string t_MaNhaMang, string t_SoDienThoai, bool t_TrangThai, double t_SoDuTK, int t_SoLanNap) : SIM(t_SoSerial, t_MaNhaMang, t_SoDienThoai, t_TrangThai), m_SoDuTK(t_SoDuTK), m_SoLanNap(t_SoLanNap) {}

// Phương thức hủy
TraTruoc::~TraTruoc() {}

// Phương thức nhập thông tin
// Gọi phương thức nhập thông tin cơ bản của SIM, sau đó nhập thêm số dư tài khoản và số lần nạp tiền
void TraTruoc::Nhap()
{
	SIM::Nhap();
	cout << "Nhap so du tai khoan: ";
	cin >> m_SoDuTK;
	cout << "Nhap so lan nap: ";
	cin >> m_SoLanNap;
}

// Phương thức xuất thông tin
// Gọi phương thức xuất thông tin cơ bản của SIM, sau đó xuất thêm số dư tài khoản và số lần nạp tiền
void TraTruoc::Xuat()
{
	SIM::Xuat();
	cout << "So du tai khoan: " << fixed << setprecision(2) << m_SoDuTK << "\n";
	cout << "So lan nap: " << m_SoLanNap << "\n";
	cout << "Khuyen mai: " << fixed << setprecision(2) << TinhKhuyenMai() << "\n";
}

// Phương thức tính khuyến mãi
double TraTruoc::TinhKhuyenMai()
{
	if (m_SoLanNap < 5)
		return m_SoDuTK * 0.1;
	else if (m_SoLanNap <= 10)
		return m_SoDuTK * 0.2;
	else
		return m_SoDuTK * 0.5;
}

// Phương thức trả về true nếu là SIM trả trước (luôn trả về true vì đây là hàm của lớp TraTruoc)
bool TraTruoc::isTraTruoc()
{
	return true;
}