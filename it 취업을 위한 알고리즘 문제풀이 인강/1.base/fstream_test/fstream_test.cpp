#include <iostream>
#include <fstream>

using namespace std;

int main(){
   
   // vscode 특성상 절대 경로로 설정해야함
   // 아마 다른 방법이 있을듯 한데 더 찾아봐야할듯
    std::ifstream in("G:\\Git\\Algorithm-C-\\1.base\\fstream_test\\input.txt"); 
    std:string s;

    if(in.is_open()){
        in >> s;
        cout << "입력 받은 문자열 :: " << s << endl;
    } else {
        cout << "파일을 찾을 수 없습니다!" << endl;
    }
    return 0;
}