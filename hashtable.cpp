#include "hashtable.h"
#include "group.h" 
#include <iostream>
#include <string>
#include <vector>

using namespace std;



// Khởi tạo một node trong hash table
hashTableClass::hashTableClass() {
    classID = "";
    lop = nullptr;
    status = 0; 
}


// Ham bam
int hashFunction(string key) {
    int sum = 0;
    for (char c : key) sum += c;
    return sum % TABLE_SIZE;
}


// === TÌM LỚP
ClassGroup* findClass(hashTableClass table[], string classID) {
    int index = hashFunction(classID);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        
       
        if (table[pos].status == 0) { 
            return nullptr; 
        }

        
        if (table[pos].status == 1 && table[pos].classID == classID) { // OCCUPIED
            return table[pos].lop;
        }
        
        
    }
    return nullptr; 
}


// === THÊM LỚP 
void insertClass(hashTableClass table[], string classID) {
    ClassGroup* existingClass = findClass(table, classID);
    
    
    if (existingClass != nullptr) {
        cout << "Loi: Lop " << classID << " da ton tai! Khong the them.\n";
        return; 
    }

    
    int index = hashFunction(classID);
    
    for (int i = 0; i < TABLE_SIZE; i++) { 
        int pos = (index + i) % TABLE_SIZE;
        
        if (table[pos].status == 0 || table[pos].status == 2) { 
            table[pos].classID = classID;
            table[pos].lop = new ClassGroup(classID); 
            table[pos].status = 1; // Đặt trạng thái là OCCUPIED
            cout << "Da them lop " << classID << " thanh cong.\n";
            return;
        }
    }
    
    cout << "Loi: Khong the them lop " << classID << ". Bang bam da day.\n";
}


// XÓA LỚP 
void deleteClass(hashTableClass table[], string classID) {
    int index = hashFunction(classID);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;

        
        if (table[pos].status == 0) { 
            cout << "Khong tim thay lop " << classID << " de xoa.\n";
            return;
        }

        
        if (table[pos].status == 1 && table[pos].classID == classID) {
            
            
            delete table[pos].lop; 
            
            
            table[pos].lop = nullptr;
            table[pos].status = 2;
            
            cout << "Da xoa lop " << classID << " thanh cong!\n";
            return;
        }
    }
    
    cout << "Khong tim thay lop " << classID << " de xoa.\n";
}


// In lop hien co
void printAllClasses(hashTableClass table[]) {
    cout << "\n=== Danh sach cac lop hien co ===\n";
    bool found = false;
    for (int i = 0; i < TABLE_SIZE; i++) {
        
        if (table[i].status == 1) { 
            cout << "- " << table[i].classID << endl;
            found = true;
        }
    }
    if (!found) {


        cout << "(Khong co lop nao trong bang bam.)\n";
    }
}