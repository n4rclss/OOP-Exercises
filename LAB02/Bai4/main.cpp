#include "ThiSinh.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    cin.ignore();

    vector<ThiSinh> dsThiSinh(n);

    // Nhập thông tin cho từng thí sinh
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        dsThiSinh[i].Nhap();
    }

	// In ra thông tin của từng thí sinh có tổng điểm > 15
	cout << "**********************************************************\n";
    cout << "\nDanh sach thi sinh co tong diem > 15:\n";
    for (const auto& thiSinh : dsThiSinh) {
        if (thiSinh.Tong() > 15) {
            thiSinh.Xuat();
            cout << "-----------------\n";
        }
    }

    // In ra thông tin thí sinh có điểm cao nhất
    float maxTong = 0;
    ThiSinh thiSinhMax;

    for (const auto& thiSinh : dsThiSinh) {
        if (thiSinh.Tong() > maxTong) {
            maxTong = thiSinh.Tong();
            thiSinhMax = thiSinh;
        }
    }
    cout << "**********************************************************\n";
    cout << "\nThong tin thi sinh co diem cao nhat:\n";
    thiSinhMax.Xuat();

    return 0;
}
