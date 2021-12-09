#include <iostream>
#include <functional>

using namespace std;

int main(){
    //////////  //////////  //////////  //////////  //////////  //////////
    cout << "========== bind1st ==========" <<endl;
    
    // less의 첫 인자를 10으로 고정한 단항 조건자 binder 생성
    binder1st<less<int>> binder = bind1st(less<int>(), 10); // 즉 10과 비교하게 됨

    // binder는 첫 번째 인자를 10으로 고정한 less
    cout << binder(5) << " : " << less<int>()(10, 5) << endl; // 10은 5보다 작은가? false
    // 두 문장이 같다
    cout << binder(10) << " : " << less<int>()(10, 10) << endl; // 10은 10보다 작은가? false
    // 두 문장이 같다
    cout << binder(20) << " : " << less<int>()(10, 20) << endl; // 10은 20보다 작은가? true
    // 두 문장이 같다

    cout << "========== 위와 같음 ==========" <<endl;

    // 임시 객체 사용
    cout << bind1st(less<int>(), 10)(5) << " : " << less<int>()(10, 5) << endl;     
    cout << bind1st(less<int>(), 10)(10) << " : " << less<int>()(10, 10) << endl;
    cout << bind1st(less<int>(), 10)(20) << " : " << less<int>()(10, 20) << endl;

    //////////  //////////  //////////  //////////  //////////  //////////
    cout << "========== bind2nd ==========" <<endl;
    
    // less의 두 번째 인자를 10으로 고정한 단항 조건자 binder 생성
    binder2nd<less<int>> binder2 = bind2nd(less<int>(), 10);

    // binder는 두 번쨰 인자를 10으로 고정한 less
    cout << binder2(5) << " : " << less<int>()(5, 10) << endl; // 5는 10보다 작은가? true
    // 두 문장이 같다.
    cout << binder2(10) << " : " << less<int>()(10, 10) << endl; // 5는 10보다 작은가? true
    // 두 문장이 같다.
    cout << binder2(20) << " : " << less<int>()(20, 10) << endl; // 5는 10보다 작은가? true
    // 두 문장이 같다.
    
     cout << "========== 위와 같음 ==========" <<endl;

    // 임시 객체 사용
    cout << bind2nd(less<int>(), 10)(5) << " : " << less<int>()(5, 10) << endl;     
    cout << bind2nd(less<int>(), 10)(10) << " : " << less<int>()(10, 10) << endl;
    cout << bind2nd(less<int>(), 10)(20) << " : " << less<int>()(20, 10) << endl;

    return 0;
}