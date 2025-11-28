#include "bst.h"
#include <iostream>
using namespace std;



void insertSV(inf sv, group& malop)
{
    treeNode* newNode = new treeNode(sv);
    if(malop.root == nullptr) {malop.root = newNode; return;}
    treeNode* cur = malop.root;
    treeNode* parent = nullptr;
    //vong lap
    while(cur != nullptr){
        if(sv.id == cur->sv.id){
            cout<<"+-----------------------------+\n";
            cout<<"| Sinh vien nay da ton tai!!! |\n";
            cout<<"+-----------------------------+\n";
            delete newNode;
            return;
        }
        parent = cur;
        if(sv.id < cur->sv.id) cur = cur->left;
        else if(sv.id > cur->sv.id) cur = cur->right;
    }
    if(sv.id < parent->sv.id) parent->left = newNode;
    else parent->right = newNode; 
    
    // de quy
    // if(newNode.sv.id <= malop.root.sv.id) return insertSV(sv, malop.root->left);
    // else return insertSV(sv, malop.root->right);
}

treeNode *searchSV(treeNode *root, string id)
{
    return nullptr;
}

treeNode *deleteSV(treeNode *root, string id)
{
    return nullptr;
}

void printSV(treeNode *root, int &stt)
{
}

void printOneSV(inf sv, int stt)
{
}

void countGrades(treeNode *root)
{
}
