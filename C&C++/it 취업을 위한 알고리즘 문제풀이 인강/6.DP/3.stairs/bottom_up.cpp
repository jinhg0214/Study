#include <iostream>

using namespace std;

int dy[46];

int main(){
    int n;
    cin >> n;

    dy[1]=1;
    dy[2]=2;

    for(int i=3; i<=n; i++){
        dy[i] = dy[i-2] + dy[i-1];
    }

    cout << dy[n];

    return 0;
}