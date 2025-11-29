#ifndef THONGKE_H
#define THONGKE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string makeBar(float percent, int width = 30) {
    if (percent > 100.0) percent = 100.0;
    if (percent < 0.0) percent = 0.0;
    
    int filled = static_cast<int>((percent * width) / 100.0);
    string bar = "";

    for (int i = 0; i < filled; i++) bar += "█";
    for (int i = filled; i < width; i++) bar += "░";

    return bar;
}

void printStatistics(float tonghop[]);

#endif // THONGKE_H