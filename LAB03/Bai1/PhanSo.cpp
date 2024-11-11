#include "PhanSo.h"
#include <iostream>
#include <numeric>
using namespace std;

//Phương thức khởi tạo mặc định
PhanSo::PhanSo() : iTu(0), iMau(1) {}

//Phương thức khởi tạo có tham số là tử số và mẫu số
PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) { RutGon(); }

//Phương thức khởi tạo có tham số là tử số, mẫu số mặc định là 1
PhanSo::PhanSo(int Tu) : iTu(Tu), iMau(1) {}

/* 
Phương thức rút gọn phân số
Hàm std::gcd(a, b) trả về ước chung lớn nhất của a và b
Sau đó chia tử số và mẫu số cho ước chung lớn nhất đó
Nếu mẫu số âm thì đổi dấu tử số và mẫu số
*/
void PhanSo::RutGon() {
    int tmp = std::gcd(iTu, iMau);
    iTu /= tmp;
    iMau /= tmp;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

//Toán tử cộng 2 phân số
PhanSo operator+(PhanSo p1, PhanSo p2)
{
    return PhanSo(p1.iTu * p2.iMau + p2.iTu * p1.iMau, p1.iMau * p2.iMau);
}

//Toán tử trừ 2 phân số
PhanSo operator-(PhanSo p1, PhanSo p2)
{
    return PhanSo(p1.iTu * p2.iMau - p2.iTu * p1.iMau, p1.iMau * p2.iMau);
}

//Toán tử nhân 2 phân số
PhanSo operator*(PhanSo p1, PhanSo p2)
{
    return PhanSo(p1.iTu * p2.iTu, p1.iMau * p2.iMau);
}

//Toán tử chia 2 phân số
PhanSo operator/(PhanSo p1, PhanSo p2)
{
    return PhanSo(p1.iTu * p2.iMau, p1.iMau * p2.iTu);
}

//Toán tử so sánh 2 phân số bằng nhau
bool operator==(PhanSo p1, PhanSo p2)
{
    return (p1.iTu * p2.iMau == p1.iMau * p2.iTu);
}

//Toán tử so sánh 2 phân số khác nhau
bool operator!=(PhanSo p1, PhanSo p2)
{
    return !(p1==p2);

}

//Toán tử so sánh 2 phân số lớn hơn
bool operator>(PhanSo p1, PhanSo p2)
{
    return (p1.iTu * p2.iMau > p1.iMau * p2.iTu);
}

//Toán tử so sánh 2 phân số nhỏ hơn
bool operator<(PhanSo p1, PhanSo p2)
{
    return (p1.iTu * p2.iMau < p1.iMau * p2.iTu);
}

//Toán tử so sánh 2 phân số lớn hơn hoặc bằng
bool operator>=(PhanSo p1, PhanSo p2)
{
    return (p1 > p2 || p1 == p2);
}

//Toán tử so sánh 2 phân số nhỏ hơn hoặc bằng
bool operator<=(PhanSo p1, PhanSo p2)
{
    return (p1 < p2 || p1 == p2);
}

//Toán tử nhập phân số
istream& operator>>(istream& is, PhanSo& p)
{
    is >> p.iTu >> p.iMau;
    while (!p.iMau) {
        cout << "Nhap lai mau so: ";
        is >> p.iMau;
    }
    p.RutGon();
    return is;
}

//Toán tử xuất phân số
ostream& operator<<(ostream& os, PhanSo p)
{
    os << p.iTu;
    if (p.iTu != 0 && p.iMau != 1)
        os << "/" << p.iMau;
    return os;
}
