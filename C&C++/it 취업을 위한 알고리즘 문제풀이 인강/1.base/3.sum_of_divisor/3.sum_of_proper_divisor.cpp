#include <iostream>

using namespace std;

int main(){
    int n, sum = 1; // 1은 모든 수의 약수임

    cin >> n;

    cout << 1;
    
    // 1은 출력했으니 2부터 루프
    for(int i = 2; i < n ; i++){
        // 진약수라면 sum += i
        if((n % i) == 0){
            cout << " + " << i;
            sum += i; 
        }
    }
    cout << " = "<< sum;

    return 0;
}

// 약수의 패턴을 찾을 수 없으므로 
// '1+' '2+' '...' 'N=' 'sum' 이 아닌
// 1 '+2' '+3' ... '+N' '=sum'으로 묶음 