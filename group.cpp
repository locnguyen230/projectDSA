#include "group.h"
#include "bst.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


// Thêm SV vào lớp
void addStudentToGroup(ClassGroup &g, SinhVien sv) {
    insertSV(g.root, sv);
}



// Tìm SV trong lớp
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
        cout << "Thong tin sinh vien can tim: \n";
        cout << "+-----------------------------------------+\n";
        printOneSV(p->sv, stt);
    }
}


// Xóa SV khỏi lớp
void deleteStudentInGroup(ClassGroup &g, string id) {
    if (g.root == nullptr) {
        cout << "Lop " << g.classID << " chua co sinh vien.\n";
        return;
    }

    treeNode* p = searchSV(g.root, id);
    if (p == nullptr) {
        cout << "Khong tim thay sinh vien co ma: " << id << endl;
        return;
    }

    g.root = deleteSV(g.root, id);
    cout << "Da xoa sinh vien: " << id << endl;
}


// In danh sách lớp
void printGroup(const ClassGroup &g) {
    cout << "\n=== Danh sach lop " << g.classID << " ===\n";

    if (g.root == nullptr) {
        cout << "(Lop chua co sinh vien)\n";
        return;
    }

    int stt = 0;
    cout << "+-----------------------------------------+\n";
    cout << "| " << left << setw(3) << "STT ";
    cout << "| " << left << setw(17) << "TEN";
    cout << "|  " << left << setw(6) << "MSSV";
    cout << "| " << left << setw(5) << "GRADE |\n";
    cout << "+-----------------------------------------+\n";
    printSV(g.root, stt);
}



// In bang rank theo diem giam dan

// Dua SV từ BST vào vector
void collectStudents(treeNode* root, vector<SinhVien> &arr) {
    if (!root) return;
    collectStudents(root->left, arr);
    arr.push_back(root->sv);
    collectStudents(root->right, arr);
}

// QuickSort giam dan chon pivot o cuoi
int partitionGrade(vector<SinhVien> &a, int left, int right) {
    float pivot = a[right].grade;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (a[j].grade > pivot) {      
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}

void quickSortGrade(vector<SinhVien> &a, int left, int right) {
    if (left < right) {
        int pi = partitionGrade(a, left, right);
        quickSortGrade(a, left, pi - 1);
        quickSortGrade(a, pi + 1, right);
    }
}


// In bảng điểm xếp hạng
void printScoreRanking(const ClassGroup &g) {
    if (!g.root) {
        cout << "Lop " << g.classID << " chua co sinh vien.\n";
        return;
    }

    vector<SinhVien> list;
    collectStudents(g.root, list);

    quickSortGrade(list, 0, list.size() - 1);

    cout << "\n===== BANG DIEM XEP HANG - LOP " << g.classID << " =====\n";
    cout << "+-----------------------------------------+\n";
    cout << "| STT |        Ten         |  MSSV | Diem |\n";

    int stt = 1;
    for (auto &sv : list) {
        cout << "+-----------------------------------------+\n";
        cout << "| " << setw(3) << stt;
        cout << " | " << left << setw(17) << sv.name;
        cout << " | " << setw(6) << sv.id;
        cout << " | " << setw(4) << sv.grade << " |\n";
        stt++;
    }

    cout << "+-----------------------------------------+\n";
}



// In bang thong ke
string makeBar(float percent, int width = 30) {
    int filled = (percent * width) / 100;
    string bar = "";

    for (int i = 0; i < filled; i++) bar += "#";
    for (int i = filled; i < width; i++) bar += " ";

    return bar;
}

void printStatistics(ClassGroup &g){
    if (!g.root) {
        cout << "Lop " << g.classID << " chua co sinh vien.\n";
        return;
    }

    int xl[5]={0};
    vector<SinhVien> list;
    collectStudents(g.root, list);


    for(int i = 0; i < list.size(); i++ ) {
        if(list[i].grade >= 9.0) xl[0]++;      // Xuất sắc (>= 9.0)
        else if (list[i].grade >= 8.0) xl[1]++; // Giỏi (>= 8.0)
        else if (list[i].grade >= 6.5) xl[2]++; // Khá (>= 6.5 )
        else if (list[i].grade >= 5.0) xl[3]++; // Trung bình (>= 5.0)
        else xl[4]++;                           // Yếu (< 5.0)
    }

    float data[5];
    for(int i=0; i<5; i++){
        data[i] = ((float)xl[i] / list.size()) * 100.0; 
    }

    cout << "+--------------------------------------------------------+\n";
    cout << "|                   THONG KE XEP LOAI                    |\n";
    cout << "+--------------------------------------------------------+\n";
    cout << "| XUAT SAC   | " << makeBar(data[0])   << " | " << fixed << setw(7) << setprecision(2) << data[0]  << "% |\n";
    cout << "| GIOI       | " << makeBar(data[1]) << " | " << fixed << setw(7) << setprecision(2) << data[1] << "% |\n";
    cout << "| KHA        | " << makeBar(data[2])  << " | " << fixed << setw(7) << setprecision(2) << data[2]  << "% |\n";
    cout << "| TRUNG BINH | " << makeBar(data[3])   << " | " << fixed << setw(7) << setprecision(2) << data[3]   << "% |\n";
    cout << "| YEU        | " << makeBar(data[4])  << " | " << fixed << setw(7) << setprecision(2) << data[4]  << "% |\n";

    cout << "+--------------------------------------------------------+\n";
}
