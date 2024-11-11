#pragma once
#include <iostream>
using namespace std; 

class NgayThangNam
{
private:
	int iNgay;		//Ngày 
	int iThang;		//Tháng
	int iNam;		//Năm
public:
	// Phương thức khởi tạo
	NgayThangNam();
	NgayThangNam(int, int, int);
	NgayThangNam(int);

	// Phương thức khác
	void ChuanHoa();
	bool checkNamNhuan();
	bool checkInput();
	void ResetDayInMonth();
	int TinhNgay();

	// Các phương thức toán tử
	NgayThangNam operator+(int);
	NgayThangNam operator-(NgayThangNam);
	NgayThangNam operator-(int);

	NgayThangNam& operator++();
	NgayThangNam operator++(int);
	NgayThangNam& operator--();
	NgayThangNam operator--(int);

	bool operator==(NgayThangNam);
	bool operator!=(NgayThangNam);
	bool operator>(NgayThangNam);
	bool operator<(NgayThangNam);
	bool operator>=(NgayThangNam);
	bool operator<=(NgayThangNam);

	friend istream& operator>>(istream&, NgayThangNam&);
	friend ostream& operator<<(ostream&, NgayThangNam);
};

