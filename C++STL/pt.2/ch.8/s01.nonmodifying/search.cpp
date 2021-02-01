#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int left, int right){
    return abs(right-left) <= 5;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(32);
    v.push_back(28);
    v.push_back(33);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter;

    // 순차열에 30(n)과의 차가 5 이하인 원소가(Pred) 
    // 3번 이상 연속한 첫 원소의 반복자를 반환
    iter = search_n(v.begin(), v.end(), 3, 30, Pred);

    if(iter != v.end()){
        cout << "iter-1 :" << *(iter-1) << endl;
        cout << "iter :" << *(iter) << endl;
        cout << "iter+1 :" << *(iter+1) << endl;
    }
}