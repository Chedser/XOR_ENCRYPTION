
#ifndef IOMANAGER_C
#define IOMANAGER_C

#include "IOManager.h"

string IOManager::GetManual() {
    string manual = "Программа шифрует и дешифрует файл:\n\n\
    Шифрование:\n\
    ./codec -e 23 file.txt\n\
    codec -- название файла программы\n\
    -e или -encrypt -- флаг шифрования\n\
    23 -- ключ\n\
    file.txt -- название файла для шифрования/дешифрования\n\n\
    Дешифрование:\n\
    ./codec -d 23 file.txt\n\
    -d или -decrypt -- флаг дешифрования\n\n\
    -h или -help -- справка\n";
    return manual;
}

bool IOManager::IsDigit(string str) {
    if (str.empty()) { return false; }

    bool isDigit = true;

    for (char s : str) {
        if (!isdigit(s)) {
            isDigit = false;
            break;
        }
    }
    return isDigit;
}
bool IOManager::FileExists(string fileName) {
    bool isExist = false;
    std::ifstream fin(fileName.c_str());

    if (fin.is_open())isExist = true;

    fin.close();
    return isExist;
}

bool IOManager::FileIsEmpty(string fileName) {
    ifstream fin(fileName);
    if (!fin.is_open()) { throw std::runtime_error("File opening error\n"); }

    int symCount = 0;
    char c;

    while (!fin.eof()) {
        fin >> c;
        ++symCount;
    }

    fin.close();
    return (symCount == 1 || symCount == 0) ? true : false;
}

void IOManager::CreateFile(string fileName) {
    ofstream fout(fileName, std::ios_base::out);

    if (!fout.is_open()) { throw std::runtime_error("File opening error\n"); }
    fout.close();
}
void  IOManager::WriteFile(string fileName, string str) {
    ofstream fout(fileName, std::ios_base::out | std::ios_base::trunc);

    if (!fout.is_open()) { throw std::runtime_error("File openning error\n"); }
    fout << str;
    fout.close();
}

string IOManager::ReadFile(string fileName) {
    ifstream fin(fileName, std::ios_base::in);

    if (!fin.is_open()) { throw std::runtime_error("File opening error\n"); }

    int i = 0;
    string line;

    while (!fin.eof()) {
        getline(fin, line);
   }
    fin.close();
    return line;
}
#endif
