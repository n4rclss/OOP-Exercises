#include <iostream>
using namespace std;

int DAYOFMONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

void PrevDay(int &day, int &month, int &year) {
    if (--day < 1) {
        if (--month < 1) {
            --year;
            month = 12;
        }
        day = DAYOFMONTH[month - 1];
    }
}

int DayInYear(const int &day, const int &month, const int &year) {
    int result = 0;
    for (int i = 0; i < month - 1; i++) {
        result += DAYOFMONTH[i];
    }
    return result + day;
}

int main() {
    int day, month, year;
    cout << "Nhập ngày tháng năm (dd mm yyyy): ";
    cin >> day >> month >> year;
    
    bool checkLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (checkLeapYear) {
        DAYOFMONTH[1] = 29;
    }

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