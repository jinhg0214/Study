#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Brick{
    int xy, h, w; // �ظ� ����, ����, ����
    Brick(int a, int b, int c){
        xy=a;
        h=b;
        w=c;
    }
    bool operator<(const Brick &b)const{
        return xy > b.xy; // �ظ��� ���̿� ���� ����
        // ������������ ����
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\7.LIS_tower\\input.txt", "rt", stdin);

    int n, a, b, c, res=0;

    cin >> n;

    vector<Brick> arr;

    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        arr.push_back(Brick(a,b,c));
    }

    // �ظ��� ���̸� �������� �������� ����
    sort(arr.begin(), arr.end());

    vector<int> dy(n);

    // LIS
    dy[0] = arr[0].h; // ù��° dy���Ҵ� arr�迭�� ù��° Brick�� h

    for(int i=1; i<n; i++){ // �ι�° ���Һ��� Ž��
        int max_h = 0; // �ִ� ���̸� ����
        
        for(int j=i-1; j>=0; j--){
            if(arr[j].w < arr[i].w && // ���� 5. ���԰� �������� ���� �ø� �� �ִ�
               dy[j] > max_h ){ 
                max_h = dy[j]; // �ִ� ���̸� ����
            }
        }

        dy[i] = max_h + arr[i].h; // �ִ� ���̸� ����

        res = max(dy[i], res);
    }

    cout << res;

    return 0;
}