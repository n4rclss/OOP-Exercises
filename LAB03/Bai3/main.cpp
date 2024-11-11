#include "ThoiGian.h"

int main()
{
	ThoiGian t1, t2;
	int giay;
	cout << "************************************\n";
	cout << "Nhap thoi gian t1: ";
	cin >> t1;
	cout << "Nhap thoi gian t2: ";
	cin >> t2;
	cout << "Nhap so giay: ";
	cin >> giay;

	cout << "\n************************************\n";
	cout << "Thoi gian vua nhap:\n";
	cout << "t1 = " << t1 << "\n";
	cout << "t2 = " << t2 << "\n";
	cout << "giay = " << giay << "\n";

	cout << "\n*************Tinh giay**************\n";
	cout << "t1 = " << t1.TinhGiay() << " giay\n";
	cout << "t2 = " << t2.TinhGiay() << " giay\n";

	cout << "\n*************Tinh lai gio***********\n";
	ThoiGian temp(giay);
	cout << "Thoi gian tu " << giay << " giay: " << temp << "\n";


	cout << "\n*************So sanh*****************\n";
	cout << "t1 == t2: " << (t1 == t2) << "\n";
	cout << "t1 != t2: " << (t1 != t2) << "\n";
	cout << "t1 > t2: " << (t1 > t2) << "\n";
	cout << "t1 < t2: " << (t1 < t2) << "\n";
	cout << "t1 >= t2: " << (t1 >= t2) << "\n";
	cout << "t1 <= t2: " << (t1 <= t2) << "\n";

	cout << "\n*************Tinh toan***************\n";
	cout << "t1 + t2 = " << t1 + t2 << "\n";
	cout << "t1 + " << giay << " = " << t1 + giay << "\n";
	cout << "t1 - t2 = " << t1 - t2 << "\n";
	cout << "t1 - " << giay << " = " << t1 - giay << "\n";
	cout << "t1 = t1++ = " << t1++ << "\n";
	cout << "t1 = ++t1 = " << ++t1 << "\n";
	cout << "t2 = t2-- = " << t2-- << "\n";
	cout << "t2 = --t2 = " << --t2 << "\n";

	return 0;
}