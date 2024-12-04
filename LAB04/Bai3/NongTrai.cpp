#include "NongTrai.h"

// Hàm tạo mặc định
// Yêu cầu người dùng phải nhập thông tin về số lượng từng loại
// và khởi tạo mảng động chứa các con vật
NongTrai::NongTrai()
{
	cout << "Nhap so luong bo: ";
	cin >> slBo;
	cout << "Nhap so luong de: ";
	cin >> slDe;
	cout << "Nhap so luong cuu: ";
	cin >> slCuu;
	DsQuanLy = new GiaSuc* [slBo + slDe + slCuu];
	
	for (int i = 0; i < slBo; i++)
	{
		DsQuanLy[i] = new Bo;
	}
	for (int i = slBo; i < slBo + slDe; i++)
	{
		DsQuanLy[i] = new De;
	}
	for (int i = slBo + slDe; i < slBo + slDe + slCuu; i++)
	{
		DsQuanLy[i] = new Cuu;
	}
}

// Hàm huỷ
// Xoá từng phần tử trong màng động
// và xoá mảng động chứa các con vật
NongTrai::~NongTrai()
{
	for (int i = 0; i < slBo + slDe + slCuu; i++)
	{
		delete DsQuanLy[i];
	}
	delete[] DsQuanLy;
}

// Hàm in ra toàn bộ tiếng kêu của các con vật trong nông trại
void NongTrai::TiengKeuNgheDuoc()
{
	for (int i = 0; i < slBo + slDe + slCuu; i++)
	{
		DsQuanLy[i]->Keu();
		cout << " ";
	}
	cout << "\n";
}

// Hàm trả số lượng con trong nông trại sau một lứa sinh
int NongTrai::SoLuongConSauSinh()
{
	int slCon = 0;
	for (int i = 0; i < slBo + slDe + slCuu; i++)
	{
		slCon += DsQuanLy[i]->SinhCon();
	}
	return slCon + slBo + slDe + slCuu;
}

// Hàm trả về số lượng sữa thu được từ nông trại sau một đợt cho sữa
double NongTrai::SoLuongSua()
{
	double slSua = 0;
	for (int i = 0; i < slBo + slDe + slCuu; i++)
	{
		slSua += DsQuanLy[i]->ChoSua();
	}
	return slSua;
}