#pragma once
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
using namespace std;

// Lớp cơ sở trừu tượng
class GiaSuc
{
public:
	// Phương thức thể hiện tiếng kêu của gia súc (Thuần ảo)
	virtual void Keu() = 0;

	// Phương thức cho biết số con sinh được sau 1 lứa của gia súc (Thuần ảo)
	virtual int SinhCon() = 0;

	// Phương thức cho biết số lượng sữa cho được của gia súc (Thuần ảo)
	virtual double ChoSua() = 0;
};

