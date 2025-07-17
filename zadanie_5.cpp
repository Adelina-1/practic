#include <iostream>
using namespace std;

int main() {
    for (int cows = 2; cows <= 10; cows++) {
        for (int goats = 2; goats <= 10; goats++) {
            float milk = cows * 25 + goats * 2.5;
            cout << "Коров: " << cows
                 << ", Коз: " << goats
                 << " → Молока: " << milk << " л" << endl;
        }
    }

    return 0;
}