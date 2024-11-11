#pragma once
#include <iostream>
using namespace std;

class ThoiGian
{
private:
	int iGio;		//Giờ
	int iPhut;		//Phút
	int iGiay;		//Giây
public:
	//Phương thức khởi tạo mac định
	ThoiGian();

	//Phương thức khởi tạo có tham số
	ThoiGian(int, int, int);
	ThoiGian(int);

	//Phương thức tính giây từ giờ, phút, giây
	int TinhGiay() const;

	//Phương thức tính giờ, phút, giây từ giây
	void TinhLaiGio(int);

	//Phương thức chuẩn hóa thời gian
	void ChuanHoa();

	//Toán tử cộng
	ThoiGian operator+(ThoiGian) const;
	ThoiGian operator+(int) const;
	
	//Toán tử trừ
	ThoiGian operator-(ThoiGian) const;
	ThoiGian operator-(int) const;   

	//Toán tử ++ và --
	ThoiGian& operator++();
	ThoiGian operator++(int);
	ThoiGian& operator--();
	ThoiGian operator--(int);

	//Toán tử so sánh
	bool operator==(ThoiGian) const;
	bool operator!=(ThoiGian) const;
	bool operator>(ThoiGian) const;
	bool operator<(ThoiGian) const;
	bool operator>=(ThoiGian) const;
	bool operator<=(ThoiGian) const;

	//Toán tử nhập xuất
	friend istream& operator>>(istream&, ThoiGian&);
	friend ostream& operator<<(ostream&, ThoiGian);
};

