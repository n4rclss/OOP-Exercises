#pragma once
#include "GiaSuc.h"
#include "Bo.h"
#include "De.h"
#include "Cuu.h"

class NongTrai
{
private:
	int slBo;				// Số lượng bò trong nông trại
	int slDe;				// Số lượng dê trong nông trại
	int slCuu;				// Số lượng cừu trong nông trại
	GiaSuc** DsQuanLy;		// Mảng chứa các con vật trong nông trại
public:
	// Hàm khởi tạo mặc định
	NongTrai();

	// Hàm huỷ
	~NongTrai();

	// Hàm in ra các tiếng kêu nghe được từ các con vật trong nông trại
	void TiengKeuNgheDuoc();

	// Hàm trả về số lượng con trong nông trại sau một lứa sinh
	int SoLuongConSauSinh();

	// Hàm trả về số lượng sữa thu được từ nông tại sau một đợt cho sữa
	double SoLuongSua();
};

