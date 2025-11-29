#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct SinhVien {
    string id;
    string name;
    float grade;
};

struct treeNode {
    SinhVien sv;
    treeNode* left;
    treeNode* right;
    treeNode(SinhVien data){
        sv = data;
        left = nullptr;
        right = nullptr;
    }
};

// ===== Các hàm xử lý BST =====
void insertSV(treeNode* root, SinhVien sv);
treeNode* searchSV(treeNode* root, string id);
treeNode* deleteSV(treeNode* root, string id);

// duyệt cây
void printSV(treeNode* root, int &stt);
void printOneSV(SinhVien sv, int stt);

// thống kê điểm
float countGrades(treeNode* root);

#endif
