#include <iostream>

using namespace std;

int main(){
    int sum=0;
    int n, m;

    // 
    cin >> n >> m;

    for(int i=0; i<=n ; i++){
        // 만약 i가 m의 배수라면 sum에 더함
        if((i % m) == 0){
            sum += i;
        }
    }
    cout << sum;

    return 0;
}