#pragma
#define PI 3.14

class TamGiac {
private:
    float x1, y1; // Tọa độ điểm A
    float x2, y2; // Tọa độ điểm B
    float x3, y3; // Tọa độ điểm C

public:
	// Phương thức khởi tạo mặc định
    TamGiac();

	// Phương thức khởi tạo có tham số
    TamGiac(float x1, float y1, float x2, float y2, float x3, float y3);

    // Phương thức nhập tọa độ tam giác
    void Nhap();

    // Phương thức xuất tọa độ tam giác
    void Xuat() const;

    // Phương thức tịnh tiến tam giác
    void TinhTien(float huong, float khoangCach);
};
