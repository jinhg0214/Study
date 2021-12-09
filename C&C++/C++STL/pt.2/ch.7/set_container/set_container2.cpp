#include <iostream>
#include <set>

using namespace std;

void print(set<int> s){

    set<int>::iterator iter;

    for(iter = s.begin(); iter != s.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

}

int main(){

    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);

    print(s);

    cout << "원소 50의 개수: " << s.count(50) << endl; // 원소의 개수를 반환하는 멤버함수(set은 유일한 원소를 가지므로 0, 1)
    cout << "원소 100의 개수: " << s.count(100) << endl;

    /////////////////////////////

    set<int>::iterator iter;
    iter = s.find(30); // 검색 결과의 반복자를 반환, 없으면 s.end()와 같은 반복자 끝을 반환함

    if(iter != s.end()) 
        cout << *iter << "가 s에 있다" << endl;
    else
        cout << "30이 s에 없습니다." << endl;

    // !!!!!!!!!! 연관 컨테이너의 찾기 관련 멤버함수는 key(원소)를 찾을 때 == 연산을 사용하지 않음!! 
    

    // 범위 검색 lower_boudn, upper_bound
    set<int>::iterator iter_lower; 
    set<int>::iterator iter_upper;

    iter_lower = s.lower_bound(30); // 찾은 원소의 시작 반복자를 반환
    iter_upper = s.upper_bound(30); // 찾은 원소의 다음 원소를 가리키는 반복자를 반환
    // [lower_bound(), upper_bound()) 로 표현 가능

    cout << *iter_lower << endl;
    cout << *iter_upper << endl;

    iter_lower = s.lower_bound(55);
    iter_upper = s.upper_bound(55);

    if(iter_lower != iter_upper)
        cout << "55가 s에 있음!" << endl;
    else    // 찾는 원소가 없을 경우 lower==upper
        cout << "55가 s에 없음!" << endl;

    // 또는 equal_range()를 통해 범위 검색 가능 
    // equal_range()는 lower_bound(), upper_bound()를 pair로 리턴함

    pair<set<int>::iterator, set<int>::iterator> iter_pair; // equal_range의 리턴값을 저장하기 위한 iter_pair
    iter_pair = s.equal_range(30);

    cout << *iter_pair.first << endl;
    cout << *iter_pair.second << endl;

    iter_pair = s.equal_range(55);

    if(iter_pair.first != iter_pair.second)
        cout << "55가 s에 있음!" << endl;
    else    // 찾는 원소가 없을 경우 lower==upper
        cout << "55가 s에 없음!" << endl;

    return 0;
}