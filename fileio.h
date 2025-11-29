#ifndef FILEIO_H
#define FILEIO_H

#include "hashtable.h"
#include "group.h"
#include <string>
using namespace std;

// ================================================
// ĐỌC CÁC SINH VIÊN TRONG MỖI LỚP TỪ FILE TXT
// Hàm này đọc dữ liệu lớp từ một file .txt,
// sau đó chèn vào BST của lớp (group)
//
// Format file gợi ý:
// CNTT1
// SV01 | Nguyen Van A | 9.0
// SV02 | Le Thi B | 8.5
// END
// 
// CNTT2
// SV11 | Nguyen Thi A | 9.0
// SV12 | Le Van B | 8.5
// END
// ================================================

void loadAllClassesFromFile(hashTableClass table[], const string &filename);



// ================================================
// GHI DANH SÁCH SINH VIÊN CỦA LỚP RA FILE TXT
// Ghi theo thứ tự In-Order để đảm bảo danh sách
// sắp xếp theo MSSV trong file.
//
// Format ghi:
// CNTT1
// SV01 | Nguyen Van A | 9.0
// SV02 | Le Thi B | 8.5
// END
// ================================================

void saveAllClassesToFile(hashTableClass table[], const string &filename);
#endif