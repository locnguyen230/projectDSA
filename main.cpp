#include <iostream>
#include "menu.h"
#include "hashtable.h"
#include "fileio.h"
using namespace std;

int main() {

    hashTableClass *table = new hashTableClass[TABLE_SIZE];

    loadAllClassesFromFile(table, "DanhSachLop.txt");

    menuClass(table);

    saveAllClassesToFile(table, "DanhSachLop.txt");

    delete[] table;
    return 0;
}
