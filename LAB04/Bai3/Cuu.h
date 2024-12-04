#pragma once
#include "GiaSuc.h"

class Cuu : public GiaSuc
{
public:
	// Phương thức thể hiện tiếng kêu của cừu
	void Keu();

	// Phương thức cho biết số con sinh được sau 1 lứa của cừu
	int SinhCon();

	// Phương thức cho biết số lượng sữa cho được của cừu
	double ChoSua();
};



