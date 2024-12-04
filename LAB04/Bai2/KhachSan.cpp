#include "KhachSan.h"

// Khởi tạo mặc định
KhachSan::KhachSan()
{
	SoPhong = 0;
	phong = nullptr;
}

// Khởi tạo với số phòng
// Cấp phát động mảng phòng có số lượng phần từ là số phòng
KhachSan::KhachSan(int soPhong) : SoPhong(soPhong)
{
	phong = new Phong* [SoPhong];
}

// Nhập thông tin các phòng
void KhachSan::Nhap()
{
	// Nhập thông tin phòng theo từng loại phòng tương ứng
	cout << "Nhap danh sach cac phong:\n";
	for (int i = 0; i < SoPhong; i++)
	{
		int loai;
		cout << "-------Phong " << i + 1 << "------\n";
		cout << "Loai phong (1: Deluxe, 2: Premium, 3: Business): ";
		cin >> loai;
		switch (loai)
		{
		case 1:
			phong[i] = new Deluxe();
			break;
		case 3:
			phong[i] = new Business();
			break;
		case 2:
			phong[i] = new Premium();
			break;
		default:
		{
			cout << "Loai phong khong hop le\n";
			i--;
			continue;
		}
		}
		phong[i]->Nhap();
	}
}

// Xuất doanh thu của các phòng
void KhachSan::XuatDoanhThu()
{
	for (int i = 0; i < SoPhong; i++)
	{
		cout << "Phong " << i + 1 << ": " 
			<< fixed << setprecision(2) << phong[i]->tinhDoanhThu() << "\n";
	}
}

// Tính tổng doanh thu của khách sạn theo từng loại
// Rồi so sánh để tìm loại phòng có doanh thu lớn nhất
void KhachSan::DoanhThuLonNhatTheoLoai()
{
	double sumDeluxe = 0, sumBusiness = 0, sumPremium = 0;
	string loaiMax;

	// Tính tổng doanh thu của từng loại phòng
	for (int i = 0; i < SoPhong; i++)
	{
		if (phong[i]->isDeluxe())
			sumDeluxe += phong[i]->tinhDoanhThu();
		if (phong[i]->isBusiness())
			sumBusiness += phong[i]->tinhDoanhThu();
		if (phong[i]->isPremium())
			sumPremium += phong[i]->tinhDoanhThu();
	}

	// So sánh để tìm loại phòng có doanh thu lớn nhất
	if (sumDeluxe > sumBusiness && sumDeluxe > sumPremium)
	{
		loaiMax = "Deluxe";
	}
	else if (sumBusiness > sumDeluxe && sumBusiness > sumPremium)
	{
		loaiMax = "Business";
	}
	else
	{
		loaiMax = "Premium";
	}

	// Xuất kết quả
	cout << "Loai phong co doanh thu lon nhat: " << loaiMax << "\n";
	cout << "Tong doanh thu cua loai phong do: " << fixed << setprecision(2) << max(sumDeluxe, max(sumBusiness, sumPremium)) << "\n";
	
}

// Hủy mảng phòng
KhachSan::~KhachSan()
{
	// Xóa từng phần tử trong mảng phòng
	for (int i = 0; i < SoPhong; i++)
	{
		delete phong[i];
	}
	// Xóa mảng phòng
	delete[] phong;
}
