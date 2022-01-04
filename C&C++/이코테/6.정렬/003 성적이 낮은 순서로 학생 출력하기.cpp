#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int score;

    // 생성자
    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }

    // 정렬 기준 : 점수 오름차순
    bool operator < (Student& other) {
        return this->score < other.score;
    }
};

int main() {
    int N;
    cin >> N;
       
    vector<Student> vec;

    for (int i = 0; i < N; i++) {
        string name;
        int score;
        cin >> name >> score;
        vec.push_back(Student(name, score));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        cout << vec[i].name << " ";
    }
    cout << endl;

    return 0;
}