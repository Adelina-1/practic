#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Candidate {
    string name;
    int artistry;
    int photogenic;
    int erudition;
    int total;
};

// Функция для ввода данных о кандидатах
void inputCandidates(vector<Candidate>& candidates) {
    int n;
    cout << "Введите количество кандидатов: ";
    cin >> n;
    
    candidates.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\nКандидат #" << i+1 << endl;
        cout << "Имя: ";
        cin >> candidates[i].name;
        cout << "Артистичность (0-10): ";
        cin >> candidates[i].artistry;
        cout << "Фотогеничность (0-10): ";
        cin >> candidates[i].photogenic;
        cout << "Эрудированность (0-10): ";
        cin >> candidates[i].erudition;
        
        // Вычисляем общую сумму баллов
        candidates[i].total = candidates[i].artistry + candidates[i].photogenic + candidates[i].erudition;
    }
}

// Функция для нахождения лучшего по общему баллу
void findBestOverall(const vector<Candidate>& candidates) {
    auto best = max_element(candidates.begin(), candidates.end(),
        [](const Candidate& a, const Candidate& b) {
            return a.total < b.total;
        });
    
    cout << "\nЛучший кандидат (по общему баллу): " << endl;
    cout << "Имя: " << best->name << endl;
    cout << "Общий балл: " << best->total << endl;
    cout << "Артистичность: " << best->artistry << endl;
    cout << "Фотогеничность: " << best->photogenic << endl;
    cout << "Эрудированность: " << best->erudition << endl;
}

// Функция для нахождения лучших в каждой номинации
void findBestInCategories(const vector<Candidate>& candidates) {
    // Лучший по артистичности
    auto bestArt = max_element(candidates.begin(), candidates.end(),
        [](const Candidate& a, const Candidate& b) {
            return a.artistry < b.artistry;
        });
    
    // Лучший по фотогеничности
    auto bestPhoto = max_element(candidates.begin(), candidates.end(),
        [](const Candidate& a, const Candidate& b) {
            return a.photogenic < b.photogenic;
        });
    
    // Лучший по эрудированности
    auto bestErud = max_element(candidates.begin(), candidates.end(),
        [](const Candidate& a, const Candidate& b) {
            return a.erudition < b.erudition;
        });
    
    cout << "\nЛучшие в номинациях:" << endl;
    cout << "Артистичность: " << bestArt->name << " (" << bestArt->artistry << " баллов)" << endl;
    cout << "Фотогеничность: " << bestPhoto->name << " (" << bestPhoto->photogenic << " баллов)" << endl;
    cout << "Эрудированность: " << bestErud->name << " (" << bestErud->erudition << " баллов)" << endl;
}

int main() {
    vector<Candidate> candidates;
    
    // Ввод данных
    inputCandidates(candidates);
    
    // Определение лучших
    findBestOverall(candidates);
    findBestInCategories(candidates);
    
    return 0;
}