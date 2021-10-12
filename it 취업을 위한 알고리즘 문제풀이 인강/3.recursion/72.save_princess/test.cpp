#include <stdio.h>
#include <queue>

using namespace std;

int main(){

    int n ,k, i, tmp;
    queue<int> q;

    scanf("%d %d", &n, &k);

    for(i=1; i<=n; i++){
        q.push(i);
    }


    while(!q.empty()){
        for(i=1; i<k; i++){
            q.push(q.front());
            q.pop();
        }
        
        q.pop();

        if(q.size()==1){
            printf("%d", q.front());
        }
    }



    return 0;
}