#ifndef GROUP_H
#define GROUP_H

#include "bst.h"
#include <string>
using namespace std;

struct group {
    string classID;
    treeNode* root;
    group(string malop){
        classID = malop;
        root = nullptr; 
    }
};

// thêm / tim / xóa trong lớp
void addStudentToGroup(group &g, inf sv);
void findStudentInGroup(group &g);
void deleteStudentInGroup(group &g, string id);

// in danh sách 1 lớp
void printGroup(const group &g);

#endif
