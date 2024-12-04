#include "Bo.h"

// Phương thức thể hiện tiếng kêu của bò
// Khi kêu bò sẽ phát ra tiếng kêu "Um bo"
void Bo::Keu()
{
	cout << "Um bo";
}

// Phương thức cho biết số con sinh được sau 1 lứa của bò
// Đa số bò chỉ sinh 1 con trong 1 lứa
int Bo::SinhCon()
{
	return 1;
}

// Phương thức cho biết số lượng sữa cho được của bò
// Số lượng sữa cho được của bò trong khoảng từ 0 đến 20 lít
double Bo::ChoSua()
{
	return rand() % 21 + 1.0/(rand() % 100 + 1);
}
