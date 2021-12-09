#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > hs, pz;
int ch[20], m, res=2147000000, dis, sum=0;

void DFS(int L, int s){
    
    if(L==m){ /* Level이 m일 때, (선택된 pz가 m개일 때)
        ch배열에 저장된 배열의 값을 통해 pz[i]에 접근, 
        이를 통해 거리를 계산 */
       sum = 0;

        for(int i=0; i<hs.size(); i++){ // hs배열의 각 원소와 선택된 pz원소의 거리를 계산
            int x1=hs[i].first;
            int y1=hs[i].second;

            dis = 2147000000;

            for(int j=0; j<m; j++){
                int x2=pz[ch[j]].first;
                int y2=pz[ch[j]].second;

                dis=min(dis, abs(x1-x2)+abs(y1-y2)); // 최소 거리를 비교
            }
            sum = sum+dis;
        }
        if(sum < res) res = sum; // 최소값을 변경
    }

    else {
        for(int i=s; i<pz.size(); i++){ // pz.size()개의 피자집 중에서 m개를 뽑는 조합
            ch[L]=i;
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
            if(a == 1) hs.push_back(make_pair(i, j));   // 집을 저장하는 벡터
            else if (a == 2) pz.push_back(make_pair(i, j)); // 피자가게를 저장하는 벡터
        }
    }
    DFS(0, 0);

    cout << res;

    return 0;
}