#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "group.h"
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct hashTableClass {
    string classID;
    ClassGroup* lop;
    hashTableClass();
};


int hashFunction(string key);

//chuc nang
void insertClass(hashTableClass table[], string classID);
ClassGroup* findClass(hashTableClass table[], string classID);
void deleteClass(hashTableClass table[], string classID);
void printAllClasses(hashTableClass table[]);

#endif
