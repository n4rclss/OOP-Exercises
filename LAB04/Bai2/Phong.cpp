#include "Phong.h"

// Khởi tạo mặc định
Phong::Phong() : SoDem(0) {}

// Khởi tạo với số đêm
Phong::Phong(int soDem) : SoDem(soDem){}

// Nhập số đêm
void Phong::Nhap()
{
	do {
		cout << "Nhap so dem: ";
		cin >> SoDem;
	} while (SoDem <= 0);
}

// Kiểm tra loại phòng
bool Phong::isBusiness()
{
	return false;
}

bool Phong::isDeluxe()
{
	return false;
}

bool Phong::isPremium()
{
	return false;
}