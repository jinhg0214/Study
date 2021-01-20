#include <iostream>
#include <vector>

// vector의 임의 접근 반복자

using namespace std;

int main(){

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    vector<int>::iterator iter = v.begin(); // 반복자 생성(아직 원소를 가리키지 않음)
    
    cout << iter[0] << endl; // [] 연산자를 이용한 임의 원소 접근. iter+i 번째 원소에 접근(역참조)
    cout << iter[1] << endl;
    cout << iter[2] << endl;
    cout << iter[3] << endl;
    cout << iter[4] << endl;
    cout << endl;

    iter += 2; // += 연산. iter를 n만큼 이동시킴
    cout << *iter << endl;
    cout << endl;

    vector<int>::iterator iter2 = iter+2; // + 연산.
    cout << *iter2 << endl; 


    return 0;
}