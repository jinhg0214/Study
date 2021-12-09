#include <iostream>
#include <functional>

using namespace std;

template<typename T>
struct Plus: public binary_function<T, T, T> // ����� ������ �����ϰ�
{
    T operator()(const T& left, const T& right){
        return left + right;
    }
};

int main(){
    plus<int> oPlus;
    // 1. oPlus ��ü�� 10, 20 ���ϱ�. �Ϲ��� ȣ��
    cout << oPlus(10, 20) << endl;

    // 2. oPlus ��ü�� 10, 20 ���ϱ�. ����� ȣ��
    cout << oPlus.operator()(10,20) << endl;

    // 3. �ӽ� ��ü�� 10, 20 ���ϱ�. �Ϲ��� ȣ�� (�Ϲ��� ���)
    cout << plus<int>()(10,20) << endl;

    // 4. �ӽ� ��ü�� 10, 20 ���ϱ�. ����� ȣ��
    cout << plus<int>().operator()(10,20) << endl;

}