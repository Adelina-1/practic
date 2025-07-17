#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

vector<vector<double>> solveSystem(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    // Проверка размеров матриц
    if (A.empty() || B.empty() || A.size() != B.size() || A[0].size() != B[0].size()) {
        throw invalid_argument("Несовместимые размеры матриц A и B");
    }

    int n = A.size();
    int m = A[0].size();
    vector<vector<double>> X(n, vector<double>(m));

    // Решение уравнения AX + B = 0 => X = -A⁻¹B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            X[i][j] = -B[i][j] / A[i][j]; 
        }
    }

    return X;
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    try {
        vector<vector<double>> A = {{2, 0}, {0, 3}};
        vector<vector<double>> B = {{4, 6}, {9, 12}};

        cout << "Матрица A:" << endl;
        printMatrix(A);
        cout << "\nМатрица B:" << endl;
        printMatrix(B);

        vector<vector<double>> X = solveSystem(A, B);

        cout << "\nМатрица решений X:" << endl;
        printMatrix(X);
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}