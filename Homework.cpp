#include <iostream>
#include <string>
using namespace std;

#define SO_LUONG_MAX 10

string nhapChuoi(string thongBao) {
    string s;
    cout << thongBao;
    getline(cin, s);
    return s;
}

class DienThoai {
public:
    int maSo;
    string hang;
    string phienBan;
    string maDong;
    int namSanXuat;
    double gia;

    void nhap() {
        cout << "Nhap ma so dien thoai: ";
        cin >> maSo;
        cin.ignore();

        hang = nhapChuoi("Nhap hang dien thoai: ");
        phienBan = nhapChuoi("Nhap phien ban: ");
        maDong = nhapChuoi("Nhap ma dong san pham: ");

        cout << "Nhap nam san xuat: ";
        cin >> namSanXuat;

        cout << "Nhap gia ban: ";
        cin >> gia;
    }

    void xuat() {
        cout << "------------------------------" << endl;
        cout << " Ma so    : " << maSo << endl;
        cout << " Hang     : " << hang << endl;
        cout << " Phien ban: " << phienBan << endl;
        cout << " Ma dong  : " << maDong << endl;
        cout << " Nam SX   : " << namSanXuat << endl;
        cout << " Gia      : " << gia << endl;
        cout << "------------------------------" << endl;
    }
};

class DonHang {
public:
    int maDonHang;
    int maKhachHang;
    string ghiChuKhach;
    string ngayDat;
    int hinhThucTT;
    DienThoai danhSachDT[SO_LUONG_MAX];
    int soLuongDT;

    void nhap(DienThoai kho[], int soLuongKho) {
        cout << "Nhap ma don hang: ";
        cin >> maDonHang;

        cout << "Nhap ma khach hang: ";
        cin >> maKhachHang;
        cin.ignore();

        ghiChuKhach = nhapChuoi("Nhap ghi chu / yeu cau cua khach: ");
        ngayDat = nhapChuoi("Nhap ngay dat (dd/mm/yyyy): ");

        cout << "Hinh thuc thanh toan (1: Chuyen khoan, 0: Tien mat): ";
        cin >> hinhThucTT;

        cout << "Nhap so luong san pham trong don: ";
        cin >> soLuongDT;

        for (int i = 0; i < soLuongDT; i++) {
            int maTim;
            cout << "Nhap ma san pham thu " << i + 1 << ": ";
            cin >> maTim;

            bool timThay = false;
            for (int j = 0; j < soLuongKho; j++) {
                if (kho[j].maSo == maTim) {
                    danhSachDT[i] = kho[j];
                    timThay = true;
                    break;
                }
            }

            if (!timThay) {
                cout << "Khong tim thay ma nay trong kho, nhap tay thong tin san pham:" << endl;
                cin.ignore();
                danhSachDT[i].nhap();
            }
        }
    }

    void xuat() {
        cout << "==============================" << endl;
        cout << " Ma don hang   : " << maDonHang << endl;
        cout << " Ma khach hang : " << maKhachHang << endl;
        cout << " Ghi chu       : " << ghiChuKhach << endl;
        cout << " Ngay dat      : " << ngayDat << endl;
        cout << " Thanh toan    : " << (hinhThucTT == 1 ? "Chuyen khoan" : "Tien mat") << endl;
        cout << " So san pham   : " << soLuongDT << endl;
        cout << " --- Danh sach san pham ---" << endl;
        for (int i = 0; i < soLuongDT; i++) {
            danhSachDT[i].xuat();
        }
        cout << "==============================" << endl;
    }
};

struct CuaHang {
    int maCH;
    string tenCH;

    DienThoai kho[SO_LUONG_MAX];
    int soLuongDT = 0;

    DonHang dsDonHang[SO_LUONG_MAX];
    int soLuongDon = 0;

    bool kiemTraCuaHang(int ma, string ten) {
        if (ma == 123 && ten == "A5-103")
            return true;
        return false;
    }

    bool nhapThongTinCH() {
        cout << "================================" << endl;
        cout << "Nhap ma cua hang: ";
        cin >> maCH;
        cin.ignore();

        tenCH = nhapChuoi("Nhap ten cua hang: ");

        if (!kiemTraCuaHang(maCH, tenCH)) {
            cout << "Cua hang nay khong ton tai trong he thong!" << endl;
            return false;
        }

        cout << "Nhap so luong dien thoai ban dau: ";
        cin >> soLuongDT;
        for (int i = 0; i < soLuongDT; i++) {
            cout << "\n--> Nhap dien thoai thu " << i + 1 << ":" << endl;
            kho[i].nhap();
        }

        cout << "Nhap so luong don hang ban dau: ";
        cin >> soLuongDon;
        for (int i = 0; i < soLuongDon; i++) {
            cout << "\n--> Nhap don hang thu " << i + 1 << ":" << endl;
            dsDonHang[i].nhap(kho, soLuongDT);
        }

        cout << "================================" << endl;
        return true;
    }

    void xuatThongTinCH() {
        cout << "<<<<<< THONG TIN CUA HANG >>>>>>" << endl;
        cout << "Ma cua hang: " << maCH << endl;
        cout << "Ten cua hang: " << tenCH << endl;

        cout << "\nTong so dien thoai trong kho: " << soLuongDT << endl;
        for (int i = 0; i < soLuongDT; i++)
            kho[i].xuat();

        cout << "\nTong so don hang: " << soLuongDon << endl;
        for (int i = 0; i < soLuongDon; i++)
            dsDonHang[i].xuat();
    }

    void themDienThoai() {
        if (soLuongDT >= SO_LUONG_MAX) {
            cout << "Kho da day, khong the them!" << endl;
            return;
        }
        cout << "\n== THEM DIEN THOAI MOI ==" << endl;
        cin.ignore();
        kho[soLuongDT].nhap();
        soLuongDT++;
        cout << "Them thanh cong!" << endl;
    }

    void xoaDienThoai(int maCanXoa) {
        int viTri = -1;
        for (int i = 0; i < soLuongDT; i++) {
            if (kho[i].maSo == maCanXoa) {
                viTri = i;
                break;
            }
        }

        if (viTri == -1) {
            cout << "Khong tim thay dien thoai co ma " << maCanXoa << endl;
            return;
        }

        for (int i = viTri; i < soLuongDT - 1; i++) {
            kho[i] = kho[i + 1];
        }
        soLuongDT--;
        cout << "Da xoa dien thoai ma " << maCanXoa << endl;
    }

    void taoDonHang() {
        if (soLuongDon >= SO_LUONG_MAX) {
            cout << "Danh sach don hang da day!" << endl;
            return;
        }
        cout << "\n== TAO DON HANG MOI ==" << endl;
        cin.ignore();
        dsDonHang[soLuongDon].nhap(kho, soLuongDT);
        soLuongDon++;
        cout << "Tao don hang thanh cong!" << endl;
    }

    void suaDonHang(int maDonCanSua) {
        int viTri = -1;
        for (int i = 0; i < soLuongDon; i++) {
            if (dsDonHang[i].maDonHang == maDonCanSua) {
                viTri = i;
                break;
            }
        }

        if (viTri == -1) {
            cout << "Khong tim thay don hang ma " << maDonCanSua << endl;
            return;
        }

        cout << "\n== SUA DON HANG MA " << maDonCanSua << " ==" << endl;
        cin.ignore();
        dsDonHang[viTri].nhap(kho, soLuongDT);
        cout << "Cap nhat don hang thanh cong!" << endl;
    }

    void thongKeTheoThang(string thang) {
        cout << "\n=== DON HANG TRONG THANG " << thang << " ===" << endl;
        int dem = 0;
        for (int i = 0; i < soLuongDon; i++) {
            if (dsDonHang[i].ngayDat.length() >= 5) {
                string thangTrongNgay = dsDonHang[i].ngayDat.substr(3, 2);
                if (thangTrongNgay == thang) {
                    dsDonHang[i].xuat();
                    dem++;
                }
            }
        }
        cout << "Tong so don tim thay: " << dem << endl;
    }
};

int main() {
    CuaHang cuaHang;

    cout << "=========================================" << endl;
    cout << "     CHAO MUNG DEN VOI SHOP DIEN THOAI    " << endl;
    cout << "=========================================" << endl;

    if (!cuaHang.nhapThongTinCH()) {
        cout << "Sai thong tin cua hang, chuong trinh ket thuc!" << endl;
        return 0;
    }

    int chon;
    do {
        cout << "\n============ MENU ============" << endl;
        cout << "1. Them dien thoai moi" << endl;
        cout << "2. Xoa dien thoai theo ma" << endl;
        cout << "3. Tao don hang moi" << endl;
        cout << "4. Sua thong tin don hang" << endl;
        cout << "5. Thong ke don hang theo thang" << endl;
        cout << "6. Xem toan bo thong tin cua hang" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Moi ban chon: ";
        cin >> chon;

        switch (chon) {
            case 1:
                cuaHang.themDienThoai();
                break;
            case 2: {
                int ma;
                cout << "Nhap ma dien thoai can xoa: ";
                cin >> ma;
                cuaHang.xoaDienThoai(ma);
                break;
            }
            case 3:
                cuaHang.taoDonHang();
                break;
            case 4: {
                int maDon;
                cout << "Nhap ma don hang can sua: ";
                cin >> maDon;
                cuaHang.suaDonHang(maDon);
                break;
            }
            case 5: {
                string thang;
                cout << "Nhap thang can thong ke (vd: 03, 12): ";
                cin >> thang;
                cuaHang.thongKeTheoThang(thang);
                break;
            }
            case 6:
                cuaHang.xuatThongTinCH();
                break;
            case 0:
                cout << "Cam on da su dung chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!" << endl;
        }
    } while (chon != 0);

    return 0;
}