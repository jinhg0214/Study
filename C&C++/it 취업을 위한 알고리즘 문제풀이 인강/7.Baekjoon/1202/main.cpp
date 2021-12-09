#include <iostream>
#include <vector>

using namespace std;

/*
n : 보석 개수
k : 가방 개수
m_i : 보석 무게
v_i : 보석 가격
c_i : 가방 최대 한도
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\7.Baekjoon\\1202\\input.txt", "rt", stdin);

    int n, k, m ,v, c;

    cin >> n >> k;

    vector<pair<int, int> > j(n); // 보석의 정보를 저장

    for(int i=0; i<n; i++){
        cin >> m >> v;
        j.push_back(make_pair(m, v));
    }

    for(int j=0; j<k; j++){
        cin >> c;

        vector<int> dy(c+1, 0);

        for(int i=0; i<n; i++){
            for(int k = j[i].first; 
        }
    }



}