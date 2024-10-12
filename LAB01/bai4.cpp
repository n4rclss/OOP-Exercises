#include <iostream>
#include <cmath>
using namespace std;

#define PRECISION 0.00001

/**
 * @brief Tính giai thừa của một số nguyên dương n.
 * 
 * Hàm này sử dụng đệ quy để tính giai thừa của n.
 * 
 * @param n Số nguyên dương mà ta cần tính giai thừa.
 * @return Giai thừa của n.
 */
long long GiaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * GiaiThua(n - 1);
}

/**
 * @brief Tính giá trị hàm sin sử dụng chuỗi Taylor.
 * 
 * Hàm này sử dụng chuỗi Taylor để tính giá trị sin của x.
 * Đầu vào x sẽ được chuẩn hóa về khoảng [0, 2π) để tính toán chính xác hơn.
 * 
 * @param x Giá trị mà ta cần tính sin(x). Có thể là số âm hoặc lớn hơn 2π.
 * @return Giá trị sin(x) tính bằng chuỗi Taylor.
 */
double TaylorSin(double x) {
    bool negative;
    (x < 0) ? negative = 1 : negative = 0;

    x = fmod(fabs(x), 2*M_PI);
    double ans = 0;
    double tmp = x;
    int n = 0;
    while (tmp > PRECISION) {
        (n % 2 == 0) ? ans += tmp : ans -= tmp;
        n++;
        tmp = pow(x, 2*n+1) / GiaiThua(2*n+1);
    }
    return (negative) ? -ans : ans;
}

/**
 * @brief Hàm chính để chạy chương trình.
 * 
 * Hàm này yêu cầu người dùng nhập một giá trị x,
 * sau đó tính và in ra giá trị sin(x) sử dụng hàm TaylorSin
 * 
 * @return 0 nếu chương trình chạy thành công.
 */
int main() {
    double x; 
    cout << "Nhap x de tinh sin(x): ";
    cin >> x;
    double ans = TaylorSin(x);
    cout << "sin(x) = " << ans << "\n";
    return 0;
}