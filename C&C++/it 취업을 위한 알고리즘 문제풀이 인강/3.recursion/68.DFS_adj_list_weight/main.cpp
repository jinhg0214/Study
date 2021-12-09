#include <stdio.h>
#include <vector>

// pair�� �̿��Ͽ� ��������Ʈ ǥ��
using namespace std;

int ch[30], n, cost=2147000000;
vector<pair<int, int> > map[21]; 

void DFS(int v, int sum){

    int i;
    if(v==n){
        if(sum < cost) cost=sum;
    }
    else{
        for(i=0; i<map[v].size(); i++){
            if(ch[ map[v][i].first ]==0){
                ch[ map[v][i].first ]=1;
                DFS(map[v][i].first, sum + map[v][i].second);
                ch[ map[v][i].first ]=0;
            }
        }
    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\68.DFS_adj_list_weight\\input.txt", "rt", stdin);

    int m, start, end, weight;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        map[start].push_back( make_pair(end,weight) ); // map[n]�� pair�ڷ����� �����Ͽ� ������
    }

    ch[1]=1;

    DFS(1, 0);
    printf("%d\n", cost);

    return 0;    
}