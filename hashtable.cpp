#include "hashtable.h"
#include "group.h" 
#include <iostream>
#include <string>
using namespace std;

// Khởi tạo một node trong hash table
hashTableClass::hashTableClass() {
    classID = "";
    lop = nullptr;
}


// Ham bam
int hashFunction(string key) {
    int sum = 0;
    for (char c : key) sum += c;
    return sum % TABLE_SIZE;
}


ClassGroup* findClass(hashTableClass table[], string classID) {
    int index = hashFunction(classID);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (table[pos].lop == nullptr) return nullptr; 
        if (table[pos].classID == classID) return table[pos].lop;
    }
    return nullptr; 
}


// Them lop
void insertClass(hashTableClass table[], string classID) {
    ClassGroup* existingClass = findClass(table, classID);
    
    if (existingClass != nullptr) {
        cout << "Loi: Lop " << classID << " da ton tai! Khong the them.\n";
        return; 
    }

    int index = hashFunction(classID);
    
    for (int i = 0; i < TABLE_SIZE; i++) { 
        int pos = (index + i) % TABLE_SIZE;
        
        if (table[pos].lop == nullptr) {
            table[pos].classID = classID;
            table[pos].lop = new ClassGroup(classID); 
            cout << "Da them lop " << classID << " thanh cong.\n";
            return;
        }
    }
    
    
    cout << "Loi: Khong the them lop " << classID << ". Bang bam da day.\n";
}


// Xoa lop
void deleteClass(hashTableClass table[], string classID) {
    int index = hashFunction(classID);

    
    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;

        
        if (table[pos].lop == nullptr) {
            cout << "Khong tim thay lop " << classID << " de xoa.\n";
            return;
        }

        if (table[pos].classID == classID) {
            delete table[pos].lop;       
            table[pos].lop = nullptr;    
            table[pos].classID = "";     
            
            cout << "Da xoa lop " << classID << " thanh cong!\n";
            return;
        }
    }
    
    
    cout << "Khong tim thay lop " << classID << " de xoa.\n";
}


// In lop hien co
void printAllClasses(hashTableClass table[]) {
    cout << "Danh sach cac lop hien co: \n";
    bool found = false;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].lop != nullptr) {
            cout << "- " << table[i].classID << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "(Khong co lop nao trong bang bam.)\n";
    }
}