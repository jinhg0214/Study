#include <iostream>

using namespace std;

class MyType{};
// Copy(t, s, n) t:������ �ּ�, s: �ҽ� �ּ�, n: ���� ����
// �� �Ű������� �޾� �迭�� �����ϴ� �Լ�
template<typename T>
void Copy(T t[],const T s[], int n){
    for(int i =0; i< n; i++){
        t[i] = s[i];
    }
}

template<typename T, int size>
void PrintArray(T* arr){
    for(int i=0; i< size; ++i){
        cout << "[" << i << "] : " << arr[i] << endl; 
    }
    cout << endl;
}


int main(){
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];

    Copy(arr2, arr1, 5);
    PrintArray<int,5>(arr2);

    MyType myArr1[5];
    MyType myArr2[5];

    Copy(myArr2, myArr1, 5);

    return 0;
}