#include "KhachSan.h"

int main()
{
	// Khởi tạo danh sách phòng với 5 phòng
	KhachSan ks(5);

	// Nhập thông tin các phòng
	ks.Nhap();

	// Xuất doanh thu theo từng phòng và loại phòng có doanh thu lớn nhất
	cout << "\n==============Doanh thu theo tung phong ==================\n";
	ks.XuatDoanhThu();
	ks.DoanhThuLonNhatTheoLoai();
	return 0;
}