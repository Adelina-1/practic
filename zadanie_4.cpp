#include <iostream>
using namespace std;

// Проверка на арифметическую прогрессию
bool isArithmeticProgression(int a, int b, int c, int d) {
    int d1 = b - a;
    int d2 = c - b;
    int d3 = d - c;
    return (d1 == d2) && (d2 == d3);
}

int main() {
    char choice;

    do {
        int a, b, c, d;

        cout << "Введите 4 целых числа через пробел: ";
        cin >> a >> b >> c >> d;

        if (isArithmeticProgression(a, b, c, d)) {
            cout << "Эти числа образуют арифметическую прогрессию." << endl;
        } else {
            cout << "Эти числа НЕ образуют арифметическую прогрессию." << endl;
        }

        cout << "Повторить? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Завершение программы." << endl;
    return 0;
}