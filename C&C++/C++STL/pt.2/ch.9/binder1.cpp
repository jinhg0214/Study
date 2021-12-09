#include <iostream>
#include <functional>

using namespace std;

int main(){
    //////////  //////////  //////////  //////////  //////////  //////////
    cout << "========== bind1st ==========" <<endl;
    
    // less�� ù ���ڸ� 10���� ������ ���� ������ binder ����
    binder1st<less<int>> binder = bind1st(less<int>(), 10); // �� 10�� ���ϰ� ��

    // binder�� ù ��° ���ڸ� 10���� ������ less
    cout << binder(5) << " : " << less<int>()(10, 5) << endl; // 10�� 5���� ������? false
    // �� ������ ����
    cout << binder(10) << " : " << less<int>()(10, 10) << endl; // 10�� 10���� ������? false
    // �� ������ ����
    cout << binder(20) << " : " << less<int>()(10, 20) << endl; // 10�� 20���� ������? true
    // �� ������ ����

    cout << "========== ���� ���� ==========" <<endl;

    // �ӽ� ��ü ���
    cout << bind1st(less<int>(), 10)(5) << " : " << less<int>()(10, 5) << endl;     
    cout << bind1st(less<int>(), 10)(10) << " : " << less<int>()(10, 10) << endl;
    cout << bind1st(less<int>(), 10)(20) << " : " << less<int>()(10, 20) << endl;

    //////////  //////////  //////////  //////////  //////////  //////////
    cout << "========== bind2nd ==========" <<endl;
    
    // less�� �� ��° ���ڸ� 10���� ������ ���� ������ binder ����
    binder2nd<less<int>> binder2 = bind2nd(less<int>(), 10);

    // binder�� �� ���� ���ڸ� 10���� ������ less
    cout << binder2(5) << " : " << less<int>()(5, 10) << endl; // 5�� 10���� ������? true
    // �� ������ ����.
    cout << binder2(10) << " : " << less<int>()(10, 10) << endl; // 5�� 10���� ������? true
    // �� ������ ����.
    cout << binder2(20) << " : " << less<int>()(20, 10) << endl; // 5�� 10���� ������? true
    // �� ������ ����.
    
     cout << "========== ���� ���� ==========" <<endl;

    // �ӽ� ��ü ���
    cout << bind2nd(less<int>(), 10)(5) << " : " << less<int>()(5, 10) << endl;     
    cout << bind2nd(less<int>(), 10)(10) << " : " << less<int>()(10, 10) << endl;
    cout << bind2nd(less<int>(), 10)(20) << " : " << less<int>()(20, 10) << endl;

    return 0;
}