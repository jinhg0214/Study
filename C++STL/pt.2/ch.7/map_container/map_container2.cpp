// 찾기 관련 멤버함수 사용
// find(), lower_bound(), upper_bound(), equal_range() 사용 예제

#include <iostream>
#include <map>

using namespace std;

void PrintMap(map<int, int> m)
{

    map<int, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++)
        //(*iter).first , 또는 iter->first등으로 접근 가능
        cout << "(" << (*iter).first << "," << iter->second << ")"
             << " ";
    cout << endl;
}

int main()
{

    map<int, int> m;

    m[5] = 100;
    m[3] = 100;
    m[8] = 30;
    m[4] = 40;
    m[1] = 70;
    m[7] = 100;
    m[9] = 50;

    PrintMap(m);

    map<int, int>::iterator iter;

    ///////////// find() 멤버함수 ////////////
    iter = m.find(5); // 검색 후 결과 존재시 반복자는 그 원소의 시작 반복자를, 존재하지 않으면 end()를 가리킴
    if (iter != m.end())
        cout << "(" << iter->first << "," << iter->second << ")" << " ";
    cout << endl;

    ///////////// lower_bound(), upper_bound() 멤버 함수 /////////////

    map<int, int>::iterator lower_iter = m.lower_bound(5); // 시작을 가리키는 반복자 반환
    map<int, int>::iterator upper_iter = m.upper_bound(5); // 다음 원소를 가리키는 반복자 반환

    cout << "구간 [lower_iter, upper_iter)의 순차열: "; 

    for(iter = lower_iter ; iter != upper_iter; iter++)
        cout << "(" << iter->first << "," << iter->second << ")"<< " ";
    cout << endl;
    
    ///////////// equal_range() 멤버 함수 /////////////

    pair<map<int,int>::iterator, map<int,int>::iterator> iter_pair; // <iter, iter>를 쌍으로 가지는 iter_pair
    iter_pair = m.equal_range(5); //  [iter_pair.first, iter_pair.second) 순차열 구간을 리턴

    cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";

    for(iter = iter_pair.first; iter != iter_pair.second; iter++){
        cout << "(" << iter->first << "," << iter->second << ")"<< " ";
    } cout << endl;

    return 0;
}
