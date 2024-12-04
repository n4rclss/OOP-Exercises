#include "De.h"

// Phương thức thể hiện tiếng kêu của dê
// Khi dê kêu phát ra tiếng "de de"
void De::Keu()
{
	cout << "de de";
}

// Phương thức cho biết số con sinh được sau 1 lứa của dê
// Trong 1 lứa dê có thể sinh từ 1 đến 3 con
int De::SinhCon()
{
	return rand() % 3 + 1;
}

// Phương thức cho biết số lượng sữa cho được của dê
// Số lượng sữa dê cho được trong khoảng từ 0 đến 10 lít
double De::ChoSua()
{
	return (rand() % 11) + 1.0 / (rand() % 100 + 1);
}