#include "TraSau.h"

// Phương thức khởi tạo mặc định
// Khởi tạo mặc định cho một SIM trả sau, gói cước mặc định là rỗng, số ghi nợ mặc định là 0
TraSau::TraSau() : m_GoiCuoc(""), m_SoGhiNo(0) {}

// Phương thức khởi tạo có tham số
// Khởi tạo một SIM trả sau với các thông số truyền vào
TraSau::TraSau(string t_SoSerial, string t_MaNhaMang, string t_SoDienThoai, bool t_TrangThai, string t_GoiCuoc, double t_SoGhiNo) : SIM(t_SoSerial, t_MaNhaMang, t_SoDienThoai, t_TrangThai), m_GoiCuoc(t_GoiCuoc), m_SoGhiNo(t_SoGhiNo) {}

// Phương thức hủy
TraSau::~TraSau() {}

// Phương thức nhập thông tin
// Gọi phương thức nhập thông tin cơ bản của SIM, sau đó nhập thêm gói cước và số ghi nợ
void TraSau::Nhap()
{
	SIM::Nhap();
	cout << "Nhap goi cuoc: ";
	cin.ignore();
	getline(cin, m_GoiCuoc);
	cout << "Nhap so ghi no: ";
	cin >> m_SoGhiNo;
}

// Phương thức xuất thông tin
// Gọi phương thức xuất thông tin cơ bản của SIM, sau đó xuất thêm gói cước và số ghi nợ
void TraSau::Xuat()
{
	SIM::Xuat();
	cout << "Goi cuoc: " << m_GoiCuoc << "\n";
	cout << "So ghi no: " << fixed << setprecision(2) << m_SoGhiNo << "\n";
	cout << "Khuyen mai: " << fixed << setprecision(2) << TinhKhuyenMai() << "\n";
}

// Phương thức tính khuyến mãi
double TraSau::TinhKhuyenMai()
{
	if (m_GoiCuoc == "LCAP")
		return m_SoGhiNo * 0.05;
	else if (m_GoiCuoc == "MCAP")
		return m_SoGhiNo * 0.1;
	else if (m_GoiCuoc == "HCAP")
		return m_SoGhiNo * 0.15;
	else
		return 0;
}

// Phương thức trả về true nếu là SIM trả sau (luôn trả về true vì đây là hàm của lớp TraSau)
bool TraSau::isTraSau()
{
	return true;
}

// Phương thức trả về số ghi nợ
double TraSau::getSoGhiNo()
{
	return m_SoGhiNo;
}