#include <iostream>
#include <vector>

// vector�� ���� ���� �ݺ���

using namespace std;

int main(){

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    vector<int>::iterator iter = v.begin(); // �ݺ��� ����(���� ���Ҹ� ����Ű�� ����)
    
    cout << iter[0] << endl; // [] �����ڸ� �̿��� ���� ���� ����. iter+i ��° ���ҿ� ����(������)
    cout << iter[1] << endl;
    cout << iter[2] << endl;
    cout << iter[3] << endl;
    cout << iter[4] << endl;
    cout << endl;

    iter += 2; // += ����. iter�� n��ŭ �̵���Ŵ
    cout << *iter << endl;
    cout << endl;

    vector<int>::iterator iter2 = iter+2; // + ����.
    cout << *iter2 << endl; 


    return 0;
}