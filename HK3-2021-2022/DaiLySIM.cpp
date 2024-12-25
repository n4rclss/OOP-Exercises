#include "DaiLySIM.h"

// Phương thức khởi tạo mặc định
// Khởi tạo mặc định con trỏ mảng SIM là NULL (tức chưa có danh sách) và số lượng SIM là 0
DaiLySIM::DaiLySIM()
{
	m_pDsSIM = NULL;
	m_SoLuong = 0;
} 

// Phương thức khởi tạo có tham số
// Khởi tạo một đại lý SIM với số lượng SIM truyền vào 
// và cấp phát động mảng chứa các SIM
DaiLySIM::DaiLySIM(int t_SoLuong)
{
	m_pDsSIM = new SIM* [t_SoLuong];
	m_SoLuong = t_SoLuong;
}

// Phương thức hủy
// Hủy từng phần tử trong mảng SIM, sau đó hủy mảng
DaiLySIM::~DaiLySIM()
{
	for (int i = 0; i < m_SoLuong; i++)
		delete m_pDsSIM[i];
	delete[] m_pDsSIM;
}

// Phương thức nhập danh sách SIM
// Nhập số lượng SIM, sau đó nhập từng SIM
void DaiLySIM::NhapDs()
{
	cout << "Nhap so luong SIM: ";
	cin >> m_SoLuong;
	m_pDsSIM = new SIM * [m_SoLuong];
	for (int i = 0; i < m_SoLuong; i++)
	{
		int loai;
		cout << "Nhap loai SIM (1: Tra truoc, 2: Tra sau): ";
		cin >> loai;
		switch (loai)
		{
		case 1:
			m_pDsSIM[i] = new TraTruoc();
			break;
		case 2:
			m_pDsSIM[i] = new TraSau();
			break;
		default:
			cout << "Loai SIM khong hop le\n";
			i--;
			break;
		}
		m_pDsSIM[i]->Nhap();
	}
}

// Phương thức xuất danh sách SIM
// Xuất từng SIM trong mảng
void DaiLySIM::XuatDs()
{
	for (int i = 0; i < m_SoLuong; i++)
	{
		cout << "SIM thu " << i + 1 << "\n";
		m_pDsSIM[i]->Xuat();
	}
}

// Phương thức tính tổng khuyến mãi của SIM trả trước của một nhà mạng 
// Input: t_MaNhaMang - mã nhà mạng cần tính tổng khuyến mãi
// Output: tổng khuyến mãi của SIM trả trước của nhà mạng t_MaNhaMang
double DaiLySIM::TinhTongKhuyenMai_SIMTraTruoc(string t_MaNhaMang)
{
	double tong = 0;
	for (int i = 0; i < m_SoLuong; i++)
		if (m_pDsSIM[i]->isTraTruoc() && m_pDsSIM[i]->getMaNhaMang() == t_MaNhaMang)
			tong += m_pDsSIM[i]->TinhKhuyenMai();
	return tong;
}

// Phương thức tìm SIM trả sau có số ghi nợ lớn nhất
// Output: thông tin của SIM trả sau có số ghi nợ lớn nhất
void DaiLySIM::MaxSoGhiNo_SIMTraSau()
{
	double max = 0;
	int i = 0;
	vector<int> DsLonNhat;

	// Tìm SIM trả sau đầu tiên và để là max
	for (; i < m_SoLuong; i++)
		if (m_pDsSIM[i]->isTraSau())
		{
			max = m_pDsSIM[i]->getSoGhiNo();
			break;
		}

	// Nếu không có SIM trả sau nào
	if (i == m_SoLuong) {
		cout << "Khong co SIM tra sau nao\n";
		return;
	}

	// Duyệt danh sách SIM và tìm ra danh sách gồm một hay nhiều SIM trả sau có số ghi nợ lớn nhất
	for (; i < m_SoLuong; i++)
	{
		if (m_pDsSIM[i]->isTraSau() && m_pDsSIM[i]->getSoGhiNo() > max)
		{
			max = m_pDsSIM[i]->getSoGhiNo();
			DsLonNhat.clear();
			DsLonNhat.push_back(i);
		}
		else if (m_pDsSIM[i]->isTraSau() && m_pDsSIM[i]->getSoGhiNo() == max)
			DsLonNhat.push_back(i);
		else
			continue;
	}

	// In kết quả
	cout << "SIM tra sau co so ghi no lon nhat: \n";
	for (int i = 0; i < DsLonNhat.size(); i++)
	{
		cout << "-----SIM thu " << DsLonNhat[i] + 1 << "-----\n";
		m_pDsSIM[DsLonNhat[i]]->Xuat();
	}
}