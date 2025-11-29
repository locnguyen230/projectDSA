#ifndef GROUP_H
#define GROUP_H

#include "bst.h"
#include <string>
using namespace std;

struct ClassGroup {
    string classID;
    treeNode* root;
    ClassGroup(string malop){
        classID = malop;
        root = nullptr; 
    }
};

// thêm / tim / xóa trong lớp
void addStudentToGroup(ClassGroup &g, SinhVien sv);
void findStudentInGroup(ClassGroup &g);
void deleteStudentInGroup(ClassGroup &g, string id);

// in danh sách 1 lớp
void printGroup(const ClassGroup &g);

#endif
