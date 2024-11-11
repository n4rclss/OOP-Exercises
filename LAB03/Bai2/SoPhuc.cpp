#include "SoPhuc.h"

//Phương thức khởi tạo mặc định
SoPhuc::SoPhuc() {
	dThuc = 0;
	dAo = 0;
}

//Phương thức khởi tạo có tham số (Phần thực, Phần ảo)
SoPhuc::SoPhuc(double Thuc, double Ao) : dThuc(Thuc), dAo(Ao) {}

//Phương thức khởi tạo có tham số (Phần thực), phần ảo mặc định là 0
SoPhuc::SoPhuc(double Thuc) : dThuc(Thuc), dAo(0) {}

//Toán tử cộng 2 số phức
SoPhuc operator+(SoPhuc p1, SoPhuc p2) {
	return SoPhuc(p1.dThuc + p2.dThuc, p1.dAo + p2.dAo);
}

//Toán tử trừ 2 số phức
SoPhuc operator-(SoPhuc p1, SoPhuc p2) {
	return SoPhuc(p1.dThuc - p2.dThuc, p1.dAo - p2.dAo);
}

//Toán tử nhân 2 số phức
SoPhuc operator*(SoPhuc p1, SoPhuc p2) {
	return SoPhuc(p1.dThuc * p2.dThuc - p1.dAo * p2.dAo, p1.dThuc * p2.dAo + p1.dAo * p2.dThuc);
}

//Toán tử chia 2 số phức
SoPhuc operator/(SoPhuc p1, SoPhuc p2) {
	double dMau = p2.dThuc * p2.dThuc + p2.dAo * p2.dAo;
	return SoPhuc((p1.dThuc * p2.dThuc + p1.dAo * p2.dAo) / dMau, (p1.dAo * p2.dThuc - p1.dThuc * p2.dAo) / dMau);
}

//So sánh 2 số phức bằng nhau
bool operator==(SoPhuc p1, SoPhuc p2) {
	return p1.dThuc == p2.dThuc && p1.dAo == p2.dAo;
}

//So sánh 2 số phức khác nhau
bool operator!=(SoPhuc p1, SoPhuc p2) {
	return !(p1 == p2);
}

//Nhập số phức
istream& operator>>(istream& is, SoPhuc& p) {
	is >> p.dThuc >> p.dAo;
	return is;
}

//Xuất số phức
ostream& operator<<(ostream& os, SoPhuc p) {
	os << p.dThuc << (p.dAo >= 0 ? " + " : " - ") << abs(p.dAo) << "i";
	return os;
}
