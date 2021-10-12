#include <iostream>
#include <string>

using namespace std;

int findStart(string& str, int index) {

    int a = str.find("http://", index);
    if (a == -1) a = str.length();

    int b = str.find("https://", index);
    if (b == -1) b = str.length();

    int res = min(a, b);

    return res;
}

int findEnd(string& str, int index) {

    int arr[4];
    string ender[4] = { ".com", ".co.kr", ".org", ".net" };

    for (int i = 0; i < 4; i++) {
        arr[i] = str.find(ender[i], index);
        if (arr[i] == -1) arr[i] = str.length();
    }

    int min = 21e8;
    //abcd중 최소값 리턴
    for (int i = 0; i < 4; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void to_lower(string& str) {

    int sz = str.length();

    for (int i = 0; i < sz; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return;
}

bool isValid(string& str) {
    // http:// ~~~ 까지 저장된 str 
    // .com 은 저장되어있지 않음

    int a = 0;
    int c = 0;

    // 마지막 /와 첫. 사이의 문자수를 확인
    while (1) {
        a = str.find('/', a);
        if (a == -1)break;

        c = str.find('/', a + 1);
        if (c == -1) {
            break;
        }
        if (a < c) {
            a = c;
        }
    }
    string tmp = str.substr(a + 1, str.length() -a - 1);

    if (tmp.size() < 3) return false;

    return true;
}

// https:// http://를 여는 괄호, .com, .org 등등을 닫는괄호로 생각하면될듯
int main() {
    string str;

    cin >> str;

	to_lower(str);

    int a = 0;
    int b = 0;
    int c = 0;

    int cnt = 0;

    while (1) {
        a = findStart(str, a);
        if (a == str.length())break;

        b = findEnd(str, a + 1);

        while (1) {
            c = findStart(str, a + 1);
            if (c == str.length())break;
            if (c < b) {
                a = c;
            }
            else break;
        }
        string tmp = str.substr(a, b - a);

        if (isValid(tmp) == true) {
            cnt++;
        }

        a = a + 1;
        b = b + 1;
    }

    cout << cnt << "개";

	return 0;
}