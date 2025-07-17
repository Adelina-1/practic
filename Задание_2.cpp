#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double x1, y1, x2, y2, x3, y3;
    
    cout << "Введите координаты трех вершин треугольника:\n";
    cout << "Вершина 1 (x y): ";
    while (!(cin >> x1 >> y1)) {
        cout << "Ошибка! Введите два числа через пробел: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    cout << "Вершина 2 (x y): ";
    while (!(cin >> x2 >> y2)) {
        cout << "Ошибка! Введите два числа через пробел: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    cout << "Вершина 3 (x y): ";
    while (!(cin >> x3 >> y3)) {
        cout << "Ошибка! Введите два числа через пробел: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    double a = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    double c = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    cout << "\nДлины сторон треугольника:\n";
    cout << "AB = " << c << "\nBC = " << a << "\nAC = " << b;
    
    return 0;
}