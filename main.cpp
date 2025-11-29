#include <iostream>
#include "menu.cpp"
#include "hashtable.h"
using namespace std;

int main() {

    hashTableClass *table = new hashTableClass[TABLE_SIZE];

    // loadAllClassesFromFile(table, "DanhSachLop.txt");

    menuClass(table);

    // saveAllClassesToFile(table, "DanhSachLop.txt");

    delete[] table;
    return 0;
}
