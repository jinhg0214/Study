#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\45.save_princess\\input.txt", "rt", stdin);
    int n, k, pos=0, bp=0, cnt=0; // 
    
    scanf("%d %d", &n, &k);

    vector<int> p(n+1); // index 1~n+1

    while(1){
        pos++;

        if(pos>n){
            pos = 1;
        }

        if(p[pos]==0){
            cnt++;
            if(cnt == k){
                cnt = 0;
                p[pos]=1;
                bp++;
            }
        }

        if(bp==n-1){
            break;
        }
    }

    for(int i=1; i<=n; i++){
        if(p[i]==0){
            printf("%d\n", i);
            break;
        }
    }


    return 0;
}