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

int main() 
{
    int a, b;
    // Nhập tử số.
    cout << "Nhập tử số của phân số cần rút gọn: ";
    cin >> a;
    // Nhập mẫu số và kiểm tra mẫu số nhập vào phải khác 0.
    while(true) {
        cout << "Nhập mẫu số của phân số cần rút gọn: ";
        cin >> b;
        if (b!=0) break;
        cout << "Mẫu số không thể bằng 0. Vui lòng nhập lại!";
    }
    // Gọi hàm rút gọn phân số.
    RutGon(a, b);
    cout << "Phân số rút gọn là: " << a << '/' << b << '\n';
    return 0;
}