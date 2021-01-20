#include <iostream>

using namespace std;


class Adder{

public:
    int operator()(int left, int right) const {
        return left + right;
    }

};

int main(){

    Adder add;
    int sum = add(10,20);
    cout << "sum= " << sum << endl;

    return 0;

}