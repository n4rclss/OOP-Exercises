#include "Cuu.h"

// Phương thức thể hiện tiếng kêu của cừu
// Khi kêu cừu sẽ phát ra tiếng kêu "be be"
void Cuu::Keu()
{
	cout << "be be";
}

// Phương thức cho biết số con sinh được sau 1 lứa của cừu
// Trong 1 lứa cừu có thể sinh từ 1 đến 3 con
int Cuu::SinhCon()
{
	return rand() % 3 + 1;
}

// Phương thức cho biết số lượng sữa cho được của cừu
// Số lượng sữa cừu cho được trong khoảng từ 0 đến 6 lít
double Cuu::ChoSua()
{
	return rand() % 6 + 1.0 / (rand() % 100 + 1);
} 