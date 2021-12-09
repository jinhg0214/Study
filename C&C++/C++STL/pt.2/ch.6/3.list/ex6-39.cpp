// reverse() 멤버함수
// 원소의 순차열을 반대로 뒤집어야 할 경우 사용

// unique() 멤버함수
// 원소를 중복되지 않게 하나씩만 남김.

// sort() 멤버함수
// list는 sort() 알고리즘 이용 불가(임의 접근 반복자가 아니므로)
// 자체 정렬 멤버함수 sort() 를 제공함. 기본은 오름차순 less <-> Greater()

#include <iostream>
#include <list>

using namespace std;

void print(list<int> lt){

    list<int>::iterator iter;

    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

}

int main(){

    list<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    list<int>::iterator iter;

    print(lt);

    lt.reverse(); // 원소의 순차열을 반대로 뒤집음

    print(lt);

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    print(lt);

    lt.unique(); // 인접한 중복된 원소를 합침-> 10 10 10 20 30 20 30 -> 10 20 30 20 30 ...

    print(lt);

    // unique()로 모든 원소를 유일하게 만들고자 한다면, 원소를 정렬하고 수행해야함.

    lt.sort(); 
   

    lt.unique(); // 1010 2020 3030 4040 5050 -> 10 20 30 40 50 

    print(lt);

    return 0;

}