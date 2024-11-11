#include "ThoiGian.h"

//Phương thức khởi tạo mặc định (khởi tạo giờ, phút, giây bằng 0)
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

//Phương thức khởi tạo có tham số (khởi tạo giờ, phút, giây bằng tham số truyền vào)
//Thực hiện chuẩn hoá lại thời gian sau khi khởi tạo
ThoiGian::ThoiGian(int gio, int phut, int giay) : iGio(gio), iPhut(phut), iGiay(giay) { ChuanHoa(); }

//Phương thức khởi tạo với tham số là giây: Sử dụng hàm TinhLaiGio() tính giờ, phút, giây từ giây truyền vào
ThoiGian::ThoiGian(int giay) { TinhLaiGio(giay); }

//Phương thức tính giây từ giờ, phút, giây
int ThoiGian::TinhGiay() const
{
	return iGio * 3600 + iPhut * 60 + iGiay;
}

//Phương thức tính giờ, phút, giây từ giây
void ThoiGian::TinhLaiGio(int giay)
{
	iGio = giay / 3600;
	iPhut = (giay % 3600) / 60;
	iGiay = giay % 60;
	if (giay < 0) {
		iPhut = -iPhut;
		iGiay = -iGiay;
	}
}

//Phương thức chuẩn hóa thời gian
void ThoiGian::ChuanHoa()
{
	int giay = TinhGiay();
	TinhLaiGio(giay);
	if (iGio >= 24)
		iGio %= 24;
}

bool ThoiGian::CheckInput()
{
	if (iGio < 0 || iGio >= 24 || iPhut < 0 || iPhut >= 60 || iGiay < 0 || iGiay >= 60)
	{
		cout << "Thoi gian khong hop le. Nhap lai: ";
		return false;
	}
	return true;
}

//Toán tử cộng 2 thời gian
ThoiGian ThoiGian::operator+(ThoiGian t) const
{
	return ThoiGian(TinhGiay() + t.TinhGiay());
}

//Toán tử cộng thời gian với số giây
ThoiGian ThoiGian::operator+(int giay) const
{
	return ThoiGian(TinhGiay() + giay);
}

//Toán tử trừ 2 thời gian
ThoiGian ThoiGian::operator-(ThoiGian t) const
{
	return ThoiGian(TinhGiay() - t.TinhGiay());
}

//Toán tử trừ thời gian với số giây
ThoiGian ThoiGian::operator-(int giay) const
{
	return ThoiGian(TinhGiay() - giay);
}

//Toán tử ++ (prefix):
//Tăng thời gian hiện tại lên 1 giây
//Trả về thời gian sau khi tăng
ThoiGian& ThoiGian::operator++()
{
	TinhLaiGio(TinhGiay() + 1);
	return *this;
}

//Toán tử ++ (postfix):
//Tăng thời gian hiện tại lên 1 giây
//Trả về thời gian khi chưa tăng
ThoiGian ThoiGian::operator++(int)
{
	ThoiGian tmp = *this;
	TinhLaiGio(TinhGiay() + 1);
	return tmp;
}

//Toán tử -- (prefix):
//Giảm thời gian hiện tại đi 1 giây
//Trả về thời gian sau khi giảm
ThoiGian& ThoiGian::operator--()
{
	TinhLaiGio(TinhGiay() - 1);                                  
	return *this;
}	

//Toán tử -- (postfix):
//Giảm thời gian hiện tại đi 1 giây
//Trả về thời gian khi chưa giảm
ThoiGian ThoiGian::operator--(int)
{
	ThoiGian tmp = *this;
	TinhLaiGio(TinhGiay() - 1);
	return tmp;
}	

//Toán tử so sánh bằng nhau
bool ThoiGian::operator==(ThoiGian t) const
{
	return TinhGiay() == t.TinhGiay();
}

//Toán tử so sánh khác nhau
bool ThoiGian::operator!=(ThoiGian t) const
{
    return (TinhGiay() != t.TinhGiay());
}

//Toán tử so sánh lớn hơn
bool ThoiGian::operator>(ThoiGian t) const
{
	return (TinhGiay() > t.TinhGiay());
}

//Toán tử so sánh nhỏ hơn
bool ThoiGian::operator<(ThoiGian t) const
{
	return (TinhGiay() < t.TinhGiay());
}

//Toán tử so sánh lớn hơn hoặc bằng
bool ThoiGian::operator>=(ThoiGian t) const
{
	return (TinhGiay() >= t.TinhGiay());
}

//Toán tử so sánh nhỏ hơn hoặc bằng
bool ThoiGian::operator<=(ThoiGian t) const
{
	return (TinhGiay() <= t.TinhGiay());
}

//Toán tử nhập
istream& operator>>(istream& is, ThoiGian& t)
{	
	do {
		is >> t.iGio >> t.iPhut >> t.iGiay;
	} while (!t.CheckInput());
	return is;
}

//Toán tử xuất
ostream& operator<<(ostream& os, ThoiGian t)
{
	os << t.iGio << " gio " << t.iPhut << " phut " << t.iGiay << " giay";
	return os;
}
