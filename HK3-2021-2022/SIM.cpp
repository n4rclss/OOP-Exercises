#include "SIM.h"

// Phương thúc khởi tạo mặc định
// Khởi tạo mặc định cho một SIM, trạng thái mặc định là chưa kích hoạt
SIM::SIM() : m_SoSerial(""), m_MaNhaMang(""), m_SoDienThoai(""), m_TrangThai(false) {}

// Phương thức khởi tạo có tham số
// Khởi tạo một SIM với các thông số truyền vào
SIM::SIM(string t_SoSerial, string t_MaNhaMang, string t_SoDienThoai, bool t_TrangThai) : m_SoSerial(t_SoSerial), m_MaNhaMang(t_MaNhaMang), m_SoDienThoai(t_SoDienThoai), m_TrangThai(t_TrangThai) {}

// Phương thức hủy (hàm ảo)
SIM::~SIM() {}

// Phương thức nhập thông tin SIM
void SIM::Nhap()
{
	cout << "Nhap so serial: ";
	cin.ignore();
	getline(cin, m_SoSerial);
	cout << "Nhap ma nha mang: ";
	getline(cin, m_MaNhaMang);
	cout << "Nhap so dien thoai: ";
	getline(cin, m_SoDienThoai);
	cout << "Nhap trang thai (1: Kich hoat, 0: Chua kich hoat): ";
	cin >> m_TrangThai;
}

// Phương thức xuất thông tin SIM
void SIM::Xuat()
{
	cout << "So serial: " << m_SoSerial << "\n";
	cout << "Ma nha mang: " << m_MaNhaMang << "\n";
	cout << "So dien thoai: " << m_SoDienThoai << "\n";
	cout << "Trang thai: " << (m_TrangThai ? "Kich hoat" : "Chua kich hoat") << "\n";
}

// Phương thức trả về true nếu SIM là trả sau, ngược lại trả về false
bool SIM::isTraSau()
{
	return false;
}

// Phương thức trả về true nếu SIM là trả trước, ngược lại trả về false
bool SIM::isTraTruoc()
{
	return false;
}

// Phương thức trả về mã nhà mạng
string SIM::getMaNhaMang()
{
	return m_MaNhaMang;
}

// Phương thức trả về số ghi nợ ở SIM trả sau (hàm ảo)
double SIM::getSoGhiNo()
{
	return 0;
}