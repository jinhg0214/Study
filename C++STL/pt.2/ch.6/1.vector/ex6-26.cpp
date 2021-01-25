// 반복자로 동작하는 vector의 인터페이스(생성자, assign() 등)

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
    
    // 순차열을 이용한 생성
    vector<int> v2(v.begin(), v.end());
   
    vector<int>::iterator iter;

    for(iter = v2.begin(); iter!= v2.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;

    vector<int> v3;
    v3.assign(v.begin(), v.end()); // assign을 이용한 할당

    for(iter = v3.begin(); iter!= v3.end(); ++iter){
        cout << *iter << " ";
    } cout << endl;   

    ////////////// 컨테이너 연산자 ////////////////////
    // == != < <= > >= 


    return 0;
}