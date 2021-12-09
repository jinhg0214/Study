#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

// *(p+1)�� *p ���� 3���� ũ�� ���� ��ȯ
// �� ������ ���̰� 3���϶��, ���� ���ҷ� �����
bool Pred(int left, int right){
    return 3 < right - left;
}

int main(){
    //////////////////////////////////////////////////
    cout << "========== 1. binary_search(b,e,x,f) ==========" << endl;
    vector<int> v;

    v.push_back(40);
    v.push_back(46);
    v.push_back(12);
    v.push_back(80);
    v.push_back(10);
    v.push_back(47);
    v.push_back(30);
    v.push_back(55);
    v.push_back(90);
    v.push_back(53);

    cout << "[v: ����] : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // ���� ���� ���� �˰����� ����ϱ� ���� ���� �ʿ�
    sort(v.begin(), v.end(), Pred); // 12, 55�� 10, 53���� �տ� ����.(���� ������ Pred�̹Ƿ�)

    cout << "[v: ����] : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    if(binary_search(v.begin(), v.end(), 32, Pred))
        cout << "32 ���Ұ� �����մϴ�." << endl;
    else    
        cout << "32 ���Ұ� �������� �ʽ��ϴ�." << endl;

    if(binary_search(v.begin(), v.end(), 35, Pred))
        cout << "35 ���Ұ� �����մϴ�." << endl;
    else    
        cout << "35 ���Ұ� �������� �ʽ��ϴ�." << endl;

    return 0;
}