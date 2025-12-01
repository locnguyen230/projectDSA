#include "fileio.h"
#include "bst.h"
#include "hashtable.h"
#include "group.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;


//  ham ho tro Ghi 1 cay BST theo inorder

void writeOneTree(ofstream &out, treeNode* root) {
    if (!root) return;

    writeOneTree(out, root->left);

    out << root->sv.id << " | "
        << root->sv.name << " | "
        << fixed << setprecision(1) << root->sv.grade << "\n";

    writeOneTree(out, root->right);
}


//  Ghi toàn bộ bảng băm (tất cả lớp)

void saveAllClassesToFile(hashTableClass table[], const string &filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Không mở được file để ghi: " << filename << endl;
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].lop != nullptr) {
            out << table[i].classID << "\n";              
            writeOneTree(out, table[i].lop->root);        
            out << "END\n\n";                             
        }
    }

    out.close();
    cout << "Đa luu du lieu ra file thanh cong!\n";
}

// xu ly khoang trang dau cuoi

static void trimString(string &s) {
    while (!s.empty() && s.front() == ' ') s.erase(s.begin());
    while (!s.empty() && s.back() == ' ') s.pop_back();
}


//  Load data: Đọc toàn bộ lớp từ file

void loadAllClassesFromFile(hashTableClass table[], const string &filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Không mở được file: " << filename << endl;
        return;
    }

    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;

        string className = line;

        // Thêm lớp vào bảng băm 
        insertClass(table, className);
        ClassGroup* pGroup = findClass(table, className);

        // Đọc danh sách SV trong lớp
        while (getline(in, line)) {
            if (line == "END") break;

            stringstream ss(line);
            string maSV, hoTen, diemStr;

            getline(ss, maSV, '|');
            getline(ss, hoTen, '|');
            getline(ss, diemStr);

            trimString(maSV);
            trimString(hoTen);
            trimString(diemStr);

            float diem = stof(diemStr);

            SinhVien sv;
            sv.id=maSV;
            sv.name=hoTen;
            sv.grade=diem;
            addStudentToGroup( *pGroup, sv);
        }
    }

    in.close();
    cout << "Đa tai da lieu tu file thanh cong!\n";
}
