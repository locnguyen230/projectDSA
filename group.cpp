#include "group.h"
#include "bst.h"
#include <iostream>
#include <iomanip>
using namespace std;

// =====================
// Thêm SV vào lớp
// =====================
void addStudentToGroup(ClassGroup &g, SinhVien sv) {
    insertSV(g.root, sv);
}


// =====================
// Tìm SV trong lớp
// =====================
void findStudentInGroup(ClassGroup &g) {
    if (g.root == nullptr) {
        cout << "Lop " << g.classID << " chua co sinh vien.\n";
        return;
    }

    string id;
    cout << "Nhap ma so sinh vien can tim: ";
    cin >> id;

    treeNode* p = searchSV(g.root, id);
    if (p == nullptr) {
        cout << "Khong tim thay sinh vien co ma: " << id << endl;
    } else {
        int stt = 1;
        printOneSV(p->sv, stt);
    }
}


// =====================
// Xóa SV khỏi lớp
// =====================
void deleteStudentInGroup(ClassGroup &g, string id) {
    if (g.root == nullptr) {
        cout << "Lop " << g.classID << " chua co sinh vien.\n";
        return;
    }else {
        treeNode* p = searchSV(g.root, id);
        if (p == nullptr) {
            cout << "Khong tim thay sinh vien co ma: " << id << endl;
            return;
        }
    }

    g.root = deleteSV(g.root, id);
    cout << "Da xoa sinh vien: " << id << endl;
}


// =====================
// In danh sách lớp
// =====================
void printGroup(const ClassGroup &g) {
    cout << "\n=== Danh sach lop " << g.classID << " ===\n";

    if (g.root == nullptr) {
        cout << "(Lop chua co sinh vien)\n";
        return;
    }

    int stt=0;
    cout << "+-----------------------------------------+\n";
    cout << "| " << left << setw(3) << "STT ";
    cout << "| " << left << setw(17) << "TEN";
    cout << "|  " << left << setw(6) << "MSSV";
    cout << "| " << left << setw(5) << "GRADE " << "|\n";
    printSV(g.root, stt);
     cout << "+-----------------------------------------+\n";
}
