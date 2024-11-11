#pragma once
#include <iostream>
using namespace std;

class SoPhuc {
private:
    double dThuc;     //Phần thực
	double dAo;	      //Phần ảo
public:
    //Phương thức khởi tạo mặc định
    SoPhuc();

	//Phương thức khởi tạo có tham số
    SoPhuc(double Thuc, double Ao);
    SoPhuc(double Thuc);

    //Các phép toán cộng, trừ, nhân, chia, so sánh, nhập, xuất
    friend SoPhuc operator+(SoPhuc p1, SoPhuc p2);
    friend SoPhuc operator-(SoPhuc p1, SoPhuc p2);
    friend SoPhuc operator*(SoPhuc p1, SoPhuc p2);
    friend SoPhuc operator/(SoPhuc p1, SoPhuc p2);
    friend bool operator==(SoPhuc p1, SoPhuc p2);
    friend bool operator!=(SoPhuc p1, SoPhuc p2);
    friend istream& operator>>(istream& is, SoPhuc& p);
    friend ostream& operator<<(ostream& os, SoPhuc p);
};