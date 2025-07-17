#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    char choice;

    do {
        cout << "Введите N1 и N2: ";
        cin >> n1 >> n2;

        if (n1 > n2) {
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }

        cout << "Подходящие числа:\n";

        for (int i = n1; i <= n2; i++) {
            int sq = i * i;
            int copy = i;
            int mod = 1;

            // считаем, какая степень 10 нужна для остатка (например, 25 -> 100)
            while (copy > 0) {
                mod *= 10;
                copy /= 10;
            }

            if (sq % mod == i) {
                cout << i << " ";
            }
        }

        cout << "\nПовторить? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}