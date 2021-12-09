// list의 splice() 멤버함수
// 다른 list 컨테이너의 순차열을 잘라 붙일 수 있음

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
    list<int> lt1;
    list<int> lt2;

    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);

    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);

    list<int>::iterator iter;

    cout << " lt1 : "; print(lt1);
    cout << " lt2 : "; print(lt2);

    iter = lt1.begin();
    ++iter;
    ++iter; // 30 원소의 위치를 가리킴

    lt1.splice(iter, lt2); // iter가 가리키는 위치에 lt2의 모든 원소를 잘라 붙임

    cout << " lt1 : "; print(lt1);
    cout << " lt2 : "; print(lt2);

    return 0;
}