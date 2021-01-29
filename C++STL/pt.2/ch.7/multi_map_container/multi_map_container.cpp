// map 컨테이너에 중복 원소를 허용한 컨테이너

#include <iostream>
#include <map>

using namespace std;

int main(){

    multimap<int, int> mm;

    mm.insert(pair<int, int>(5, 100));
    mm.insert(pair<int, int>(3, 100));
    mm.insert(pair<int, int>(8, 30));
    mm.insert(pair<int, int>(3, 40)); // value는 순서 상관 없이 삽입 된 순서대로 정렬됨 (3,100), (3,40)
    mm.insert(pair<int, int>(1, 70));
    mm.insert(pair<int, int>(7, 100));
    mm.insert(pair<int, int>(8, 50));

    multimap<int,int>::iterator iter;

    for(iter = mm.begin() ; iter != mm.end(); iter++)
        cout << "(" << iter->first <<"," << ")" << " ";
    cout << endl;

    cout << "key 3의 원소의 개수는 " << mm.count(3) << endl;

    iter = mm.find(3);

    if(iter != mm.end()){
        cout << "첫번째 key 3에 매핑된 value: " << iter->second << endl;
    }

    return 0;
    
}