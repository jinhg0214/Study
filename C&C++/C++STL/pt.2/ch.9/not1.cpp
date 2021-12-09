#include <iostream>
#include <functional>

using namespace std;

int main(){
    less<int> oLess;
    binary_negate<less<int>> negate = not2(less<int>());

    cout << negate(5, 10) << ":" << not2(oLess)(5,10) << ":" << not2(less<int>())(5,10)<< endl;    // ￢(5는 10보다 작다)   = 5는 10보다 크거나 같다 (false)
    cout << negate(10, 10) << ":" << not2(oLess)(10,10) << ":" << not2(less<int>())(10,10)<< endl; // ￢(10은 10보다 작다)   
    cout << negate(20, 10) << ":" << not2(oLess)(20,10) << ":" << not2(less<int>())(20,10)<< endl; // ￢(20은 10보다 작다)

    cout << "========== 이항 조건자-> 단항 조건자-> not1 부정자 ==========" << endl;

    binder2nd<less<int>> binder = bind2nd(less<int>(), 10); // 이항 조건자를 단항 조건자로 만들고,
    unary_negate<binder2nd<less<int>>> negate2 = not1(binder); //  다시 반대의 단항 조건자로 변환

    cout << negate2(5) << ":" << not1(binder)(5) << ":" << not1(bind2nd(less<int>(), 10))(5) << endl;    // ￢(5은 10보다 작다) = 5는 10보다 크거나 같다 (false)
    cout << negate2(10) << ":" << not1(binder)(10) << ":" << not1(bind2nd(less<int>(), 10))(10) << endl; // ￢(10은 10보다 작다) = 10은 10보다 크거나 같다 (true)
    cout << negate2(20) << ":" << not1(binder)(20) << ":" << not1(bind2nd(less<int>(), 10))(20) << endl; // 

    return 0;
}