#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

bool Pred(int n){
    return 30 <= n && n <= 40;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    cout << "30�̻� 40���� ������ ���� : " << count_if(v.begin(), v.end(), Pred) << endl;

    // Pred�� ���� �Լ��� �ƴ� �Ϲ� �Լ��̹Ƿ� ������ ������.
    // not1�� ����ͷ� �Լ� ��ü�� argument_type, result_type�� ���� �Ǿ��־����
    // cout << "30�̻� 40���� ������ ���� : " << count_if(v.begin(), v.end(), not1(Pred)) << endl;
     
    // ptr_fun()�� ���� ����� ������ ������ �Լ� ��ü�� ��ȯ �� not1����
    cout << "30�̻� 40���ϰ� �ƴ� ������ ���� : " << count_if(v.begin(), v.end(), not1(ptr_fun(Pred))) << endl;

    return 0;
}