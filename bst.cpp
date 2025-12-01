#include "bst.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Ham ho tro

// chuyen sang chu thuong
string toLower(string s) {
    for (char &c : s)
        if (c >= 'A' && c <= 'Z')
            c += 32;
    return s;
}


//  Thêm sinh viên vào BST
void insertSV(treeNode*& root, SinhVien sv) {
    if (root == nullptr) {
        root = new treeNode(sv);
        return;
    }

    sv.id = toLower(sv.id);

    treeNode* cur = root;
    treeNode* parent = nullptr;

    while (cur != nullptr) {
        if (sv.id == cur->sv.id) {
            cout << "+-----------------------------+\n";
            cout << "| Sinh vien nay da ton tai!!! |\n";
            cout << "+-----------------------------+\n";
            return;
        }
        parent = cur;

        if (sv.id < cur->sv.id)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (sv.id < parent->sv.id)
        parent->left = new treeNode(sv);
    else
        parent->right = new treeNode(sv);
}



//  Tìm sinh viên theo ID

treeNode* searchSV(treeNode* root, string id) {
    id = toLower(id);

    while (root != nullptr) {
        if (id == root->sv.id)
            return root;

        if (id < root->sv.id)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}



//   Xóa sinh viên theo ID

treeNode* findMin(treeNode* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

treeNode* deleteSV(treeNode* root, string id) {
    if (root == nullptr) return nullptr;

    id = toLower(id);

    if (id < root->sv.id) {
        root->left = deleteSV(root->left, id);
    }
    else if (id > root->sv.id) {
        root->right = deleteSV(root->right, id);
    }
    else {

        // TH1: không có con
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // TH2: chỉ có 1 con
        if (!root->left) {
            treeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            treeNode* temp = root->left;
            delete root;
            return temp;
        }

        // TH3: có 2 con tim node the man trai cung ben phai
        treeNode* minRight = findMin(root->right);
        root->sv = minRight->sv;
        root->right = deleteSV(root->right, minRight->sv.id);
    }

    return root;
}



//  In danh sach sv theo Inorder(L-N-R)

void printOneSV(SinhVien sv, int stt) {
    cout << "|  " << left << setw(3) << stt;
    cout << "| " << left << setw(17) << sv.name;
    cout << "|  " << left << setw(6) << sv.id;
    cout << "|  " << left << setw(5) << sv.grade << "|\n";
    cout << "+-----------------------------------------+\n";
}

void printSV(treeNode* root, int &stt ) {
    if (root == nullptr) return;

    printSV(root->left, stt);
    printOneSV(root->sv, stt);
    stt++;
    printSV(root->right, stt);
}



