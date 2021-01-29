#include <iostream>
#include <map>
#include <string>

using namespace std;

void Print(map<int, int> m){

    map<int, int>::iterator iter;

    for(iter = m.begin(); iter != m.end(); iter++)
        //(*iter).first , 또는 iter->first등으로 접근 가능
        cout << "(" << (*iter).first << "," << iter->second << ")" << " "; 
    cout << endl;
}

int main(){
    // key, value 모두 정수형인 컨테이너 생성
    // 기본 정렬 기준 less
    map<int, int> m;

    m.insert(pair<int, int>(5, 100));   // pair 임시 객체로 삽입    
    m.insert(pair<int, int>(3, 100));
    m.insert(pair<int, int>(8, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(1, 70));
    m.insert(pair<int, int>(7, 100));

    pair<int, int> pr(9, 50);       // pair 객체 pr을 생성하여 삽입
    m.insert(pr);   // 성공 여부를 bool값로 리턴함

    Print(m);

    //[] 연산자를 이용한 삽입, 수정
    m[5]= 200;

    Print(m);
    
    map<int, string, greater<int>> m2; // key:int, value:string, greater 정렬 기준은 map 생성

    m2[5]= "five";
    m2[3]= "three";
    m2[8]= "eight";
    m2[4]= "four";
    m2[1]= "one";
    m2[7]= "seven";
    m2[9]= "nine";
    
    map<int, string, greater<int>>::iterator iter2;

    for(iter2 = m2.begin(); iter2 != m2.end(); iter2++)
        cout << "(" << iter2->first << "," << iter2->second << ")" << " ";
    cout << endl;

    cout << m2[9] << " ";
    cout << m2[8] << " ";
    cout << m2[7] << " ";
    cout << m2[5] << " ";
    cout << m2[4] << " ";
    cout << m2[3] << " ";
    cout << m2[1] << endl;

    return 0;
}