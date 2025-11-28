#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "group.h"
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct hashTableClass {
    string classID;
    group* lop;
    hashTableClass();
};

int hashFunction(string key);

void insertClass(hashTableClass table[], string classID);
group* findClass(hashTableClass table[], string classID);

// optional
void deleteClass(hashTableClass table[], string classID);

// in toàn bộ lớp
void printAllClasses(hashTableClass table[]);

#endif
