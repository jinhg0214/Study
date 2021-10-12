#include<iostream>
#include<string>

using namespace std;

// 연산자를 찾는 함수
int findOper(string& str, int index) {
    
    int sz = str.length();

    for (int i = index; i < sz; i++) {
        if (str[i] == '+' || str[i] == '-') {
            return i;
        }
    }
    
    return -1;
}

int main()
{
    string str;

    cin >> str;

    if (str[0] != '-') {
        str.insert(str.begin(), '+');
    }
    
    int a = 0;
    int b = 0;

    string temp;
    int res = 0;

    while (1) {
        a = findOper(str, a);
        if (a == -1)break;

        b = findOper(str, a + 1); // 다음 연산자 찾기
        if (b == -1) { // 뒤에 더이상 연산자가 없음
            b = str.length(); // 마지막 연산자 ~ 끝까지
            temp = str.substr(a + 1, b - a - 1);

            if (str[a] == '+') {
                res += stoi(temp);
            }
            else {
                res -= stoi(temp);
            }

            break;  
        }

        // 계산하는 부분
        // stoi
        temp = str.substr(a + 1, b - a - 1);

        if (str[a] == '+') {
            res += stoi(temp);
        }
        else {
            res -= stoi(temp);
        }

        a = a + 1;
        b = b + 1;
    }

    cout << res;

    return 0;
}