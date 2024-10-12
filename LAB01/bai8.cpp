#include <bits/stdc++.h>
using namespace std;

/**
 * day: Ngày của tháng (giá trị từ 1 đến 31 tùy theo tháng).
 * month: Tháng trong năm (giá trị từ 1 đến 12).
 * year: Năm hiện tại.
 * strdate: Chuỗi biểu diễn ngày tháng dưới định dạng "dd/mm/yyyy".
 */

struct Date {
    int day;
    int month;
    int year; 
    string strdate;   
};

/**
 * id: Mã sổ tiết kiệm (không quá 5 ký tự).
 * loai: Loại tiết kiệm (không quá 10 ký tự).
 * hoTen: Họ tên khách hàng (không quá 30 ký tự).
 * cmnd: Số CMND (9 hoặc 12 chữ số).
 * ngaymoso: Ngày mở sổ.
 * soTien: Số tiền gửi.
 */

struct SoTietKiem {
    string id; 
    string loai;
    string hoTen;
    string cmnd;
    Date ngaymoso;
    double soTien;
};

/**
 * Hàm process_date: Chuyển đổi chuỗi ngày tháng sang dạng số.
 * @param date: Ngày tháng cần chuyển đổi.
 * @param s: Chuỗi ngày tháng cần chuyển đổi.
 */

void process_date(Date &date, string &s) {
    date.day = stoi(s.substr(0, 2));
    date.month = stoi(s.substr(3, 2));
    date.year = stoi(s.substr(6, 4));  
    date.strdate = s;  
}

/**
 * Hàm check_id: Kiểm tra mã sổ tiết kiệm.
 * @param s: Mã sổ tiết kiệm cần kiểm tra.
 * @return true nếu mã sổ tiết kiệm hợp lệ, ngược lại trả về false.
 */
bool check_id(string &s) {
    bool check = regex_match(s, regex("^[A-Za-z0-9]{1,5}$"));
    if (!check)
    {
        cout << "[!] Mã sổ không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * Hàm check_loai: Kiểm tra loại sổ tiết kiệm.
 * @param s: Loại sổ tiết kiệm cần kiểm tra.
 * @return true nếu loại sổ tiết kiệm hợp lệ, ngược lại trả về false.
 */

bool check_loai(string &s) {
    bool check = regex_match(s, regex("^[A-Za-z ]{1,10}$"));
    if (!check)
    {
        cout << "[!] Loại sổ không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * Hàm check_hoten: Kiểm tra họ tên khách hàng.
 * @param s: Họ tên khách hàng cần kiểm tra.
 * @return true nếu họ tên hợp lệ, ngược lại trả về false.
 */

bool check_hoten(string &s) {
    bool check = regex_match(s, regex("^[A-Za-z ]{1,30}$"));
    if (!check)
    {
        cout << "[!] Họ tên không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * Hàm check_cmnd: Kiểm tra số CMND.
 * @param s: Số CMND cần kiểm tra.
 * @return true nếu số CMND hợp lệ, ngược lại trả về false.
 */

bool check_cmnd(string &s) {
    bool check = regex_match(s, regex("^(\\d{9}|\\d{12})$"));
    if (!check)
    {
        cout << "[!] Số CMND không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * Hàm check_date_value: Kiểm tra ngày tháng.
 * @param date: Ngày tháng cần kiểm tra.
 * @return true nếu ngày tháng hợp lệ, ngược lại trả về false.
 */

bool check_date_value(Date &date)
{
    int DAYOFMONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
    if (isLeapYear)
        DAYOFMONTH[1] = 29;
    if (date.day > DAYOFMONTH[date.month - 1])
    {
        return false;
    }
    return true;
}

/**
 * Hàm check_date_string: Kiểm tra chuỗi ngày tháng.
 * @param s: Chuỗi ngày tháng cần kiểm tra.
 * @return true nếu chuỗi ngày tháng hợp lệ, ngược lại trả về false.
 */

bool check_date_string(string &s)
{
    bool check1 = regex_match(s, regex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(19|20)\\d{2}$"));
    Date testDate;
    process_date(testDate, s);
    bool check2 = check_date_value(testDate);
    if (!(check1 && check2))
    {
        cout << "[!] Ngày không hợp lệ. Vui lòng nhập lại!\n";
        cout << "Nhập ngày mở sổ (dd/mm/yyyy): ";
        return false;
    }
    return true;
}

/**
 * Hàm check_money: Kiểm tra số tiền gửi.
 * @param s: Số tiền gửi cần kiểm tra.
 * @return true nếu số tiền gửi hợp lệ, ngược lại trả về false.
 */

bool check_money(double &s) {
    if (s < 0)
    {
        cout << "[!] Số tiền gửi phải là số dương. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * Hàm InputID: Nhập mã sổ tiết kiệm.
 * @param id: Mã sổ tiết kiệm cần nhập.
 */

void InputID(string &id) {
    do
    {
        cout << "Nhập mã sổ tiết kiệm: ";
        getline(cin, id);
    } while (!check_id(id));    
}

/**
 * Hàm InputLoai: Nhập loại tiết kiệm.
 * @param loai: Loại tiết kiệm cần nhập.
 */
void InputLoai(string &loai) {
    do
    {
        cout << "Nhập loại tiết kiệm: ";
        getline(cin, loai);
    } while (!check_loai(loai));      
}

/**
 * Hàm InputhoTen: Nhập họ tên khách hàng.
 * @param hoten: Họ tên khách hàng cần nhập.
 */

void InputhoTen(string &hoten) {
    do
    {
        cout << "Nhập họ tên khách hàng: ";
        getline(cin, hoten);
    } while (!check_hoten(hoten));  
}

/**
 * Hàm InputCMND: Nhập số CMND.
 * @param cmnd: Số CMND cần nhập.
 */
void InputCMND(string &cmnd) {
    do
    {
        cout << "Nhập số CMND: ";
        getline(cin, cmnd);
    } while (!check_cmnd(cmnd));      
}

/**
 * Hàm InputDate: Nhập ngày tháng.
 * @param date: Ngày tháng cần nhập.
 */
void InputDate(Date &date) {
    string s;
    do
    {
        //cout << "Nhập ngày mở sổ (dd/mm/yyyy): ";
        getline(cin, s);
    } while (!check_date_string(s));
    process_date(date, s);   
}

/**
 * Hàm InputMoney: Nhập số tiền gửi.
 * @param soTien: Số tiền gửi cần nhập.
 */

void InputMoney(double &soTien) {
    do
    {
        cout << "Nhập số tiền gửi: ";
        cin >> soTien;
    } while (!check_money(soTien)); 
    cin.ignore();   
}

/**
 * Hàm NhapThongTin: Nhập thông tin sổ tiết kiệm.
 * @param tk: Sổ tiết kiệm cần nhập thông tin.
 */

void NhapThongTin(SoTietKiem &tk) {
    string id, loai, hoten, cmnd; 
    Date date;
    double soTien;
    InputID(id);
    InputLoai(loai);
    InputhoTen(hoten);
    InputCMND(cmnd);
    cout << "Nhập ngày mở sổ (dd/mm/yyyy): ";
    InputDate(date);
    InputMoney(soTien);
    tk = {
        id, 
        loai,
        hoten,
        cmnd,
        date,
        soTien
    };
}

/**
 * Hàm NhapSTK: Nhập danh sách sổ tiết kiệm.
 * @param tk: Danh sách sổ tiết kiệm cần nhập.
 */

void NhapSTK(vector<SoTietKiem> &tk) {
    for (int i=0; i<tk.size(); i++) {
        cout << "Nhập thông tin sổ tiết kiệm " << i + 1 << ":\n";
        NhapThongTin(tk[i]);
    }
}

/**
 * Hàm Xuat: Xuất thông tin sổ tiết kiệm.
 */

void Xuat()
{
    cout << "|" << setw(10) << "Mã sổ"
         << "|" << setw(25) << "Loại tiết kiệm"
         << "|" << setw(30) << "Họ tên khách hàng"
         << "|" << setw(17) << "Số CMND"
         << "|" << setw(20) << "Ngày mở sổ"
         << "|" << setw(21) << "Số tiền gửi"
         << "|\n";
}

/**
 * Hàm XuatThongTin: Xuất thông tin sổ tiết kiệm.
 * @param tk: Sổ tiết kiệm cần xuất thông tin.
 */

void XuatThongTin(SoTietKiem &tk)
{
    cout << "|" << setw(7) << tk.id
         << "|" << setw(19) << tk.loai
         << "|" << setw(25) << tk.hoTen
         << "|" << setw(15) << tk.cmnd
         << "|" << setw(15) << tk.ngaymoso.strdate
         << "|" << setw(15) << fixed << setprecision(0) << tk.soTien        
         << "|\n";
}

/**
 * Hàm XuatMang: Xuất danh sách sổ tiết kiệm.
 * @param tk: Danh sách sổ tiết kiệm cần xuất.
 */

void XuatMang(vector<SoTietKiem> &tk) {
    Xuat();
    for (auto i : tk) {
        XuatThongTin(i);
    }
}

/**
 * Hàm XuatMang: Xuất danh sách sổ tiết kiệm.
 * @param tk: Danh sách sổ tiết kiệm cần xuất.
 */

void XuatMang(vector<SoTietKiem> &tk, vector<int> &idx) {
    Xuat();
    for (auto i : idx) {
        XuatThongTin(tk[i]);
    }
}

/**
 * Hàm CompareSTK_Date: So sánh ngày mở sổ của sổ tiết kiệm.
 * @param a: Sổ tiết kiệm thứ nhất.
 * @param b: Sổ tiết kiệm thứ hai.
 * @return true nếu ngày mở sổ của sổ tiết kiệm thứ nhất nhỏ hơn sổ tiết kiệm thứ hai, ngược lại trả về false.
 */

bool CompareSTK_Date(const SoTietKiem &a, const SoTietKiem &b)
{
    if (a.ngaymoso.year != b.ngaymoso.year)
        return a.ngaymoso.year < b.ngaymoso.year;
    if (a.ngaymoso.month != b.ngaymoso.month)
        return a.ngaymoso.month < b.ngaymoso.month;
    return a.ngaymoso.day < b.ngaymoso.day;
}

/**
 * Hàm Asc_Date: So sánh ngày tháng.
 * @param a: Ngày tháng thứ nhất.
 * @param b: Ngày tháng thứ hai.
 * @return true nếu ngày tháng thứ nhất nhỏ hơn ngày tháng thứ hai, ngược lại trả về false.
 */
bool Asc_Date(const Date &a, const Date &b)
{
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    return a.day <= b.day;
}

/**
 * Hàm Desc_Money: So sánh số tiền gửi.
 * @param a: Sổ tiết kiệm thứ nhất.
 * @param b: Sổ tiết kiệm thứ hai.
 * @return true nếu số tiền gửi của sổ tiết kiệm thứ nhất lớn hơn sổ tiết kiệm thứ hai, ngược lại trả về false.
 */

bool Desc_Money(const SoTietKiem &a, const SoTietKiem &b) 
{
    return a.soTien > b.soTien;
}

/**
 * Hàm Searching_cmnd: Tìm kiếm sổ tiết kiệm theo số CMND.
 * @param tk: Danh sách sổ tiết kiệm.
 * @param match: Danh sách các sổ tiết kiệm thỏa mãn điều kiện tìm kiếm.
 * @param search: Số CMND cần tìm kiếm.
 */
 

void Searching_cmnd(vector<SoTietKiem> &tk, vector<int> &match, string &search)
{
    InputCMND(search);
    for (int i = 0; i < tk.size(); i++) {
        if (tk[i].cmnd == search) {
            match.push_back(i);
        }
    }
}

/**
 * Hàm Searching_id: Tìm kiếm sổ tiết kiệm theo mã số.
 * @param tk: Danh sách sổ tiết kiệm.
 * @param match: Danh sách các sổ tiết kiệm thỏa mãn điều kiện tìm kiếm.
 * @param search: Mã số cần tìm kiếm.
 */

void Searching_id(vector<SoTietKiem> &tk, vector<int> &match, string &search)
{
    InputID(search);
    for (int i = 0; i < tk.size(); i++) {
        if (tk[i].id == search) {
            match.push_back(i);
            break;
        }
    }    
}

/**
 * Hàm isInRange: Kiểm tra ngày tháng có nằm trong khoảng thời gian xác định hay không.
 * @param a: Ngày tháng cần kiểm tra.
 * @param from: Ngày tháng bắt đầu của khoảng thời gian.
 * @param to: Ngày tháng kết thúc của khoảng thời gian.
 * @return true nếu ngày tháng nằm trong khoảng thời gian xác định, ngược lại trả về false.
 */

bool isInRange(Date &a, Date &from, Date &to) 
{
    return (Asc_Date(a, to) && Asc_Date(from, a));
}


/**
 * Hàm SearchingInRange: Tìm kiếm sổ tiết kiệm theo khoảng thời gian mở sổ.
 * @param tk: Danh sách sổ tiết kiệm.
 * @param match: Danh sách các sổ tiết kiệm thỏa mản điều kiện tìm kiếm.
 * @param from: Ngày tháng bắt đầu của khoảng thời gian.
 * @param to: Ngày tháng kết thúc của khoảng thời gian.
 */

void SearchingInRange(vector<SoTietKiem> &tk, vector<int> &match, Date &from, Date &to)
{
    for (int i = 0; i < tk.size(); i++) {
        if (isInRange(tk[i].ngaymoso, from, to)) {
            match.push_back(i);
        }
    }
}

/**
 * Hàm func_1: Xuất dữ liệu sổ tiết kiệm.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_1(vector<SoTietKiem> &tk) {
    cout << "Danh sách sổ tiết kiệm:\n";
    XuatMang(tk);
}

/**
 * Hàm func_2: Cập nhật lãi suất.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_2(vector<SoTietKiem> &tk) {
    return;
}

/**
 * Hàm func_3: Tính toán tiền lãi.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_3(vector<SoTietKiem> &tk) {
    return;
}

/**
 * Hàm func_4: Rút tiền.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_4(vector<SoTietKiem> &tk) {
    return;
}

/**
 * Hàm func_5: Tìm kiếm sổ tiết kiệm theo số CMND.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_5(vector<SoTietKiem> &tk) {
    string search;
    vector<int> match;
    Searching_cmnd(tk, match, search);
    if (match.size()){
        cout << "Thông tin sổ tiết kiệm có CMND " << search << ":\n";
        XuatMang(tk, match);
    } 
    else {
        cout << "Không tồn tại sổ tiết kiệm có CMND " << search << "\n";
    }
}

/**
 * Hàm func_6: Tìm kiếm sổ tiết kiệm theo mã số.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_6(vector<SoTietKiem> &tk) {
    string search;
    vector<int> match;
    Searching_id(tk, match, search);
    if (match.size()){
        cout << "Thông tin sổ tiết kiệm mã " << search << ":\n";
        XuatMang(tk, match);
    } 
    else {
        cout << "Không tồn tại sổ tiết kiệm mã " << search << "\n";
    }
}

/**
 * Hàm func_7: Liệt kê tất cả các sổ tiết kiệm mở trong một khoảng thời gian xác định.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_7(vector<SoTietKiem> &tk) {
    Date from, to;
    vector<int> match;
    cout << "Nhập khoảng thời gian mở sổ\n";
    cout << "Từ: ";
    InputDate(from);
    cout << "Đến: ";
    InputDate(to);
    SearchingInRange(tk, match, from, to);
    if (match.size()){
        cout << "Thông tin sổ tiết kiệm có ngày mở sổ từ"
             << from.strdate
             << " đến "
             << to.strdate
             << ":\n";
        XuatMang(tk, match);
    } 
    else {
        cout << "Không tồn tại sổ tiết kiệm có ngày mở sổ trong khoảng thời gian này\n";
    }    
}

/**
 * Hàm func_8: Sắp xếp sổ tiết kiệm theo số tiền gửi giảm dần.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_8(vector<SoTietKiem> &tk) {
    vector<SoTietKiem> sort_tk = tk;
    sort(sort_tk.begin(), sort_tk.end(), Desc_Money);
    cout << "Danh sách sổ tiết kiệm theo tiền gửi giảm dần:\n";
    XuatMang(sort_tk);    
    return;
}

/**
 * Hàm func_9: Sắp xếp sổ tiết kiệm theo ngày mở sổ tăng dần.
 * @param tk: Danh sách sổ tiết kiệm.
 */

void func_9(vector<SoTietKiem> &tk) {
    vector<SoTietKiem> sort_tk = tk;
    sort(sort_tk.begin(), sort_tk.end(), CompareSTK_Date);
    cout << "Danh sách sổ tiết kiệm theo ngày mở sổ tăng dần:\n";
    XuatMang(sort_tk);
}

/**
 * Hàm main: Hàm chính của chương trình.
 * 
 */

int main() {
    int n;
    cout << "Nhập số lượng sổ tiết kiệm: ";
    cin >> n;
    cin.ignore();

    vector<SoTietKiem> tk(n);
    NhapSTK(tk);

    int choice;
    int exit = 0;
    while (!exit) 
    {
        cout << "\n**************************************************************\n";
        cout << "Chương trình quản lí sổ tiết kiệm:\n"
             << "1. Xuất dữ liệu sổ tiết kiệm\n"
             << "2. Cập nhật lãi suất\n"
             << "3. Tính toán tiền lãi\n"
             << "4. Rút tiền\n"
             << "5. Tìm kiếm sổ tiết kiệm theo CMND\n"
             << "6. Tìm kiếm sổ tiết kiệm theo mã số\n"
             << "7. Liệt kê tất cả các sổ tiết kiệm mở trong một khoảng thời gian xác định\n"
             << "8. Sắp xếp sổ tiết kiệm theo số tiền gửi giảm dần\n"
             << "9. Sắp xếp sổ tiết kiệm theo ngày mở sổ tăng dần\n"
             << "10. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;
        cout << "\n";
        cin.ignore();
        switch (choice)
        {
            case 1:
            {
                func_1(tk);
                break;
            }
            case 2: 
            {   
                func_2(tk);
                break;
            }
            case 3:
            {
                func_3(tk);
                break;
            }
            case 4:
            {
                func_4(tk);
                break;
            }
            case 5:
            {
                func_5(tk);
                break;
            }
            case 6:
            {
                func_6(tk);
                break;
            }
            case 7:
            {
                func_7(tk);
                break;
            }
            case 8:
            {
                func_8(tk);
                break;
            }
            case 9:
            {
                func_9(tk);
                break;
            }
            case 10:
            {
                exit = 1;
                break;
            }
            default:
            {
                cout << "[!] Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
                break; 
            }           
        }
    }
    return 0;
}