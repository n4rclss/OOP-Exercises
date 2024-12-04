#pragma once
#include "GiaSuc.h"
class Bo : public GiaSuc
{
public:
	// Phương thức thể hiện tiếng kêu của bò
	void Keu();

	// Phương thức cho biết số con sinh được sau 1 lứa của bò
	int SinhCon();

	// Phương thức cho biết số lượng sữa cho được của bò
	double ChoSua();
};

