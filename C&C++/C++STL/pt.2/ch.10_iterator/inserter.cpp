#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    // copy(v1.begin(), v1.end(), v2.begin()) // 에러!! (v2의 사이즈가 0이므로)

    // inserter 객체 생성 후 호출
    // insert_iterator<vector<int>> insert(v2, v2.begin()); 
    // copy(v1.begin(), v1.end(), insert);

    // 혹은 바로 inserter를 넣음
    copy(v1.begin(), v1.end(), inserter<vector<int>>(v2, v2.begin()));

    cout << "v1 : ";
    for(vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::iterator iter = v2.begin(); iter != v2.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    

    return 0;
}