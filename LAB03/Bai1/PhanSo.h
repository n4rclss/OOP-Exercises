#pragma once
#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu;    //Tử số
	int iMau;   //Mẫu số    
public:
	//Phương thức khởi tạo mặc định
    PhanSo();

	//Phương thức khởi tạo có tham số
    PhanSo(int Tu, int Mau);
    PhanSo(int Tu);

	//Phương thức rút gọn phân số
    void RutGon();

	//Các phép toán cộng, trừ, nhân, chia, so sánh, nhập, xuất
    friend PhanSo operator+(PhanSo p1, PhanSo p2);
    friend PhanSo operator-(PhanSo p1, PhanSo p2);
    friend PhanSo operator*(PhanSo p1, PhanSo p2);
    friend PhanSo operator/(PhanSo p1, PhanSo p2);
    friend bool operator==(PhanSo p1, PhanSo p2);
    friend bool operator!=(PhanSo p1, PhanSo p2);
    friend bool operator>(PhanSo p1, PhanSo p2);
    friend bool operator<(PhanSo p1, PhanSo p2);
    friend bool operator>=(PhanSo p1, PhanSo p2);
    friend bool operator<=(PhanSo p1, PhanSo p2);
    friend istream& operator>>(istream& is, PhanSo& p);
    friend ostream& operator<<(ostream& os, PhanSo p);
};