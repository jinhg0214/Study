#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int n){
    return n > 35;
}

bool Pred2(int left, int right){
    return left <= right;
}

bool Pred3(int left, int right){
    return left > right;
}

int main(){
    //////////////////////////////////////////////////////////////////////////
    // find() : Ư�� ���Ҹ� ã�� �˰���
    
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter;
    iter = find(v.begin(),v.end(), 20); // [v.begin(), v.end()) ���� ���� 20�� ã��

    if(iter != v.end()){
        cout << *iter << "�� �����մϴ�." << endl;
    } cout << "==============================" << endl;
    
    //////////////////////////////////////////////////////////////////////////
    // find_if() : Ư�� ���ǿ� �´� ���Ҹ� ã�� �˰���

    // ���� [v.begin(), v.end()) ���� 35���� ū ���Ҹ� ã�� ù���� ���Ҹ� ��ȯ 
    iter = find_if(v.begin(), v.end(), Pred);
    if(iter != v.end()){
        cout << "���������� 35���� ū ù��° ����: " << *iter << endl;
    } cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // find_end() : 
    
    v.clear();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    vector<int> v2;
    
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    // [v.begin(), v.end())�� ������ ������, [v2.begin(), v2.end())�� �������� ��ġ�ϴ��� �Ǵ��Ͽ�,
    // ��ġ�ϴ� ������ ������ ���������, 
    // ������ �������� ù ���� �ݺ��ڸ� ��ȯ
    iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    if(iter != v.end()){
        // ��ġ�ϴ� ������ �������� ù ���� �ݺ��� iter
        cout << "iter : "<< *iter << endl; // 30,40,50�� �� ������ ������ �����ϹǷ�, ������ �������� ��ȯ��
        cout << "iter-1 : "<< *(iter-1) << endl;
        cout << "iter+1 : "<< *(iter+1) << endl;
    } cout << "==============================" << endl;

    // find_end() ������ ����
    v.clear(); v2.clear();
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(80);

    v2.push_back(10);
    v2.push_back(15);
    v2.push_back(20);

    iter = find_end(v.begin(), v.end(), v2.begin(), v2.end(), Pred2); // Pred2���ǿ� �´� ���� �˻�
    if(iter != v.end()){
        cout << "iter : "<< *iter << endl; 
        cout << "iter-1 : "<< *(iter-1) << endl;
        cout << "iter+1 : "<< *(iter+1) << endl;
    } cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // find_first_of() : �� �������� ���Ͽ�, ��� ���� �� ���� ���Ұ� �ϳ��� �߰ߵǸ� ù ������ �ݺ��ڸ� ��ȯ
    v.clear(); v2.clear();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    v2.push_back(40);
    v2.push_back(80);
    v2.push_back(20);

   
    iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end());

    if(iter != v.end()){
        // v1���� v2�� ���Ұ� ù��°�� �߰ߵǴ� ��ġ�� 20�̹Ƿ� 20�� ���ϵ�
        cout << "iter : " << *iter << endl; 
    } cout << "==============================" << endl;

    // find_first_of() ������ ����
    iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), Pred3);

    // v���� v2���� ū ���Ҵ� 30�� ó���̹Ƿ�, 30�� ��ȯ��
    
    if(iter != v.end())
        cout << "iter : " << *iter << endl; 


    return 0;
}