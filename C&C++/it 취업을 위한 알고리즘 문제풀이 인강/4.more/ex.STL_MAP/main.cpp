#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
STL MAP 을 이용하여 가장 많이 쓰인 단어 찾기
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\ex.STL_MAP\\input.txt","rt", stdin);

    map<string, int> ch; //key:char, val:int
    map<string, int>::iterator it; // 반복자 

    char a[100];
    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;
        ch[a]++; // 단어가 Key, val이 1씩 증가함
    }

    int max=0;
    string res;

    for(it=ch.begin(); it!=ch.end(); it++){
        if(it->second > max){
            max = it->second;
            res = it->first;
        }
    }

    cout << res << " : "<< max << endl;

}