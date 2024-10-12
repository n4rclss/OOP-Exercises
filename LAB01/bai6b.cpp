#include <bits/stdc++.h>
using namespace std;


struct HocSinh {
     /**
     * hoTen: Họ và tên đầy đủ của học sinh.
     * Ten: Tên riêng của học sinh sau khi xử lý từ họ tên.
     * diemToan: Điểm môn Toán.
     * diemVan: Điểm môn Văn.
     * diemNN: Điểm môn Ngoại ngữ.
     * diemTB: Điểm trung bình sau khi tính toán.
     * phanLoai: Xếp loại học sinh dựa trên điểm trung bình.
     */
    string hoTen;
    string Ten;
    float diemToan;
    float diemVan;
    float diemNN;
    float diemTB;
    string phanLoai;
    /**
     * Phương thức xử lý họ tên để lấy tên riêng của học sinh.
     * @return Tên riêng của học sinh (string).
     */
    string XulyTen() {
        int i = 0, j = 0;
        string tmp;
        while (hoTen[i]) {
            if (isspace(hoTen[i])) {
                tmp = ho
            }
        }
    }
    /**
     * Phương thức tính điểm trung bình của học sinh.
     * @return Điểm trung bình (float) được tính theo công thức:
     * (Điểm Toán * 2 + Điểm Văn + Điểm Ngoại ngữ) / 4.
     */
    float TinhDTB() {
        return (diemToan * 2 + diemVan + diemNN) / 4;
    }
    
    /**
     * Phương thức phân loại học sinh dựa trên điểm trung bình.
     * @return Xếp loại học sinh (string) theo các tiêu chí sau:
     * - "Xuat sac" nếu điểm TB >= 9
     * - "Gioi" nếu điểm TB >= 8
     * - "Kha" nếu điểm TB >= 6.5
     * - "Trung binh" nếu điểm TB >= 5
     * - "Yeu" nếu điểm TB < 5
     */
    string PhanLoai() {
        if (diemTB >= 9) 
            return "Xuat sac";
        else if (diemTB >= 8)
            return "Gioi";
        else if (diemTB >= 6.5)
            return "Kha";
        else if (diemTB >= 5)
            return "Trung binh";
        else   
            return "Yeu";
    }

    /**
     * Phương thức xuất thông tin của học sinh theo định dạng bảng.
     * @param a: Hiển thị họ tên (1: có, 0: không).
     * @param b: Hiển thị điểm Toán (1: có, 0: không).
     * @param c: Hiển thị điểm Văn (1: có, 0: không).
     * @param d: Hiển thị điểm Ngoại ngữ (1: có, 0: không).
     * @param e: Hiển thị điểm trung bình (1: có, 0: không).
     * @param f: Hiển thị phân loại học sinh (1: có, 0: không).
     */

    void XuatThongTin(int a, int b, int c, int d, int e, int f) {
        if (a) cout << "|" << setw(25) << hoTen;
        if (b) cout << "|" << setw(15) << setprecision(3) << diemToan;
        if (c) cout << "|" << setw(15) << setprecision(3) << diemVan;
        if (d) cout << "|" << setw(15) << setprecision(3) << diemNN;
        if (e) cout << "|\t" << setw(15) << setprecision(3) << diemTB;
        if (f) cout << "|\t" << setw(10) << phanLoai;
        cout << "|\n";
    }

      /**
     * Hàm tạo (constructor) để khởi tạo một đối tượng HocSinh với họ tên và điểm của các môn học.
     * @param hoten: Họ tên đầy đủ của học sinh.
     * @param diemtoan: Điểm môn Toán.
     * @param diemvan: Điểm môn Văn.
     * @param diemnn: Điểm môn Ngoại ngữ.
     */
    HocSinh(string hoten, float diemtoan, float diemvan, float diemnn) {
        hoTen = hoten;
        diemToan = diemtoan;
        diemVan = diemvan;
        diemNN = diemnn;
        Ten = XulyTen();
        diemTB = TinhDTB();   
        phanLoai = PhanLoai();
    }

    /**
     * Hàm tạo mặc định (constructor) không tham số.
     */
    HocSinh() {}
};

/**
 * Hàm kiểm tra họ tên hợp lệ.
 * @param s: Chuỗi họ tên cần kiểm tra.
 * @return True nếu họ tên hợp lệ, ngược lại trả về False.
 */

bool check_hoTen(string s) {
    bool check = true;
    if (s.empty()) check = false;
    int i = 0;
    while (s[i]) {
        if (!isalpha(s[i]) && !isspace(s[i])) {
            check = false;
            break;
        }
        i++;
    }
    if (!check) {
        cout << "Ho ten khong hop le. Vui long nhap lai!\n";
        return false;
    }
    return true;
}

/**
 * Hàm kiểm tra điểm hợp lệ.
 * @param n: Điểm cần kiểm tra.
 * @return True nếu điểm hợp lệ, ngược lại trả về False.
 */
bool check_diem(float n) {
    bool check = (n >= 0 && n <=10);
    if (!check) {
        cout << "Gia tri diem khong hop le. Vui long nhap lai!\n";
        return false;
    }
    return true;
}

/**
 * Hàm nhập thông tin của học sinh.
 * @param hoten: Họ tên của học sinh.
 * @param diemToan: Điểm môn Toán.
 * @param diemVan: Điểm môn Văn.
 * @param diemNN: Điểm môn Ngoại ngữ.
 * @param idx: Thứ tự của học sinh.
 */
void NhapThongTin(string &hoten, float &diemToan, float &diemVan, float &diemNN, int &idx) {
    cout << "Nhap thong tin hoc sinh " << idx + 1 << ":\n";
    cin.ignore();
    do {
        cout << "Nhap ho ten hoc sinh: ";
        getline(cin, hoten);
    } while (!check_hoTen(hoten));
    do {
        cout << "Nhap diem Toan (0-10): ";
        cin >> diemToan;
    } while (!check_diem(diemToan));
    do {
        cout << "Nhap diem Van (0-10): ";
        cin >> diemVan;
    } while (!check_diem(diemVan));
    do {
        cout << "Nhap diem Ngoai Ngu (0-10): ";
        cin >> diemNN;
    } while (!check_diem(diemNN)); 
}

/**
 * Hàm tìm học sinh có điểm trung bình cao nhất.
 * @param hs: Danh sách học sinh.
 * @param n: Số lượng học sinh.
 * @param idx: Vị trí của học sinh có điểm trung bình cao nhất.
 */

void MaxDTB(vector<HocSinh> &hs, int &n, vector<int> &idx) {
    idx.clear();
    float maxDTB = hs[0].diemTB; 
    for (int i = 0; i < n; i++) {
        if (hs[i].diemTB > maxDTB) 
        {
            maxDTB = hs[i].diemTB;
            idx.clear();
            idx.push_back(i);

        }
        else if (hs[i].diemTB == maxDTB)
        {
            idx.push_back(i);
        }
    }
}

/**
 * Hàm tìm học sinh có điểm toán thấp nhất.
 * @param hs: Danh sách học sinh.
 * @param n: Số lượng học sinh.
 * @param idx: Vị trí của học sinh có điểm toán thấp nhất.
 */

void MinDT(vector<HocSinh> &hs, int &n, vector<int> &idx) {
    idx.clear();
    float minDT = 10;
    for (int i = 0; i < n; i++) {
        if (hs[i].diemToan < minDT) 
        {
            minDT = hs[i].diemToan;
            idx.clear();
            idx.push_back(i);

        }
        else if (hs[i].diemToan == minDT)
        {
            idx.push_back(i);
        }
    }    
}

/**
 * Hàm main.
 */
int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    vector<HocSinh> hs(n);
    for (int i = 0; i < n; i++) {
        string hoten;
        float diemToan, diemVan, diemNN;
        NhapThongTin(hoten, diemToan, diemVan, diemNN, i);
        hs[i] = HocSinh(hoten, diemToan, diemVan, diemNN);
    }

    cout << "Diem trung binh va phan loai tung hoc sinh:\n";
    cout << "|" << setw(25) << "Ho ten" 
         << "|\t" << setw(10) << "Diem trung binh" 
         << "|\t" << setw(10) << "Xep loai" 
         << "|\n";
    for (HocSinh i : hs) {
        i.XuatThongTin(1,0,0,0,1,1);
    }

    vector<int> idx;
    MaxDTB(hs, n, idx);
    cout << "Hoc sinh co diem trung binh cao nhat:\n";
    cout << "|" << setw(25) << "Ho ten" 
         << "|\t" << setw(10) << "Diem Toan" 
         << "|\t" << setw(10) << "Diem Van" 
         << "|\t" << setw(10) << "Diem NN" 
         << "|\t" << setw(10) << "Diem trung binh" 
         << "|\t" << setw(10) << "Xep loai" 
         << "|\n";
    for (auto i : idx) {
        hs[i].XuatThongTin(1,1,1,1,1,1);
    }

    MinDT(hs, n, idx);
    cout << "Danh sach hoc sinh co diem toan thap nhat:\n";
    cout << "|" << setw(25) << "Ho ten" 
         << "|\t" << setw(10) << "Diem Toan" 
         << "|\n";
    for (auto i : idx) {
        hs[i].XuatThongTin(1,1,0,0,0,0);
    }    

}