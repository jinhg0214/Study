#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
STL MAP �� �̿��Ͽ� ���� ���� ���� �ܾ� ã��
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\ex.STL_MAP\\input.txt","rt", stdin);

    map<string, int> ch; //key:char, val:int
    map<string, int>::iterator it; // �ݺ��� 

    char a[100];
    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;
        ch[a]++; // �ܾ Key, val�� 1�� ������
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