#ifndef GROUP_H
#define GROUP_H

#include "bst.h"
#include <string>
#include <vector>
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
// in bang xep hang
void collectStudents(treeNode* root, vector<SinhVien> &arr);
int partitionGrade(vector<SinhVien> &a, int left, int right);
void quickSortGrade(vector<SinhVien> &a, int left, int right);
void printScoreRanking(const ClassGroup &g);
// in bang thong ke
string makeBar(float percent, int width); 
// void printStatistics(float tonghop[]);
void printStatistics(ClassGroup &g);


#endif
