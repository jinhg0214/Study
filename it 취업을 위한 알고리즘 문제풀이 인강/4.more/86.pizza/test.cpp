#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > hs, pz;
int m, ch[20], res=2147000000, dis, sum=0;

void DFS(int L, int s){
    if(L == m){
        // m���� �������� ���� �� ���, ������ ���� ��� �Ÿ��� ���
        sum = 0;

        // �� ���� ���� ��ްŸ� ���
        for(int i=0; i<hs.size(); i++){
            int x1 = hs[i].first;
            int y1 = hs[i].second;

            dis = 2147000000;

            for(int j=0; j<m; j++){ // ���� m���� �Ÿ� ���
                int x2 = pz[ch[j]].first;
                int y2 = pz[ch[j]].second;

                dis = min(dis, abs(x1-x2) + abs(y1-y2));
            }
            sum = sum + dis; // ���� ���� ����� �Ÿ�
        }

        if(sum < res) res = sum;
    }
    else{
        for(int i=s; i<pz.size(); i++){ // pz.size()�� ����, s���� �̴� ����
            ch[L] = i;
            DFS(L+1, i+1);     
        }
    }
}

int main(){

    freopen("G:\\Git\\Algorithm-C-\\4.more\\86.pizza\\input.txt", "rt", stdin);

    int n, a;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a;
            if(a==1) hs.push_back(make_pair(i, j)); 
            else if(a==2) pz.push_back(make_pair(i, j));
        }
    }

    DFS(0, 0);

    cout << res;

    return 0;
}