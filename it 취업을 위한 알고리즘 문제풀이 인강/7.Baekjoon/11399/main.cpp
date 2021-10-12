#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\7.Baekjoon\\11399\\input.txt", "rt", stdin);

    int n, sum=0;
    int p[1000];

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    sort(p, p+n);
   
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            sum += p[j];
        }
    }

    cout << sum;

    return 0;
}