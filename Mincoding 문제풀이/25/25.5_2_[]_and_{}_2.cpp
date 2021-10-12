#include<iostream>
#include<string>

using namespace std;

int main(){

    string str;

    cin >> str;

    int a = 0; // [ 을 추적
    int b = 0; // ] 또는 }을 추적
    int c = 0; // { 을 추적
    
    string temp;
    int res = 0;

    while (1) {
        a = str.find('[', a);
        if (a == -1) { // 대괄호가 더이상 없는경우
            // 남은 중괄호들 처리
            while (1) {
                c = str.find('{', c);
                if (c == -1)break; // 중괄호도 없으면 진짜 끝

                b = str.find('}', c + 1);
                if (b == -1) break;

                temp = str.substr(c + 1, b - c - 1);

                res = res * stoi(temp);
                
                c = c + 1;
                b = c + 1;
            }
            break;
        }
        c = str.find('{', c);
        if (c == -1) { // 중괄호가 더이상 없는경우
            // 남은 대괄호들 처리
            while (1) {
                a = str.find('[', a);
                if (a == -1)break;

                b = str.find(']', a + 1);
                if (b == -1) break;

                temp = str.substr(a + 1, b - a - 1);

                res += stoi(temp);
                a = a + 1;
                b = a + 1;
            }
            break;
        }

        // [ 가 더 앞에 있다면
        if (a < c) {
            // b는 ]을 추적한다
            b = str.find(']', a + 1);
            if (b == -1) break;

            temp = str.substr(a+1, b - a-1);

            res += stoi(temp);

            a = a + 1;
            b = a + 1;
        }
        // { 가 더 앞에 있다면
        else { 
            // b는 }을 추적한다
            b = str.find('}', c + 1);
            if (b == -1) break;

            temp = str.substr(c+1, b - c-1);

            res = res * stoi(temp);

            c = c + 1;
            b = c + 1;
        }       
    }

    cout << res << endl;

    return 0;
}