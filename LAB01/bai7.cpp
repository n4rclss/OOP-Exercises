#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Cấu trúc đại diện cho một ngày.
 * 
 * Cấu trúc này lưu trữ thông tin về ngày, tháng và năm.
 */
struct Date
{
    int day;            //Ngày trong tháng.
    int month;          //Tháng trong năm.
    int year;           //Năm.
    Date() {}           //Hàm khởi tạo mặc định.

    /**
     * @brief Khởi tạo đối tượng Date từ chuỗi.
     * 
     * Hàm này sẽ phân tích chuỗi có định dạng "dd/mm/yyyy"
     * để khởi tạo ngày, tháng và năm.
     * 
     * @param[in] s Chuỗi chứa thông tin ngày.
     */
    Date(string &s)
    {
        day = stoi(s.substr(0, 2));
        month = stoi(s.substr(3, 2));
        year = stoi(s.substr(6, 4));
    }
};

/**
 * @brief Cấu trúc đại diện cho một thời gian.
 * 
 * Cấu trúc này lưu trữ thông tin về giờ và phút.
 */
struct Time
{
    int hour; //Giờ trong ngày.
    int minute; //Phút.
    Time() {} //Hàm khởi tạo mặc định.

    /**
     * @brief Khởi tạo đối tượng Time từ chuỗi.
     * 
     * Hàm này sẽ phân tích chuỗi có định dạng "hh:mm"
     * để khởi tạo giờ và phút.
     * 
     * @param[in] s Chuỗi chứa thông tin thời gian.
     */
    Time(string &s)
    {
        hour = stoi(s.substr(0, 2));
        minute = stoi(s.substr(3, 2));
    }
};

/**
 * @brief Cấu trúc đại diện cho một chuyến bay.
 * 
 * Cấu trúc này lưu trữ thông tin chi tiết về chuyến bay,
 * bao gồm mã chuyến bay, ngày khởi hành, giờ khởi hành,
 * nơi đi và nơi đến.
 */
struct Flight
{
    string id;          //Mã chuyến bay.
    Date departDate;    //Ngày khởi hành.  
    Time departTime;    //Giờ khởi hành.
    string strdate;      //Chuỗi đại diện cho ngày.
    string strtime;     //Chuỗi đại diện cho thời gian.
    string fromLoc;     //Nơi khởi hành.
    string toLoc;       //Nơi đến.

    /**
     * @brief Khởi tạo đối tượng Flight với thông tin chuyến bay.
     * 
     * Hàm này khởi tạo một chuyến bay mới với các thông tin
     * như mã chuyến bay, ngày, giờ, nơi đi và nơi đến.
     * 
     * @param[in] flightCode Mã chuyến bay.
     * @param[in] date Ngày khởi hành.
     * @param[in] time Giờ khởi hành.
     * @param[in] from Nơi khởi hành.
     * @param[in] to Nơi đến.
     */
    Flight(string flightCode, string date, string time, string from, string to)
    {
        id = flightCode;
        strdate = date;
        strtime = time;
        departDate = Date(date);
        departTime = Time(time);
        fromLoc = from;
        toLoc = to;
    }
    //Hàm khởi tạo mặc định.
    Flight() {}
};

/**
 * @brief Xác thực định dạng mã chuyến bay. Nếu mã chuyến bay 
 * không hợp lệ thì hiển thị yêu cầu nhập lại.
 * 
 * @param[in] s Chuỗi mã chuyến bay cần xác thực.
 * @return true nếu mã chuyến bay hợp lệ; false nếu không.
 */
bool check_id(const string &s)
{
    bool check = regex_match(s, regex("^[A-Za-z0-9]{1,5}$"));
    if (!check)
    {
        cout << "[!] Mã chuyến bay không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * @brief Xác thực định dạng tên địa điểm. Nếu tên địa điểm 
 * không hợp lệ thì hiển thị yêu cầu nhập lại.
 * 
 * @param[in] s Chuỗi địa điểm cần xác thực.
 * @return true nếu tên địa điểm hợp lệ; false nếu không.
 */
bool check_loc(const string &s)
{
    bool check = regex_match(s, regex("^[A-Za-z ]{1,20}$"));
    if (!check)
    {
        cout << "[!] Địa điểm không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * @brief Kiểm tra xem ngày có hợp lệ hay không, 
 * bao gồm năm nhuận.
 * 
 * @param[in] date Cấu trúc Date cần kiểm tra.
 * @return true nếu ngày hợp lệ; false nếu không.
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
 * @brief Xác thực định dạng chuỗi ngày và kiểm tra giá trị 
 * của nó. Nếu không hợp lệ thì hiển thị yêu cầu nhập lại.
 * 
 * @param[in] s Chuỗi ngày theo định dạng dd/mm/yyyy.
 * @return true nếu chuỗi ngày hợp lệ; false nếu không.
 */
bool check_date_string(string &s)
{
    bool check1 = regex_match(s, regex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(19|20)\\d{2}$"));
    Date testDate = Date(s);
    bool check2 = check_date_value(testDate);
    if (!(check1 && check2))
    {
        cout << "[!] Ngày không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * @brief Xác thực định dạng chuỗi thời gian. Nếu không hợp lệ 
 * thì hiển thị yêu cầu nhập lại.
 * 
 * @param[in] s Chuỗi thời gian theo định dạng hh:mm.
 * @return true nếu chuỗi thời gian hợp lệ; false nếu không.
 */
bool check_time_string(string &s)
{
    bool check = regex_match(s, regex("^([01]\\d|2[0-3]):[0-5]\\d$"));
    if (!check)
    {
        cout << "[!] Thời gian không hợp lệ. Vui lòng nhập lại!\n";
        return false;
    }
    return true;
}

/**
 * @brief Yêu cầu người dùng nhập một mã chuyến bay hợp lệ.
 * 
 * Hàm này sẽ lặp lại yêu cầu nhập mã chuyến bay cho đến khi 
 * người dùng cung cấp một mã hợp lệ.
 * 
 * @param[in,out] id Tham chiếu đến chuỗi sẽ chứa mã chuyến bay.
 */
void InputID(string &id) {
    do
    {
        cout << "Nhập mã chuyến bay: ";
        getline(cin, id);
    } while (!check_id(id));
}

/**
 * @brief Yêu cầu người dùng nhập một ngày bay hợp lệ.
 * 
 * Hàm này sẽ lặp lại yêu cầu nhập ngày bay cho đến khi 
 * người dùng cung cấp một ngày hợp lệ theo định dạng dd/mm/yyyy.
 * 
 * @param[in,out] date Tham chiếu đến chuỗi sẽ chứa ngày bay.
 */
void InputDate(string &date) {
    do
    {
        cout << "Nhập ngày bay (dd/mm/yyyy): ";
        getline(cin, date);
    } while (!check_date_string(date));
}

/**
 * @brief Yêu cầu người dùng nhập một địa điểm hợp lệ (nơi đi hoặc nơi đến).
 * 
 * Hàm này sẽ lặp lại yêu cầu nhập địa điểm cho đến khi 
 * người dùng cung cấp một địa điểm hợp lệ.
 * 
 * @param[in,out] loc Tham chiếu đến một chuỗi sẽ chứa địa điểm.
 * @param[in] des Boolean xác định nếu đây là nơi đến (mặc định là true).
 */
void InputLoc(string &loc, bool des=1) {
    string text[2] = {"Nhập nơi đi: ", "Nhập nơi đến: "};
    do
    {
        cout << text[des];
        getline(cin, loc);
    } while (!check_loc(loc));
}

/**
 * @brief Yêu cầu người dùng nhập một thời gian bay hợp lệ.
 * 
 * Hàm này sẽ lặp lại yêu cầu nhập thời gian bay cho đến khi 
 * người dùng cung cấp một thời gian hợp lệ theo định dạng hh:mm.
 * 
 * @param[in,out] time Tham chiếu đến chuỗi sẽ chứa thời gian bay.
 */
void InputTime(string &time) {
    do
    {
        cout << "Nhập giờ bay (hh:mm): ";
        getline(cin, time);
    } while (!check_time_string(time));   
}

/**
 * @brief Quản lý quá trình nhập thông tin cho chuyến bay.
 * 
 * Hàm này sẽ yêu cầu người dùng nhập mã chuyến bay, ngày bay, 
 * thời gian bay, địa điểm đi và địa điểm đến cho chuyến bay 
 * tương ứng với chỉ số idx.
 * 
 * @param[in,out] id Tham chiếu đến chuỗi chứa mã chuyến bay.
 * @param[in,out] date Tham chiếu đến chuỗi chứa ngày bay.
 * @param[in,out] time Tham chiếu đến chuỗi chứa thời gian bay.
 * @param[in,out] from Tham chiếu đến chuỗi chứa địa điểm đi.
 * @param[in,out] to Tham chiếu đến chuỗi chứa địa điểm đến.
 * @param[in] idx Chỉ số của chuyến bay đang được nhập.
 */
void NhapThongTin(string &id, string &date, string &time, string &from, string &to, int &idx)
{
    cout << "Nhập thông tin chuyến bay thứ " << idx + 1 << ":\n";
    InputID(id);
    InputDate(date);
    InputTime(time);
    InputLoc(from, 0);
    InputLoc(to);
}

/**
 * @brief So sánh hai chuyến bay theo ngày và giờ khởi hành.
 * 
 * Hàm này sẽ trả về true nếu chuyến bay a khởi hành trước chuyến bay b,
 * ngược lại trả về false.
 * 
 * @param[in] a Chuyến bay đầu tiên để so sánh.
 * @param[in] b Chuyến bay thứ hai để so sánh.
 * @return true nếu a khởi hành trước b; false nếu không.
 */
bool compareFlights(const Flight &a, const Flight &b)
{
    if (a.departDate.year != b.departDate.year)
        return a.departDate.year < b.departDate.year;
    if (a.departDate.month != b.departDate.month)
        return a.departDate.month < b.departDate.month;
    if (a.departDate.day != b.departDate.day)
        return a.departDate.day < b.departDate.day;
    if (a.departTime.hour != b.departTime.hour)
        return a.departTime.hour < b.departTime.hour;
    return a.departTime.minute < b.departTime.minute;
}

/**
 * @brief Xuất tiêu đề bảng thông tin chuyến bay.
 * 
 * Hàm này sẽ in ra tiêu đề cho bảng hiển thị thông tin chuyến bay.
 */
void Xuat()
{
    cout << "|" << setw(10) << "Mã chuyến bay"
         << "|" << setw(17) << "Ngày bay"
         << "|" << setw(17) << "Giờ bay"
         << "|" << setw(17) << "Nơi đi"
         << "|" << setw(19) << "Nơi đến"
         << "|\n";
}

/**
 * @brief Xuất thông tin của một chuyến bay.
 * 
 * Hàm này sẽ in ra thông tin của chuyến bay theo định dạng bảng.
 * 
 * @param[in] cb Tham chiếu đến chuyến bay cần xuất thông tin.
 */
void XuatThongTin(Flight &cb)
{
    cout << "|" << setw(13) << cb.id
         << "|" << setw(16) << cb.strdate
         << "|" << setw(15) << cb.strtime
         << "|" << setw(15) << cb.fromLoc
         << "|" << setw(15) << cb.toLoc
         << "|\n";
}

/**
 * @brief Xuất thông tin của một danh sách các chuyến bay.
 * 
 * Hàm này sẽ gọi hàm Xuat để in tiêu đề và sau đó in thông tin cho từng chuyến bay.
 * 
 * @param[in] inp Tham chiếu đến vector chứa danh sách các chuyến bay.
 */
void XuatMang(vector<Flight> &inp) {
    Xuat();
    for (auto i : inp) {
        XuatThongTin(i);
    }
}

/**
 * @brief Xuất thông tin của một danh sách các chuyến bay theo chỉ số.
 * 
 * Hàm này sẽ gọi hàm Xuat để in tiêu đề và sau đó in thông tin cho các chuyến bay
 * dựa trên chỉ số trong vector idx.
 * 
 * @param[in] inp Tham chiếu đến vector chứa danh sách các chuyến bay.
 * @param[in] idx Tham chiếu đến vector chứa các chỉ số chuyến bay cần xuất.
 */
void XuatMang(vector<Flight> &inp, vector<int> &idx) {
    Xuat();
    for (auto i : idx) {
        XuatThongTin(inp[i]);
    }
}

/**
 * @brief Tìm kiếm chuyến bay theo mã chuyến bay.
 * 
 * Hàm này sẽ yêu cầu người dùng nhập mã chuyến bay và tìm chuyến bay
 * trong danh sách, nếu tìm thấy sẽ lưu chỉ số vào vector match.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 * @param[out] match Tham chiếu đến vector chứa các chỉ số của chuyến bay tìm thấy.
 * @param[in,out] search Tham chiếu đến chuỗi chứa mã chuyến bay tìm kiếm.
 */
void Searching_ID(vector<Flight> &cb, vector<int> &match, string &search)
{
    InputID(search);
    for (int i = 0; i < cb.size(); i++) {
        if (cb[i].id == search) {
            match.push_back(i);
            break;
        }
    }
}

/**
 * @brief Tìm kiếm chuyến bay theo địa điểm (nơi đi hoặc nơi đến).
 * 
 * Hàm này sẽ yêu cầu người dùng nhập địa điểm và tìm chuyến bay
 * trong danh sách dựa trên nơi đi hoặc nơi đến.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 * @param[out] match Tham chiếu đến vector chứa các chỉ số của chuyến bay tìm thấy.
 * @param[in,out] search Tham chiếu đến chuỗi chứa địa điểm tìm kiếm.
 * @param[in] des Boolean xác định nếu đây là nơi đến (mặc định là true).
 */
void Searching_Loc(vector<Flight> &cb, vector<int> &match, string &search, bool des=1) {
    InputLoc(search, des);
    for (int i = 0; i < cb.size(); i++) {
        if (des && cb[i].toLoc == search) {
            match.push_back(i);
        }
        if (!des && cb[i].fromLoc == search) {
            match.push_back(i);
        }
    }
}

/**
 * @brief Tìm kiếm chuyến bay theo ngày bay.
 * 
 * Hàm này sẽ yêu cầu người dùng nhập ngày bay và tìm chuyến bay
 * trong danh sách dựa trên ngày đã cho.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 * @param[out] match Tham chiếu đến vector chứa các chỉ số của chuyến bay tìm thấy.
 * @param[in,out] search Tham chiếu đến chuỗi chứa ngày bay tìm kiếm.
 */
void Searching_Date(vector<Flight> &cb, vector<int> &match, string &search)
{
    InputDate(search);
    for (int i = 0; i < cb.size(); i++) {
        if (cb[i].strdate == search) {
            match.push_back(i);
        }
    }
}


/**
 * @brief Xuất danh sách chuyến bay đã sắp xếp theo ngày và giờ khởi hành.
 * 
 * Hàm này sẽ in ra danh sách chuyến bay đã được sắp xếp theo thứ tự 
 * ngày và giờ khởi hành.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 */
void func_1(vector<Flight> &cb)
{
    cout << "Danh sách chuyến bay đã sắp xếp theo ngày giờ khởi hành:\n";
    XuatMang(cb);
}

/**
 * @brief Tìm kiếm chuyến bay theo mã, nơi đi hoặc nơi đến.
 * 
 * Hàm này cung cấp cho người dùng các tùy chọn để tìm kiếm chuyến bay
 * và in ra thông tin chuyến bay tương ứng.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 */
void func_2(vector<Flight> cb)
{
    bool exit = false;
    string search;
    int choice;
    vector<int> match;
    while (!exit)
    {
        match.clear();
        cout << "\n**************************************************************\n";
        cout << "1. Mã chuyến bay\n"
             << "2. Nơi đi\n"
             << "3. Nơi đến\n"
             << "4. Thoát\n" ;
        cout << "Nhập thông tin muốn tìm kiếm: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1: {
            Searching_ID(cb, match, search);
            if (match.size()){
                cout << "Thông tin chuyến bay mã " << search << ":\n";
                XuatMang(cb, match);
            } 
            else {
                cout << "Không tồn tại chuyến bay mã " << search << "\n";
                }
            break;
            }
        case 2: {
            Searching_Loc(cb, match, search, 0);
            if (match.size()){
                cout << "Thông tin chuyến bay có nơi đi từ " << search << ":\n";
                XuatMang(cb, match);
            } 
            else {
                cout << "Không tồn tại chuyến bay có nơi đi từ " << search << "\n";   
            }
            break;
        }
        case 3: {
            Searching_Loc(cb, match, search, 1);
            if (match.size()){
                cout << "Thông tin chuyến bay có nơi đến là " << search << ":\n";
                XuatMang(cb, match);
            } 
            else {
                cout << "Không tồn tại chuyến bay có nơi đến là " << search << "\n";
            }
            break;
        }
        case 4: {
            exit = true;
            break;
        }
        default:
            cout << "[!] Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
            break;
        }
    }
}

/**
 * @brief Hiển thị chuyến bay khởi hành từ một địa điểm trong một ngày nhất định.
 * 
 * Hàm này sẽ yêu cầu người dùng nhập địa điểm và ngày bay, sau đó 
 * in ra danh sách các chuyến bay khởi hành từ địa điểm đó trong ngày đã cho.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 */
void func_3(vector<Flight> &cb) {
    string from;
    string date;
    vector<int> match1, match2, intersection;
    Searching_Loc(cb, match1, from, 0);
    Searching_Date(cb, match2, date);
    set_intersection(match1.begin(), match1.end(), match2.begin(), match2.end(), back_inserter(intersection));
    cout << "Danh sách các chuyến bay khởi hành từ " << from << " trong ngày "
         << date << ":\n";
    XuatMang(cb, intersection);
}

/**
 * @brief Đếm số lượng chuyến bay từ một nơi đến một nơi khác.
 * 
 * Hàm này sẽ yêu cầu người dùng nhập địa điểm đi và địa điểm đến,
 * sau đó đếm và in ra số lượng chuyến bay giữa hai địa điểm đó.
 * 
 * @param[in] cb Tham chiếu đến vector chứa danh sách các chuyến bay.
 */
void func_4(vector<Flight> &cb) {
    string from, to;
    vector<int> match1, match2, intersection;
    Searching_Loc(cb, match1, from, 0);
    Searching_Loc(cb, match2, to, 1);
    set_intersection(match1.begin(), match1.end(), match2.begin(), match2.end(), back_inserter(intersection));
    cout << "Số lượng chuyến bay từ " << from << " đến " 
         << to << " là: " << intersection.size() << "\n";

}

/**
 * @brief Hàm chính của chương trình.
 * 
 * Hàm này sẽ quản lý quá trình nhập liệu, xuất thông tin và tương tác 
 * với người dùng thông qua menu.
 * 
 * @return 0 nếu chương trình kết thúc thành công.
 */
int main()
{
    int n;
    cout << "Nhập số lượng chuyến bay: ";
    cin >> n;
    cin.ignore();

    vector<Flight> cb(n);
    for (int i = 0; i < n; i++)
    {
        string id, date, time, from, to;
        cout << "\n===============================================================\n";
        NhapThongTin(id, date, time, from, to, i);
        cb[i] = Flight(id, date, time, from, to);
    }
    sort(cb.begin(), cb.end(), compareFlights);

    int choice;
    int exit = 0;
    while (!exit)
    {
        cout << "\n**************************************************************\n";
        cout << "Chương trình quản lý chuyến bay:\n"
             << "1. Xuất thông tin chuyến bay theo thứ tự ngày và giờ khởi hành\n"
             << "2. Tìm kiếm chuyến bay theo mã chuyến bay, nơi đến hoặc nơi đi\n"
             << "3. Hiển thị tất cả các chuyến bay khởi hành từ nơi đi trong một ngày\n"
             << "4. Đếm số lượng chuyến bay từ nơi đi đến nơi đến\n"
             << "5. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;
        cout << "\n";
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            func_1(cb);
            break;
        }
        case 2:
        {
            func_2(cb);
            break;
        }
        case 3:
        {
            func_3(cb);
            break;
        }
        case 4:
        {
            func_4(cb);
            break;
        }
        case 5:
        {
            exit = 1;
            break;
        }
        default:
            cout << "[!] Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
            break;
            
        }
    }
    return 0;
}