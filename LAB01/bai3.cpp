#include <iostream>
#include <numeric>
using namespace std;

/**
 * @brief Rút gọn phân số a và b.
 *
 * Hàm này nhận vào hai tham số nguyên a và b, 
 * tính ước số chung lớn nhất (GCD) của chúng, 
 * và chia mỗi số cho ước số này để rút gọn phân số.
 * Nếu b âm, hàm sẽ đổi dấu a và b để đảm bảo b(mẫu số) luôn dương.
 *
 * @param[in, out] a Tử số của phân số.
 * @param[in, out] b Mẫu số của phân số.
 */
void RutGon(int &a, int &b)
{
    int tmp = gcd(a, b);
    a /= tmp;
    b /= tmp;
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

/**
 * @brief Tính tổng hai phân số.
 *
 * Hàm này nhận vào tử số và mẫu số của hai phân số, 
 * tính tổng của chúng, rút gọn và in ra kết quả.
 *
 * @param[in] tu1 Tử số của phân số thứ nhất.
 * @param[in] mau1 Mẫu số của phân số thứ nhất (phải khác 0).
 * @param[in] tu2 Tử số của phân số thứ hai.
 * @param[in] mau2 Mẫu số của phân số thứ hai (phải khác 0).
 */
void Tong(int tu1, int mau1, int tu2, int mau2) {
    int a, b;
    a = tu1 * mau2 + tu2 * mau1;
    b = mau1 * mau2;
    RutGon(a, b);
    cout << "Tổng hai phân số: " << a << "/" << b << "\n";
}

/**
 * @brief Tính hiệu hai phân số.
 *
 * Hàm này nhận vào tử số và mẫu số của hai phân số, 
 * tính hiệu của chúng, rút gọn và in ra kết quả.
 *
 * @param[in] tu1 Tử số của phân số thứ nhất.
 * @param[in] mau1 Mẫu số của phân số thứ nhất (phải khác 0).
 * @param[in] tu2 Tử số của phân số thứ hai.
 * @param[in] mau2 Mẫu số của phân số thứ hai (phải khác 0).
 */
void Hieu(int tu1, int mau1, int tu2, int mau2) {
    int a, b;
    a = tu1 * mau2 - tu2 * mau1;
    b = mau1 * mau2;
    RutGon(a, b);
    cout << "Hiệu hai phân số: " << a << "/" << b << "\n";
}

/**
 * @brief Tính tích hai phân số.
 *
 * Hàm này nhận vào tử số và mẫu số của hai phân số, 
 * tính tích của chúng, rút gọn và in ra kết quả.
 *
 * @param[in] tu1 Tử số của phân số thứ nhất.
 * @param[in] mau1 Mẫu số của phân số thứ nhất (phải khác 0).
 * @param[in] tu2 Tử số của phân số thứ hai.
 * @param[in] mau2 Mẫu số của phân số thứ hai (phải khác 0).
 */
void Tich(int tu1, int mau1, int tu2, int mau2) {
    int a, b;
    a = tu1 * tu2;
    b = mau1 * mau2;
    RutGon(a, b);
    cout << "Tích hai phân số: " << a << "/" << b << "\n";
}

/**
 * @brief Tính thương hai phân số.
 *
 * Hàm này nhận vào tử số và mẫu số của hai phân số, 
 * tính thương của chúng, rút gọn và in ra kết quả.
 *
 * @param[in] tu1 Tử số của phân số thứ nhất.
 * @param[in] mau1 Mẫu số của phân số thứ nhất (phải khác 0).
 * @param[in] tu2 Tử số của phân số thứ hai.
 * @param[in] mau2 Mẫu số của phân số thứ hai (phải khác 0).
 */
void Thuong(int tu1, int mau1, int tu2, int mau2) {
    int a, b;
    a = tu1 * mau2;
    b = tu2 * mau1;
    RutGon(a, b);
    cout << "Thương hai phân số: " << a << "/" << b << "\n";
}

int main() {
    int tu1, mau1, tu2, mau2;
    //Nhập tử và mẫu của hai phân số và kiểm tra mẫu số nhập vào phải khác 0.
    cout << "Nhập tử số và mẫu số của phân số thứ nhất: ";
    cin >> tu1 >> mau1;
    if (mau1 == 0) {
        cout << "Mau so khong the la 0\n";
        exit(1);
    }
    cout << "Nhập tử số và mẫu số của phân số thứ hai: ";
    cin >> tu2 >> mau2;
    if (mau2 == 0) {
        cout << "Mau so khong the la 0\n";
        exit(1);
    }
    //Gọi các hàm tính toán và xuất kết quả.
    Tong(tu1, mau1, tu2, mau2);
    Hieu(tu1, mau1, tu2, mau2);
    Tich(tu1, mau1, tu2, mau2);
    Thuong(tu1, mau1, tu2, mau2);
    return 0;
}