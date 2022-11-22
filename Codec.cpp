/* Codec.cpp - Листинг программы шифрования/дешифрования

*****************************************************************

* Имя файла : Codec.cpp
* Резюме : Пример программы, написанной на языке программирования C++
* Описание : Разрабатываемая программа шифрует и дешифрует файл
* Автор : Morozov Oleg
* Платформа : OS Linux Ubuntu
*/

#define A 8253729
#define B 2396403
#define C 32768

#include "IOManager_h.h"
#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;

/* Генератор случайных чисел */
unsigned int Random(unsigned int seed){ return (A * seed + B) % C;}

/* Шифрование/дешифрование */
string ModifySequence(string str, int key, int seed) {
    if (str.size() == 0) { throw 1; }
    string modified_str(str);
    int seed2 = seed;
    for (int i = 0; i < str.size(); i++) {
        modified_str[i] = str[i]^key + Random(seed2);
        ++seed2;
    }
    return modified_str;
}

int main(int argc, char* argv[]){
         
     if (argc < 2 || argc == 3 || argc > 4) {
        cout << "Неверное количество аргументов\n";
        cout << IOManager::GetManual();
        exit(1);
    }

     string commandType = argv[1]; // Тип команды
     
     if (commandType == "-h" || commandType == "-help"){ // Вызов справки
         cout << IOManager::GetManual();
         exit(0);
     }
     
     string keyString = argv[2]; // Ключ
     string filename = argv[3]; // Имя файла
     string string_to_modify; // Строка для шифрования/дешифрования
     string modified_string; // Измененная строка
     int seed = 0; // Сид для генератора случайных чисел
     int key; // Ключ
    
    try{
    
	     /* ШИФРОВАНИЕ */
	     if (commandType == "-e" || commandType == "-encrypt"){ 
	     
		 if (!IOManager::IsDigit(keyString)) {
		     cout << "Ключ должен быть числом\n";
		     exit(1);
		 }

		 key = std::stoi(keyString);

		 cout << "Введите строку для шифрования\n";
		 getline(cin, string_to_modify);
		 modified_string = ModifySequence(string_to_modify, key, seed);
		 cout << "\nВведенная строка\n" << string_to_modify << "\n\n";
		 cout << "Зашифрованная строка\n" << modified_string << "\n\n";
		 
		 if (!IOManager::FileExists(filename)) {
		     IOManager::CreateFile(filename);
		 }
	       
		 IOManager::WriteFile(filename, modified_string);

		 cout << "Зашифрованная строка записана в " << filename << "\n";

	     }

	     /* ДЕШИФРОВАНИЕ */
	     if (commandType == "-d" || commandType == "-decrypt") {

		 if (!IOManager::IsDigit(keyString)) {
		     cout << "Ключ должен быть числом\n";
		     exit(1);
		 } 

		 key = std::stoi(keyString);
	    
		 if (!IOManager::FileExists(filename)) {
		     cout << "Файл " << filename << " не существует\n";
		     exit(1);
		 }
		 else if (IOManager::FileIsEmpty(filename)) {
		     cout << "Файл " << filename << " пуст\n";
		     exit(1);
		 }

	       string string_from_file = IOManager::ReadFile(filename);

	       cout << "Строка из файла\n" << string_from_file << "\n\n";
	       modified_string = ModifySequence(string_from_file, key, seed);
	       cout << "Расшифрованная строка\n" << modified_string << "\n";

	}
}catch(std::runtime_error er){
	cout << "Неизвестная ошибка\n";
	exit(1);
}
  
    return 0;
}
