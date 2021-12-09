#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > hs, pz;
int ch[20], m, res=2147000000, dis, sum=0;

void DFS(int L, int s){
    
    if(L==m){ /* Level�� m�� ��, (���õ� pz�� m���� ��)
        ch�迭�� ����� �迭�� ���� ���� pz[i]�� ����, 
        �̸� ���� �Ÿ��� ��� */
       sum = 0;

        for(int i=0; i<hs.size(); i++){ // hs�迭�� �� ���ҿ� ���õ� pz������ �Ÿ��� ���
            int x1=hs[i].first;
            int y1=hs[i].second;

            dis = 2147000000;

            for(int j=0; j<m; j++){
                int x2=pz[ch[j]].first;
                int y2=pz[ch[j]].second;

                dis=min(dis, abs(x1-x2)+abs(y1-y2)); // �ּ� �Ÿ��� ��
            }
            sum = sum+dis;
        }
        if(sum < res) res = sum; // �ּҰ��� ����
    }

    else {
        for(int i=s; i<pz.size(); i++){ // pz.size()���� ������ �߿��� m���� �̴� ����
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
            if(a == 1) hs.push_back(make_pair(i, j));   // ���� �����ϴ� ����
            else if (a == 2) pz.push_back(make_pair(i, j)); // ���ڰ��Ը� �����ϴ� ����
        }
    }
    DFS(0, 0);

    cout << res;

    return 0;
}