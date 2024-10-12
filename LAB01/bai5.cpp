#include <iostream>
using namespace std;

int DAYOFMONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @brief Kiểm tra tính hợp lệ của ngày, tháng, năm được nhập.
 * 
 * Hàm này sẽ kiểm tra các giá trị ngày, tháng, năm có hợp lệ hay không.
 * Nếu không hợp lệ, hàm sẽ in ra thông báo và thoát chương trình.
 * 
 * @param[in] day Tham chiếu tới giá trị ngày.
 * @param[in] month Tham chiếu tới giá trị tháng.
 * @param[in] year Tham chiếu tới giá trị năm.
 */
void CheckInput(int &day, int &month, int &year) {
    if (day <= 0 || month <= 0 || year <= 0) {
        cout << "Giá trị nhập vào không hợp lệ!\n";
        exit(1);
    }
    if (month > 12) {
        cout << "Giá trị tháng không hợp lệ!\n";
        exit(1);
    }
    if (day > DAYOFMONTH[month - 1]) {
        cout << "Giá trị ngày trong tháng " << month << " không hợp lệ!\n";
        exit(1);
    }
}

/**
 * @brief Kiểm tra năm nhuận và cập nhật số ngày của tháng 2.
 * 
 * Hàm này kiểm tra xem năm được cung cấp có phải là năm nhuận hay không.
 * Nếu năm đó là năm nhuận, số ngày của tháng 2 sẽ được cập nhật thành 29.
 * 
 * @param[in] year Tham chiếu tới năm cần kiểm tra.
 */
void CheckLeapYear(int &year) {
    bool checkLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (checkLeapYear) {
        DAYOFMONTH[1] = 29;
    }    
}

/**
 * @brief Tính toán ngày kế tiếp.
 * 
 * Hàm này sẽ tính toán ngày kế tiếp dựa trên ngày, tháng, năm hiện tại.
 * Nếu ngày kế tiếp vượt qua tháng, tháng sẽ được cập nhật và ngày sẽ được đặt lại về 1.
 * Nếu tháng vượt qua 12, năm sẽ được tăng lên và tháng sẽ được đặt lại về 1.
 * 
 * @param[in, out] day Tham chiếu tới giá trị ngày.
 * @param[in, out] month Tham chiếu tới giá trị tháng.
 * @param[in, out] year Tham chiếu tới giá trị năm.
 */
void NextDay(int &day, int &month, int &year) {
    if (++day > DAYOFMONTH[month - 1]) {
        day = 1;
        month++;
    }
    if (month > 12) {
        month = 1;
        ++year;
    }
}

/**
 * @brief Tính toán ngày trước đó.
 * 
 * Hàm này sẽ tính toán ngày trước đó dựa trên ngày, tháng, năm hiện tại.
 * Nếu ngày trước đó nhỏ hơn 1, tháng sẽ được giảm và ngày sẽ được đặt lại
 * dựa trên số ngày của tháng đó.
 * Nếu tháng trước nhỏ hơn 1, năm sẽ được giảm và tháng sẽ được đặt lại thành 12,
 * ngày được đặt lại dựa trên số ngày cuối cùng của tháng đó.
 * 
 * @param[in, out] day Tham chiếu tới giá trị ngày.
 * @param[in, out] month Tham chiếu tới giá trị tháng.
 * @param[in, out] year Tham chiếu tới giá trị năm.
 */
void PrevDay(int &day, int &month, int &year) {
    if (--day < 1) {
        if (--month < 1) {
            --year;
            month = 12;
        }
        day = DAYOFMONTH[month - 1];
    }
}

/**
 * @brief Tính số ngày đã trôi qua trong năm.
 * 
 * Hàm này sẽ tính toán số ngày đã trôi qua từ đầu năm đến ngày hiện tại.
 * 
 * @param[in] day Giá trị ngày hiện tại.
 * @param[in] month Giá trị tháng hiện tại.
 * @param[in] year Giá trị năm hiện tại.
 * @return Số ngày đã trôi qua trong năm.
 */
int DayInYear(const int &day, const int &month, const int &year) {
    int result = 0;
    for (int i = 0; i < month - 1; i++) {
        result += DAYOFMONTH[i];
    }
    return result + day;
}

/**
 * @brief Hàm chính để chạy chương trình.
 * 
 * Hàm này yêu cầu người dùng nhập một ngày, tháng và năm,
 * sau đó tính toán và in ra ngày kế tiếp, ngày trước đó,
 * và số ngày đã trôi qua trong năm.
 * 
 * @return 0 nếu chương trình chạy thành công.
 */
int main() {
    int day, month, year;
    cout << "Nhập ngày tháng năm (dd mm yyyy): ";
    cin >> day >> month >> year;
    
    CheckLeapYear(year);

    CheckInput(day, month, year);

    int nextday = day, nextmonth = month, nextyear = year;
    NextDay(nextday, nextmonth, nextyear);
    cout << "Ngày kế tiếp là " << nextday << "/" << nextmonth << "/" << nextyear << "\n";
    
    int prevday = day, prevmonth = month, prevyear = year;
    PrevDay(prevday, prevmonth, prevyear);
    cout << "Ngày trước là " << prevday << "/" << prevmonth << "/" << prevyear << "\n";

    int cal = DayInYear(day, month, year);
    cout << "Ngày " << day << "/" << month << "/" << year << " là ngày thứ " << cal << " trong năm\n";
    return 0; 
}