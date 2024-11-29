#include "SIM.h"
#include "DaiLySIM.h"

int main()
{
	// Khởi tạo đại lý SIM
	DaiLySIM DsCacSIM;

	// Nhập danh sách SIM
	DsCacSIM.NhapDs();

	// Xuất danh sách SIM
	DsCacSIM.XuatDs();
	cout << "\n=====================\n";

	// Tính tổng khuyến mãi của SIM trả trước của nhà mạng AT&T (mã nhà mạng +002)
	cout << "Tong khuyen mai cua cac SIM tra truoc cua nha mang AT&T: " << fixed << setprecision(2) << DsCacSIM.TinhTongKhuyenMai_SIMTraTruoc("+002") << "\n";
	cout << "\n=====================\n";

	// Tìm SIM trả sau có số ghi nợ lớn nhất
	DsCacSIM.MaxSoGhiNo_SIMTraSau();
	return 0;
}