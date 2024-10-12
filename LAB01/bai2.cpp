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
 * @brief So sánh hai phân số và in ra phân số lớn nhất.
 * 
 * Hàm này nhận vào hai phân số. 
 * Phân số đầu tiên được biểu diễn bởi (tu1, mau1) và phân số thứ hai 
 * bởi (tu2, mau2). Hàm sẽ so sánh hai phân số và in ra phân số lớn nhất.
 * Nếu hai phân số bằng nhau thì in ra phân số thứ nhất.
 *
 * @param[in] tu1 Tử số của phân số đầu tiên.
 * @param[in] mau1 Mẫu số của phân số đầu tiên (khác 0).
 * @param[in] tu2 Tử số của phân số thứ hai.
 * @param[in] mau2 Mẫu số của phân số thứ hai (khác 0).
 */
void MaxPS(int tu1, int mau1, int tu2, int mau2) {
    //Rút gọn phân số.
    RutGon(tu1, mau1);
    RutGon(tu2, mau2);
    bool check = tu1 * mau2 >= mau1 * tu2;
    if (check) {
        cout << "Phân số lớn nhất là: " << tu1 << '/' << mau1 <<'\n';
    }
    else {
        cout << "Phân số lớn nhất là: " << tu2 << '/' << mau2 <<'\n';
    }
}

int main() {
    int tu1, mau1, tu2, mau2;
    //Nhập tử và mẫu của hai phân số và kiểm tra mẫu số nhập vào phải khác 0.
    cout << "Nhập tử số và mẫu số của phân số thứ nhất: ";
    cin >> tu1 >> mau1;
    if (mau1 == 0) {
        cout << "Mẫu số không thể là 0.\n";
        exit(1);
    }
    cout << "Nhập tử số và mẫu số của phân số thứ hai: ";
    cin >> tu2 >> mau2;
    if (mau2 == 0) {
        cout << "Mẫu số không thể là 0.\n";
        exit(1);
    }
    //Gọi hàm xử lí.
    MaxPS(tu1, mau1, tu2, mau2);
    return 0;
}