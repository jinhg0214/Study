#include <iostream>
#include <functional>

using namespace std;

int main(){
    less<int> oLess;
    binary_negate<less<int>> negate = not2(less<int>());

    cout << negate(5, 10) << ":" << not2(oLess)(5,10) << ":" << not2(less<int>())(5,10)<< endl;    // ��(5�� 10���� �۴�)   = 5�� 10���� ũ�ų� ���� (false)
    cout << negate(10, 10) << ":" << not2(oLess)(10,10) << ":" << not2(less<int>())(10,10)<< endl; // ��(10�� 10���� �۴�)   
    cout << negate(20, 10) << ":" << not2(oLess)(20,10) << ":" << not2(less<int>())(20,10)<< endl; // ��(20�� 10���� �۴�)

    cout << "========== ���� ������-> ���� ������-> not1 ������ ==========" << endl;

    binder2nd<less<int>> binder = bind2nd(less<int>(), 10); // ���� �����ڸ� ���� �����ڷ� �����,
    unary_negate<binder2nd<less<int>>> negate2 = not1(binder); //  �ٽ� �ݴ��� ���� �����ڷ� ��ȯ

    cout << negate2(5) << ":" << not1(binder)(5) << ":" << not1(bind2nd(less<int>(), 10))(5) << endl;    // ��(5�� 10���� �۴�) = 5�� 10���� ũ�ų� ���� (false)
    cout << negate2(10) << ":" << not1(binder)(10) << ":" << not1(bind2nd(less<int>(), 10))(10) << endl; // ��(10�� 10���� �۴�) = 10�� 10���� ũ�ų� ���� (true)
    cout << negate2(20) << ":" << not1(binder)(20) << ":" << not1(bind2nd(less<int>(), 10))(20) << endl; // 

    return 0;
}