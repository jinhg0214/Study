#include <iostream>
#include <vector> // 벡터 컨테이너 사용
// 벡터 컨테이너는 시퀸스 컨테이너 & 배열 기반 컨테이너!
// FIFO 구조

using namespace std;

int main(){

    // int 타입을 저장하는 컨테이너 v를 생성
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    for(int i =0; i<v.size() ; i++){
        cout << v[i] << endl; // operator[] 연산자를 이용하여 일반 배열처럼 원소에 접근 가능
    }

    return 0;

}