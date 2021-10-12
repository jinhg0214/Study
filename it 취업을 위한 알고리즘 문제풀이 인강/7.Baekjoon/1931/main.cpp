#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time{
    int start;
    int end;
    Time(int a, int b){
        start = a;
        end = b;
    }
    bool operator<(const Time &b)const{ 
        return end < b.end; 
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\7.Baekjoon\\1931\\input.txt", "rt", stdin);

    int n;
    cin >> n;

    vector<Time> t(n);

    for(int i=0; i<n; i++){
        cin >> t[i].start >> t[i].end;
    }

    sort(t.begin(), t.end()); // 끝나는 시간 순으로 오름차순 정렬

    int cnt=0;
    int m=0;

    for(int i=0; i<t.size(); i++){
        if(m <= t[i].start){
            m = t[i].end;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}