#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Функции для задачи 1
int sumOdd(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int sumNegative(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int sumOddNegative(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0 && arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Функции для задачи 2
void inputArray(int arr[], int size) {
    cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void removePrimes(int arr[], int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            arr[newSize++] = arr[i];
        }
    }
    size = newSize;
}

// Функции для задачи 3
void generateRandomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void arrayOperation(const int arr1[], const int arr2[], int result[], int size, char op) {
    for (int i = 0; i < size; i++) {
        if (op == '+') {
            result[i] = arr1[i] + arr2[i];
        } else {
            result[i] = arr1[i] - arr2[i];
        }
    }
}

int main() {
    srand(time(0));
    const int SIZE = 5;
    int arr[SIZE];

    // Задача 1
    cout << "Задача 1:\n";
    generateRandomArray(arr, SIZE, -10, 10);
    printArray(arr, SIZE);
    cout << "Сумма нечетных: " << sumOdd(arr, SIZE) << endl;
    cout << "Сумма отрицательных: " << sumNegative(arr, SIZE) << endl;
    cout << "Сумма нечетных и отрицательных: " << sumOddNegative(arr, SIZE) << endl;

    // Задача 2
    cout << "\nЗадача 2:\n";
    inputArray(arr, SIZE);
    printArray(arr, SIZE);
    removePrimes(arr, SIZE);
    cout << "Массив после удаления простых чисел: ";
    printArray(arr, SIZE);

    // Задача 3
    cout << "\nЗадача 3:\n";
    int arr1[SIZE], arr2[SIZE], result[SIZE];
    generateRandomArray(arr1, SIZE, 1, 10);
    generateRandomArray(arr2, SIZE, 1, 10);
    cout << "Массив 1: "; printArray(arr1, SIZE);
    cout << "Массив 2: "; printArray(arr2, SIZE);
    arrayOperation(arr1, arr2, result, SIZE, '+');
    cout << "Сумма массивов: "; printArray(result, SIZE);
    arrayOperation(arr1, arr2, result, SIZE, '-');
    cout << "Разность массивов: "; printArray(result, SIZE);

    return 0;
}