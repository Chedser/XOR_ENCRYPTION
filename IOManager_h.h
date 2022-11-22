#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

class IOManager {

public:

    static  string GetManual(); // Справка
    static bool IsDigit(string); // Проверка на цифру
    static bool FileExists(string); // Проверка на существование файла
    static bool FileIsEmpty(string); // Проверка файла на пустоту
    static void CreateFile(string); // Создание файла
    static void  WriteFile(string, string); // Запись в файл
    static string ReadFile(string); // Чтение файйла в строку
};

#endif

