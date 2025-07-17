#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string Yes(double x1, double y1, double r1, double x2, double y2, double r2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    if (distance == 0) {
        if (r1 == r2) {
            return "Окружности концентрические (совпадают)";
        } else {
            return "Окружности концентрические (не пересекаются)";
        }
    } else if (distance > r1 + r2) {
        return "Окружности не пересекаются";
    } else if (distance == r1 + r2) {
        return "Окружности касаются внешним образом";
    } else if (distance < abs(r1 - r2)) {
        return "Одна окружность содержится внутри другой без пересечений";
    } else if (distance == abs(r1 - r2)) {
        return "Окружности касаются внутренним образом";
    } else {
        return "Окружности пересекаются в двух точках";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    
    double x1, y1, r1, x2, y2, r2;
    
    cout << "Введите параметры первой окружности (x y r): ";
    cin >> x1 >> y1 >> r1;
    
    cout << "Введите параметры второй окружности (x y r): ";
    cin >> x2 >> y2 >> r2;
    
    string result = Yes(x1, y1, r1, x2, y2, r2);
    cout << result << endl;
    
    return 0;
}