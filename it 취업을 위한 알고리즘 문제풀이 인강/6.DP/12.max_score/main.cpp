#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제는 여러개 풀 수 있는게 아니라, 한번 풀면 끝임!!
가방에 보석 담는 문제와는 다름

2차원 배열 :
dy[i][j] : i번째 문제까지 적용했을 때, 시간j까지의 최대 점수
dy[i-1][j-pt]를 참조해야함, 현재 문제가 적용되기 전의 dy배열 참조

1차원 배열로 해결하는 방법 : 
dy[j] : j분이 주어졌을때 얻을 수 있는 최대점수
        dy  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
ps  pt      0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   
10  5       0   0   0   0   0   10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  // 뒤에서부터 채워나감
25  12      0   0   0   0   0   10  10  10  10  10  10  10  25  25  25  25  25  35  35  35  35
15  8       0   0   0   0   0   10  10  10  15  15  15  15  25  25  25  25  25  35  35  35  40
...
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\12.max_score\\input.txt", "rt", stdin);

    int n, m, ps, pt;

    cin >> n >> m;

    vector<int> dy(m+1);

    for(int i=0; i<n; i++){
        cin >> ps >> pt;

        for(int j=m; j>=pt; j--){ // 뒤에서 앞으로 이동
            dy[j] = max(dy[j], dy[j-pt] + ps);
        }
    }
    
    cout << dy[m];

    return 0;
}