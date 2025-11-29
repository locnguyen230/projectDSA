#include "hashtable.h"
#include <iostream>
using namespace std;

hashTableClass::hashTableClass() {
    classID = "";
    lop = nullptr;
}

int hashFunction(string key) {
    int sum = 0;
    for (char c : key) sum += c;
    return sum % TABLE_SIZE;
}

void insertClass(hashTableClass table[], string classID) {
    int index = hashFunction(classID);

    while (table[index].lop != nullptr) {
        if (table[index].classID == classID)
            return;
        index = (index + 1) % TABLE_SIZE;
    }

    table[index].classID = classID;
    table[index].lop = new ClassGroup(classID);
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

void deleteClass(hashTableClass table[], string classID) {
    int index = hashFunction(classID);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;

        if (table[pos].lop == nullptr) return;

        if (table[pos].classID == classID) {
            delete table[pos].lop;
            table[pos].lop = nullptr;
            table[pos].classID = "";
            return;
        }
    }
}

void printAllClasses(hashTableClass table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].lop != nullptr) {
            cout << table[i].classID << endl;
        }
    }
}
