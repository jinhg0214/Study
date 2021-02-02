#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

// ����� �Լ��� �Ű������� ��� �Ű������� ���Ǿ�� �ϹǷ� �� &�� �����!!(���� �����ؾ� �ϹǷ�)
void Func(int& r){
    r += 5;
}

// ���� �����ϴ� Ŭ����
class Accumulation{
    int total;
public:
    explicit Accumulation(int init=0):total(init){}
    void operator()(int& r){
        total += r;
        r = total;
    }
};

int main(){
    cout << "==========1.fill()==========" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << "fill ���� v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // ���� [v.begin(), v.end())�� ��� ���Ҹ� 0���� ä��
    fill(v.begin(), v.end(), 0);

    cout << "fill ���� v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // 2. fill_n()
    cout << "==========2.fill_n()==========" << endl;
    // ���� [v.begin(), v.begin()+3)�� ��� ���Ҹ� 55�� ä��
    fill_n(v.begin(), 3, 55);
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // 3. for_each() - �Լ�
    cout << "==========3.for_each()==========" << endl;
    v.clear();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.end(), Func); // [v.begin(), v.end())�� ��� ���ҿ� Func(*p)�� ������.
    
    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // 4. for_each() - �Լ���
    cout << "==========4.for_each()==========" << endl;
    
    v.resize(5);
    v.clear();

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // [v.begin(), v.end()) ��� ���Ҹ� �ʱⰪ 0���� ������ *p += *(p-1)�� ������
    for_each(v.begin(), v.end(), Accumulation(0)); 

    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl; // v�� ���� �����!!

    return 0;
}