#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Функция для получения массива длин слов в строке
vector<int> getWordLengths(const string& str) {
    vector<int> lengths;
    istringstream iss(str);
    string word;
    
    while (iss >> word) {
        lengths.push_back(word.length());
    }
    
    return lengths;
}

// Функция для преобразования строки (разделение слов "***")
string transformString(const string& str) {
    istringstream iss(str);
    ostringstream oss;
    string word;
    bool firstWord = true;
    
    while (iss >> word) {
        if (!firstWord) {
            oss << "***";
        }
        oss << word;
        firstWord = false;
    }
    
    return oss.str();
}

// Функция для обработки файлов
void processFiles(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    
    if (!in.is_open() || !out.is_open()) {
        cerr << "Ошибка открытия файлов!" << endl;
        return;
    }
    
    string line;
    while (getline(in, line)) {
        // Часть 1: Получаем длины слов
        vector<int> lengths = getWordLengths(line);
        cout << "Длины слов: ";
        for (int len : lengths) {
            cout << len << " ";
        }
        cout << endl;
        
        // Часть 2: Преобразуем строку и записываем в файл
        string transformed = transformString(line);
        out << transformed << endl;
    }
    
    in.close();
    out.close();
}

int main() {
    // Пример работы с одной строкой
    string testStr = "Пример строки  с   разным  количеством пробелов";
    
    // Часть 1
    vector<int> lengths = getWordLengths(testStr);
    cout << "Тест 1 - Длины слов: ";
    for (int len : lengths) {
        cout << len << " ";
    }
    cout << endl;
    
    // Часть 2
    string transformed = transformString(testStr);
    cout << "Тест 2 - Преобразованная строка: " << transformed << endl;
    
    // Обработка файлов
    processFiles("F1.txt", "F2.txt");
    
    return 0;
}