#include <iostream>
#include <string>

using namespace std;

int main() {
    string str[3];

    for (int i = 0; i < 3; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < 3; i++) {
        if (str[i].find('M') != std::string::npos) {
            cout << "M이 존재합니다" << endl;
            return 0;
        }

    }
    cout << "M이 존재하지 않습니다" << endl;

    return 0;
}