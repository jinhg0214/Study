#include <iostream>
#include <string.h>

using namespace std;

int main() {

    string id, password;
    cin >> id >> password;

    // string.h의 compare함수는 같으면 0을, 아니면 -1,1을 출력함
    if (id.compare("qlqlaqkq") == 0 && password.compare("tkaruqtkf") == 0) {
        cout << "LOGIN" << endl;
    }
    else {
        cout << "INVALID" << endl;
    }

    return 0;
}