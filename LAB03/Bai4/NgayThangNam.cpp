#include "NgayThangNam.h"

int DAY_IN_MONTH[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// Khởi tạo mặc định là 1/1/2000
NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

// Khởi tạo ngày tháng năm, chuẩn hoá ngày tháng năm
NgayThangNam::NgayThangNam(int ngay, int thang, int nam) : iNgay(ngay), iThang(thang), iNam(nam) { ChuanHoa(); }

// Khởi tạo ngày tháng năm khi chỉ có số ngày (tính từ 1/1/2000) => Để nguyên giá trị ngày, tháng và năm sẽ được để là 0
NgayThangNam::NgayThangNam(int n) : iNgay(n), iThang(0), iNam(0) {}

// Chỉ có hai trường hợp cần được chuẩn hoá 
// 1. Khi ngày lớn hơn số ngày trong tháng => Tăng tháng và tăng năm (nếu có)
// 2. Khi ngày nhỏ hơn 1 => Giảm tháng và giảm năm (nếu có)
void NgayThangNam::ChuanHoa() {
	ResetDayInMonth();

	while (iNgay > DAY_IN_MONTH[iThang]) {
		iNgay -= DAY_IN_MONTH[iThang];
		iThang++;
		if (iThang > 12) {
			iThang = 1;
			iNam++;
			ResetDayInMonth();
		}
	}

	while (iNgay < 1) {
		iThang--;
		if (iThang < 1) {
			iThang = 12;
			iNam--;
			ResetDayInMonth();
		}
		iNgay += DAY_IN_MONTH[iThang];
	}
}

// Kiểm tra năm nhuận
bool NgayThangNam::checkNamNhuan() {
	if (iThang == 2 && iNgay == 29 && ((iNam % 4 != 0) || (iNam % 100 == 0 && iNam % 400 != 0))) {
		return true;
	}
	return false;
}

// Khởi tạo lại số ngày trong tháng tương ứng với năm nhuận/năm không nhuận
void NgayThangNam::ResetDayInMonth() {
	if (checkNamNhuan()) {
		DAY_IN_MONTH[2] = 29;
	}
	else {
		DAY_IN_MONTH[2] = 28;
	}
}

// Kiểm tra ngày tháng năm nhập vào có hợp lệ không
bool NgayThangNam::checkInput() {
	bool result = true;

	// Kiểm tra ngày tháng năm nhập vào có hợp lệ không (Các giá trị vào nằm trong khoảng đúng, năm không nhỏ hơn 2000)
	if (iNgay < 1 || iThang < 1 || iThang > 12 || iNam < 2000) {
		result = false;
	}

	// Kiểm tra giá trị ngày trong tháng có hợp lệ không
	ResetDayInMonth();
	if (iNgay > DAY_IN_MONTH[iThang]) {
		result = false;
	}

	if (!result) {
		cout << "Ngay thang nam khong hop le. Vui long nhap lai.\n";
	}
	return result;
}

// Tính tổng số ngày từ gốc thời gian là 1/1/2000 đến ngày tháng năm hiện tại
int NgayThangNam::TinhNgay() {
	int soNgay = 0;
	for (int i = 2000; i < iNam; i++) {
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
			soNgay += 366;
		}
		else {
			soNgay += 365;
		}
	}
	ResetDayInMonth();
	for (int i = 1; i < iThang; i++) {
		soNgay += DAY_IN_MONTH[i];
	}
	return soNgay;
}

// Toán tử cộng ngày tháng năm với ngày 
// Trả về ngày tháng năm mới
NgayThangNam NgayThangNam::operator+(int n) {
	return NgayThangNam(iNgay + n, iThang, iNam);
}

// Toán tử trừ ngày tháng năm với ngày tháng năm
// Trả về số ngày giữa hai ngày tháng năm (Khoảng cách ngày giữa hai ngày tháng năm này)
NgayThangNam NgayThangNam::operator-(NgayThangNam ntn) {
	return NgayThangNam(TinhNgay() - ntn.TinhNgay());
}

// Toán tử trừ ngày tháng năm với ngày
// Trả về ngày tháng năm mới
NgayThangNam NgayThangNam::operator-(int n) {
	return NgayThangNam(iNgay - n, iThang, iNam);
}

// Toán tử tăng ngày tháng năm lên 1 ngày
// Trả về ngày tháng năm sau khi tăng
NgayThangNam& NgayThangNam::operator++() {
	iNgay++;
	ChuanHoa();
	return *this;
}

// Toán tử tăng ngày tháng năm lên 1 ngày
// Trả về ngày tháng năm trước khi tăng
NgayThangNam NgayThangNam::operator++(int) {
	NgayThangNam temp = *this;
	iNgay++;
	ChuanHoa();
	return temp;
}

// Toán tử giảm ngày tháng năm đi 1 ngày
// Trả về ngày tháng năm sau khi giảm
NgayThangNam& NgayThangNam::operator--() {
	iNgay--;
	ChuanHoa();
	return *this;
}

// Toán tử giảm ngày tháng năm đi 1 ngày
// Trả về ngày tháng năm trước khi giảm
NgayThangNam NgayThangNam::operator--(int) {
	NgayThangNam temp = *this;
	iNgay--;
	ChuanHoa();
	return temp;
}

// Toán tử so sánh bằng
bool NgayThangNam::operator==(NgayThangNam ntn) {
	return iNgay == ntn.iNgay && iThang == ntn.iThang && iNam == ntn.iNam;
}

// Toán tử so sánh khác
bool NgayThangNam::operator!=(NgayThangNam ntn) {
	return !(*this == ntn);
}

// Toán tử so sánh lớn hơn
bool NgayThangNam::operator>(NgayThangNam ntn) {
	return TinhNgay() > ntn.TinhNgay();
}

// Toán tử so sánh nhỏ hơn
bool NgayThangNam::operator<(NgayThangNam ntn) {
	return TinhNgay() < ntn.TinhNgay();
}

// Toán tử so sánh lớn hơn hoặc bằng
bool NgayThangNam::operator>=(NgayThangNam ntn) {
	return TinhNgay() >= ntn.TinhNgay();
}

// Toán tử so sánh nhỏ hơn hoặc bằng
bool NgayThangNam::operator<=(NgayThangNam ntn) {
	return TinhNgay() <= ntn.TinhNgay();
}

// Toán tử xuất ra ngày tháng năm theo định dạng dd/mm/yyyy
// Nếu ngày tháng năm chỉ có giá trị ngày thì sẽ xuất ra dạng dd ngay
ostream& operator<<(ostream& os, NgayThangNam ntn) {
	os << ntn.iNgay;
	if (ntn.iThang != 0 && ntn.iNam != 0 ) os << "/" << ntn.iThang << "/" << ntn.iNam;
	else os << " ngay";
	return os;
}

// Toán tử nhập vào ngày tháng năm
// Nếu ngày tháng năm nhập vào không hợp lệ thì yêu cầu nhập lại cho đên khi hợp lệ
istream& operator>>(istream& is, NgayThangNam& ntn) {
	do {
		is >> ntn.iNgay >> ntn.iThang >> ntn.iNam;
	} while (!ntn.checkInput());
	return is;
}