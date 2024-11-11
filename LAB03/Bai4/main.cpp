#include "NgayThangNam.h"

int main()
{
	NgayThangNam ntn1, ntn2;
	int ngay1, ngay2;
	
	// Nhập giá trị
	cout << "===================================\n";
	cout << "Nhap ngay thang nam thu nhat: ";
	cin >> ntn1;
	cout << "Nhap ngay thang nam thu hai: ";
	cin >> ntn2;
	cout << "Nhap so ngay can cong vao ngay thang nam thu nhat: ";
	cin >> ngay1;
	cout << "Nhap so ngay can tru vao ngay thang nam thu hai: ";
	cin >> ngay2;

	// Xuất giá trị vừa nhập
	cout << "\n===================================\n";
	cout << "Ngay thang nam thu nhat da nhap: " << ntn1 << "\n";
	cout << "Ngay thang nam thu hai da nhap: " << ntn2 << "\n";
	cout << "So ngay can cong vao ngay thang nam thu nhat: " << ngay1 << "\n";
	cout << "So ngay can tru vao ngay thang nam thu hai: " << ngay2 << "\n";

	// Tính số ngày
	cout << "\n===================================\n";
	cout << "Tong so ngay cua ngay thang nam thu nhat: " << ntn1.TinhNgay() << "\n";
	cout << "Tong so ngay cua ngay thang nam thu hai: " << ntn2.TinhNgay() << "\n";

	// Tính toán
	cout << "\n===================================\n";
	cout << ntn1 << " + " << ngay1 << " = " << ntn1 + ngay1 << "\n";
	cout << ntn2 << " - " << ngay2 << " = " << ntn2 - ngay2 << "\n";
	cout << ntn1 << " - " << ntn2 << " = " << ntn1 - ntn2 << "\n";

	// So sáng
	cout << "\n===================================\n";
	cout << ntn1 << " == " << ntn2 << " = " << (ntn1 == ntn2) << "\n";
	cout << ntn1 << " != " << ntn2 << " = " << (ntn1 != ntn2) << "\n";
	cout << ntn1 << " > " << ntn2 << " = " << (ntn1 > ntn2) << "\n";
	cout << ntn1 << " < " << ntn2 << " = " << (ntn1 < ntn2) << "\n";
	cout << ntn1 << " >= " << ntn2 << " = " << (ntn1 >= ntn2) << "\n";
	cout << ntn1 << " <= " << ntn2 << " = " << (ntn1 <= ntn2) << "\n";

}