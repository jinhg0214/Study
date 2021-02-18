#include <iostream>
#include <algorithm>
#include <vector>
#include <list> 
#include <iterator>

using namespace std;

int main(){

    ////////// ////////// ////////// ////////// //////////
    cout << "========== 1. ostream ==========" << endl;

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 : ";
    // cout�� ����� ����(int)�� ����ϴ� �ݺ��� ���� 
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout));
    cout << endl;

    cout << "v1 : ";
    // ��� �� ������ ", "�� �ϴ� �ݺ��� ���� 
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    list<int> lt1;
    lt1.push_back(100);
    lt1.push_back(200);
    lt1.push_back(300);

    cout << "lt1+v1 : ";
    transform(lt1.begin(), lt1.end(), v1.begin(), 
        ostream_iterator<int>(cout, " "), plus<int>());
    cout << endl;

    ////////// ////////// ////////// ////////// //////////
    cout << "========== 2. istream ==========" << endl;

    vector<int> v2;

    // ǥ�� �Է� ��Ʈ������ ������ �Է¹޾� v�� ����
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int>>(v2));

    cout << "v2 : ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // ������ ��Ʈ�� ��(Ctrl+D) ���� �Է¹޾� ȭ�鿡 ���
    // copy(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout," "));

    return 0;
}