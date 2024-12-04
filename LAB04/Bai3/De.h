#pragma once
#include "GiaSuc.h"
class De : public GiaSuc
{
public:
	// Phương thức thể hiện tiếng kêu của dê
	void Keu();

	// Phương thức cho biết số con sinh được sau 1 lứa của dê
	int SinhCon();

	// Phương thức cho biết số lượng sữa cho được của dê
	double ChoSua();
};

