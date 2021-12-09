// vector와 반복자

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //반복자를 이용한 원소 순회.
    for(vector<int>::iterator iter = v.begin(); iter != v.end() ; ++iter){
        cout << *iter << endl;
    }

    //반복자에는 + - += -= [] 연산이 가능함
    vector<int>::iterator iter2 = v.begin();
    cout << *iter2 << endl;
    cout << *++iter2 << endl; // 다음 원소 참조
    *iter2 = 100; // 일반 반복자는 가리키는 원소를 변경할 수 있음

    //상수 반복자 const_iterator 는 상수 포인터와 비슷하게 사용가능
    vector<int>::const_iterator citer = v.begin();
    cout << *citer << endl;
    cout << *++citer << endl;
    // *citer = 100; // 상수 반복자는 가리키는 원소를 변경할 수 없음!!

    vector<int>::reverse_iterator riter; // 역방향 반복자

    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

    for(riter = v.rbegin(); riter != v.rend(); ++riter){ // rbegin: 역방향 반복자의 첫 원소 = 정방향 반복자의 끝 , rend : 역방향 반복자의 끝 = 정방향 반복자의 시작(begin)
        cout << *riter << " ";
    } cout << endl;

    return 0;

}