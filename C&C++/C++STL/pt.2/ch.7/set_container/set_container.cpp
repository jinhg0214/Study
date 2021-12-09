/*
set은 key라 불리는 원소의 집합으로 이루어진 컨테이너. 
- 원소를 저장하는 insert() 멤버함수를 제공. -> insert실패시 반환값(bool)로 성공 실패를 알 수 있음
- 모든 원소가 유일함 <-> 중복을 허용해야 한다면 multiset 사용
- 특정 정렬 기준에 따라 원소를 자동 정렬하는 연관 컨테이너

*/

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

    pair<set<int>::iterator, bool> pr;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    pr = s.insert(90);
    // 삽입 시, 자동 정렬됨.

    cout << pr.second << endl;

    set<int>::iterator iter; // 기본 정렬 기준이 less인 set의 양방향 반복자
   
    print(s);

    //////////////////////////////////////////////////////////////////////////////////////
    pr = s.insert(50); // 중복된 원소(key)를 삽입한다. !! 실패!!
    s.insert(50);

    cout << pr.second << endl;

    print(s);

    /////////////////////////////////////////////////////////////////////////////////////
    pr = s.insert(90); 
    // 삽입시도 시, 반복자는 성공할 경우 성공한 원소를 가리키고,
    // 실패시, 실패한 위치를 가리키는 반복자가 됨.

    s.insert(pr.first, 85);// 90의 원소의 반복자에서(반복자가 가리키는 위치에서) 검색 시작 후 삽입(속도↑)

    print(s);


    ///////////////////
    set<int, greater<int> > s2;// 정렬 기준으로 greater<int> 조건자를 사용(내림차순 정렬)
    s2.insert(50);
    s2.insert(30);
    s2.insert(80);
    s2.insert(40);
    s2.insert(10);
    s2.insert(70);

    for(iter = s2.begin(); iter != s2.end() ; iter++)
        cout<< *iter << " ";
    cout << endl;

    return 0;

}