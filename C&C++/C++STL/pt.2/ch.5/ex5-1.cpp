#include <iostream>
#include <vector> // ���� �����̳� ���
// ���� �����̳ʴ� ������ �����̳� & �迭 ��� �����̳�!
// FIFO ����

using namespace std;

int main(){

    // int Ÿ���� �����ϴ� �����̳� v�� ����
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    for(int i =0; i<v.size() ; i++){
        cout << v[i] << endl; // operator[] �����ڸ� �̿��Ͽ� �Ϲ� �迭ó�� ���ҿ� ���� ����
    }

    return 0;

}