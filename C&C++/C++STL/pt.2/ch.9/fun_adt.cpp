#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

bool Pred(int n){
    return 30 <= n && n <= 40;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    cout << "30이상 40이하 원소의 개수 : " << count_if(v.begin(), v.end(), Pred) << endl;

    // Pred가 단항 함수가 아닌 일반 함수이므로 다음은 에러임.
    // not1은 어댑터로 함수 객체에 argument_type, result_type이 정의 되어있어야함
    // cout << "30이상 40이하 원소의 개수 : " << count_if(v.begin(), v.end(), not1(Pred)) << endl;
     
    // ptr_fun()을 통해 어댑터 적용이 가능한 함수 객체로 변환 후 not1적용
    cout << "30이상 40이하가 아닌 원소의 개수 : " << count_if(v.begin(), v.end(), not1(ptr_fun(Pred))) << endl;

    return 0;
}