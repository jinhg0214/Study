#include <iostream>

using namespace std;

class Equal{

public:
    bool operator()(int left, int right) const{
        return left == right;
    }
};

int main(){

    Equal cmp;

    if(cmp(20,20))
        cout << "같다!" << endl;
    else
        cout << "다르다!" << endl;

}