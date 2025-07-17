#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct Goat {
    int id;
    int strength;
};

bool compareGoats(const Goat& a, const Goat& b) {
    return a.strength > b.strength;
}

vector<Goat> processTournament(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<Goat> goats(n);

    for (int i = 0; i < n; i++) {
        goats[i].id = i + 1;  
        goats[i].strength = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                goats[i].strength += matrix[i][j];
            }
        }
    }
    
    sort(goats.begin(), goats.end(), compareGoats);
    
    return goats;
}

vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    vector<vector<int>> matrix(7, vector<int>(7));
    
    if (!file.is_open()) {
        cerr << "Не удалось открыть файл!" << endl;
        return matrix;
    }
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            file >> matrix[i][j];
        }
    }
    
    file.close();
    return matrix;
}

int main() {
  
    vector<vector<int>> tournamentMatrix = readMatrixFromFile("tournament.txt");
 
    vector<Goat> rankedGoats = processTournament(tournamentMatrix);

    cout << "Рейтинг козлят по силе:\n";
    cout << "Место | Номер козленка | Сила\n";
    cout << "----------------------------\n";
    for (int i = 0; i < rankedGoats.size(); i++) {
        cout << i + 1 << "\t|\t" << rankedGoats[i].id << "\t|\t" << rankedGoats[i].strength << endl;
    }
    
    return 0;
}