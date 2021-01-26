// merge() 멤버함수
// 두개의 "정렬된" list를 하나의 정렬된 list로 합병함
// 합병은 두 list가 오름차순으로 정렬되어 있다는 가정 하에 동작함
// 정렬되어있지 않은 경우, 오류가 발생할수도있음
// slice() 멤버함수와 비교하여 알아둘것!!

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
    
    lt2.push_back(35);
    lt2.push_back(25);
    lt2.push_back(60);

    list<int>::iterator iter;

    cout << "lt1 : "; print(lt1);
    cout << "lt2 : "; print(lt2);

    lt1.merge(lt2); // lt2를 lt1으로 합병 정렬. 정렬 기준은 less

    cout << "lt1 : "; print(lt1);
    cout << "lt2 : "; print(lt2);  
    


    return 0;
}