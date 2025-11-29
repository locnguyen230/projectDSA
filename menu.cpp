#include <iostream>
#include <string>
using namespace std;

#include "bst.h"
#include "hashtable.h"
#include "group.h"    
#include "fileio.h"

// ---------------------- MENU SINH VIÊN (BST) --------------------------

void menuStudent(ClassGroup* lop) {
    int choice;

    while (true) {
        cout << "+--------------------------------------+\n";
        cout << "|===== MENU SINH VIEN - LOP " << lop->classID << " =====|\n";
        cout << "|1. Them sinh vien                     |\n";
        cout << "|2. Tim sinh vien theo ID              |\n";
        cout << "|3. Xoa sinh vien                      |\n";
        cout << "|4. In danh sach sinh vien             |\n";
        cout << "|5. In danh sach sinh vien theo diem   |\n";
        cout << "|6. Tao bang thong ke                  |\n";
        cout << "|0. Quay lai                           |\n";
        cout << "+--------------------------------------+\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int n;
            cout << "So sinh vien can nhap: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; i++) {
                SinhVien sv;
                cout << "\n--- Sinh vien thu " << i + 1 << " ---";

                cout << "\nNhap ten: ";
                getline(cin, sv.name);

                cout << "Nhap MSSV: ";
                getline(cin, sv.id);

                cout << "Nhap diem: ";
                cin >> sv.grade;
                cin.ignore();

                addStudentToGroup(*lop, sv);
            }
            break;
        }

        case 2:
            findStudentInGroup(*lop);
            break;

        case 3: {
            string id;
            cout << "Nhap MSSV can xoa: ";
            getline(cin, id);

            deleteStudentInGroup(*lop, id);
            break;
        }

        case 4:
            printGroup(*lop);
            break;

        case 0:
            return;

        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}


// ---------------------- MENU CHÍNH --------------------------

void menuClass(hashTableClass table[]) {
    int choice;
    string classID;

    while (true) {
        cout << "+------------------------------------+\n";
        cout << "|========= MENU QUAN LY LOP =========|\n";
        cout << "|1. Them lop                         |\n";
        cout << "|2. Xoa lop                          |\n";
        cout << "|3. Tim lop                          |\n";
        cout << "|4. Xem tat ca lop                   |\n";
        cout << "|5. Chon lop de quan ly sinh vien    |\n";
        cout << "|0. Thoat                            |\n";
        cout << "+------------------------------------+\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Nhap ma lop: ";
            getline(cin, classID);
            insertClass(table, classID);
            break;

        case 2:
            cout << "Nhap ma lop can xoa: ";
            getline(cin, classID);
            deleteClass(table, classID);
            break;

        case 3:
            cout << "Nhap ma lop can tim: ";
            getline(cin, classID);
            if (findClass(table, classID))
                cout << "Tim thay lop!\n";
            else
                cout << "Khong tim thay.\n";
            break;

        case 4:
            printAllClasses(table);
            break;

        case 5:
            cout << "Nhap ma lop: ";
            getline(cin, classID);
            {
                ClassGroup* lop = findClass(table, classID);
                if (lop)
                    menuStudent(lop);
                else
                    cout << "Lop khong ton tai!\n";
            }
            break;

        case 0:
            return;

        default:
            cout << "Lua chon khong hop le.\n";
        }
    }
}



