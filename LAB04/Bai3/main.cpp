#include "NongTrai.h"

int main() {
	// Tạo seed cho hàm rand()
	srand(time(NULL));

	NongTrai nongTrai;

	// In ra tiếng kêu nghe được từ các con vật trong nông trại
	cout << "Tieng keu nghe duoc tu nong trai:\n";
	nongTrai.TiengKeuNgheDuoc();

	// In ra số lượng con trong nông tại sau một lứa sinh
	cout << "So luong con sau sinh: " << nongTrai.SoLuongConSauSinh() << "\n";

	// In ra số lượng sữa thu được từ nông trại sau một đợt cho sữa
	cout << "So luong sua: " << nongTrai.SoLuongSua() << " lit\n";
	return 0;

}