#include <iostream>
#include <vector>

using namespace std;

/*
n : ���� ����
k : ���� ����
m_i : ���� ����
v_i : ���� ����
c_i : ���� �ִ� �ѵ�
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\7.Baekjoon\\1202\\input.txt", "rt", stdin);

    int n, k, m ,v, c;

    cin >> n >> k;

    vector<pair<int, int> > j(n); // ������ ������ ����

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