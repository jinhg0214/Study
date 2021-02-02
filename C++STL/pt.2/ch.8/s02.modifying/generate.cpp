#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Integer{
    int data;
public:
    explicit Integer(int d = 0):data(d) {}
    int operator()(){ // ������ 1�� ������Ű�� ��� �Լ�
        return data++;
    }
};

template<typename T>
void Print(T n){
    cout << n << " ";
}

int main(){
    //////////////////////////////////////////////////
    cout << "==========1.generate()==========" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;

    // [v.begin(), v.end())�� ���Ҹ� 1~5�� ä��
    generate(v.begin(), v.end(), Integer(1));

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;

    // [v.begin(), v.end())�� ���Ҹ� 100~104�� ä��
    generate(v.begin(), v.end(), Integer(100));

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;

    // [v.begin(), v.begin()+3 )�� ���Ҹ� 1~3�� ä��
    generate(v.begin(), v.begin()+3, Integer(1));

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;


    return 0;
}